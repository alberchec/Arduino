#include <CapacitiveSensor.h>

CapacitiveSensor capSensor(7, 5);

// Limiar para ligar a lampada(quanto maior, mais difícil de ligar)
int threshold = 500;

const int led_pin = 8;
int led_state = false;


void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    led_state = !led_state;
  }

  if(led_state) digitalWrite(led_pin,HIGH);
  else          digitalWrite(led_pin,LOW);
  delay(300);
}
