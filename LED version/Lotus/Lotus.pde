import processing.serial.*;

Serial port; //print things to serial

String [] gen; //array for genome 
String [] proxy; //array for each row in the genome 

String val;
boolean contact = false; //determines if arduino and processing are connected 

int countGen; //index for genome array 
int countProx; //index for proxy array 



void setup() {
  size(50, 50); //size of window, CLICK IN HERE 

  port = new Serial(this, Serial.list()[1], 9600); //serial port for the arduino 
  port.bufferUntil('\n'); //every new line 

  gen = loadStrings("lotus.csv"); //loading file 

  frameRate(30); //slows frame rate down, prevent lagging 
}

void draw() {
}

void serialEvent(Serial port) {
  val = port.readStringUntil('\n');

  if (val != null) { //value is not empty 
    val=trim(val); //removes whitespace 
    println(val); //prints value 
  }

  if (contact == false) { //no connection 
    if (val.equals("A")) {
      port.clear();
      contact = true;
      println("con");
    }
  } else {
    println(val);

    println("A");
  }
}


void mousePressed() {

  proxy = split(gen[countGen], ","); //splitting genome sequence by line 

  if (proxy[countProx].equals("A")) { //sends a number depending on what letter it is to arduino
    println("writing A");
    port.write('1');
    //println("1");
  } else if (proxy[countProx].equals("C")) {
    println("writing C");
    port.write('2');
    //println("2");
  } else if (proxy[countProx].equals("G")) {
    println("writing G");
    port.write('3');
    //println("3");
  } else if (proxy[countProx].equals("T")) {
    println("writing T");
    port.write('4');
    //println("4");
  }
 

  if (countProx != proxy.length - 1) { //move onto the next line 
    countProx++;
  } else {
    countProx = 0;
  }

  if (countGen != gen.length - 1) { //start over 
    countGen++;
  } else {
    countGen = 0;
  }
}
