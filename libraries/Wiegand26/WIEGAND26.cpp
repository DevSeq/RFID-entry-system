#include <WIEGAND26.h>

extern byte reader1Pins[];          // Reader 1 connected to pins 4,5
extern byte reader2Pins[];          // Reader2 connected to pins 6,7
extern long reader1;
extern int  reader1Count;
extern long reader2;
extern int  reader2Count;


WIEGAND26::WIEGAND26(){
}

WIEGAND26::~WIEGAND26(){
}



/* Wiegand Reader code. Modify as needed or comment out unused readers.
 *  system supports up to 2 independent readers.
 */



void WIEGAND26::initReaderOne(void) {
  for(byte i=0; i<2; i++){
    pinMode(reader1Pins[i], OUTPUT);
    digitalWrite(reader1Pins[i], HIGH); // enable internal pull up causing a one
    digitalWrite(reader1Pins[i], LOW); // disable internal pull up causing zero and thus an interrupt
    pinMode(reader1Pins[i], INPUT);
    digitalWrite(reader1Pins[i], HIGH); // enable internal pull up
  }
  delay(10);
  reader1Count=0;
  reader1=0;
}


void  WIEGAND26::initReaderTwo(void) {
  for(byte i=0; i<2; i++){
    pinMode(reader2Pins[i], OUTPUT);
    digitalWrite(reader2Pins[i], HIGH); // enable internal pull up causing a one
    digitalWrite(reader2Pins[i], LOW); // disable internal pull up causing zero and thus an interrupt
    pinMode(reader2Pins[i], INPUT);
    digitalWrite(reader2Pins[i], HIGH); // enable internal pull up
  }
  delay(10);
  reader2Count=0;
  reader2=0;
}



void  WIEGAND26::reader1One() {
  if(digitalRead(reader1Pins[1]) == LOW){
    reader1Count++;
    reader1 = reader1 << 1;
    reader1 |= 1;
  }
}

void  WIEGAND26::reader1Zero() {
  if(digitalRead(reader1Pins[0]) == LOW){
    reader1Count++;
    reader1 = reader1 << 1;
   
  }
}


void  WIEGAND26::reader2One() {
  if(digitalRead(reader2Pins[1]) == LOW){
    reader2Count++;
    reader2 = reader2 << 1;
    reader2 |= 1;
  }
}

void  WIEGAND26::reader2Zero(void) {
  if(digitalRead(reader2Pins[0]) == LOW){
    reader2Count++;
    reader2 = reader2 << 1;  
  }
}
