#include <stdio.h>
#include <unistd.h>
#include "gpio.h"

int main() {
    if (gpio_setup() < 0) {
        perror("Failed to access /dev/mem");
        return 1;
    }

    gpio_set_output(LED_PIN);
    gpio_set_input(BUTTON_PIN);
    gpio_enable_pullup(BUTTON_PIN);

    int led_state = 0;
    int prev_button = 1;

    while (1) {
        int button = gpio_read(BUTTON_PIN);

        // Detect falling edge (button press)
        if (prev_button == 1 && button == 0) {
            led_state = !led_state;
            gpio_write(LED_PIN, led_state);
        }

        prev_button = button;
        usleep(10000); // 10 ms debounce
    }

    return 0;
}
