#include <Servo.h>


 Servo myservo;  // create servo object to control a servo


Servo servo;  // a maximum of eight servo objects can be created


 int pos = 0;    // variable to store the servo position
 
int motor1Pin1 = 5; // pin 2 on L293D IC
int motor1Pin2 = 12; // pin 7 on L293D IC
int enable1Pin = 3; // pin 1 on L293D IC
int motor2Pin1 = 6; // pin 10 on L293D IC
int motor2Pin2 = 13; // pin 15 on L293D IC
int enable2Pin = 4; // pin 9 on L293D IC

int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;


void setup()


{
   pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    // sets enable1Pin and enable2Pin high so that motor can turn on:
    digitalWrite(enable1Pin, HIGH);
    digitalWrite(enable2Pin, HIGH);
 
    

  Serial.begin(9600);


  myservo.attach(9);  // attaches the servo on pin 9 to the     servo object


 servo.attach(11);





 // myservo.write(0);


 //servo.write(0);


}

   
void loop()
{
char Data;
 
if (Serial.available())


{


  Data = Serial.read();
  flag=0;


Serial.println(Data);


while(Data == 'A')


    {
pos=180;
myservo.write(pos);

      if(pos == 180)


        {


          break;


        }


    }


         while(Data == 'B')


    {
pos=0;
myservo.write(pos);
     
myservo.write(90);

       


      if(pos ==0)


        {


          break;


        }


    }


       


        while(Data == 'C')


    {
pos=180;
       servo.write(pos);


      if(pos == 180)


        {


          break;


        }


    }


       


        while(Data == 'D')


    {

pos=0;
servo.write(pos);
     
servo.write(90);
   


      if(pos ==0)


        {


          break;


        }


    }



   
    while(Data == 'E')
    {
    digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
    break;
    }
    
    while( Data == 'F')
    {
     digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
    break;
    }
    
    while( Data == 'G')  // turn right
    {
      digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
    break;
    }
    
    while( Data == 'H')  //turn left
    {
      digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
    break;
    }
    
    while (Data == 'I')
    {
      
      digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
 break;   
    }
    
}
}
