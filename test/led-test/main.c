#include <stdio.h>
#include <unistd.h>
#include "gpio.h"

int main() {
    if (gpio_setup() < 0) {
        perror("Failed to access /dev/mem");
        return 1;
    }

    gpio_set_output(GPIO_PIN);

    while (1) {
        gpio_write(GPIO_PIN, 1);
        usleep(500000);
        gpio_write(GPIO_PIN, 0);
        usleep(500000);
    }

    return 0;
}
