# Atividade 1: Temporizador Periódico - Semáforo com Raspberry Pi Pico W

## Descrição
Esta atividade utiliza o microcontrolador **Raspberry Pi Pico W** para simular um semáforo controlado por LEDs (vermelho, amarelo e verde) com um temporizador periódico de 3 segundos. O sistema é implementado com o uso da função `add_repeating_timer_ms()` presente no **Pico SDK**, permitindo o controle dos LEDs de acordo com um ciclo de sinal de trânsito.

## Funcionalidades Principais
- O semáforo alterna entre vermelho, amarelo e verde.
- O temporizador é configurado para disparar a cada 3 segundos (3000 ms), alternando os estados.
- A cada 1 segundo, uma mensagem de status é impressa no terminal, indicando o estado atual do semáforo.

## Fluxo de Funcionamento
- O semáforo inicia com o **LED vermelho** aceso.
- Após 3 segundos, o **LED amarelo** é aceso.
- Após mais 3 segundos, o **LED verde** é aceso.
- O ciclo se repete continuamente.

## Componentes Utilizados
- **Raspberry Pi Pico W**.
- **3 LEDs (vermelho, amarelo, verde)** para o semáforo.
- **Resistores de 330 Ω** para cada LED.

## Tecnologias de Software Utilizadas
- Linguagem: **C**.
- Ferramentas: **Pico SDK**, **Visual Studio Code**.
- Simulação: **Wokwi**.

## Como Executar
1. **Configuração do Código**:
   - Compile o código no **Raspberry Pi Pico W** utilizando o **Pico SDK** e o arquivo **CMakeLists**.
   - Carregue o código no Raspberry Pi Pico.

2. **Execução**:
   - Quando o código for carregado, o semáforo começará a funcionar, alternando entre as cores vermelha, amarela e verde a cada 3 segundos.
   - A cada segundo, uma mensagem de status será exibida no terminal serial, indicando o estado atual do semáforo.

3. **Simulação no Wokwi**:
   - Você pode simular o projeto no [Wokwi](https://wokwi.com/), utilizando o LED RGB nas GPIOs 11, 12 e 13. Ou, como requisitado nesta tarefa, utilizar o Wokwi integrado ao ambiente de desenvolvimento VS Code.

## Funções do Código
- **Função `init()`**: Inicializa as GPIOs para os LEDs.
- **Função `repeating_timer_callback()`**: Controla a alternância dos estados do semáforo a cada 3 segundos.
- **Função `main()`**: Inicia o semáforo e imprime mensagens de status a cada 1 segundo.
