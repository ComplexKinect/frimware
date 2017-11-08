#include <Wire.h>
int x = 0;
byte data;
int val;

void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  /*
  x++; // Increment x
  if (x > 5) x = 0; // `reset x once it gets 6
  delay(500);
  */
  // Read Serial Data
  if(Serial.available() > 0) {
    data = Serial.read();
    val = int(data);
  }

  // Decide which node to trigger
  if(val == 1) {
    Wire.beginTransmission(9);
    x = 1;
    Wire.write(x);
    Wire.endTransmission();
  } else if(val == 2) {
    Wire.beginTransmission(9);
    x = 2;
    Wire.write(x);
    Wire.endTransmission();
  } else if(val == 3) {
    Wire.beginTransmission(9);
    x = 3;
    Wire.write(x);
    Wire.endTransmission();
  }
}