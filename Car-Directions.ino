/**
 * Car-Directions
 * Developed by: Rafael Anguiano 
 * Cibernética y Sistemas Computacionales
 * 6to Semestre
 * 09/03/2021
 */
#include <Servo.h>  //Librería Servo

Servo motor; // Tipo de dato SERVO
int pos = 0;  //Posición, auxiliar para los FOR
// A y B para motor 1
int A = 10;   // Defino pin A = 10
int B = 11;   // Defino pin B = 11
// C y D para motor 2
int C = 9;    // Defino pin C = 9
int D = 8;    // Defino pin D = 8
// 
char dato;    // Variable dato para leer en el monitor serial

void setup()
{
  Serial.begin(9600);   // Monitor Serial
  pinMode(A, OUTPUT);   // Defino A como salida
  pinMode(B, OUTPUT);   // Defino B como salida
  pinMode(C, OUTPUT);   // Defino C como salida
  pinMode(D, OUTPUT);   // Defino D como salida
}

void loop()
{
  if( Serial.available() ){ 
    
      dato = Serial.read();   // Lectura del dato en monitor
      Serial.println(dato);   // Imprimiento dato en el monitor

    //Carro hacia adelante, una rueda hacia un lado y una rueda hacia el otro
    if(dato == 'a'){
      for(pos = 0; pos < 180; pos++){
        digitalWrite(A, HIGH);  // Definiendo el movimiento del motor 1 
        digitalWrite(B, LOW);   // Definiendo el movimiento del motor 1 
        digitalWrite(C, HIGH);  // Definiendo el movimiento del motor 2
        digitalWrite(D, LOW);   // Definiendo el movimiento del motor 2
        delay(15);
      }
    }

    //Carro hacia atras, una rueda hacia un lado y una rueda hacia el otro (pero al contrario de con 'a'
    if(dato == 'r'){
      for(pos = 0; pos < 180; pos++){
        digitalWrite(A, LOW);   // Definiendo el movimiento del motor 1
        digitalWrite(B, HIGH);  // Definiendo el movimiento del motor 1
        digitalWrite(C, LOW);   // Definiendo el movimiento del motor 2
        digitalWrite(D, HIGH);  // Definiendo el movimiento del motor 2
        delay(15);
      }
    }

    // Vuelta a la derecha, Ambas ruedas hacia un lado
    if(dato == 'd'){
      for(pos = 0; pos < 180; pos++){
        digitalWrite(A, LOW);   // Definiendo el movimiento del motor 1
        digitalWrite(B, HIGH);  // Definiendo el movimiento del motor 1
        digitalWrite(C, HIGH);  // Definiendo el movimiento del motor 2
        digitalWrite(D, LOW);   // Definiendo el movimiento del motor 2
        delay(15);
      }
    }

    // Vuelta a la izquierda, Ambas ruedas hacia un lado pero al contrario de en 'd'
    if(dato == 'i'){
      for(pos = 0; pos < 180; pos++){
        digitalWrite(A, HIGH);  // Definiendo el movimiento del motor 1
        digitalWrite(B, LOW);   // Definiendo el movimiento del motor 1
        digitalWrite(C, LOW);   // Definiendo el movimiento del motor 2
        digitalWrite(D, HIGH);  // Definiendo el movimiento del motor 2
        delay(15);
      }
    }
  }
}
