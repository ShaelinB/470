int xPin = A0;  // X-axis along handle (toward you)

bool flipped = false;  // tracks whether a flip has occurred

int flipThreshold = 800;    // X rises above this → flip detected
int resetThreshold = 750;   // X drops below this → reset for next flip

unsigned long lastFlipTime = 0;  // Timestamp of last flip
unsigned long flipCooldown = 500; // 500 ms cooldown

void setup() {
  Serial.begin(9600);  // Open serial communication
}

void loop() {
  int xVal = analogRead(xPin);  // raw X value
  unsigned long currentTime = millis();

  // Detect flip with cooldown
  if (xVal > flipThreshold && !flipped && (currentTime - lastFlipTime > flipCooldown)) {
    flipped = true; // flip detected
    lastFlipTime = currentTime;
  }

  // Reset when X drops below resetThreshold
  if (xVal < resetThreshold && flipped) {
    flipped = false; // reset
  }

  // Send flipped as 0/1 + raw X value to Unity
  Serial.print(flipped);
  Serial.print(",");
  Serial.println(xVal);

  delay(50);
}
