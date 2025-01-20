# U4-T1-gpio-keypad-control
# Tarefa 1 -Controle de pinos GPIO com oemprego de um teclado matricial. 
## Descrição
Este projeto implementa o controle de pinos GPIO de um microcontrolador RP2040 utilizando:

Teclado Matricial 4x4 (Atividade 1).

O objetivo é realizar o acionamento de LEDs RGB e um buzzer conforme as entradas fornecidas pelo teclado.

## Funcionalidades:

Leitura de teclas pressionadas no teclado matricial.

Controle individual dos LEDs RGB e do buzzer baseado nas teclas pressionadas.

Mapeamento de teclas para ações:

Tecla 1: Liga o LED vermelho.

Tecla 2: Liga o LED verde.

Tecla 3: Liga o LED azul.

Tecla 4: Desliga o LED vermelho.

Tecla 5: Desliga o LED verde.

Tecla 6: Desliga o LED azul.

Tecla 7: Liga o LED vermelho por 500 ms.

Tecla 8: Liga o LED verde por 500 ms.

Tecla 9: Liga o LED azul por 500 ms.

Tecla 0: Alterna o estado de todos os LEDs.

## Requisitos:

Microcontrolador Raspberry Pi Pico W.

Simulador Wokwi.

Ambiente de desenvolvimento configurado com Pico SDK.

## Execução:

Compile e carregue o código no simulador Wokwi.

Pressione as teclas no teclado matricial para acionar os LEDs.
