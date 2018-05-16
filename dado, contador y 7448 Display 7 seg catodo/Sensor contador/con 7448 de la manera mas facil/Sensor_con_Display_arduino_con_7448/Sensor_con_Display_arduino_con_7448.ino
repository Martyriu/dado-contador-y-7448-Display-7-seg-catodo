//https://programarfacil.com/blog/arduino-blog/display-7-segmentos-dado/

#define PULSADOR 2
 
/* Array multidimensional para mostrar los números */
byte Pines[10][5] = {
  { 0, 0, 0, 0, 0 },   /* 0    _ 0, 0, 0, 0 */
  { 0, 1, 0, 0, 0 },   /* 1    _ 0, 0, 0, 1 */
  { 0, 0, 1, 0, 0 },   /* 2    _ 0, 0, 1, 0 */
  { 0, 1, 1, 0, 0 },   /* 3    _ 0, 0, 1, 1 */
  { 0, 0, 0, 1, 0 },   /* 4    _ 0, 1, 0, 0 */
  { 0, 1, 0, 1, 0 },   /* 5    _ 0, 1, 0, 1 */
  { 0, 0, 1, 1, 0 },   /* 6    _ 0, 1, 1, 0 */
  { 0, 1, 1, 1, 0 },   /* 7    _ 0, 1, 1, 1 */
  { 0, 0, 0, 0, 1 },   /* 8    _ 1, 0, 0, 0 */
  { 0, 1, 0, 0, 1 }    /* 9    _ 1, 0, 0, 1 */
};


byte Number = 0;
 
void setup() {
  /* Iniciamos el monitor serie */
  //Serial.begin(9600);
  
  /* Ponemos los pines de los segmentos en modo OUTPUT (salida) */
  for(int i = 3; i < 7; i++){
    pinMode(i, OUTPUT);
  }

  /* Ponemos el pin del pulsador en modo INPUT (entradda)*/
  pinMode(PULSADOR, INPUT_PULLUP);
}
 
void loop() {

  if(digitalRead(PULSADOR) == 0){ delay(150);
    if(digitalRead(PULSADOR) == 1){
      Number += 1;
      if(Number == 10) Number=0;
      /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for (int e = 0; e < 5; e++){
        digitalWrite(e+2, Pines[Number][e]);
        }
       }
      }
}
