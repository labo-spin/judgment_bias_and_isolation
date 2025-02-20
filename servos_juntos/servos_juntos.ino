//hacer funcionar 5 servos por separado y todos juntos

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
const int boton_accion = 8; // Botón asignado en el pin 8.
const int boton_selec = 7;
bool EstadoPuerta = 0; // Puerta cerrada
int PINSERVO1 = 10;
int PINSERVO2 = 9; // attaches the servo on pin 9 to the servo object
int PINSERVO3 = 6;
int PINSERVO4 = 5;
int PINSERVO5 = 3;
int listaservos[] = {3, 5 , 6, 9, 10, 34}; //34 es para todos
int PULSOMIN = 700;    // pulso minimo en microsegundos - 700
int PULSOMAX = 2000;    
int longitud = sizeof(listaservos) / sizeof(listaservos[0]);

void setup() {
  // Vamos a usar el puerto serie para mostrar el estado del botón.
  Serial.begin(9600);
  
  // Usar un bucle for para recorrer la lista
  for (int i = 0; i < longitud; i++) {
    Serial.println(listaservos[i]); // Imprimir cada valor de la lista en el monitor serial
    myservo.attach(listaservos[i]); 
    myservo.write(10); //posicionarlo a 10 grados
    delay(1000);
    myservo.detach();
  }
  // Ponemos el pin como una entrada, puesto que vamos a leer un botón. Habilito la resistencia de PULLUP.
  pinMode(boton_accion,INPUT_PULLUP);
  pinMode(boton_selec,INPUT_PULLUP);
 
  Serial.println("Listo para operar!!");
}

void loop() {
  if (digitalRead(boton_selec)==LOW and EstadoPuerta==0 ) {
    desplazar(listaservos, longitud); //desplazar hacia la izquierda la lista
    Serial.println("Puerta seleccionada ");
    Serial.println(listaservos[0]);
    delay(500);
  }
  
  if (digitalRead(boton_accion)==LOW ) {   // Cuando la entrada se ponga a 0, el botón "debería" estar pulsado.
    if (EstadoPuerta == 0){
      if (listaservos[0] == 34){
        Serial.println("Abrir todas las puertas");
        for (int i = 1; i < longitud; i++) {
           myservo.attach(listaservos[i]);
           myservo.write(180);
           delay(500);
        }
      }
      else {
      Serial.println("Abrir la puerta");
      myservo.attach(listaservos[0]);
      myservo.write(180);
      delay(1000);
      myservo.detach();
      }
      EstadoPuerta = 1;
    }
    
    else {
      if (listaservos[0] == 34){
         Serial.println("Cerrar todas las puertas");
         for (int i = 1; i < longitud; i++) {
            myservo.attach(listaservos[i]);
            myservo.write(10);
            delay(500);
           }
      }
      else{
      Serial.println("Cerrar la puerta");
      myservo.attach(listaservos[0]);
      myservo.write(10);
      delay(1000);
      myservo.detach();
      }
      EstadoPuerta = 0;
    }
    
  delay(500);
  Serial.println("Listo para operar!!");
  }
}

// Función para desplazar la lista cíclicamente hacia la izquierda
void desplazar(int lista[], int tamano) {
  int ultimoElemento = lista[0];  // Guardamos el último elemento
  for (int i = 0; i < tamano - 1; i++) {
    lista[i] = lista[i + 1];  // Desplazamos los elementos una posición hacia la izquierda
  }
  lista[tamano-1] = ultimoElemento;  // El último elemento pasa a la primera posición
}
