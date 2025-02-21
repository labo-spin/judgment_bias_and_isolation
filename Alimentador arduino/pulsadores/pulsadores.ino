void pulsadores(){
  puls1();
  puls2();
  puls3();
  puls4();

}


void puls1(){//incrementa modo
  
 estadoPulsador1=digitalRead(pulsador1); 
  
  if( estadoPulsador1 == LOW){
    modo++;
    if(modo >4){
      modo=0;
      }
    delay(500);
    }
  }

  void puls2(){
   estadoPulsador2=digitalRead(pulsador2); 
  
  if( estadoPulsador2 == LOW){
    if(modo == 0 ) {
       nroDePasos= nroDePasos+1;
      delay(200);
       if( nroDePasos>1000){
        lcd.setCursor(8,0);
        lcd.print("P:     ");
                            nroDePasos=0;
                            }
                    }

      if(modo == 1 ) {
      cuantosPasos();
      }
   
     

      if(modo == 2){
      cuantosPasosAh();
 
    }
    if(modo == 3){
      cuantosPasos1Vuelta();
 
    }
    if(modo == 4){
      cuantosPasosAh1Vuelta();
 
    }
    
  }
  }

    void puls3()
    {
     
    estadoPulsador3=digitalRead(pulsador3); 
   if( estadoPulsador3 == LOW){
      cuantosPasos1Vuelta();
      } 
    }

    void puls4()    
    {
      
       estadoPulsador4=digitalRead(pulsador4); 
   if( estadoPulsador4 == LOW){
      cuantosPasosAh1Vuelta();
      }
      } 


    
