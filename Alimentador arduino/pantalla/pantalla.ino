void pantalla(){

  if (modo == 4){
  lcd.setCursor(0,0);
  lcd.print("modo: ");
  lcd.print(modo);
   lcd.setCursor(0,1);
  lcd.print("Paso: ");
  lcd.print(paso);
    }
  if (modo == 3){
  lcd.setCursor(0,0);
  lcd.print("modo: ");
  lcd.print(modo);
   lcd.setCursor(0,1);
  lcd.print("Paso: ");
  lcd.print(paso);
    }
    
  if (modo == 2){
  lcd.setCursor(0,0);
  lcd.print("modo: ");
  lcd.print(modo);
   lcd.setCursor(0,1);
  lcd.print("Paso: ");
  lcd.print(paso);
    }

  
   if (modo == 1){
  lcd.setCursor(0,0);
  lcd.print("modo: ");
  lcd.print(modo);
   lcd.setCursor(0,1);
  lcd.print("Paso: ");
  lcd.print(paso);
    }
     if (modo == 0){
  
   lcd.setCursor(0,0);//columna , linea
  lcd.print("modo: ");
  lcd.print(modo);
  
    lcd.setCursor(8,0);
  lcd.print("P: ");
  lcd.print(nroDePasos);
  
  }
  }
