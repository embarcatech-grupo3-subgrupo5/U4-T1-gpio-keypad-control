#include <stdio.h>
#include "pico/stdlib.h"

#define RED 13
#define GREEN 11
#define BLUE 12

void init_led(){
    gpio_init(RED);
    gpio_set_dir(RED, GPIO_OUT);
    gpio_init(GREEN);
    gpio_set_dir(GREEN, GPIO_OUT);
    gpio_init(BLUE);
    gpio_set_dir(BLUE, GPIO_OUT);
}

void ligar_led_R(){
    gpio_put(RED, true);
}

void ligar_led_B(){
    gpio_put(GREEN, true);
}

void ligar_led_G(){
    gpio_put(GREEN, true);
}
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

    while (1) {
        printf("Buzzer ligado por 1 segundo...\n");
        play_buzzer(1000); // Liga o buzzer por 1 segundo
        sleep_ms(1000);    // Espera 1 segundo antes de tocar novamente
    }
}


int main()
{
    stdio_init_all();
    init_led();


    /** @todo implementar leitura de teclada matricial */
    char key = ' ';

    while (true) {
        switch (key)
        {
        case ' '/* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
        sleep_ms(500);    
    }
}
