

/*
 Controlling a servo position with two pushbuttons
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 19 Sept 2019
 by Carl Fung
 Modified from zoomkat servo button test 12-29-2011
 http://www.arduino.cc/en/Tutorial/Knob
*/
#include <Servo.h>
int button1 = 4; //button set to pin 4, connect to ground to move servo left, put 10k resistor between ground and button as pullup
int press1 = 0;
int button2 = 5; //button set to pin 5, connect to ground to move servo right, put 10k resistor between ground and button as pullup
int press2 = 0;
Servo myservo; // create servo object to control a servo

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  myservo.attach(9);      // attaches the servo on pin 9 to the servo object
  digitalWrite(4, HIGH); //enable pullups to make pin high
  digitalWrite(5, HIGH); //ditto above
}

void loop() //Could probably store a position variable in a future version and have button pushes incrementally change servo position
{
  press1 = digitalRead(button1);
  if (press1 == LOW)
  {
    myservo.write(170); 
  }   
 
  press2 = digitalRead(button2);
  if (press2 == LOW)
  {
    myservo.write(10);
  }
  delay(15); //gives servo time to move between positions
  
}
