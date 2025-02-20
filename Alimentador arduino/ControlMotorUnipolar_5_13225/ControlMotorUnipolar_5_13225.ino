 
 /*
  * 
  * controlMotorUnipolar_5_13225
  * cambio de patas pulsadores                
                  
  *                        
  * control horario antihorario
  * 
  *
  * 
  */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int pulsador1 = 8;//
const int pulsador2 = 9;//
const int pulsador3 = 10;//
const int pulsador4 = 11;//

const int finCarreraLadoJeringa = 6;
const int finCarreraLadoMotor = 7;

 const int bobina1a = 2;
 const int bobina2a = 3;
 const int bobina1b = 4;
 const int bobina2b = 5;
 
int modo =0;

int  nroDePasos=0;
int  nroDePasos1V=0;
int paso=0;

 int lecturaPote;//no se utiliza
 int velocidad;//no se utiliza
 int espera;
 
int estadoPulsador1= 0;
int estadoPulsador2= 0;
int estadoPulsador3= 0;
int estadoPulsador4= 0;

int estadofinCarreraLadoMotor= 0;
int estadofinCarreraLadoJeringa= 0;  

int auxiliarNroDePasos=0;

int t=0;//índice de for next
int t2=0;//índice de for next (en fin de carrera)



void setup() {
                   
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  

pinMode (pulsador1, INPUT_PULLUP);
pinMode (pulsador2, INPUT_PULLUP); 
pinMode (pulsador3, INPUT_PULLUP);
pinMode (pulsador4, INPUT_PULLUP); 

pinMode (finCarreraLadoMotor,INPUT_PULLUP);
pinMode (finCarreraLadoJeringa,INPUT_PULLUP);


pinMode(bobina1a,OUTPUT);
pinMode(bobina2a,OUTPUT);
pinMode(bobina1b,OUTPUT);
pinMode(bobina2b,OUTPUT);

nroDePasos1V=48;//48 => 1 vuelta

nroDePasos=48;

}


void loop() {
  
  estableceVelocidad();//establece espera en 2500
  
  //finDeCarreras();
  
  pulsadores();
  
  pantalla();
      
    }
    



void pasosMotor1(){
  
  switch(paso){
   case 1:
            paso1De4();
   break;
   
   case 2:
            paso2De4();
   break;
   
   case 3:
            paso3De4();
   break;
   
   case 4:
            paso4De4();
   break;
  
  }
  finDeCarreras();//revisa los fin de carrera en 
                  //ambos extremos
                  
  }
  
  void cuantosPasos(){
    auxiliarNroDePasos = nroDePasos;
    for (t=0; t< nroDePasos;t++){
      paso++;
      if (paso>4){
        paso =1;        
        }
        // Serial.print(paso);
         pasosMotor1();
        // secuencia4Pasos();
      } 
    
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, LOW);
    }
  void cuantosPasos1Vuelta(){
    
    auxiliarNroDePasos = nroDePasos1V;
    
    for ( t=0; t< nroDePasos1V;t++){
      paso++;
      if (paso>4){
        paso =1;        
        }
        // Serial.print(paso);
         pasosMotor1();
        // secuencia4Pasos();
      } 
    
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, LOW);
    }
      void cuantosPasosAh(){
auxiliarNroDePasos = nroDePasos;
    for ( t=0; t < nroDePasos;t++){
      paso--;
      if (paso<1){
        paso =4;        
        }
       //  Serial.print(paso);
         pasosMotor1();
        // secuencia4Pasos();
      } 
    
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, LOW);
    }
    
       void cuantosPasosAh1Vuelta(){
    auxiliarNroDePasos = nroDePasos1V;
    for (t=0; t < nroDePasos1V;t++){
      paso--;
      if (paso<1){
        paso =4;        
        }
       //  Serial.print(paso);
         pasosMotor1();
        // secuencia4Pasos();
      } 
    
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, LOW);
    }
void secuencia4Pasos(){
  paso1De4();
  paso2De4();
  paso3De4();
  paso4De4();
  
  }

   
void paso1De4(){
  //paso 1
 digitalWrite(bobina1a, HIGH);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, HIGH);
 digitalWrite(bobina2b, LOW);
 delayMicroseconds (espera);;   
 
//paso 2
 digitalWrite(bobina1a, HIGH);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, LOW);
 delayMicroseconds (espera);;
  }
  
  void paso2De4(){
    //paso 3
 digitalWrite(bobina1a, HIGH);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, HIGH);
 delayMicroseconds (espera);;   

//paso 4
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, HIGH);
 delayMicroseconds (espera);;   
    }

    void paso3De4(){
      //paso 5
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, HIGH);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, HIGH);
 delayMicroseconds (espera);;   
 
//paso 6
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, HIGH);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, LOW);
  delayMicroseconds (espera);;   

      }

      void paso4De4(){
        //paso 7
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, HIGH);
 digitalWrite(bobina1b, HIGH);
 digitalWrite(bobina2b, LOW);
  delayMicroseconds (espera);;   

 
//paso 8
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, HIGH);
 digitalWrite(bobina2b, LOW);
 delayMicroseconds (espera);; 
        
        }
        

      
void secuencia8Pasos(){
  
  //SECUENCIA DE 8 1/2 PASOS 
//paso 1
 digitalWrite(bobina1a, HIGH);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, HIGH);
 digitalWrite(bobina2b, LOW);
 delayMicroseconds (espera);;   
 
//paso 2
 digitalWrite(bobina1a, HIGH);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, LOW);
 delayMicroseconds (espera);;   

 
//paso 3
 digitalWrite(bobina1a, HIGH);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, HIGH);
 delayMicroseconds (espera);;   

//paso 4
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, HIGH);
 delayMicroseconds (espera);;   

//paso 5
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, HIGH);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, HIGH);
 delayMicroseconds (espera);;   
 
//paso 6
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, HIGH);
 digitalWrite(bobina1b, LOW);
 digitalWrite(bobina2b, LOW);
  delayMicroseconds (espera);;   

 
//paso 7
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, HIGH);
 digitalWrite(bobina1b, HIGH);
 digitalWrite(bobina2b, LOW);
  delayMicroseconds (espera);;   

 
//paso 8
 digitalWrite(bobina1a, LOW);
 digitalWrite(bobina2a, LOW);
 digitalWrite(bobina1b, HIGH);
 digitalWrite(bobina2b, LOW);
 delayMicroseconds (espera);;  
  }

  void estableceVelocidad() {
  lecturaPote = analogRead(A0); // Reads the potentiometer
  velocidad = map(lecturaPote, 0, 1023, 100,5000); // Convrests the read values of the potentiometer from 0 to 1023 into desireded delay values (300 to 4000)
  espera = velocidad;
     espera = 2500;
}
   
