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
    delay(30);
  }
}

void downDegree(int posFinal, Servo servo){
  int posActual;
  for(posActual = servo.read(); posActual > posFinal; posActual-=mov){
    servo.write(posActual);
    delay(30);
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

}
