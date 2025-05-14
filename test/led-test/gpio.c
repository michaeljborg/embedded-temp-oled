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
    gpio[reg] &= ~(7 << shift);  // Clear function
    gpio[reg] |=  (1 << shift);  // Set to output (001)
}

void gpio_write(int pin, int value) {
    int reg = value ? 7 : 10;  // GPSET0 = 7, GPCLR0 = 10
    gpio[reg] = (1 << pin);
}

void gpio_cleanup() {
    // Optionally unmap later
}
