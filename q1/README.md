# DroneGuard – Sistema Inteligente de Prevenção de Desastres Naturais 🚁

## 📜 Descrição
O **DroneGuard** é um sistema IoT que utiliza drones equipados com sensores e inteligência artificial para monitorar e prever desastres naturais, como enchentes, deslizamentos e outros riscos ambientais.

## 🚁 Funcionalidades do Drone
1. Monitoramento em tempo real de áreas de risco (encostas, rios e zonas costeiras).
2. Coleta de dados climáticos e ambientais:
   - Chuva
   - Vento
   - Temperatura
   - Umidade
   - Inclinação do solo
3. Reconhecimento visual com câmeras e sensores para detectar:
   - Rachaduras no solo
   - Acúmulo de água
   - Sinais de deslizamento
   - Início de enchentes
4. Envio automático de alertas para Defesa Civil ou órgãos competentes.
5. Mapeamento 3D da região para auxiliar planos de evacuação.

## 🧠 Tecnologias Envolvidas
- Microcontrolador (ESP32 ou equivalente)
- Sensores (DHT22, BMP280, Sensor de inclinação)
- Broker MQTT
- Node-RED para visualização dos dados
- Python para simulação de sensores
- Banco de dados (opcional)
- Inteligência Artificial para análise preditiva (futuro)

## 🎯 Objetivo
Reduzir perdas humanas e materiais através da prevenção ativa, utilizando tecnologia para detectar riscos antes que eles ocorram.

## ⚙️ Componentes do Projeto
- **Microcontrolador:** ESP32
- **Broker MQTT:** Mosquitto (local ou online)
- **Node-RED:** Painel de controle e monitoramento
- **Simulador Python:** Para testes

## 🔧 Requisitos
- Python 3.x
- PlatformIO ou Arduino IDE
- Node-RED instalado
- Broker MQTT (Mosquitto)

## 🚀 Como Executar
1. Execute o código do microcontrolador (`src/droneguard.ino`).
2. Ou execute o simulador Python (`src/main.py`) para testes.
3. Importe o fluxo do Node-RED (`node-red/diagram.json`).
4. Visualize os dados e receba alertas no painel do Node-RED.

## 🧪 Extras
- Energia solar (opcional)
- Funciona em regiões de difícil acesso
- Aplicativo web ou mobile pode ser integrado para alertas

---

Desenvolvido para a disciplina **Global Solution - 2025**.
