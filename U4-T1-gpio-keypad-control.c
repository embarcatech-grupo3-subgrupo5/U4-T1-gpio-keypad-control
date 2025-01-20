#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos dos LEDs
#define RED 13
#define GREEN 11
#define BLUE 12
#define BUZZER 21

// Definição dos pinos do teclado matricial
#define ROW1 8
#define ROW2 7
#define ROW3 6
#define ROW4 5
#define COL1 4
#define COL2 3
#define COL3 2
#define COL4 1

#define DEBOUNCE_TIME 60 // Tempo de debounce em ms, para evitar leituras incorretas ao pressionar rapidamente as teclas

// Função para inicializar o teclado matricial
void init_keypad() {
    // Configurar linhas como saída e desativá-las inicialmente
    gpio_init(ROW1);
    gpio_set_dir(ROW1, GPIO_OUT);
    gpio_put(ROW1, true);

    gpio_init(ROW2);
    gpio_set_dir(ROW2, GPIO_OUT);
    gpio_put(ROW2, true);

    gpio_init(ROW3);
    gpio_set_dir(ROW3, GPIO_OUT);
    gpio_put(ROW3, true);

    gpio_init(ROW4);
    gpio_set_dir(ROW4, GPIO_OUT);
    gpio_put(ROW4, true);

    // Configurar colunas como entrada com pull-up
    gpio_init(COL1);
    gpio_set_dir(COL1, GPIO_IN);
    gpio_pull_up(COL1);

    gpio_init(COL2);
    gpio_set_dir(COL2, GPIO_IN);
    gpio_pull_up(COL2);

    gpio_init(COL3);
    gpio_set_dir(COL3, GPIO_IN);
    gpio_pull_up(COL3);

    gpio_init(COL4);
    gpio_set_dir(COL4, GPIO_IN);
    gpio_pull_up(COL4);
}

// Função para ler a tecla pressionada no teclado matricial
char read_keypad() {
    const char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };

    for (int row = 0; row < 4; row++) {
        // Desativa todas as linhas
        gpio_put(ROW1, true);
        gpio_put(ROW2, true);
        gpio_put(ROW3, true);
        gpio_put(ROW4, true);

        // Ativa apenas a linha correspondente
        if (row == 0) gpio_put(ROW1, false);
        if (row == 1) gpio_put(ROW2, false);
        if (row == 2) gpio_put(ROW3, false);
        if (row == 3) gpio_put(ROW4, false);

        // Verificar cada coluna
        if (!gpio_get(COL1)) return keys[row][0];
        if (!gpio_get(COL2)) return keys[row][1];
        if (!gpio_get(COL3)) return keys[row][2];
        if (!gpio_get(COL4)) return keys[row][3];
    }

    return ' '; // Nenhuma tecla pressionada
}

// Função para inicializar os LEDs
void init_led() {
    gpio_init(RED);
    gpio_set_dir(RED, GPIO_OUT);
    gpio_init(GREEN);
    gpio_set_dir(GREEN, GPIO_OUT);
    gpio_init(BLUE);
    gpio_set_dir(BLUE, GPIO_OUT);
}

// Desenvolvida por: Mario Vinicius
// Função para inicializar o buzzer
void init_buzzer() {
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// Desenvolvida por: Mario Vinicius
// Função que ativa o buzzer por 3 segundos
void ativar_buzzer() {
    gpio_put(BUZZER, true);
    sleep_ms(3000);
    gpio_put(BUZZER, false);
    sleep_ms(3000);
}

//------------------------------------------------------
void map_key_to_action(char key) {
    switch (key) {
        case '1': // Liga LED Vermelho
            gpio_put(RED, true);
            gpio_put(GREEN, false);
            gpio_put(BLUE, false);
            break;

        case '2': // Liga LED Verde
            gpio_put(RED, false);
            gpio_put(GREEN, true);
            gpio_put(BLUE, false);
            break;

        case '3': // Liga LED Azul
            gpio_put(RED, false);
            gpio_put(GREEN, false);
            gpio_put(BLUE, true);
            break;

        case '4': // Desliga o LED Vermelho
            gpio_put(RED, false);
            break;

        case '5': // Desliga o LED Verde
            gpio_put(GREEN, false);
            break;

        case '6': // Desliga o LED Azul
            gpio_put(BLUE, false);
            break;

        case '7': // Liga o LED Vermelho e desliga após 500ms
            gpio_put(RED, true);
            sleep_ms(500);
            gpio_put(RED, false);
            break;

        case '8': // Liga o LED Verde e desliga após 500ms
            gpio_put(GREEN, true);
            sleep_ms(500);
            gpio_put(GREEN, false);
            break;

        case '9': // Liga o LED Azul e desliga após 500ms
            gpio_put(BLUE, true);
            sleep_ms(500);
            gpio_put(BLUE, false);
            break;

        case '0': // Inverte o estado de todos os LEDs
            gpio_put(RED, !gpio_get(RED));
            gpio_put(GREEN, !gpio_get(GREEN));
            gpio_put(BLUE, !gpio_get(BLUE));
            break;

        //Desenvolvida por: Geison
        case '*': 
            ativar_buzzer();
            break;

        default:
            // Caso a tecla não esteja mapeada, não faz nada
            printf("Tecla não mapeada: %c\n", key);
            break;
    }
}

int main() {
    stdio_init_all();
    init_led();
    init_buzzer();
    init_keypad();

    while (true) {
        char key = read_keypad();
        if (key != ' ') {
            printf("Tecla pressionada: %c\n", key);
            map_key_to_action(key);
        }
        sleep_ms(DEBOUNCE_TIME);
    }
}
