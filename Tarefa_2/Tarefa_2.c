#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos GPIOs
#define BUTTON_GPIO 5
#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Protótipos das funções de callback
int64_t debounce_callback(alarm_id_t id, void *user_data);
int64_t timer_callback(alarm_id_t id, void *user_data);

typedef enum {
    STEP_1,
    STEP_2,
    STEP_3
} sequence_step_t;

// Variáveis globais
static volatile bool sequence_active = false;
static volatile bool button_pressed = false;
static volatile bool debounce = false;

// Tratador de interrupção do botão
void button_isr(uint gpio, uint32_t events) {
    if (gpio == BUTTON_GPIO && (events & GPIO_IRQ_EDGE_FALL)) {
        if (!debounce) {
            debounce = true;
            add_alarm_in_ms(50, debounce_callback, NULL, false);
        }
    }
}

// Callback de debounce 
int64_t debounce_callback(alarm_id_t id, void *user_data) {
    if (!gpio_get(BUTTON_GPIO)) {
        button_pressed = true;
    }
    debounce = false;
    return 0;
}

// Callback do temporizador para mudança de estados
int64_t timer_callback(alarm_id_t id, void *user_data) {
    sequence_step_t step = (sequence_step_t)(uintptr_t)user_data;

    switch (step) {
        case STEP_1:
            gpio_put(LED_GREEN, 0);  // Desliga verde
            add_alarm_in_ms(3000, timer_callback, (void *)(uintptr_t)STEP_2, false);
            break;
        case STEP_2:
            gpio_put(LED_YELLOW, 0);  // Desliga vermelho
            add_alarm_in_ms(3000, timer_callback, (void *)(uintptr_t)STEP_3, false);
            break;
        case STEP_3:
            gpio_put(LED_RED, 0);  
            sequence_active = false; 
            break;
    }
    return 0;
}

// Configuração inicial dos GPIOs
void setup_gpio() {
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_put(LED_YELLOW, 0);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    // Configura interrupção
    gpio_set_irq_enabled_with_callback(BUTTON_GPIO, GPIO_IRQ_EDGE_FALL, true, &button_isr);
}

int main() {
    stdio_init_all();
    setup_gpio();

    while (true) {
        if (button_pressed) {
            button_pressed = false;
            if (!sequence_active) {
                gpio_put(LED_RED, 1);
                gpio_put(LED_YELLOW, 1);
                gpio_put(LED_GREEN, 1);
                sequence_active = true;

                add_alarm_in_ms(3000, timer_callback, (void *)(uintptr_t)STEP_1, false);
            }
        }
        sleep_ms(100);
    }
    return 0;
}