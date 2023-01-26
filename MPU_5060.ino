
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  for(int i=4; i<=6; i++)
    pinMode(i, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 1000){
    
    int angelx = mpu6050.getAngleX();
    Serial.println(angelx);

    if(mpu6050.getAngleX() <= 110 && mpu6050.getAngleX() >= 80)
    {
      digitalWrite(4,1);
      digitalWrite(5,0);
      digitalWrite(6,0);
      }
    if(mpu6050.getAngleX() <= 10  && mpu6050.getAngleX() >= -20)
    {
      digitalWrite(4,0);
      digitalWrite(5,1);
      digitalWrite(6,0);
      }

      if(mpu6050.getAngleX() <= -75  && mpu6050.getAngleX() >= -110)
    {
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,1);
      }
    
    
    Serial.println("=======================================================\n");
    timer = millis();
    
  }

}
