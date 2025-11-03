int readData = -1;
long mappedData = 0;

void setup() {
  // initialize serial communication
  Serial.begin(9600);

  pinMode(7, OUTPUT);

  digitalWrite(7, HIGH);
}

void loop() {
  // read the value of A0 (the twisty knob)
  readData = analogRead(A0);

  //map it
  mappedData = map(readData, 0, 1023, -100, 100);

  //Unity Read as a string?
  //String for Unity

  Serial.print("Hi");
  Serial.print(",");
  Serial.print(readData);
  Serial.print(",");
  Serial.print(mappedData);
  Serial.println();

  if (Serial.available()) {
    int data = Serial.read();

    if (data == '1') {
      digitalWrite(7, HIGH);
    } else {
      digitalWrite(7, LOW);
    }
  }

  delay(100);
}