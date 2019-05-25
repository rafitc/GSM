#include <GSM.h>
void start1();
void start2();
void start3();
void sms1();
#define PINNUMBER ""
char charbuffer[20];
// initialize the library instance
GSM gsmAccess;
GSM_SMS sms;
GSMVoiceCall vcs;

byte h=0,v=0;    //variables used in for loops
const unsigned long period=50;  //little period used to prevent error
unsigned long kdelay=0;        // variable used in non-blocking delay 
const byte rows=4;             //number of rows of keypad
const byte columns=4;            //number of columnss of keypad
const byte Output[rows]={5,6,7,8}; //array of pins used as output for rows of keypad
const byte Input[columns]={9,10,11,12}; //array of pins used as input for columnss of keypad
byte keypad() // function used to detect which button is used 
{
 static bool no_press_flag=0;  //static flag used to ensure no button is pressed 
  for(byte x=0;x<columns;x++)   // for loop used to read all inputs of keypad to ensure no button is pressed 
  {
     if (digitalRead(Input[x])==HIGH);   //read evry input if high continue else break;
     else
     break;
     if(x==(columns-1))   //if no button is pressed 
     {
      no_press_flag=1;
      h=0;
      v=0;
     }
  }
  if(no_press_flag==1) //if no button is pressed 
  {
    for(byte r=0;r<rows;r++) //for loop used to make all output as low
    digitalWrite(Output[r],LOW);
    for(h=0;h<columns;h++)  // for loop to check if one of inputs is low
    {
      if(digitalRead(Input[h])==HIGH) //if specific input is remain high (no press on it) continue
      continue;
      else    //if one of inputs is low
      {
          for (v=0;v<rows;v++)   //for loop used to specify the number of row
          {
          digitalWrite(Output[v],HIGH);   //make specified output as HIGH
          if(digitalRead(Input[h])==HIGH)  //if the input that selected from first sor loop is change to high
          {
            no_press_flag=0;                //reset the no press flag;
            for(byte w=0;w<rows;w++) // make all outputs as low
            digitalWrite(Output[w],LOW);
            return v*4+h;  //return number of button 
          }
          }
      }
    }
  }
 return 50;
}
void setup() 
{
  for(byte i=0;i<rows;i++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(Output[i],OUTPUT);
  }
  for(byte s=0;s<columns;s++)  //for loop used to makk pin mode of inputs as inputpullup
  {
    pinMode(Input[s],INPUT_PULLUP);
  }
  Serial.begin(9600); //to use serial monitor we set the buad rate

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("SMS Messages Sender");

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

  Serial.println("GSM initialized");
  vcs.hangCall();
  Serial.println("Ready To Call");

  
}
void loop()
{
  if(millis()-kdelay>period) //used to make non-blocking delay
  {
    kdelay=millis();  //capture time from millis function
switch (keypad())  //switch used to specify which button
   {
            case 0:
            Serial.println(1);
            start1();
            
       break;  
            case 1:
            Serial.println(2);
            start2();
       break;
            case 2:
            Serial.println(3);
            start3();
       break;
            case 3:
            Serial.println("F1");
       break;
            case 4:
            Serial.println(4);
       break;
            case 5:
            Serial.println(5);
       break;
            case 6:
            Serial.println(6);
       break;
            case 7:
            Serial.println("F2");
       break;
            case 8:
            Serial.println(7);
       break;
            case 9:
            Serial.println(8);
       break;
            case 10:
            Serial.println(9);
       break;
            case 11:
            Serial.println("F3");
       break;
            case 12:
            Serial.println("Mode");
       break;
            case 13:
            Serial.println(0);
       break;
            case 14:
            Serial.println("Cancel");
       break;
            case 15:
            Serial.println("Enter");
       break;
            default:
            ;
}
}
}
void start1() {
    // Check the status of the voice call
       String remoteNumber = "9048747682";
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
        delay(1000);
        sms1();
}
void start2() {
    // Check the status of the voice call
       String remoteNumber = "9539581551";
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
        delay(1000);
        sms2();
}
void start3() {
        // Check the status of the voice call
       String remoteNumber = "8086933488";
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
        delay(1000);
        sms3();
}
void sms1(){
  char remoteNum[20] = "9048747682" ; // telephone number to send sms
  Serial.print("SMS to ");
  Serial.print(remoteNum);
  char txtMsg[200] = "Please Help Me ! My location :10.8814331,76.078371";
  Serial.println("SENDING");
  Serial.println();
  // send the message
  sms.beginSMS(remoteNum);
  sms.print(txtMsg);
  sms.endSMS();
  Serial.println("\nSMS SENT\n");
  //exit(0);
  }
  void sms2(){
  char remoteNum[20] = "9539581551" ; // telephone number to send sms
  Serial.print("SMS to ");
  Serial.print(remoteNum);
  char txtMsg[200] = "Please Help Me ! My location :10.8814331,76.078371";
  Serial.println("SENDING");
  Serial.println();
  // send the message
  sms.beginSMS(remoteNum);
  sms.print(txtMsg);
  sms.endSMS();
  Serial.println("\nSMS SENT\n");
  //exit(0);
  }
void sms3(){
  char remoteNum[20] = "8086933488" ; // telephone number to send sms
  Serial.print("SMS to ");
  Serial.print(remoteNum);
  char txtMsg[200] = "Please Help Me ! My location :10.8814331,76.078371";
  Serial.println("SENDING");
  Serial.println();
  // send the message
  sms.beginSMS(remoteNum);
  sms.print(txtMsg);
  sms.endSMS();
  Serial.println("\nSMS SENT\n");
  //exit(0);
  }
