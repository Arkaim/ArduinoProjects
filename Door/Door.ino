#include <Servo.h> 

int t = 9; //trig pin of ultrasonic sensor
int e = 10; //echo pin of ultrasonic sensor
long duration;
int distance;
Servo servo; //servo motor

void setup()
{
  pinMode(t,OUTPUT);
  pinMode(e, INPUT);
  Serial.begin(9600);
  servo.attach(10); //привязываем привод к порту 10

}

void loop() 
{
  duration = pulseIn(e, HIGH); //time for wave to go to the obstacle and back

  //distance measured by ultrasonic sensor
  //0.034 is a velocity of sound, divided by 2, as it goes to the obstacle and back by the time
  distance = duration * 0.034 / 2; 
  Serial.println(distance); //in cm
  
   if(distance<5){
    //now turn on the servo
    servo.write(0); 
    delay(2000); 
    servo.write(90); 
    delay(2000); 

   }
}
