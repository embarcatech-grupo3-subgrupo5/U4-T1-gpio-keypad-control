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
