import paho.mqtt.client as mqtt
import json
import random
import time

broker = 'test.mosquitto.org'
port = 1883
topic = "droneguard/sensores"

client_id = f'droneguard-simulator-{random.randint(0, 1000)}'
client = mqtt.Client(client_id=client_id)

def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("✅ Conectado ao MQTT Broker!")
        else:
            print(f"❌ Falha na conexão, código {rc}")

    client.on_connect = on_connect
    client.connect(broker, port)
    return client

def publish(client):
    while True:
        data = {
            "temperatura": round(random.uniform(20.0, 35.0), 2),
            "umidade": round(random.uniform(40.0, 80.0), 2),
            "pressao": round(random.uniform(950.0, 1050.0), 2),
            "altitude": round(random.uniform(10.0, 50.0), 2),
            "inclinacao": round(random.uniform(0.0, 30.0), 2)
        }
        msg = json.dumps(data)
        result = client.publish(topic, msg)
        status = result[0]
        if status == 0:
            print(f"📤 Enviado `{msg}` para o tópico `{topic}`")
        else:
            print(f"⚠️ Falha ao enviar mensagem para o tópico {topic}")
        time.sleep(5)

if __name__ == '__main__':
    client = connect_mqtt()
    client.loop_start()
    publish(client)
