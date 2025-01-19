#include <stdio.h>
#include "pico/stdlib.h"

// Definição do pino do buzzer
#define BUZZER_PIN 21

// Função para configurar o buzzer como saída
void setup_buzzer() {
    gpio_init(BUZZER_PIN);         // Inicializa o pino do buzzer
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Define como saída
}

// Função para tocar o buzzer
void play_buzzer(int duration_ms) {
    gpio_put(BUZZER_PIN, 1); // Liga o buzzer
    sleep_ms(duration_ms);   // Mantém ligado pelo tempo especificado
    gpio_put(BUZZER_PIN, 0); // Desliga o buzzer
}

int main() {
    stdio_init_all(); // Inicializa a interface padrão
    setup_buzzer();   // Configura o pino do buzzer

    printf("Iniciando o controle do buzzer...\n");
}
    while (1) {
        printf("Buzzer ligado por 1 segundo...\n");
        play_buzzer(1000); // Liga o buzzer por 1 segundo
        sleep_ms(1000);    // Espera 1 segundo antes de tocar novamente
    }