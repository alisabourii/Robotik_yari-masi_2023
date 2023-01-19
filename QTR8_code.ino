#include <QTRSensors.h>
 
#define NUM_SENSORS 8
#define NUM_SAMPLES_PER_SENSOR 4
#define EMITTER_PIN 2
 
QTRSensorsAnalog qtra((unsigned char[]) {0, 1, 2, 3, 4, 5, 6, 7},
NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
 
void setup()
{
Serial.begin(9600);
delay(500);
int i;
pinMode(13, OUTPUT);
digitalWrite(13, HIGH);
for (i = 0; i < 400; i++)
{
qtra.calibrate();
}
digitalWrite(13, LOW);
for (i = 0; i < NUM_SENSORS; i++)
{
Serial.print(qtra.calibratedMinimumOn[i]);
Serial.print(' ');
}
Serial.println();
for (i = 0; i < NUM_SENSORS; i++)
{
Serial.print(qtra.calibratedMaximumOn[i]);
Serial.print(' ');
}
Serial.println();
Serial.println();
delay(1000);
}
 
void loop()
{
unsigned int position = qtra.readLine(sensorValues);
 
unsigned char i;
for (i = 0; i < NUM_SENSORS; i++)
{
Serial.print(sensorValues[i] * 10 / 1001);
Serial.print(' ');
}
Serial.print(" ");
Serial.println(position);
 
delay(250);
}