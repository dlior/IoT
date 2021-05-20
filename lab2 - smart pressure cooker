## smart pressure cooker -- indications through rgb light and piezo buzzer
## this lab was done only in simulation in tinkercad on arduino

int sensorPin = A0;
int buzzerPin = A1;

int redPin= 3;
int greenPin = 5;
int bluePin = 6;

float val = 0;
float m = 10.0;
float v1 = 100.0;
float T1 = -40.0;
float prevT = -40.0;

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void playBuzzer(int state) {
  if (state == 1) {
    for (int i = 0; i < 3; i++) {
      tone(buzzerPin, 400, 400);
      delay(1000);
    }
  } 
  else if (state == 2) {
    tone(buzzerPin, 400, 400);
    delay(2000);
  }
  else {
    tone(buzzerPin, 700, 400);
    delay(1000);
  }
}
    
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  val = analogRead(sensorPin);
  float volt = val * 5.0 / 1024.0 * 1000.0;
  float T = T1 + 1.0 / m * (volt - v1);
  Serial.print(String(T) + char(176) + String("C"));
  Serial.print(String(" | "));
  Serial.println(String(volt) + String("V"));
  
  if (T < 0.0) setColor(0, 0, 0);
  else if (T >= 0.0 && T <= 20.0) setColor(43, 211, 102);
  else if (T >= 21.0 && T <= 60.0) setColor(0, 132, 196);
  else if (T >= 61.0 && T <= 99.0) setColor(246, 203, 56);
  else if (T >= 100.0 && T <= 110.0) {
    setColor(255, 69, 0);
    if (prevT < 100.0) playBuzzer(1);
  }
  else if (T >= 111.0 && T <= 120.0) {
    setColor(132, 59, 183);
	playBuzzer(2);
    return;
  }
  else if (T >= 121.0) {
    setColor(236, 28, 23);
    playBuzzer(3);
    return;
  }
  
  delay(1000);
  prevT = T;
}
