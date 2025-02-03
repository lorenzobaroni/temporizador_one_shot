# Temporizador One-Shot com Raspberry Pi Pico W

## 📌 Descrição do Projeto
Este projeto implementa um sistema utilizando um **temporizador de um disparo (One-Shot Timer)** no **Raspberry Pi Pico W**. O sistema possui **três LEDs** (vermelho, verde e azul) e um **botão de disparo**. Quando o botão é pressionado, os LEDs são acesos sequencialmente, cada um permanecendo aceso por **3 segundos** antes de apagar.

## 🔗 Link do Vídeo Ensaio

[Demonstração de Funcionamento do Projeto](https://www.youtube.com/watch?v=8YaI7uup6ns&ab_channel=LorenzoGiuseppeOliveiraBaroni)

## Estrutura do Projeto
### Componentes Utilizados:
- **Microcontrolador:** Raspberry Pi Pico W / BitDogLab
- **LEDs:** Vermelho, Verde e Azul
- **Resistores:** 330Ω para cada LED
- **Botão:** Interruptor de pulso
- **Linguagem:** C/C++
- **Ferramentas:** SDK do Raspberry Pi Pico W, CMake, VS Code

## Esquema de Ligacao
A estrutura física do circuito é baseada na seguinte distribuição:

| Componente | Pino no Pico |
|------------|--------------|
| LED Azul | GPIO 10 |
| LED Vermelho | GPIO 11 |
| LED Verde | GPIO 12 |
| Botão | GPIO 5 |

O circuito foi projetado conforme a imagem de referência.

## Como Funciona
1. **Pressionamento do botão**:
   - Todos os LEDs são ligados simultaneamente.
   - Um temporizador de 3 segundos é ativado para desligar cada LED na sequência correta.

2. **Sequência de desligamento**:
   - O LED Azul desliga após 3 segundos.
   - O LED Vermelho desliga após 6 segundos.
   - O LED Verde desliga após 9 segundos e libera a possibilidade de pressionar o botão novamente.

## Como Executar o Projeto
### 1. Configuração do Ambiente
Certifique-se de ter o **SDK do Raspberry Pi Pico W** instalado. No VS Code:
1. Clone este repositório:
   ```bash
   git clone https://github.com/lorenzobaroni/temporizador_one_shot
   ```
2. Abra o projeto no VS Code.

3. Compile o código

4. Clique no arquivo diagram.json e teste o projeto no simulador do WOKWI Integrado no VS Code

5. Envie o binário para a placa:
   - Conecte o **Raspberry Pi Pico W** enquanto segura o **BOOTSEL**.
   - Copie o arquivo `.uf2` gerado para a unidade USB montada.

## Licença

Este programa foi desenvolvido como um exemplo educacional e pode ser usado livremente para fins de estudo e aprendizado.

## Autor

- LORENZO GIUSEPPE OLIVEIRA BARONI

