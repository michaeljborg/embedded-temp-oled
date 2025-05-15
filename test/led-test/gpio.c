#include "gpio.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

static volatile uint32_t *gpio;

int gpio_setup() {
    int mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (mem_fd < 0) return -1;

    void *gpio_map = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, GPIO_BASE);
    close(mem_fd);

    if (gpio_map == MAP_FAILED) return -1;

    gpio = (volatile uint32_t *)gpio_map;
    return 0;
}

void gpio_set_output(int pin) {
    int reg = pin / 10;
    int shift = (pin % 10) * 3;
    gpio[reg] &= ~(7 << shift);
    gpio[reg] |=  (1 << shift); // output (001)
}

void gpio_set_input(int pin) {
    int reg = pin / 10;
    int shift = (pin % 10) * 3;
    gpio[reg] &= ~(7 << shift); // input (000)
}

int gpio_read(int pin) {
    return (gpio[13] & (1 << pin)) ? 1 : 0; // GPLEV0 = offset 13
}

void gpio_write(int pin, int value) {
    gpio[value ? 7 : 10] = (1 << pin); // GPSET0 = 7, GPCLR0 = 10
}

void gpio_enable_pullup(int pin) {
    gpio[37] = (1 << pin);  // GPPUPPDN0/1, offset 37 = GPIO 0–15, 38 = 16–31
    gpio[38] = (1 << pin);  // Use 38 for GPIO17 and GPIO18
}
