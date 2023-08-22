void tursay(){
  if(digitalRead(encoderpinsol)==HIGH) tekerdurumsag=1; else tekerdurumsag=0;
  if(tekerdurumsag!=eskitekerdurumsag) adimsayisisag++;
  gidilenyol=(adimsayisisag*15.89)/2; 
  eskitekerdurumsag=tekerdurumsag;
  
  }

void yolsifirla(){
  adimsayisisag=0;  
  }

void doksansifirla(){
   adimsayisisag=0;  gidilenyol=20; 
  }
