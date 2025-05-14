#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define BCM2711_PERI_BASE   0xFE000000
#define GPIO_BASE           (BCM2711_PERI_BASE + 0x200000)
#define BLOCK_SIZE          (4 * 1024)

#define GPIO_PIN            18

int gpio_setup();
void gpio_set_output(int pin);
void gpio_write(int pin, int value);
void gpio_cleanup();

#endif