void degerokuma(){  
Serial.begin(9600);
         for(int i = 0; i < 8; i++){         
           Serial.print(i);   
           Serial.print("=");     
           Serial.print(sensordegeri[i]);  
           Serial.print("  "); 
            }
        Serial.println(""); 
        delay(50);
        }
void kalibrasyonoku(){
        Serial.begin(9600);
       for(int i = 0; i < 8; i++){         
          Serial.print(sensormin[i]); 
          Serial.print("  "); 
          Serial.print(sensormax[i]); 
          Serial.print("  ");     
          Serial.print(sensormax[i]-sensormin[i]); 
          Serial.println("  ");
      }
  }
   void flashyap(){
          digitalWrite(13, LOW); delay(250);
          digitalWrite(13, HIGH); delay(250);
           digitalWrite(13, LOW); delay(250);
          digitalWrite(13, HIGH); delay(250);
           digitalWrite(13, LOW); delay(250);
          digitalWrite(13, HIGH); delay(250);
           digitalWrite(13, LOW); delay(250);
          digitalWrite(13, HIGH); delay(250);
           digitalWrite(13, LOW);  delay(250);
           digitalWrite(13, HIGH); delay(250);
           digitalWrite(13, LOW);  delay(250);    
  }
