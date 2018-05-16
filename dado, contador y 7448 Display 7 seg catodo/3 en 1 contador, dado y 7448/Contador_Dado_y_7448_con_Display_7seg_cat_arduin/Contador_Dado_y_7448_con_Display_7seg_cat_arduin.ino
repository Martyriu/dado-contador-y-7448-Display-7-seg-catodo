//https://programarfacil.com/blog/arduino-blog/display-7-segmentos-dado/

#define PULSADOR 2
#define PULSADOR1 A0
#define PULSADOR2 A1
 
/* Array multidimensional para mostrar los números */
byte Pines_dado_contador[10][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },   /* 0    _1, 1, 1, 1, 1, 1, 0  */
  { 0, 0, 1, 1, 0, 0, 0, 0 },   /* 1    _0, 1, 1, 0, 0, 0, 0  */
  { 0, 1, 1, 0, 1, 1, 0, 1 },   /* 2    _1, 1, 0, 1, 1, 0, 1  */
  { 0, 1, 1, 1, 1, 0, 0, 1 },   /* 3    _1, 1, 1, 1, 0, 0, 1  */
  { 0, 0, 1, 1, 0, 0, 1, 1 },   /* 4    _1, 0, 1, 1, 0, 1, 1  */
  { 0, 1, 0, 1, 1, 0, 1, 1 },   /* 5    _1, 0, 1, 1, 1, 1, 1  */
  { 0, 1, 0, 1, 1, 1, 1, 1 },   /* 6    _1, 1, 1, 0, 0, 1, 0  */
  { 0, 1, 1, 1, 0, 0, 1, 0 },   /* 7    _1, 1, 1, 1, 1, 1, 1  */
  { 0, 1, 1, 1, 1, 1, 1, 1 },   /* 8    _1, 1, 1, 1, 1, 1, 1  */
  { 0, 1, 1, 1, 1, 0, 1, 1 }    /* 9    _1, 1, 1, 1, 0, 1, 1  */
};

byte Pines_7448_[10][6] = {
  { 0, 0, 0, 0, 0, 0 },   /*  0   _ 0, 0, 0, 0 */
  { 0, 0, 0, 0, 0, 0 },   /*  9   _ 0, 0, 0, 1 */
  { 0, 0, 1, 0, 0, 0 },   /*  1   _ 0, 0, 1, 0 */
  { 0, 0, 0, 1, 0, 0 },   /*  2    _ 0, 0, 1, 1 */
  { 0, 0, 1, 1, 0, 0 },   /*  3   _ 0, 1, 0, 0 */
  { 0, 0, 0, 0, 1, 0 },   /*  4   _ 0, 1, 0, 1 */
  { 0, 0, 1, 0, 1, 0 },   /*  5   _ 0, 1, 1, 0 */
  { 0, 0, 0, 1, 1, 0 },   /*  6   _ 0, 1, 1, 1 */
  { 0, 0, 1, 1, 1, 0 },   /*  7   _ 1, 0, 0, 0 */
  { 0, 0, 0, 0, 0, 1 }    /*  8   _ 1, 0, 0, 1 */
};

byte Number = 0;

 
void setup() {
  /* Iniciamos el monitor serie */
  //Serial.begin(9600);
  
  /* Ponemos los pines de los segmentos en modo OUTPUT (salida) */
  for(int i = 3; i < 10; i++){
    pinMode(i, OUTPUT);
  }

  for(int o = 10; o < 14; o++){
    pinMode(o, OUTPUT);
  }

  /* Ponemos el pin del pulsador en modo INPUT (entradda) */
  pinMode(PULSADOR, INPUT_PULLUP); 
  pinMode(PULSADOR1, INPUT_PULLUP); 
  pinMode(PULSADOR2, INPUT_PULLUP); 

  Number = 0;
  for (int a = 0; a < 8; a++){
    digitalWrite(a + 2, Pines_dado_contador[Number][a]);
    }
}
 
void loop() {
  if(digitalRead(PULSADOR) == 0) dado_disp();
  if(digitalRead(PULSADOR1) == 0) Contador_disp();
  if(digitalRead(PULSADOR2) == 0) deco_7478_();  
}

void dado_disp() {
    //Number += 1;
    Number = random(8);
    if(Number == 0) Number = 1;
    if(Number >= 7) Number = 1;
    
    /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
    for (int b = 0; b < 8; b++){
      digitalWrite(b + 2, Pines_dado_contador[Number][b]);
    } delay(1);
}

void Contador_disp() {
  delay(150);
    if(digitalRead(PULSADOR1) == 1){
      Number += 1;
      if(Number == 10) Number=0;
      /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for (int e = 0; e < 8; e++){
        digitalWrite(e + 2, Pines_dado_contador[Number][e]);
        }
      }
}

void deco_7478_() {
  delay(150);
    if(digitalRead(PULSADOR2) == 1){
      Number += 1;
      if(Number == 10) Number=0;
      /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for (int q = 8; q < 13; q++){
        digitalWrite(q + 2, Pines_7448_[Number][q]);
        }
       }
}
