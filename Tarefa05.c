#include "pico/stdlib.h"
#include <stdio.h>

#define LED_BLUE 12
#define LED_RED 13
#define LED_GREEN 14
#define BUTTON 15

typedef enum {
    ALL_ON,
    TWO_ON,
    ONE_ON,
    ALL_OFF
} LedState;

LedState currentState = ALL_OFF;
bool buttonPressed = false;

int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    switch (currentState) {
        case ALL_ON:
            gpio_put(LED_BLUE, 0);
            currentState = TWO_ON;
            break;
        case TWO_ON:
            gpio_put(LED_RED, 0);
            currentState = ONE_ON;
            break;
        case ONE_ON:
            gpio_put(LED_GREEN, 0);
            currentState = ALL_OFF;
            break;
        case ALL_OFF:
            break;
    }
    return 0;
}

void button_callback(uint gpio, uint32_t events) {
    if (gpio == BUTTON && currentState == ALL_OFF) {
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);
        currentState = ALL_ON;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();

    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(BUTTON);

    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);

    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_RISE, true, &button_callback);

    while (true) {
        tight_loop_contents();
    }

    return 0;
}