
#define sagtabanhiz 100  // robotun temel gidiş hızını belirler max 255 yazılabilir
#define soltabanhiz 100  // robotun temel gidiş hızını belirler max 255 yazılabilir
#define sagmotor1 10
#define sagmotor2 9
#define sagmotorpwmpin 11
#define solmotor1 6
#define solmotor2 7
#define solmotorpwmpin 5
#define MZ80 8
#define encoderpinsag 4
#define encoderpinsol 2
#define taktik 12

int gidilenyol=0;  int adimsayisi=0;   int adimsayisisag=0;  byte tekerdurumsag=0;  byte eskitekerdurumsag=0;
float Kp = 0.03;    float Kd = 1;       float Ki = 0.0001;      /*byte fanhizi=0;*/ 
int sensormin[8];   int sensormax[8];   int sensordegeri[8];    int sensordegerix[8];  
int fark=3500;      int sonhata = 0;    unsigned int pozisyon=3500; long zaman=0;  
int tanpon=0;       int sagmotorpwm = 0;    int solmotorpwm = 0;  int adimdegeri=0;
int integral=0;     int hata=0;         int sondeger=0;         byte doksansay=0;    
byte cizgisayisi=0;    byte cizgivar=0;    byte beyazcizgi=0;   /*char pist='A'; */
void setup() {
  Serial.begin(9600);
      pinMode(sagmotor1, OUTPUT);
      pinMode(sagmotor2, OUTPUT);
      pinMode(sagmotorpwmpin, OUTPUT);
      pinMode(solmotor1, OUTPUT);
      pinMode(solmotor2, OUTPUT);
      pinMode(solmotorpwmpin, OUTPUT);
      pinMode(MZ80, INPUT);
      pinMode(encoderpinsag, INPUT);
      pinMode(encoderpinsol, INPUT);
      pinMode(taktik, INPUT_PULLUP);
      //
      delay(1000);
      resetkalibrasyon();
      digitalWrite(13,LOW);    
      kalibrasyon();       // sensörleri ortam ışık ve zemşn renk tonlarına göre kalibre eder
     // kalibrasyonoku();  // kablibrasyonu pc den okumak için aktif edilir. sensor değerlerini ekrana yazdırır
      // kalibrasyon sonrası nano üzerindeki led yanıp sönerek son hizlamayı yapmak için zaman verir
      flashyap();                                       
      
      yolsifirla();       // enkoder başlangıç değeri olan gidilenyol değişkenini sıfırlar
     


      while (digitalRead(MZ80)==1) {   frenle(5);  }  // başlangıçta kapının açılmasını bekler
     //delay(200);
     zaman=millis();
 }

void loop() {
  
  tanpon=-10;
  tursay();          // gidilen mesafeyi cm cinsinden hesaplar
//  cizgisaydim();   // dik çizgileri saymak için kullanılır ihtiyaç halinde aktif edilir
//  degerokuma();    // kalibre olmuş sensörlerden gelen verileri yol üzerinde okumak yani test etmek için kullanılır. Test yaparken motor sürücüyü çıkarınız
//  sagsol90();      // 90 derece dönüşler var ise aktifleştrilir geçtiği doksanları sayar

    if(0<=gidilenyol && gidilenyol<100) tanpon=50; 
     //20cm den önce 100 pwm hızla 20-50cm arası 100+50 ile gider

    if(100<=gidilenyol && gidilenyol<200) tanpon=-30; 
    
    
        //50-500cm arası 100+150 ile gider
   // if(500<gidilenyol && gidilenyol<700) tanpon=-50;   //500-700cm arası hızını 100-50 ye düşürür
              // eğer pistten çıkmış ve engel görmüyorsa 7 sn sonra robot tamamen durur
   // 500cm yol gittikten sonra engel görürse durur

  pozisyon= sensoroku();  // sensör değerini okuyarak pozisyon değişkenine aktarır 7000-0 arası değer üretir tam ortası 3500 değeridir
  hata = pozisyon-2200;   // sensözr pozisyonunun orta naktadan ne kadar hatalı olduğunu bulur
  integral+=hata;         // geçmiş hataların toplamını hesaplar
  int duzeltmehizi = Kp * hata + Kd*(hata - sonhata) + Ki*integral;  //PID kontrol ile motorlar arasındaki hız farkının hesabı yapılır
  sonhata = hata;         // hata değeri sonhata olarak kaydedilir robot çizgi üzerinden çıkmışsa ölçüm yapılamayacağında son hataya göre işlem yapılır
   
  sagmotorpwm = sagtabanhiz + duzeltmehizi +tanpon ;  // PID den gelen düzeltme faktörü ile sağ motor hızı hesaplanır
  solmotorpwm = soltabanhiz - duzeltmehizi  +tanpon ; // PID den gelen düzeltme faktörü ile sol motor hızı hesaplanır

  sagmotorpwm = constrain(sagmotorpwm, -180, 255); // sagmotor hızı hesaplandıktan sonra -180 ile 255 değerleri arasına sınırlandırılır
  solmotorpwm = constrain(solmotorpwm, -180, 255); // solmotor hızı hesaplandıktan sonra -180 ile 255 değerleri arasına sınırlandırılır
  motorkontrol(solmotorpwm,sagmotorpwm);           // motorkontrol alt programı çağırılır
 
}
