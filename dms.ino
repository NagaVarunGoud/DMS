int measurepin = A0;
int ledpower = 2;
int samplingtime = 280;
int deltatime = 40;
int sleeptime = 9680;
float vomeasured = 0;
float calcvoltage = 0;
float dustdensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledpower, OUTPUT);
}

void loop() {
  digitalWrite(ledpower, LOW);
  delayMicroseconds(samplingtime);
  vomeasured = analogRead(measurepin);
  delayMicroseconds(deltatime);
  digitalWrite(ledpower, HIGH);
  delayMicroseconds(sleeptime);
  calcvoltage = vomeasured * (5.0 / 1024.0);
  dustdensity = 170 * calcvoltage - 0.1;

  Serial.print("Dust Density: ");
  Serial.println(dustdensity);

  delay(1000); // Add delay to avoid flooding the serial monitor
}
