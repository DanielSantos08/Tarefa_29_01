# Tarefa - Clock e Temporizadores

Este repositório contém a implementação de duas atividades relacionadas ao uso de temporizadores e LEDs com o microcontrolador Raspberry Pi Pico W, utilizando o Pico SDK e o simulador Wokwi.

## Atividade 1: Temporizador Periódico (Semáforo)

### Descrição
Nesta atividade, foi projetado um semáforo com temporização de 3 segundos para cada alteração de sinal, utilizando a função `add_repeating_timer_ms()` do Pico SDK. O semáforo alterna entre três estados (vermelho, amarelo e verde) conforme o fluxo de tráfego.

### Componentes Utilizados
- Microcontrolador Raspberry Pi Pico W.
- 03 LEDs (vermelho, amarelo e verde).
- 03 Resistores de 330 Ω.

### Funcionamento
- O semáforo inicia com o LED vermelho aceso.
- Após 3 segundos, o LED amarelo é aceso.
- Após mais 3 segundos, o LED verde é aceso.
- O ciclo se repete indefinidamente.

### Requisitos
1. O acionamento dos LEDs deve iniciar com o LED vermelho aceso, em seguida, alternando para o LED amarelo e, finalmente, para o LED verde.
2. O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms).
3. A mudança de estado dos LEDs deve ser implementada na função de callback do temporizador (como a função `repeating_timer_callback()`).
4. A rotina principal deve imprimir uma mensagem a cada 1 segundo (1.000 ms) pela porta serial.
5. O experimento foi realizado utilizando o LED RGB nas GPIOs 11, 12 e 13.

### Como Executar

## Como Utilizar o Wokwi

### Usando o Wokwi no VS Code

1. **Instalar a Extensão do Raspberry Pi Pico no VS Code:**
   - Abra o Visual Studio Code.
   - Vá para a aba de extensões (ícone de quadrado no menu lateral).
   - Pesquise por **"Raspberry Pi Pico"**.
   - Clique em **"Instalar"** na extensão correspondente (desenvolvida pela "Wokwi").

2. **Instalar o Compilador GCC:**
   - Para compilar o código, você precisará ter o **GCC** instalado no seu computador.
   - Siga as instruções de instalação do [Pico SDK](https://www.raspberrypi.org/documentation/pico/getting-started/) para configurar o ambiente corretamente.

3. **Configurar o Ambiente de Desenvolvimento:**
   - No VS Code, configure o **path do Pico SDK** para garantir que ele seja reconhecido corretamente.

4. **Compilar o Código:**
   - Com o código aberto no VS Code, pressione `Ctrl + Shift + B` para compilar o código.
   - O código será compilado utilizando o compilador GCC e o Pico SDK.

5. **Executar a Simulação no Wokwi:**
   - Abra o Wokwi no VS Code e inicie o simulador.
   - Carregue o arquivo `diagram.json` e inicie a simulação.
   - Observe o comportamento do código no simulador.

### Usando o Wokwi Online

1. **Acessar o Wokwi:**
   - Abra [Wokwi.com](https://wokwi.com).
   - Carregue o arquivo `diagram.json` e o Código da aplicação, veja a simulação.
   - A simulação será executada diretamente no navegador, sem necessidade de configuração de compilação.

---

## Atividade 2: Temporizador de um Disparo (One Shot)

### Descrição
Nesta atividade, foi projetado um sistema de temporização para o acionamento de LEDs, que é ativado pelo clique em um botão (pushbutton), utilizando a função `add_alarm_in_ms()` do Pico SDK. A mudança de estado dos LEDs ocorre a cada 3 segundos, com uma sequência de 3 LEDs acesos, 2 LEDs acesos e, finalmente, 1 LED aceso.

### Componentes Utilizados
- Microcontrolador Raspberry Pi Pico W.
- 03 LEDs (azul, vermelho e verde).
- 03 Resistores de 330 Ω.
- 01 Botão (Pushbutton).

### Funcionamento
- Ao pressionar o botão, todos os LEDs são acesos.
- Após 3 segundos, dois LEDs permanecem acesos.
- Após mais 3 segundos, apenas um LED permanece aceso.
- Após mais 3 segundos, todos os LEDs são apagados.
- O botão só pode alterar o estado dos LEDs após o último LED ser apagado.

### Requisitos
1. O temporizador do alarme deve ser ajustado para um atraso de 3 segundos (3.000ms) entre as mudanças de estado dos LEDs.
2. A mudança de estado dos LEDs deve ser implementada em funções de callback do temporizador (como a função `turn_off_callback()`).
3. O botão só pode alterar o estado dos LEDs quando o último LED for desligado.
4. O experimento foi realizado utilizando o LED RGB nas GPIOs 11, 12 e 13 e o botão A na GPIO 5.
5. **Opcional:** Implementação de uma rotina de software para atenuação do efeito de bouncing no botão (software debounce).

### Como Executar

## Como Utilizar o Wokwi

### Usando o Wokwi no VS Code

1. **Instalar a Extensão do Raspberry Pi Pico no VS Code:**
   - Abra o Visual Studio Code.
   - Vá para a aba de extensões (ícone de quadrado no menu lateral).
   - Pesquise por **"Raspberry Pi Pico"**.
   - Clique em **"Instalar"** na extensão correspondente (desenvolvida pela "Wokwi").

2. **Instalar o Compilador GCC:**
   - Para compilar o código, você precisará ter o **GCC** instalado no seu computador.
   - Siga as instruções de instalação do [Pico SDK](https://www.raspberrypi.org/documentation/pico/getting-started/) para configurar o ambiente corretamente.

3. **Configurar o Ambiente de Desenvolvimento:**
   - No VS Code, configure o **path do Pico SDK** para garantir que ele seja reconhecido corretamente.

4. **Compilar o Código:**
   - Com o código aberto no VS Code, pressione `Ctrl + Shift + B` para compilar o código.
   - O código será compilado utilizando o compilador GCC e o Pico SDK.

5. **Executar a Simulação no Wokwi:**
   - Abra o Wokwi no VS Code e inicie o simulador.
   - Carregue o arquivo `diagram.json` e inicie a simulação.
   - Observe o comportamento do código no simulador.

### Usando o Wokwi Online

1. **Acessar o Wokwi:**
   - Abra [Wokwi.com](https://wokwi.com).
   - Carregue o arquivo `diagram.json` e o Código da aplicação, veja a simulação.
   - A simulação será executada diretamente no navegador, sem necessidade de configuração de compilação.

---

## Requisitos

- **Ambiente de desenvolvimento:** VS Code.
- **Kit de Desenvolvimento de Software:** Pico SDK.
- **Simulador:** Wokwi integrado ao VS Code ou versão online.
- **Linguagem de programação:** C.
- **GitHub:** Repositório para versionamento, registro e submissão da atividade.
