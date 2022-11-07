#include <sdkconfig.h>
#include <pitches.h>
#include <vector>  
#include <string>
#include <iostream>
// // Programa : Pisque um LED
// // Autor : FILIPEFLOP

//vetor dos valores detectados:
int valor_detec[4] = {0, 0, 0, 0};


//variáveis da entrada do butão:
const int buttonPin = 41;
const int buttonPin2 = 42;  

//variáveis do estado do butão:
int buttonState = 0; 
int buttonState2 = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}
  
void loop() {  
  int xazam = bin_conver();
//  Serial.println(xazam);
  led_buz(xazam);
  add_valor_detec(xazam);
  Serial.println(valor_detec[3]);
  tocar_notas(valor_detec);
  delay(250);
}


//função que converte o valor lido pelo ldr para binário
int bin_conver(){
  int ldr_info = analogRead(4);
  ldr_info = map(ldr_info, 0, 4095, 0, 15);
  if(ldr_info == 0) {      
    ldr_info = 2222;      
  }
  if(ldr_info == 1) {
    ldr_info = 2221;
  }
  if(ldr_info == 2) {
    ldr_info = 2212;
  }
  if(ldr_info == 3) {
    ldr_info = 2122;
  }
  if(ldr_info == 4) {
    ldr_info = 1222;
  }
  if(ldr_info == 5) {
    ldr_info = 2211;
  }
  if(ldr_info == 6) {
    ldr_info = 1122;
  }
  if(ldr_info == 7) {
    ldr_info = 2121;   
  }
  if(ldr_info == 8) {
    ldr_info = 1212;
  }
  if(ldr_info == 9) {
    ldr_info = 1221;
  }
  if(ldr_info == 10) {
    ldr_info = 2112;
  }
  if(ldr_info == 11) {
    ldr_info = 2111;
  }
  if(ldr_info == 12) {
    ldr_info = 1112;
  }
  if(ldr_info == 13) {
    ldr_info = 1121;
  }
  if(ldr_info == 14) {
    ldr_info = 1211;
  }
  if(ldr_info == 15) {
    ldr_info = 1111;
  }
  return(ldr_info);
}


//função que ativa os leds e o buzzer:
void led_buz(int ldr_info) {
  if(ldr_info != 2222) {   
    if(ldr_info%10 == 1) {
      digitalWrite(5, HIGH);
      beep(NOTE_A4, 500);
        //return(note);          
    }
    else {
      ldr_info = ldr_info/10;  
      digitalWrite(5,LOW);
      beep(NOTE_F4, 500);
        //return(note); 
    }
    if(ldr_info%10 == 1) {
      digitalWrite(6, HIGH);
      beep(NOTE_C5, 500);
        //return(note);   
    }
    else {
      ldr_info = ldr_info/10;  
      digitalWrite(6,LOW);
    }
    if(ldr_info%10 == 1) {
      digitalWrite(7, HIGH); 
      beep(NOTE_C7, 500);
        //return(note);  
    }
    else {
      ldr_info = ldr_info/10;  
      digitalWrite(7,LOW);
    }
    if(ldr_info == 1) {
      digitalWrite(15, HIGH);
      beep(NOTE_D4, 500);
        //return(note);   
    }
    else {
      digitalWrite(15,LOW);
    }
  }
  else{
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(15, LOW);                 
  }
}

void beep(int note, int duration){
  tone(16, note, duration);
  delay(duration);
}

void add_valor_detec(int ldr_info) {
  int counter = 0;
  buttonState = digitalRead(buttonPin);    
  if(buttonState == LOW) {
    for(counter; counter <= 3; counter++) {
      valor_detec[counter] = ldr_info;
    } 
  }         
}


//função que toca as notas e faz os leds piscarem:
void tocar_notas(int valor_detec[]) {
  int i = 0;  
  buttonState2 = digitalRead(buttonPin2);
  if(buttonState2 == LOW) {  
    for(i; i<=3; i++) {
      if(valor_detec[i] != 2222) {   
        if(valor_detec[i]%10 == 1) {
          digitalWrite(5, HIGH);
          beep(NOTE_A4, 500);
          delay(100);  
        }
        else {
          valor_detec[i] = valor_detec[i]/10;  
          digitalWrite(5,LOW);
        }
        if(valor_detec[i]%10 == 1) {
          digitalWrite(6, HIGH);
          beep(NOTE_C5, 500);
          delay(100);   
        }
        else {
          valor_detec[i] = valor_detec[i]/10;  
          digitalWrite(6, LOW);
        }
        if(valor_detec[i]%10 == 1) {
          digitalWrite(7, HIGH); 
          beep(NOTE_C7, 500);  
          delay(100);
        }
        else {
          valor_detec[i] = valor_detec[i]/10;  
          digitalWrite(7, LOW);
        }
        if(valor_detec[i] == 1) {
          digitalWrite(15, HIGH);
          beep(NOTE_D4, 500);
          delay(100);   
        }
        else {
          digitalWrite(15, LOW);
        }        
      }         
    } 
  }
}
