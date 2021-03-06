## photoresistor, simulating fridge light

int ledPin = 6;
int sensorPin = A0;

double ReadVoltage(byte pin) {
  double reading = analogRead(pin); // Reference voltage is 3v3 so maximum reading is 3v3 = 4095 in range 0 to 4095
  if (reading < 1 || reading > 4095) return 0;
  return -0.000000000000016 * pow(reading, 4) + 0.000000000118171 * pow(reading, 3) - 0.000000301211691 * pow(reading, 2) + 0.001109019271794 * reading + 0.034143524634089;
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  double value = ReadVoltage(sensorPin);
  Serial.println(value);
  if (value > 0.05) {
    digitalWrite(ledPin, HIGH);
  }
  else digitalWrite(ledPin, LOW);
  delay(100); // Wait for 1000 millisecond(s)
}
