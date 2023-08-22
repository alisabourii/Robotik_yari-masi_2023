int sensoroku() {
    unsigned long ortalama=0; 
    unsigned int toplam=0;
    cizgivar=0;
      
    
      for(int i = 0; i < 8; i++){ 
        int minmaksfark=sensormax[i]-sensormin[i];  
        long int hesaplama=analogRead(i)-sensormin[i];
        hesaplama=hesaplama*1000;
        hesaplama=hesaplama/minmaksfark;
        sensordegeri[i]=constrain(hesaplama,0,1000);
        sensordegerix[i]=sensordegeri[i];
        // Serial.print(sensordegeri[i]); Serial.print("  ");
      }
        if(sensordegeri[0] > 300 && sensordegeri[7] > 300) beyazcizgi=1;
        if(sensordegeri[0] < 300 && sensordegeri[7] < 300) beyazcizgi=0;

        for(int i=0;i<8;i++) {         
          if(beyazcizgi==1)  sensordegerix[i] = 1000-sensordegeri[i];
          if(sensordegerix[i] > 100)  cizgivar = 1;
          if(sensordegerix[i] > 50) {
            ortalama += sensordegerix[i] * i ;
            toplam += sensordegerix[i];
          }
        }
     
      if(cizgivar==0) {
        if(sondeger < 3000)  return 0;
        if(sondeger > 4000)  return 7000;
        if(sondeger>3000 && sondeger<4000) return 3500;
      }

     
      ortalama=ortalama*1000;
      sondeger = ortalama/toplam;
      return sondeger;
}   
