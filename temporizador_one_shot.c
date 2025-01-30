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
