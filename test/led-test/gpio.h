#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define BCM2711_PERI_BASE   0xFE000000
#define GPIO_BASE           (BCM2711_PERI_BASE + 0x200000)
#define BLOCK_SIZE          (4 * 1024)

#define LED_PIN    18
#define BUTTON_PIN 17

int gpio_setup();
void gpio_set_output(int pin);
void gpio_set_input(int pin);
void gpio_enable_pullup(int pin);
int gpio_read(int pin);
void gpio_write(int pin, int value);

#endif
