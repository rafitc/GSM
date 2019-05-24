#include <GSM.h> //lib for gsm 
void call(); //functon for call 
void leerpad();
#define PINNUMBER ""
#define RECIPIENT_NUMBER "9747165032"
GSM gsmAccess;
GSMVoiceCall vcs;
GSM_SMS sms;
String remoteNumber = "9747165032";
char charbuffer[20];
//String s[5] = {"9747165032","8086242507","9747165032","9072812457"};

const int fa = 9;
const int fb = 8;
const int fc = 7;
const int fd = 6;
const int c1 = 5;
const int c2 = 10;
const int c3 = 11;

const int trigPin = 12;
const int echoPin = 13;
int sensor_pin = A0;
int output_value ;
    long duration;
    int distance;
    
void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("MAke a call");

  // connection state
  boolean notConnected = true;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while (notConnected) {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  // This makes sure the modem correctly reports incoming events
  vcs.hangCall();
  Serial.println("calling Function ok!"); 

  pinMode(fa,OUTPUT);
  pinMode(fb,OUTPUT);
  pinMode(fc,OUTPUT);
  pinMode(fd,OUTPUT);
  pinMode(c1,INPUT_PULLUP);
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP); 
  Serial.println("keypad OK!");

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  leerpad();
}
void call(){
  // Check the status of the voice call
       Serial.println("calling to ");
       Serial.println(remoteNumber);
       remoteNumber.toCharArray(charbuffer, 20);
        // Check if the receiving end has picked up the call
        vcs.voiceCall(charbuffer);
        delay(500);
        Serial.println("call attended .... will disconnect after 3 sec");
        delay(3000);
        vcs.hangCall();
        delay(500);
        Serial.println("CAll FUNction completed ! ");

        //SMS Sttings started 
        
}

void leerpad(){
  digitalWrite(fa,LOW) ;
  if (digitalRead(c1) == LOW){ Serial.println("1");
    Serial.println("calling...");
    call();
   
  }
  if (digitalRead(c2) == LOW) Serial.println("2"); 
  if (digitalRead(c3) == LOW) Serial.println("3");
  digitalWrite(fa,HIGH);
  digitalWrite(fb,LOW);
  if (digitalRead(c1) == LOW) Serial.println("4");
  if (digitalRead(c2) == LOW) Serial.println("5");
  if (digitalRead(c3) == LOW) Serial.println("6");
  digitalWrite(fb,HIGH);
  digitalWrite(fc,LOW);
  if (digitalRead(c1) == LOW) Serial.println("7");
  if (digitalRead(c2) == LOW) Serial.println("8");
  if (digitalRead(c3) == LOW) Serial.println("9");
  digitalWrite(fc,HIGH);
  digitalWrite(fd,LOW);
  if (digitalRead(c1) == LOW) Serial.println("*");
  if (digitalRead(c2) == LOW) Serial.println("0");
  if (digitalRead(c3) == LOW) Serial.println("#");
  digitalWrite(fd,HIGH);
  delay(500);


      // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    output_value= analogRead(sensor_pin);

    output_value = map(output_value,550,0,0,100);

    Serial.print("Mositure : ");
  
    Serial.print(output_value);

   Serial.println("%");
    if(distance <= 15){
      Serial.println("Vibration...");
    }
    else if(distance>=15){
      Serial.print("No Vibration...");
    }
    else if(output_value <= 35){
      Serial.println("moister...");
    }
    else{
      Serial.println("no prblm");
    }
    
 }
