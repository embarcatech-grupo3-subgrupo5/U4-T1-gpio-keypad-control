#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos dos LEDs - Emylle
#define RED 13
#define GREEN 11
#define BLUE 12

// Definição do pino do buzzer - Mario Vinicius
#define BUZZER 21

// Definição dos pinos do teclado matricial - Geison
#define ROW1 8
#define ROW2 7
#define ROW3 6
#define ROW4 5
#define COL1 4
#define COL2 3
#define COL3 2
#define COL4 1

#define DEBOUNCE_TIME 60 // Tempo de debounce em ms, para evitar leituras incorretas ao pressionar rapidamente as teclas - Geison

// Função para inicializar o teclado matricial - Geison
void init_keypad() {
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

// Função para ler a tecla pressionada no teclado matricial - Geison
char read_keypad() {
    const char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };

    for (int row = 0; row < 4; row++) {
        gpio_put(ROW1, true);
        gpio_put(ROW2, true);
        gpio_put(ROW3, true);
        gpio_put(ROW4, true);

        if (row == 0) gpio_put(ROW1, false);
        if (row == 1) gpio_put(ROW2, false);
        if (row == 2) gpio_put(ROW3, false);
        if (row == 3) gpio_put(ROW4, false);

        if (!gpio_get(COL1)) return keys[row][0];
        if (!gpio_get(COL2)) return keys[row][1];
        if (!gpio_get(COL3)) return keys[row][2];
        if (!gpio_get(COL4)) return keys[row][3];
    }

    return ' ';
}

// Função para inicializar os LEDs - Emylle
void init_led() {
    gpio_init(RED);
    gpio_set_dir(RED, GPIO_OUT);
    gpio_init(GREEN);
    gpio_set_dir(GREEN, GPIO_OUT);
    gpio_init(BLUE);
    gpio_set_dir(BLUE, GPIO_OUT);
}

// Função para inicializar o buzzer - Mario Vinicius
void init_buzzer() {
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// Função para inicializar o buzzer passivo - Geison
void acionar_buzzer_passivo(uint32_t duration_ms, uint32_t freq_hz) {
    uint32_t period_us = 1000000 / freq_hz; // Período em microssegundos
    uint32_t half_period = period_us / 2;
    uint32_t end_time = time_us_32() + (duration_ms * 1000);

    while (time_us_32() < end_time) {
        gpio_put(BUZZER, true);
        sleep_us(half_period);
        gpio_put(BUZZER, false);
        sleep_us(half_period);
    }
}

// Função que ativa o buzzer por 3 segundos com frequência de 2 kHz - Geison
void ativar_buzzer2() {
    acionar_buzzer_passivo(3000, 2000); // 3 segundos com frequência de 2 kHz
}

// Função que pulsa o buzzer 5 vezes com frequência de 2 kHz - Geison
void buzzer_pulse2() {
    for (int i = 0; i < 5; i++) {
        acionar_buzzer_passivo(500, 2000); // 500 ms com frequência de 2 kHz
        sleep_ms(500);                    // Pausa entre os pulsos
    }
}

// Função que aciona um beep longo de 5 segundos com frequência de 1.5 kHz - Geison
void buzzer_long_beep2() {
    acionar_buzzer_passivo(5000, 1500); // 5 segundos com frequência de 1.5 kHz
}

// Função que aciona 10 beeps curtos de 200 ms com frequência de 3 kHz - Geison
void buzzer_short_beeps2() {
    for (int i = 0; i < 10; i++) {
        acionar_buzzer_passivo(200, 3000); // 200 ms com frequência de 3 kHz
        sleep_ms(200);
    }
}

// Função que aciona 3 beeps alternados de 1 segundo com frequência de 2.5 kHz - Geison
void buzzer_alternate_beeps2() {
    for (int i = 0; i < 3; i++) {
        acionar_buzzer_passivo(1000, 2500); // 1 segundo com frequência de 2.5 kHz
        sleep_ms(500);                     // Pausa entre os beeps
    }
}

// Função que ativa o buzzer por 3 segundos - Mario Vinicius
void ativar_buzzer() {
    gpio_put(BUZZER, true);
    sleep_ms(3000);
    gpio_put(BUZZER, false);
    sleep_ms(3000);
}

// Funções adicionais para o controle do buzzer - Julierme 
void buzzer_pulse() {
    for (int i = 0; i < 5; i++) {
        gpio_put(BUZZER, true);
        sleep_ms(500);
        gpio_put(BUZZER, false);
        sleep_ms(500);
    }
}

void buzzer_long_beep() {
    gpio_put(BUZZER, true);
    sleep_ms(5000);
    gpio_put(BUZZER, false);
}

void buzzer_short_beeps() {
    for (int i = 0; i < 10; i++) {
        gpio_put(BUZZER, true);
        sleep_ms(200);
        gpio_put(BUZZER, false);
        sleep_ms(200);
    }
}

void buzzer_alternate_beeps() {
    for (int i = 0; i < 3; i++) {
        gpio_put(BUZZER, true);
        sleep_ms(1000);
        gpio_put(BUZZER, false);
        sleep_ms(500);
    }
}

void buzzer_off() {
    gpio_put(BUZZER, false);
}

// Função para mapear a tecla pressionada para ação correspondente - Gabriella e Geison
void map_key_to_action(char key) {
    switch (key) {
        case '1':
            gpio_put(RED, true);
            gpio_put(GREEN, false);
            gpio_put(BLUE, false);
            break;
        case '2':
            gpio_put(RED, false);
            gpio_put(GREEN, true);
            gpio_put(BLUE, false);
            break;
        case '3':
            gpio_put(RED, false);
            gpio_put(GREEN, false);
            gpio_put(BLUE, true);
            break;
        case '4':
            gpio_put(RED, false);
            break;
        case '5':
            gpio_put(GREEN, false);
            break;
        case '6':
            gpio_put(BLUE, false);
            break;
        case '7':
            gpio_put(RED, true);
            sleep_ms(500);
            gpio_put(RED, false);
            break;
        case '8':
            gpio_put(GREEN, true);
            sleep_ms(500);
            gpio_put(GREEN, false);
            break;
        case '9':
            gpio_put(BLUE, true);
            sleep_ms(500);
            gpio_put(BLUE, false);
            break;
        case '0':
            gpio_put(RED, !gpio_get(RED));
            gpio_put(GREEN, !gpio_get(GREEN));
            gpio_put(BLUE, !gpio_get(BLUE));
            break;
        case '*':
            ativar_buzzer2();
            break;
        case 'A':
            buzzer_pulse2();
            break;
        case 'B':
            buzzer_long_beep2();
            break;
        case 'C':
            buzzer_short_beeps2();
            break;
        case 'D':
            buzzer_alternate_beeps2();
            break;
        case '#':
            buzzer_off();
            break;
        default:
            printf("Tecla não mapeada: %c\n", key);
            break;
    }
}

// Função principal - Emylle e Geison
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
