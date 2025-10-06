/*
  Arduino Starter Kit example
  Project 15 - Hacking Buttons

  This sketch is written to accompany Project 15 in the Arduino Starter Kit

  Parts required:
  - battery powered component
  - 220 ohm resistor
  - 4N35 optocoupler

  created 18 Sep 2012
  by Scott Fitzgerald

  https://store.arduino.cc/genuino-starter-kit

  This example code is part of the public domain.
*/

const int optoPin = 2;  // the pin the optocoupler is connected to
const int sensorPin = A0;
int sensorVal;
float temperature;
bool fanState = 0;

void setup() {
  Serial.begin(9600);
  // make the pin with the optocoupler an output
  pinMode(optoPin, OUTPUT);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  temperature = ((sensorVal * 5 / 1024.0) - 0.5) * 100;
  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (temperature >= 25 && fanState == 0) {
    digitalWrite(optoPin, HIGH);  // pull pin 2 HIGH, activating the optocoupler

    delay(15);  // give the optocoupler a moment to activate

    digitalWrite(optoPin, LOW);  // pull pin 2 low until you're ready to activate again
    fanState = 1;                //the fan is on
    delay(10000);                // wait for 10 seconds
  } else if (temperature < 25 && fanState == 1) {
    digitalWrite(optoPin, HIGH);  // pull pin 2 HIGH, activating the optocoupler

    delay(15);  // give the optocoupler a moment to activate

    digitalWrite(optoPin, LOW);  // pull pin 2 low until you're ready to activate again
    fanState = 0;                //the fan is on
    delay(10000);                // wait for 10 seconds
  }
}
