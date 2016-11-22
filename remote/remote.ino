#include "IRremote.h"
#include <Servo.h> 
#include <Ultrasonic.h>
Ultrasonic ultrasonic(8,9);

IRrecv irrecv(2); 
Servo servo;
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  servo.attach(10);
}

void loop() {
  Serial.print(ultrasonic.Ranging(CM));
  Serial.println("cm");    
  delay(100);
  if (ultrasonic.Ranging(CM) < 20) {
    servo.write(23);
    delay(5000);
    servo.write(113);
  }
  if ( irrecv.decode( &results )) { 
    Serial.println( results.value); 
    irrecv.resume();

     switch ( results.value ) {
      case 50190375:
          servo.write(23);
          break;
      case 50198535:
          servo.write(113);
          break;
     }    
   }
}
