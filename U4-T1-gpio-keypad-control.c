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

// Definir o pino do buzzer
#define BUZZER 21

void setup_gpio() {
    gpio_set_function(BUZZER, GPIO_FUNC_PWM); // Configura o buzzer como saída PWM
}

void tocar_buzzer(uint frequency, float duration) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    pwm_set_wrap(slice_num, 125000000 / frequency);  // Define a frequência
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(BUZZER), 32768); // Volume
    pwm_set_enabled(slice_num, true);  // Liga o PWM
    sleep_ms((int)(duration * 1000));  // Duração do som
    pwm_set_enabled(slice_num, false); // Desliga o PWM
}

int main() {
    stdio_init_all();
    setup_gpio(); // Configura os GPIOs

    printf("Teste do buzzer no GPIO 21.\n");
    tocar_buzzer(440, 1.0); // Som de 1 segundo em 440 Hz
    sleep_ms(1000);
    tocar_buzzer(880, 1.0); // Som de 1 segundo em 880 Hz
    return 0;
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
