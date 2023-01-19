 
const int in1 = 8;     // Motor sürücümüze bağladığımız pinleri tanımlıyoruz
const int in2 = 9;     
const int in3 =  10;
const int in4 =  11;
 
const int enA = 5;  //Enable pinlerini arduino 5,6 pwm pinlerine bağladık.
const int enB = 6;
 
void setup() 
 
{
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT);  
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
 
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
}
 
void loop() 
 
{
 // motor 1
analogWrite(enA,  255);   //1. motor 255 ile tam hızda dönüyor...
digitalWrite(in1, LOW);
digitalWrite(in2,  HIGH);  
 
 // motor 2
analogWrite(enB,  40);  //2. motor 40 ile yavaş dönüyor...
digitalWrite(in3, HIGH);
digitalWrite(in4,  LOW);
}