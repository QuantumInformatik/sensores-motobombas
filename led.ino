int m1 = 2;   //PUERTO DE SALIDA M1
int m2 = 3;     //PUERTO DE SALIDA M2

int ledRojo = 4;
int ledAmarillo = 5;
int ledVerde = 6;

int sensorA = 8; // ENTRADA DEL SENSOR A
int sensorB = 9; // ENTRADA DEL SENSOR B 
int sensorC = 10; //ENTRADA DEL SENSOR C

int a=0; //PARA ALMACENAR EL VALOR DEL SENSOR A
int b=0; //PARA ALMACENAR EL VALOR DEL SENSOR B
int c=0; //PARA ALMACENAR EL VALOR DEL SENSOR C

int motor1; 
int motor2;

int rojo;
int amarillo;
int verde;

void setup()
{
  pinMode(m2, OUTPUT);    //SALIDA
  pinMode(m1, OUTPUT);    //SALIDA

  pinMode(ledRojo, OUTPUT);    //SALIDA
  pinMode(ledAmarillo, OUTPUT);    //SALIDA
  pinMode(ledVerde, OUTPUT);    //SALIDA
  
  pinMode(sensorA, INPUT); //ENTRADA
  pinMode(sensorB, INPUT); //ENTRADA
  pinMode(sensorC, INPUT); //ENTRADA
}

void loop()
{
  a = digitalRead(sensorA);  //LEER EL SENSOR A
  b = digitalRead(sensorB);  //LEER EL SENSOR B
  c = digitalRead(sensorC);  //LEER EL SENSOR C
  
  motor1 = (!a&!b)|(!b&!c)|(!a&!c);
  motor2 = (!a&!b)|(b&!c);

  digitalWrite(m1, motor1);
  digitalWrite(m2, motor2);
  
  //LED ROJO
  rojo = (!a&!b)|(!a&!c);
  digitalWrite(ledRojo, rojo);
  
  //LED AMARILLO
  amarillo = a&!c;
  digitalWrite(ledAmarillo, amarillo);
  
  //LED VERDE
  verde = (b&c)|(a&c);
  digitalWrite(ledVerde, verde);
   
}
