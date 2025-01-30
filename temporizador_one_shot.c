#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definições de pinos
#define LED_AZUL  11
#define LED_VERMELHO 12
#define LED_VERDE 13
#define BOTAO 5

// Variável para controlar se o botão pode ser pressionado novamente
volatile bool pode_pressionar = true;

// Callback para desligar o LED verde
int64_t turn_off_callback_verde(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERDE, 0); 
    pode_pressionar = true;
    return 0;
}

// Callback para desligar o LED vermelho
int64_t turn_off_callback_vermelho(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERMELHO, 0); 
    add_alarm_in_ms(3000, turn_off_callback_verde, NULL, false);
    return 0;
}

// Callback para desligar o LED azul
int64_t turn_off_callback_azul(alarm_id_t id, void *user_data) {
    gpio_put(LED_AZUL, 0);
    add_alarm_in_ms(3000, turn_off_callback_vermelho, NULL, false);
    return 0;
}

int main() {
    stdio_init_all();

   
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_put(LED_AZUL, 0); 

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_put(LED_VERMELHO, 0); 

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_put(LED_VERDE, 0); 

  
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    while (true) {
        sleep_ms(100); // Aguarda para evitar consumo excessivo da CPU
    }
}
