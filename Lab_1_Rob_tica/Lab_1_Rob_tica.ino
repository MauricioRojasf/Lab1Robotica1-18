#include <Servo.h>

// Instanciando Servos

Servo serBase;
Servo serDer;
Servo serIzq;
Servo serPinza;

int mov=2;
int caja=1;

void upDegree(int posFinal, Servo servo){
  int posActual;
  for(posActual = servo.read() ; posActual<=posFinal; posActual+=mov){
    servo.write(posActual);
    delay(35);
  }
}

void downDegree(int posFinal, Servo servo){
  int posActual;
  for(posActual = servo.read(); posActual > posFinal; posActual-=mov){
    servo.write(posActual);
    delay(35);
  }
}

void irBase(){
  downDegree(93,serDer);
  upDegree(93,serIzq);
  if(serBase.read()>=90){
    downDegree(90,serBase);
  }
  else{
    upDegree(90,serBase);
  }
}

void irCaja(int caja){
  downDegree(93,serDer);
  upDegree(93,serIzq);
  switch(caja) {
    case 1:
      upDegree(129,serBase);
      break;
    case 2:
      downDegree(70,serBase);
      break;
    case 3:
      upDegree(105,serBase);
  }
}

void tomarCaja(int caja){
  switch(caja) {
    case 1:
      downDegree(70,serIzq);
      upDegree(130,serDer);
      downDegree(55,serPinza);
      break;
    case 2:
      downDegree(70,serIzq);
      upDegree(130,serDer);
      downDegree(55,serPinza);
      break;
    case 3:
      downDegree(70,serIzq);
      upDegree(130,serDer);
      downDegree(55,serPinza);
      break;
  }
}

void dejarCaja(int caja){
  switch(caja) {
    case 1:
      downDegree(80,serIzq);
      upDegree(130,serDer);
      upDegree(90,serPinza);
      break;
    case 2:
      upDegree(94,serBase);
      downDegree(80,serIzq);
      upDegree(123,serDer);
      upDegree(90,serPinza);
      break;
    case 3:
      downDegree(84,serIzq);
      upDegree(122,serDer);
      upDegree(90,serPinza);
      break;
  }
}

void setup() {
  // por DEFECTO al realizar el attach todos los servos parten en 93
 serBase.attach(11); 
 serDer.attach(10);
 serIzq.attach(9);
 serPinza.attach(6);
 Serial.begin(9600);

 Serial.println(serBase.read());
 Serial.println(serDer.read());
 Serial.println(serIzq.read());
 Serial.println(serPinza.read());
}

void loop() {
  // put your main code here, to run repeatedly:
  serPinza.write(90);
  delay(100);

  irCaja(caja);
  tomarCaja(caja);
  irBase();
  dejarCaja(caja);
  caja+=1;
  delay(100);
}
