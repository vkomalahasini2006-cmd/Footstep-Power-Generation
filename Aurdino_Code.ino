// Footstep Power Generation Project
// By Komala Hasini 

const int piezoPin = A0;     // Analog input from piezo sensor
const int ledPin = 13;       // LED to indicate power generation
float voltage = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Footstep Power Generation System Initialized...");
}

void loop() {
  int sensorValue = analogRead(piezoPin);       // Read raw analog value
  voltage = sensorValue * (5.0 / 1023.0);       // Convert to voltage (0–5V scale)

  Serial.print("Generated Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  if (voltage > 1.5) {    // Adjust threshold as per sensor output
    digitalWrite(ledPin, HIGH);
    Serial.println("⚡ Energy Generated!");
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}
