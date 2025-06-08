# SmartDrone – Sistema Inteligente de Prevenção de Desastres Naturais

## 🛰️ Descrição da Solução

O **SmartDrone** é um sistema IoT que utiliza drones equipados com sensores e inteligência artificial para monitorar e prever desastres naturais, como enchentes, deslizamentos e outros riscos ambientais. A solução visa fornecer dados em tempo real para auxiliar órgãos de Defesa Civil na tomada de decisões rápidas e eficazes.

## ⚙️ Funcionalidades do Drone

- Monitoramento em tempo real de áreas de risco (encostas, rios e zonas costeiras).
- Coleta de dados climáticos e ambientais:
  - Chuva
  - Vento
  - Temperatura
  - Umidade
  - Inclinação do solo
- Reconhecimento visual com câmeras e sensores para detectar:
  - Rachaduras no solo
  - Acúmulo de água
  - Sinais de deslizamento
  - Início de enchentes
- Envio automático de alertas para Defesa Civil ou órgãos competentes.

---

## 🧰 Requisitos

### Hardware

- Microcontrolador compatível com PlatformIO (ex: ESP32)
- Sensores ambientais (chuva, vento, temperatura, umidade)
- Sensor de inclinação
- Módulo de câmera (opcional)
- Módulo de comunicação (ex: Wi-Fi, LoRa)

> ⚠️ **Importante:** até o momento, **os testes foram realizados apenas virtualmente**, utilizando o simulador **Wokwi** via extensão no VSCode. **Nenhum teste foi realizado com hardware físico.**

### Software

- [PlatformIO](https://platformio.org/) instalado no VSCode
- Python 3.x
- Bibliotecas especificadas no `platformio.ini`

---

## 🚀 Configuração e Execução

1. **Clonar o repositório**:

   ```bash
   git clone https://github.com/GMGrizao/GS-IOT.git
   cd GS-IOT
   ```

2. **Abrir o projeto no VSCode com PlatformIO**:
   - Instale a extensão PlatformIO IDE no VSCode (caso ainda não tenha).
   - Abra a pasta do projeto clonada no VSCode.

3. **Selecionar a placa correta**:
   - Verifique o arquivo `platformio.ini` e edite conforme a sua placa.
   - Exemplo para ESP32:

     ```ini
     [env:esp32dev]
     platform = espressif32
     board = esp32dev
     framework = arduino
     ```

4. **Conectar o microcontrolador ao computador via USB.**

5. **Compilar e carregar o firmware**:
   - No VSCode, abra o menu do PlatformIO na barra lateral.
   - Clique em **Upload** para compilar e enviar o código para o dispositivo.
   - Ou use o atalho:
     ```
     Ctrl + Alt + U
     ```

6. **Monitorar a saída serial**:
   - Clique em **Monitor Serial** no PlatformIO ou use o atalho:
     ```
     Ctrl + Alt + M
     ```
   - Os dados dos sensores aparecerão no console serial.

---

## 📊 Visualização dos Dados

Você pode acompanhar os dados enviados pelo drone em tempo real usando o Node-RED:

- **Editor de Fluxo (Node-RED)**: [http://172.208.54.189:1880](http://172.208.54.189:1880)
- **Dashboard com Gráficos e Indicadores**: [http://172.208.54.189:1880/ui](http://172.208.54.189:1880/ui)

---

## 🧪 Testes da Aplicação

1. **Ambiente de Teste Virtual (Wokwi)**:
   - O sistema está sendo testado via **simulador Wokwi** diretamente integrado ao VSCode.
   - Nenhum teste foi realizado em hardware físico até o momento.

2. **Verificar leitura dos sensores**:
   - Após a execução, veja os dados recebidos no monitor serial.
   - Cheque se os valores de temperatura, umidade, inclinação etc. fazem sentido.

3. **Simular condições de risco**:
   - Use os controles do Wokwi para simular chuva, calor, inclinação e verifique as respostas do sistema.

4. **Testar alertas (se implementado)**:
   - Caso o código esteja configurado para enviar alertas (ex: via Wi-Fi), valide se os dados chegam no destino (API, banco, dashboard, etc.).

---

## 📄 Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 👨‍💻 Time
- **Caio Cesar Rosa Nyimi** RM556331 - 2TDSPX
- **Guilherme Menezes Grizão** RM557958 - 2TDSPX
- **Pietro Saccarrão Cougo** RM555839 - 2TDSPY

Desenvolvido para a disciplina **IOT - Global Solution - 2025**.
