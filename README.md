# Controle de GPIO com Teclado Matricial - RP2040

![Image](https://github.com/user-attachments/assets/0fa0812b-6e31-411f-875e-13a1661fc317)


---

## Vídeo Demonstrativo
Confira o funcionamento do projeto no vídeo [aqui](https://github.com/user-attachments/assets/320c4c2b-1179-4c3c-92c5-a69f94e57b3c).

---

## Descrição do Projeto
Este projeto tem como objetivo controlar pinos GPIO utilizando um teclado matricial 4x4, integrado ao microcontrolador RP2040 presente na placa Raspberry Pi Pico W. Os componentes controlados incluem 3 LEDs RGB e um buzzer, simulando um sistema de acionamento básico para fins de aprendizado e prototipagem em sistemas embarcados.

## Funcionalidades
- Controle individual de LEDs RGB (alteração de cores e estado on/off).
- Ativação e desativação de um buzzer para gerar sinal sonoro.
- Mapeamento de teclas do teclado matricial 4x4 para realizar as ações correspondentes.
- Simulação completa no ambiente Wokwi, dispensando hardware físico.

## Requisitos do Sistema
1. **Hardware Necessário:**
   - Placa de desenvolvimento Raspberry Pi Pico W.
   - Simulador Wokwi para testes.
   - Teclado matricial 4x4 (simulado no Wokwi).
   - LEDs RGB (3 unidades).
   - Buzzer.

2. **Software e Ferramentas:**
   - Ambiente de desenvolvimento VS Code.
   - Pico SDK configurado para o RP2040.
   - Git para versionamento de código.

## Configuração do Ambiente
1. Clone este repositório:
   ```bash
   git clone https://github.com/embarcatech-grupo3-subgrupo5/U4-T1-gpio-keypad-control.git
   ```
2. Configure o Pico SDK no seu ambiente de desenvolvimento.
3. Abra o projeto no VS Code e compile os arquivos.
4. Execute a simulação no Wokwi, seguindo o arquivo de configuração fornecido no repositório.

## Histórico de Contribuições
### **Equipe e Funções:**

1. **Emylle:**
   - Definição e inicialização dos pinos dos LEDs RGB.
   - Desenvolvimento das funções para controle dos LEDs no código principal.
   - Colaboração na implementação da função principal.

2. **Mario Vinicius:**
   - Definição e inicialização do pino do buzzer.
   - Desenvolvimento de funções para ativar o buzzer e emissão de som simples.

3. **Geison:**
   - Definição dos pinos do teclado matricial.
   - Desenvolvimento das funções de inicialização e leitura do teclado matricial.
   - Implementação das funções de controle do buzzer passivo com diferentes frequências e padrões.
   - Colaboração na função principal e mapeamento das teclas para ações específicas.

4. **Julierme:**
   - Implementação de funções adicionais para controle do buzzer (beeps curtos, longos e pulsos).
   - Revisões e ajustes relacionados ao funcionamento do buzzer.

5. **Gabriella:**
   - Colaboração no mapeamento das teclas do teclado matricial para as ações no sistema.
   - Revisão e validação do código relacionado às ações mapeadas.

## Instruções de Uso
1. Inicialize o simulador Wokwi.
2. Utilize o teclado matricial para realizar as seguintes ações:
   - Acender e apagar os LEDs RGB.
   - Alterar a cor dos LEDs.
   - Ativar o sinal sonoro no buzzer.
3. Cada tecla do teclado está mapeada para uma função específica, como ilustrado no código fonte.

## Contribuindo
Se desejar contribuir com este projeto:
1. Faça um fork do repositório.
2. Crie um branch para sua funcionalidade:
   ```bash
   git checkout -b minha-funcionalidade
   ```
3. Faça commits claros e frequentes.
4. Envie um pull request para revisão.
