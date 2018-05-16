//https://programarfacil.com/blog/arduino-blog/display-7-segmentos-dado/

#define PULSADOR 2
 
/* Array multidimensional para mostrar los números */
byte Pines[10][8] = {
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

  Number = 0;
  for (int a = 0; a < 8; a++){
    digitalWrite(a + 2, Pines[Number][a]);
    }
}
 
void loop() {

  if(digitalRead(PULSADOR) == 0){

    //Number += 1;
    Number = random(8);
    if(Number == 0) Number = 1;
    if(Number >= 7) Number = 1;
    
    /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
    for (int b = 0; b < 8; b++){
      digitalWrite(b + 2, Pines[Number][b]);
    } delay(1);
  }
}
