//https://programarfacil.com/blog/arduino-blog/display-7-segmentos-dado/

#define PULSADOR 2
 
/* Array multidimensional para mostrar los números */
byte Pines[10][8] = {
  { 0, 1, 1, 1, 1, 1, 1, 0 },   /* 0    _1, 1, 1, 1, 1, 1, 0  */
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


byte Number = 0;
 
void setup() {
  /* Iniciamos el monitor serie */
  //Serial.begin(9600);
  
  /* Ponemos los pines de los segmentos en modo OUTPUT (salida) */
  for(int i = 3; i < 10; i++){
    pinMode(i, OUTPUT);
  }

  /* Ponemos el pin del pulsador en modo INPUT (entradda) */
  pinMode(PULSADOR, INPUT_PULLUP); 
}
 
void loop() {

  if(digitalRead(PULSADOR) == 0){ delay(150);
    if(digitalRead(PULSADOR) == 1){
      Number += 1;
      if(Number == 10) Number=0;
      /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for (int e = 0; e < 8; e++){
        digitalWrite(e + 2, Pines[Number][e]);
        }
       }
      }
}
