const int bill =2; 
const int ping[bill]={3,2};
#include <Servo.h>
Servo myservo0;
Servo myservo1;
int pos = 0;
int tilld = 30;
int buzzd = 10;
void setup() 
{
  
  pinMode(13, OUTPUT);
  myservo0.attach(9);
  myservo1.attach(10);
  // initialize serial communication:  
  Serial.begin(9600);
}

void loop()
{
  long duration[bill],cm[bill];
  for(int i=0;i<bill;i++)
  {
  pinMode(ping[i], OUTPUT);
  digitalWrite(ping[i], LOW);
  delayMicroseconds(2);
  digitalWrite(ping[i], HIGH);
  delayMicroseconds(5);
  digitalWrite(ping[i], LOW);

  pinMode(ping[i], INPUT);
  duration[i] = pulseIn(ping[i], HIGH);
   
  cm[i] = microsecondsToCentimeters(duration[i]);

  Serial.print("sensor");
  Serial.print(i+1);
  Serial.print(" reading");
  Serial.print("===");
  Serial.print(cm[i]);
  Serial.print("cm");
  Serial.println();
  }
  for(int i=0;i<bill;i++)
  {
    if(i==0)
 {
      if((cm[i]<tilld)&&(cm[i]>0))
    {

        if(cm[i]<buzzd)
            digitalWrite(13, HIGH);
        for (pos = 0; pos <= 180; pos=pos+20) 
        { 
             
          myservo0.write(pos); 
          delay(15);             
                                 
        }
        for (pos = 180; pos >= 0; pos=pos-20) 
        { 
          myservo0.write(pos);    
          delay(15);          
                                 
        }
        
        if(cm[i]<buzzd)
            digitalWrite(13, LOW);
     }
      
 }
  else
  {
       if((cm[i]<tilld)&&(cm[i]>0))
    {

        if(cm[i]<buzzd)
            digitalWrite(13, HIGH);
        for (pos = 0; pos <= 180; pos=pos+20) 
        { 
          myservo1.write(pos);
          delay(15);             
                                
        }
        for (pos = 180; pos >= 0; pos=pos-20) 
        { 
          myservo1.write(pos);              
                   delay(15);           
        }
         if(cm[i]<buzzd)
            digitalWrite(13, LOW);
     }
           
  
  }
  }
  Serial.println();
  
 delay(100);
}
long microsecondsToCentimeters(long microseconds) 
{
  return microseconds / 29 / 2;

}

 

