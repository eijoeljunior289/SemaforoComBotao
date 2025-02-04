# Sistema de Temporização com Botão

Este projeto implementa um sistema onde, ao pressionar um botão, três LEDs são acionados em sequência, com um atraso de 3 segundos entre cada mudança de estado. O botão só pode ser pressionado novamente após o último LED ser desligado.

## Componentes Necessários
- Raspberry Pi Pico W
- 1 LED Azul
- 1 LED Vermelho
- 1 LED Verde
- 3 Resistores de 330 Ω
- 1 Botão (Pushbutton)
- Protoboard e jumpers

## Conexões
| Componente | GPIO do Pico |
|------------|--------------|
| LED Azul   | GPIO 12      |
| LED Vermelho | GPIO 13     |
| LED Verde  | GPIO 14      |
| Botão      | GPIO 15      |
| Resistores | Conectados em série com cada LED |

## Funcionamento
1. Ao pressionar o botão, todos os LEDs são acionados (nível alto).
2. Após 3 segundos, dois LEDs são desligados.
3. Após mais 3 segundos, apenas um LED permanece aceso.
4. Após mais 3 segundos, todos os LEDs são desligados.
5. O botão só pode ser pressionado novamente quando todos os LEDs estiverem desligados.

## Como Executar
1. Conecte os componentes conforme a tabela acima.
2. Compile e carregue o código no Raspberry Pi Pico W.
3. Pressione o botão para iniciar a sequência de acionamento dos LEDs.

## Código
O código está disponível no arquivo `main.c`.

## Simulação no Wokwi
- Utilize o simulador Wokwi para testar o circuito antes de montá-lo fisicamente.
- Configure os GPIOs e componentes conforme descrito acima.

## Autor
Joel Júnior Nunes Araujo
