int ledR[] = {6,11}; //pins for red 
int ledG[] = {5,10}; //pins for green
int ledB[] = {3,9}; //pins for blue 

char val; //data coming from Processing thru the Serial port

int numLites = 2; //the number of RGB lights 

void setup(){

  for(int i = 0; i < numLites; i++){
  
  pinMode(ledR[i], OUTPUT); //sets all lights as OUTPUT
  pinMode(ledG[i], OUTPUT);
  pinMode(ledB[i], OUTPUT);
  }

  Serial.begin(9600); //opening Serial port 

} 

void loop(){

  if(Serial.available() > 0){ //if there's data from processing 
    val = Serial.read(); //read data from processing 
    Serial.println("READING");
    Serial.println(val); //print what is read 

    if(val == 1){
      aye(); //light patterns for "A" 
    } else if(val == 2){
      cee(); //light patterns for "C" 
    } else if(val == 3){
      gee(); //light patterns for "G" 
    } else if(val == 4){
      tee(); //light patterns for "T" 
    }
    delay(10);
    delay(300); //btwn letters 
  } else {
    Serial.println("!!!!"); //prints this while waiting for data 
    delay(50);
  }
}

void aye(){

  for(int i = 0; i < numLites; i++){ //turns the red values on so it blinks a red light
  analogWrite(ledR[i], 255); 
  delay(100);
  analogWrite(ledG[i], 0); 
  delay(100); 
  analogWrite(ledB[i], 0); 
  delay(100); 
  
  analogWrite(ledR[i], 0); //off 
  delay(100); 
  analogWrite(ledG[i], 0); 
  delay(100); 
  analogWrite(ledB[i], 0); 
  delay(100);
  
  analogWrite(ledR[i], 255);
  delay(300);
  analogWrite(ledG[i], 0); 
  delay(300); 
  analogWrite(ledB[i], 0); 
  delay(300);
  }
}

void cee(){

  for(int i = 0; i < numLites; i++){ //turns the green values on so it blinks a green light
  analogWrite(ledR[i], 0); 
  delay(300); 
  analogWrite(ledG[i], 255);
  delay(300); 
  analogWrite(ledB[i], 0); 
  delay(300);

  ///////////

  analogWrite(ledR[i], 0); //off
  delay(100); 

  analogWrite(ledG[i], 0);
  delay(100); 

  analogWrite(ledB[i], 0);
  delay(100);

  //////////
  
  analogWrite(ledR[i], 0);
  delay(100); 

  analogWrite(ledG[i], 255);
  delay(100); 

  analogWrite(ledB[i], 0);
  delay(100);

  ////////////

  analogWrite(ledR[i], 0); //off 
  delay(100); 

  analogWrite(ledG[i], 0);
  delay(100); 

  analogWrite(ledB[i], 0);
  delay(100);

  ///////////

  analogWrite(ledR[i], 0);
  delay(300); 

  analogWrite(ledG[i], 255);
  delay(300);

  analogWrite(ledB[i], 0);
  delay(300); 
  }
}

void tee(){
  for(int i = 0; i < numLites; i++){ //turns the blue values on so it blinks a blue light
  analogWrite(ledR[i], 0);
  analogWrite(ledG[i], 0);
  analogWrite(ledB[i], 255);
  delay(300);
  }
}

void gee(){

  for(int i = 0; i < numLites; i++){ //turns the red and blue values on so it blinks a purple light
  analogWrite(ledR[i], 255);
  analogWrite(ledG[i], 0); 
  analogWrite(ledB[i], 255);
  delay(300); 

  analogWrite(ledR[i], 0); //off 
  analogWrite(ledG[i], 0); 
  analogWrite(ledB[i], 0);
  delay(100); 

  analogWrite(ledR[i], 255);
  analogWrite(ledG[i], 0); 
  analogWrite(ledB[i], 255);
  delay(300); 

  analogWrite(ledR[i], 0); //off 
  analogWrite(ledG[i], 0); 
  analogWrite(ledB[i], 0);
  delay(100); 

  analogWrite(ledR, 255);
  analogWrite(ledG[i], 0); 
  analogWrite(ledB, 255);
  delay(100);
  }
  
}
