void setup() {
  Serial.begin(9600);
  for(int i=2; i<=6; i++)
    pinMode(i ,INPUT_PULLUP);

  for(int i=8; i<=11; i++)
    pinMode(i ,OUTPUT);

  

}

int counter = 0;
int LedSort[] = {};
void loop() {
  if(digitalRead(2) == 0){
    LedSort[counter] = 8; counter ++;
    digitalWrite(8, 1);
    delay(300);}
  else {digitalWrite(8, 0);}

  if(digitalRead(3) == 0){
    LedSort[counter] = 9; counter ++;
    digitalWrite(9, 1);
    delay(300);}
  else{digitalWrite(9, 0);}
  
  if(digitalRead(4) == 0){
    LedSort[counter] = 10; counter ++;
    digitalWrite(10, 1);
    delay(300);}
  else{digitalWrite(10, 0);}

  if(digitalRead(5) == 0){
    LedSort[counter] = 11; counter ++;
    digitalWrite(11, 1);
    delay(300);}

  else{digitalWrite(11, 0);}

  
  if(digitalRead(6) == 0){
    Serial.println(counter);
    for(int i=0; i<=counter; i++){
      digitalWrite(LedSort[i], 1); delay(500);
      digitalWrite(LedSort[i], 0); delay(500);
    }
  }
}

void ControlButton(){
  if(digitalRead(2) == 0){
    Serial.println("A");
  }
  if(digitalRead(3) == 0){
    Serial.println("B");
  }
  if(digitalRead(4) == 0){
    Serial.println("C");
  }
  if(digitalRead(5) == 0){
    Serial.println("D");
  }
  if(digitalRead(6) == 0){
    Serial.println("U");
  }
}
