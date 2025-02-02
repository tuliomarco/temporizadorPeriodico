#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Identificação das GPIOs correspondentes aos LEDs
#define LED_R_PIN 11
#define LED_G_PIN 13
#define LED_Y_PIN 12

/*
* Inicialização das GPIOs
*/
void init() {
    gpio_init(LED_R_PIN);
    gpio_init(LED_G_PIN);
    gpio_init(LED_Y_PIN);

    gpio_set_dir(LED_R_PIN, GPIO_OUT);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);
    gpio_set_dir(LED_Y_PIN, GPIO_OUT);
}

void repeating_timer_callback(struct repeating_timer *t) {}

int main() {
    stdio_init_all();
    init();

    struct repeating_timer timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        sleep_ms(1000);
        gpio_put(LED_R_PIN, 1);
        sleep_ms(300);
        gpio_put(LED_R_PIN, 0);
        sleep_ms(1000);
        gpio_put(LED_Y_PIN, 1);
        sleep_ms(300);
        gpio_put(LED_Y_PIN, 0);
        sleep_ms(1000);
        gpio_put(LED_G_PIN, 1);
        sleep_ms(300);
        gpio_put(LED_G_PIN, 0);
    }
}
