void cizgisaydim() { 
   if (sensordegeri[0]<300  && sensordegeri[2]<300  &&  sensordegeri[5]<300 &&    sensordegeri[7]<300  )
      { cizgisayisi++; 
       while(sensordegeri[0]<300  && sensordegeri[2]<300  &&  sensordegeri[5]<300 &&    sensordegeri[7]<300 )
       { motorkontrol(50,50); sensoroku();} 
      }
}
void sagsol90(){
 
 //saga doksan
 if (sensordegeri[7]>900   &&  sensordegeri[4]<500 &&  sensordegeri[3]<250   &&  sensordegeri[1]<250 &&  sensordegeri[0]<250 ) {
       digitalWrite(13,HIGH); 
       doksansay++; yolsifirla();
       while(sensordegeri[7]>900  &&  sensordegeri[4]<500 &&  sensordegeri[3]<250   &&  sensordegeri[1]<250 &&  sensordegeri[0]<250) {
          sondeger=0; motorkontrol(-100,-255); sensoroku();
        }
         motorkontrol(80,-85);  delay(10);  sensoroku();
         while(sensordegeri[0]>250) {motorkontrol(80,-85); sensoroku();}
         digitalWrite(13,LOW);    
    }
   //sola doksan
  if(sensordegeri[0]>900   &&  sensordegeri[3]<500 &&  sensordegeri[4]<250    &&  sensordegeri[6]<250 &&  sensordegeri[7]<250)  { 
      digitalWrite(13,HIGH); 
      doksansay++; yolsifirla();
      while(sensordegeri[0]>900   &&  sensordegeri[3]<500 &&  sensordegeri[4]<250    &&  sensordegeri[6]<250 &&  sensordegeri[7]<250) {
      sondeger=7000;  motorkontrol(-255,-100); sensoroku();
        } 
        motorkontrol(-85,80);  delay(10); sensoroku();
        while(sensordegeri[7]>250) {motorkontrol(-85,80); sensoroku();}
        digitalWrite(13,LOW);   
  }
}
