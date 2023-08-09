const int trigPin = 12;               //arduino 10th pin connected to trig Pin of the ultrasonic sensor
const int echoPin = 13;               //arduino 11th pin connected to echo Pin of the ultrasonic sensor

const int Input1 = 2;                 //arduino 3rd pin connected to L293D pin input1
const int Input2 = 3;                 //arduino 4th pin connected to L293D pin input2
const int Input3 = 4;                 //arduino 8th pin connected to L293D pin input3
const int Input4 = 5;                 //arduino 9th pin connected to L293D pin input4
const int En1 = 8;
const int En2 = 9;
int count=0;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (Input1, OUTPUT);        
  pinMode (Input2, OUTPUT);
  pinMode (Input3, OUTPUT);
  pinMode (Input4, OUTPUT);
  pinMode (En1, OUTPUT);
  pinMode (En2, OUTPUT);
  Serial.begin(9600);
}
long duration, distance;
void stop(){
    digitalWrite(Input1, LOW); 
    digitalWrite(Input2, LOW); 
    digitalWrite(Input3, LOW); 
    digitalWrite(Input4, LOW);
    digitalWrite(En1, HIGH);
    digitalWrite(En2, HIGH);
}
void loop()
{     
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  if(distance>=0 && distance<=10){
  Serial.println("count :");
  Serial.println(count);
  if(count==1)
  {
    digitalWrite(Input1, LOW); //clock
    digitalWrite(Input2, LOW); 
    digitalWrite(Input3, HIGH); 
    digitalWrite(Input4, LOW);
    digitalWrite(En1, HIGH);
    digitalWrite(En2, HIGH);
    
  }
  else if(count==2){
    digitalWrite(Input1, HIGH); 
    digitalWrite(Input2, LOW); 
    digitalWrite(Input3, LOW); 
    digitalWrite(Input4, LOW);
    digitalWrite(En1, HIGH);
    digitalWrite(En2, HIGH);
    
  }
  else if(count==3)
  {
    digitalWrite(Input1, HIGH); //anticlock
    digitalWrite(Input2, LOW); 
    digitalWrite(Input3, LOW); 
    digitalWrite(Input4, HIGH);
    digitalWrite(En1, HIGH);
    digitalWrite(En2, HIGH);
   
    
  }
  else{
    stop();
    }
    delay(3000);
    count++;
  } 
  
}
