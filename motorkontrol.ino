void motorkontrol(int solmotorpwm, int sagmotorpwm){
  if(sagmotorpwm<=0) {
      sagmotorpwm=sagmotorpwm*(-1);
      digitalWrite(sagmotor1, LOW);
      digitalWrite(sagmotor2, HIGH);
      analogWrite(sagmotorpwmpin, sagmotorpwm);
    }
  else {
      digitalWrite(sagmotor1, HIGH);
      digitalWrite(sagmotor2, LOW);
      analogWrite(sagmotorpwmpin, sagmotorpwm);
  }
  if(solmotorpwm<=0) {
     solmotorpwm=solmotorpwm*(-1);
     digitalWrite(solmotor1, LOW);
     digitalWrite(solmotor2, HIGH);
     analogWrite(solmotorpwmpin, solmotorpwm);
    }
   else {
    digitalWrite(solmotor1, HIGH);
    digitalWrite(solmotor2, LOW);
    analogWrite(solmotorpwmpin, solmotorpwm);
   }
}


void frenle(int bekle){motorkontrol(0,0); delay(bekle);}

void hafifsagadon(){motorkontrol(35,-35);}

void hafifsoladon(){motorkontrol(-35,35);}
