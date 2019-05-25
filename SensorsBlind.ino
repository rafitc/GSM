    /*
    * Ultrasonic Sensor HC-SR04 and Arduino Tutorial
    *
    * by Dejan Nedelkovski,
    * www.HowToMechatronics.com
    *
    */
    // defines pins numbers
    const int trigPin =12;
    const int echoPin = 11;
    int vib = 5;

    const int sensor_pin = A0;
    
    
    // defines variables
    long duration;
    int distance;
    void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(vib,OUTPUT);
    Serial.begin(9600); // Starts the serial communication
    }
    void loop() {
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
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  
  if(distance >= 20){
      digitalWrite(vib, LOW);
    }
    else if(distance<=20){
     
      digitalWrite(vib, HIGH);
    }
    else if(moisture_percentage >= 50){
      digitalWrite(vib, HIGH);
    }
    else{
      digitalWrite(vib, LOW);
      
    }
    delay(500);
    }
