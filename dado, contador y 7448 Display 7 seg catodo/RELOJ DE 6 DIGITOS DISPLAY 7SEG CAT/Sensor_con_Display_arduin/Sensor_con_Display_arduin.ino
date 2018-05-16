//https://programarfacil.com/blog/arduino-blog/display-7-segmentos-dado/

#define PULSADOR 10
#define PULSADOR1 11

#define DISPLAY1 A0
#define DISPLAY2 A1
#define DISPLAY3 A2
#define DISPLAY4 A3
#define DISPLAY5 A4
#define DISPLAY6 A5
 
/* Array multidimensional para mostrar los números */
byte Pines[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, 0 },   /* 0    _1, 1, 1, 1, 1, 1, 0  */
  { 0, 1, 1, 0, 0, 0, 0, 0 },   /* 1    _0, 1, 1, 0, 0, 0, 0  */
  { 1, 1, 0, 1, 1, 0, 1, 0 },   /* 2    _1, 1, 0, 1, 1, 0, 1  */
  { 1, 1, 1, 1, 0, 0, 1, 0 },   /* 3    _1, 1, 1, 1, 0, 0, 1  */
  { 0, 1, 1, 0, 0, 1, 1, 0 },   /* 4    _1, 0, 1, 1, 0, 1, 1  */
  { 1, 0, 1, 1, 0, 1, 1, 0 },   /* 5    _1, 0, 1, 1, 1, 1, 1  */
  { 1, 0, 1, 1, 1, 1, 1, 0 },   /* 6    _1, 1, 1, 0, 0, 1, 0  */
  { 1, 1, 1, 0, 0, 1, 0, 0 },   /* 7    _1, 1, 1, 1, 1, 1, 1  */
  { 1, 1, 1, 1, 1, 1, 1, 0 },   /* 8    _1, 1, 1, 1, 1, 1, 1  */
  { 1, 1, 1, 1, 0, 1, 1, 0 }    /* 9    _1, 1, 1, 1, 0, 1, 1  */
};

byte Pines_c_puntos[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, 1 },   /* 0    _1, 1, 1, 1, 1, 1, 0  */
  { 0, 1, 1, 0, 0, 0, 0, 1 },   /* 1    _0, 1, 1, 0, 0, 0, 0  */
  { 1, 1, 0, 1, 1, 0, 1, 1 },   /* 2    _1, 1, 0, 1, 1, 0, 1  */
  { 1, 1, 1, 1, 0, 0, 1, 1 },   /* 3    _1, 1, 1, 1, 0, 0, 1  */
  { 0, 1, 1, 0, 0, 1, 1, 1 },   /* 4    _1, 0, 1, 1, 0, 1, 1  */
  { 1, 0, 1, 1, 0, 1, 1, 1 },   /* 5    _1, 0, 1, 1, 1, 1, 1  */
  { 1, 0, 1, 1, 1, 1, 1, 1 },   /* 6    _1, 1, 1, 0, 0, 1, 0  */
  { 1, 1, 1, 0, 0, 1, 0, 1 },   /* 7    _1, 1, 1, 1, 1, 1, 1  */
  { 1, 1, 1, 1, 1, 1, 1, 1 },   /* 8    _1, 1, 1, 1, 1, 1, 1  */
  { 1, 1, 1, 1, 0, 1, 1, 1 }    /* 9    _1, 1, 1, 1, 0, 1, 1  */
};

unsigned long interval = 100;  // the time we need to wait
unsigned long previousMillis = 0; // millis() returns an unsigned long.

byte Number6 = 0, Number5 = 0, Number4 = 0, Number3 = 0, Number2 = 0, Number1 = 0;

#define en 1/* para cambiar por se ocupa transistores*/
#define ap 0

byte time = 0;

 
void setup() {
  /* Iniciamos el monitor serie */
  //Serial.begin(9600);
  
  /* Ponemos los pines de los segmentos en modo OUTPUT (salida) */
  for(int i = 2; i < 10; i++){
    pinMode(i, OUTPUT);
  }

  for(int p = A0; p < A7; p++){
    pinMode(p, OUTPUT);
  }
  /*
     pinMode(DISPLAY1, OUTPUT);
     pinMode(DISPLAY2, OUTPUT);
     pinMode(DISPLAY3, OUTPUT);
     pinMode(DISPLAY4, OUTPUT);
     pinMode(DISPLAY5, OUTPUT);
     pinMode(DISPLAY6, OUTPUT);
    */ 
     pinMode(PULSADOR, INPUT_PULLUP); 
     pinMode(PULSADOR1, INPUT_PULLUP);

     digitalWrite(DISPLAY1, en);
     digitalWrite(DISPLAY2, en);
     digitalWrite(DISPLAY3, en);
     digitalWrite(DISPLAY4, en);
     digitalWrite(DISPLAY5, en);
     digitalWrite(DISPLAY6, en);
}


void loop() {
  mostrar_digito_uno();
}

void mostrar_digito_uno() {
  
  //if(digitalRead(PULSADOR) == 0){Number1 += 1; Number2 += 1; if(Number1 >= 10){ Number1 = 0; Number2 += 1; }
/*-_-_-_-_-_-_DIGITO 1-_-_-_-_-_-_*/
      digitalWrite(DISPLAY1, en);
      digitalWrite(DISPLAY2, en);
      digitalWrite(DISPLAY3, en);
      digitalWrite(DISPLAY4, en);
      digitalWrite(DISPLAY5, en);
      digitalWrite(DISPLAY6, ap);
      
      
      for(byte a=0; a<8; a++){ digitalWrite(a + 2, Pines[Number1][a]); }
      if(Number1 >= 10){ Number1 = 0; Number2 += 1; }
      tiempo();
 
/*-_-_-_-_-_-_DIGITO 2-_-_-_-_-_-_*/
     if(Number2 >= 1){
      digitalWrite(DISPLAY5, ap);
      digitalWrite(DISPLAY6, en);
      
      if(Number2 >= 6){ Number2 = 0; Number3 += 1; } /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for(byte b=0; b<8; b++){ digitalWrite(b + 2, Pines[Number2][b]); }
      tiempo();
      } 

/*-_-_-_-_-_-_DIGITO 3-_-_-_-_-_-_*/
     if(Number3 >= 1){
      digitalWrite(DISPLAY4, ap);
      digitalWrite(DISPLAY5, en);
      
      if(Number3 >= 10){ Number3 = 0; Number4 += 1; } /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for(byte c=0; c<8; c++){ digitalWrite(c + 2, Pines_c_puntos[Number3][c]); }
      tiempo();
      }

/*-_-_-_-_-_-_DIGITO 4-_-_-_-_-_-_*/
     if(Number4 >= 1){
      digitalWrite(DISPLAY3, ap);
      digitalWrite(DISPLAY4, en);
      
      if(Number4 >= 6){ Number4 = 0; Number5 += 1; } /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for(byte d=0; d<8; d++){ digitalWrite(d + 2, Pines[Number4][d]); }
      tiempo();
      } 
      
/*-_-_-_-_-_-_DIGITO 5-_-_-_-_-_-_*/
     if(Number5 >= 1){
      digitalWrite(DISPLAY2, ap);
      digitalWrite(DISPLAY3, en);
      
      if(Number5 >= 10){ Number5 = 0; Number6 += 1; } /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for(byte e=0; e<8; e++){ digitalWrite(e + 2, Pines_c_puntos[Number5][e]); }
      tiempo();
      }

/*-_-_-_-_-_-_DIGITO 6-_-_-_-_-_-_*/
     if(Number6 >= 1){
      digitalWrite(DISPLAY1, ap);
      digitalWrite(DISPLAY2, en);
      
      if(Number6 >= 10){ Number6 = 0; } /* Ponemos los pines en estado correcto para mostrar el número randomNumber */
      for(byte f=0; f<8; f++){ digitalWrite(f + 2, Pines[Number6][f]); } 
      tiempo();
       }
/*______________________________________________________________________________________________________________________*/
       if((unsigned long)(millis() - previousMillis) >= interval){
        previousMillis = millis();
        Number1 += 1; 
        
        if(Number6 >= 1){ time = 5; }
        else {
          if(Number5 >= 1){ time = 6; }
          else {
            if(Number4 >= 1){ time = 7.5; } 
            else { 
              if(Number3 >= 1) { time = 10; }
              else {
                if(Number2 >= 1){ time = 15; } 
                else { time = 30; } 
                }
                }
                }
                } 
        } 
}

void tiempo(){
  delay(time);
}

