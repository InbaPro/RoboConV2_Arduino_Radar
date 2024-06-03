#include <Servo.h>

const int JOYSTICK_Y_pin = A0; // analog pin connected to Y output

const int ULTRA_SENSOR_TRIGGER_PIN = 7;
const int ULTRA_SENSOR_ECHO_PIN = 6;

const int SERVO_MOTER_PIN = 5;

Servo myservo;  

int val;    
long duration;
int distance;

void setup() {
  myservo.attach(SERVO_MOTER_PIN);
  pinMode(ULTRA_SENSOR_TRIGGER_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ULTRA_SENSOR_ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}

void loop() {
  val = analogRead(JOYSTICK_Y_pin);            
  val = map(val, 0, 1023, 0, 180);     
  myservo.write(val);
  delay(30);
  distance = calculateDistance();
  Serial.print("Angle: ");
  Serial.print(val);
  Serial.print(", ");
  Serial.print(("Distance: "));
  Serial.print(distance);
  Serial.print(".");
  Serial.println("");
}

int calculateDistance(){   
  digitalWrite(ULTRA_SENSOR_TRIGGER_PIN, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(ULTRA_SENSOR_TRIGGER_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(ULTRA_SENSOR_TRIGGER_PIN, LOW);
  duration = pulseIn(ULTRA_SENSOR_ECHO_PIN, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration*0.034/2;
  return distance;
}