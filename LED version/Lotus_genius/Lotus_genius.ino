int longPause = 300;
int shortPause = 100;

int leds[] = {2, 3, 4};

char val; //data coming from Processing thru the Serial port

int numLites = 3; //the number of RGB lights

void setup() {

  for (int i = 0; i < numLites; i++) {

    pinMode(leds[i], OUTPUT); //sets all lights as OUTPUT

  }

  Serial.begin(9600); //opening Serial port

}

void loop() {
  doIt();
}

void doIt() {

  if (Serial.available() > 0) { //if there's data from processing
    val = Serial.read(); //read data from processing
    Serial.println(val); //print what is read

    if (val == '1') {
      aye(); //light patterns for "A"
    } else if (val == '2') {
      cee(); //light patterns for "C"
    } else if (val == '3') {
      gee(); //light patterns for "G"
    } else if (val == '4') {
      tee(); //light patterns for "T"
    }
    delay(300); //btwn letters
  } else {
    Serial.println("!!!!"); //prints this while waiting for data
    delay(50);
  }

}


void aye() {

  // turn off all the leds
  for (int i = 0; i < numLites; i++) {
    digitalWrite(leds[i], LOW);
  }

  // A sequence --> short long

  // short
  digitalWrite(leds[0], HIGH);
  delay(shortPause);
  digitalWrite(leds[0], LOW); //off
  delay(shortPause);

  // long
  digitalWrite(leds[0], HIGH);
  delay(longPause);
  digitalWrite(leds[0], LOW); //off
  delay(shortPause);

}

void cee() {

  // turn off all the leds
  for (int i = 0; i < numLites; i++) {
    digitalWrite(leds[i], LOW);
  }

  // C sequence --> long short long short

  // long
  digitalWrite(leds[1], HIGH);
  delay(longPause);
  digitalWrite(leds[1], LOW); //off
  delay(shortPause);
  // short
  digitalWrite(leds[1], HIGH);
  delay(shortPause);
  digitalWrite(leds[1], LOW); //off
  delay(shortPause);

  // long
  digitalWrite(leds[1], HIGH);
  delay(longPause);
  digitalWrite(leds[1], LOW); //off
  delay(shortPause);
  // short
  digitalWrite(leds[1], HIGH);
  delay(shortPause);
  digitalWrite(leds[1], LOW); //off
  delay(shortPause);

}

void tee() {
  
  // turn off all the leds
  for (int i = 0; i < numLites; i++) {
    digitalWrite(leds[i], LOW);
  }

  // T sequence --> long 

  // long
  digitalWrite(leds[2], HIGH);
  delay(longPause);
  digitalWrite(leds[2], LOW); //off
  delay(shortPause);
}

void gee() {

  // turn off all the leds
  for (int i = 0; i < numLites; i++) {
    digitalWrite(leds[i], LOW);
  }

  // G sequence --> long long short 

  // long
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[1], HIGH);  
  delay(longPause);
  digitalWrite(leds[2], LOW); //off
  digitalWrite(leds[1], LOW); //off
  delay(shortPause);

  
  // long
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[1], HIGH);  
  delay(longPause);
  digitalWrite(leds[2], LOW); //off
  digitalWrite(leds[1], LOW); //off
  delay(shortPause);
  
  // short
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[1], HIGH);  
  delay(shortPause);
  digitalWrite(leds[2], LOW); //off
  digitalWrite(leds[1], LOW); //off
  delay(shortPause);

}
