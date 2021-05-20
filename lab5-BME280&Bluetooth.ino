## working with bme280 an bluetooth

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
#include "BluetoothSerial.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
unsigned long delayTime;

BluetoothSerial SerialBT;

int sensorPin = 34;
float val = 0;
float m = 10.0;
float v1 = 100.0;

double ReadVoltage(byte pin) // simple temp sensor voltage convert
{
  double reading = analogRead(pin); // Reference voltage is 3v3 so maximum reading is 3v3 = 4095 in range 0 to 4095   
  if (reading < 1 || reading > 4095) return 0;   
  return -0.000000000000016 * pow(reading, 4) + 0.000000000118171 * pow(reading, 3) - 0.000000301211691 * pow(reading, 2) + 0.001109019271794 * reading + 0.034143524634089; 
}


void setup() 
{
  pinMode(sensorPin, OUTPUT);
  Serial.begin(9600);

  Serial.begin(9600);
  SerialBT.begin("Lior_Zeev_temp_BT"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth! Device's name is Zeev_Lior");
    
  Serial.begin(9600);
  while(!Serial);    // time to get serial running
  Serial.println(F("BME280 test"));
  unsigned status;
  status = bme.begin(0x76); 

  if (!status) 
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
    Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }
  Serial.println("-- Default Test --");
  delayTime = 1000;
  Serial.println();
}

void loop() 
{
  if (Serial.available())
  {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available())
  {
    Serial.write(SerialBT.read());
  }

  double res = ReadVoltage(sensorPin);
  float volt = res * 5.0 / 1024.0 * 1000.0;
  float T = 40.0 + 1.0 / m * (volt - v1); 
  printValues(T);
  //delay(delayTime);
  
  //Serial.print("avg: ");Serial.print(avg_T / counter);Serial.print(" ");
  //Serial.print("T: ");Serial.print(T);Serial.println(" ");
  delay(1000);
}


void printValues(float T) 
{
  Serial.print("BME Serial: ");Serial.print(bme.readTemperature());Serial.print(" ");
  //Serial.print("Temperature : ");
  //Serial.println(bme.readTemperature());

  Serial.print("Regular Serial: ");Serial.print(T);Serial.println(" ");
  //Serial.println(T);

  SerialBT.print("BME BT: ");SerialBT.print(bme.readTemperature());SerialBT.print(" ");
  SerialBT.print("Regular BT: ");SerialBT.print(T);SerialBT.println(" ");
  
  //SerialBT.print("Temperature = ");
  //SerialBT.print(bme.readTemperature());
  //SerialBT.println(" °C");

  //SerialBT.print("Pressure = ");

  //SerialBT.print(bme.readPressure() / 100.0F);
  //SerialBT.println(" hPa");

  //SerialBT.print("Approx. Altitude = ");
  //SerialBT.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  //SerialBT.println(" m");

  //SerialBT.print("Humidity = ");
  //SerialBT.print(bme.readHumidity());
  //SerialBT.println(" %");

  //SerialBT.println();
}
