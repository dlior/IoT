## traffic light for cars and pedestrians. 

int car_red_led = 0;
int car_yellow_led = 1;
int car_green_led = 2;

int ped_red_led = 9;
int ped_green_led = 10;


void setup()
{
  pinMode(car_red_led, OUTPUT);
  pinMode(car_yellow_led, OUTPUT);
  pinMode(car_green_led, OUTPUT);
  
  pinMode(ped_red_led, OUTPUT);
  pinMode(ped_green_led, OUTPUT);
}

void loop()
{
  digitalWrite(car_green_led, HIGH);
  digitalWrite(ped_red_led, HIGH);
  delay(1000);
  
  digitalWrite(ped_red_led, LOW);
  digitalWrite(ped_green_led, HIGH);
  delay(4000);
  
  digitalWrite(ped_green_led, LOW);
  digitalWrite(ped_red_led, HIGH);
  delay(1000);
  
  digitalWrite(car_green_led, LOW);
  digitalWrite(car_yellow_led, HIGH);
  delay(1500);
  
  digitalWrite(car_yellow_led, LOW);
  digitalWrite(car_red_led, HIGH);
  delay(5000);
  
  digitalWrite(car_yellow_led, HIGH);
  delay(1000);
  
  digitalWrite(car_red_led, LOW);
  digitalWrite(car_yellow_led, LOW);
}
