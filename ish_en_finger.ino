
// Include the servo library to add servo-control functions:
#include <Servo.h> 

//Create a servo "object", called servo1-6. 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

				//Each servo object controls one servo (you 
				//can have a maximum of 12). 

//const int flexPin = A0; //Define analog input pin to measure
						//flex sensor position. 
const int button1Pin = 1;  // pushbutton 1 pin
const int button2Pin = 2;
const int button3Pin = 4;
const int button4Pin = 13;

const int SENSOR_PIN1 = A0;      // Analog input pin
const int FLEX_PIN1 = A1;
const int SENSOR_PIN2 = A2;
const int FLEX_PIN2 = A3;
const int SENSOR_PIN3 = A4;
const int FLEX_PIN3 = A5;


  int button1State;
  int button2State;
  int button3State;
  int button4State;

  int SPsensorValue1;
  int FlexsensorValue1;
  int SPsensorValue2;
  int FlexsensorValue2;
  int SPsensorValue3;
  int FlexsensorValue3;


  int pos;
  int pos2;

  int f1pos;
  int f1pos2;
  int f2pos;
  int f2pos2;
  int f3pos;
  int f3pos2;  

void setup() 
{ 
   
  Serial.begin(9600); //Set serial baud rate to 9600 bps

  // assign buttons as input
   pinMode(button1Pin, INPUT);
   pinMode(button2Pin, INPUT);
   pinMode(button3Pin, INPUT);
   pinMode(button4Pin, INPUT);



  // Enable control of a servo on pin 3,5,6,9,10,11
   servo1.attach(3); 
   servo2.attach(5); 
   servo3.attach(6);
   servo4.attach(9);  
   servo5.attach(10);
   servo6.attach(11); 

  // set an initial position for the fingers
   pos = 179;
   pos2 = 179;

  // write the position to the fingers
   servo1.write(pos);
   servo3.write(pos);
   servo5.write(pos);
  
   servo2.write(pos2);
   servo4.write(pos2);
   servo6.write(pos2);

  //wait before starting the program
  delay(1500); 
} 


void loop() 
{ 

 
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  button4State = digitalRead(button4Pin);  
  
  SPsensorValue1 = analogRead(SENSOR_PIN1); // Read the voltage from the softpot (0-1023)
   FlexsensorValue1 = analogRead(FLEX_PIN1);
  SPsensorValue2 = analogRead(SENSOR_PIN2);
   FlexsensorValue2 = analogRead(FLEX_PIN2);
  SPsensorValue3 = analogRead(SENSOR_PIN3); 
   FlexsensorValue3 = analogRead(FLEX_PIN3);


  Serial.print("Finger 1. Touch: "); 
  Serial.print(SPsensorValue1);         
  Serial.print(", Flex: "); 
  Serial.print(FlexsensorValue1); 
  
  Serial.print("  Finger 2. Touch : "); 
  Serial.print(SPsensorValue2);         
  Serial.print(", Flex: "); 
  Serial.print(FlexsensorValue2); 
  
  Serial.print("  Finger 3. Touch : "); 
  Serial.print(SPsensorValue3);         
  Serial.print(", Flex: "); 
  Serial.print(FlexsensorValue3); 
  
  Serial.print(" Button 1: "); 
  Serial.print(button1State); 
  Serial.print(" Button 2: "); 
  Serial.print(button2State); 
  Serial.print(" Button 3: "); 
  Serial.print(button3State); 
  Serial.print(" Button 4: "); 
  Serial.print(button4State); 

  Serial.print  ("  pos: ");
  Serial.print  (pos);
  Serial.print  (" pos2: ");
  Serial.println(pos2);
  

  pos = constrain(pos, 0, 180);  // limits range of servo values to between 0 and 180
  pos2 = constrain(pos, 0, 180);  // limits range of servo values to between 0 and 180



if ((button4State == HIGH) && (SPsensorValue1 <= 200) && (SPsensorValue3 <= 200)){
  pos  = (pos  -= 2);
  pos2 = (pos2 -= 3);
   
  
  servo1.write(pos);
  servo3.write(pos);
  servo5.write(pos);
  
  servo2.write(pos2);
  servo4.write(pos2);
  servo6.write(pos2);

  
}

/*
else if (button1State == HIGH){
  pos = (pos += 2);
  pos2 = (pos2 += 3);
  
  servo1.write(pos);
  servo3.write(pos);
  servo5.write(pos);
  
  servo2.write(pos2);
  servo4.write(pos2);
  servo6.write(pos2);
  
  
  delay(10);  // wait 20ms between servo updates
  //Serial.print("pos: ");
  //Serial.print(pos);
  //Serial.print(" pos2: ");
  //Serial.println(pos2);
}

 else if(button2State == HIGH){ 
  pos =  pos;
  pos2 = (pos2 += 3);
  
  servo1.write(pos);
  servo2.write(pos2);
  servo3.write(pos);
  servo4.write(pos2);
  servo5.write(pos);
  servo6.write(pos2);
  
  
  delay(10);  // wait 20ms between servo updates
  //Serial.print("pos: ");
  //Serial.print(pos);
  //Serial.print("  pos2: ");
  //Serial.println(pos);
}

 else if(button3State == HIGH){ 
  pos =  (pos -= 2);
  pos2 = pos2;
  
  servo1.write(pos);
  servo2.write(pos2);
  servo3.write(pos);
  servo4.write(pos2);
  servo5.write(pos);
  servo6.write(pos2);
  
  
  delay(10);  // wait 20ms between servo updates
  //Serial.print("pos: ");
  //Serial.print(pos);
  //Serial.print("  pos2: ");
  //Serial.println(pos);
}
*/
else
  { 
//nathing
  }
}
 
 
