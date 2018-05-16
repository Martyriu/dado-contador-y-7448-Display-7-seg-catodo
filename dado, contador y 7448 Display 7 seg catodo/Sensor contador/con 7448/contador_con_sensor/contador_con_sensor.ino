#define SENSOR 2

#define A 3
#define B 4
#define C 5
#define D 6

byte contador = 0;


void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  pinMode(SENSOR, INPUT_PULLUP);
  digitalWrite(SENSOR, 1);
}

void loop() {
  if(digitalRead(SENSOR) == 0){ delay(100);
    if(digitalRead(SENSOR) == 1){ contador += 1; }
  }

  if(contador == 1){ 
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
    }
  if(contador == 2){ 
    digitalWrite(A, 0);
    digitalWrite(B, 1);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
    }
  if(contador == 3){ 
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
    }
  if(contador == 4){ 
    digitalWrite(A, 0);
    digitalWrite(B, 0);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    }
  if(contador == 5){ 
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    }
  if(contador == 6){ 
    digitalWrite(A, 0);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    }
  if(contador == 7){ 
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    }
  if(contador == 8){ 
    digitalWrite(A, 0);
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 1);
    }
  if(contador == 9){
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 1);
    }
    if(contador == 10){ 
    digitalWrite(A, 0);
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
    contador = 0;
    }
}
