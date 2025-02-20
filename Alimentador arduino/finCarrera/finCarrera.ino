
   
   void finDeCarreras(){
                        control_finCarreraLadoJeringa();
                        control_finCarreraLadoMotor();
                        }
   
    
    void control_finCarreraLadoJeringa()
    {
     
    estadofinCarreraLadoJeringa = digitalRead(finCarreraLadoJeringa); 
   if( estadofinCarreraLadoJeringa == LOW){
     PasosAh1Vuelta();//vuelve una vuelta (1mm)
     PasosAh1Vuelta();//vuelve una vuelta (1mm)
     //cuantosPasosAh1Vuelta();//vuelve una vuelta
    // cuantosPasosAh1Vuelta();//vuelve una vuelta
    // cuantosPasosAh1Vuelta();//vuelve una vuelta
    //  t = auxiliarNroDePasos;
      
      } 
    }
 void control_finCarreraLadoMotor()
    {
     
    estadofinCarreraLadoMotor = digitalRead(finCarreraLadoMotor); 
   if(estadofinCarreraLadoMotor == LOW){
   Pasos1Vuelta();//va adelante una vuelta (1mm)
   Pasos1Vuelta();//va adelante una vuelta (1mm)
  // cuantosPasos1Vuelta();
  // cuantosPasos1Vuelta();
  // cuantosPasos1Vuelta();
 //  t = auxiliarNroDePasos;
      } 
    }

 void Pasos1Vuelta(){
    
    //auxiliarNroDePasos = nroDePasos1V;
    
    for ( t2=0; t2< nroDePasos1V;t2++){
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
    
      void PasosAh1Vuelta(){
    //auxiliarNroDePasos = nroDePasos1V;
    for (t2=0; t2 < nroDePasos1V;t2++){
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
