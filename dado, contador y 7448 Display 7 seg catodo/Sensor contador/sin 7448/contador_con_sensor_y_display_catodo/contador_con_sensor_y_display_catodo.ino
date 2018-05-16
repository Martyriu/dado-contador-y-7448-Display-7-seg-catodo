#define SENSOR 2

#define A 3
#define B 4
#define C 5
#define D 6
#define E 7
#define F 8
#define G 9
#define H 10

byte contador = 0;


void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);

    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 0);
    digitalWrite(H, 0);

  pinMode(SENSOR, INPUT_PULLUP);
  digitalWrite(SENSOR, 1);
}

void loop() {
  if(digitalRead(SENSOR) == 0){ delay(100);
    if(digitalRead(SENSOR) == 1){ contador += 1; }
  }

  if(contador == 1){ 
    digitalWrite(A, 0);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
    digitalWrite(H, 0);
    }
  if(contador == 2){ 
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 0);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 0);
    digitalWrite(G, 1);
    digitalWrite(H, 0);
    }
  if(contador == 3){ 
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 1);
    digitalWrite(H, 0);
    }
  if(contador == 4){ 
    digitalWrite(A, 0);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
    digitalWrite(H, 0);
    }
  if(contador == 5){ 
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
    digitalWrite(H, 0);
    }
  if(contador == 6){ 
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
    digitalWrite(H, 0);
    }
  if(contador == 7){ 
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 1); // ESTE NOP
    digitalWrite(G, 0);
    digitalWrite(H, 0);
    }
  if(contador == 8){ 
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
    digitalWrite(H, 0);
    }
  if(contador == 9){
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
    digitalWrite(H, 0);
    }
    if(contador == 10){ 
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 0);
    digitalWrite(H, 0);
    contador = 0;
    }
}
