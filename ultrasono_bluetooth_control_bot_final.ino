#define trigPin 11
#define echoPin 12
int ultrasono(int duration, int distance);
long distance,duration;
String voice;
int motor1Pin1 = 3; // pin 2 on L293D IC
int motor1Pin2 = 4; // pin 7 on L293D IC
int motor2Pin1 = 8; // pin 10 on L293D IC
int motor2Pin2 = 9; // pin 15 on L293D IC
void forward(){
     digitalWrite(motor1Pin1, HIGH);
     digitalWrite(motor1Pin2, LOW);
     digitalWrite(motor2Pin1, HIGH);
     digitalWrite(motor2Pin2, LOW);}
void stop(){
     digitalWrite(motor1Pin1, LOW);
     digitalWrite(motor1Pin2, LOW);
     digitalWrite(motor2Pin1, LOW);
     digitalWrite(motor2Pin2, LOW);}
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);}
void loop() {
distance=ultrasono(duration,distance);
if(distance <= 20)
{   stop();
    digitalWrite(led1, HIGH);}
  else{ forward();
    digitalWrite(led1, LOW);}
    delay(50);
    while (Serial.available()) 
    //Check if there is an available byte to read
  {delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit loop when # is after word
  voice += c;} //Shorthand for voice = voice + c
  if (voice.length() > 0) {
  Serial.println(voice);
  if(voice == "*forward")
  {digitalWrite(motor1Pin1,HIGH);digitalWrite(motor2Pin1,HIGH);
  digitalWrite(motor1Pin2,LOW);digitalWrite(motor2Pin2,LOW);delay(1000);}
  else if(voice == "*left") 
  {digitalWrite(motor1Pin2,LOW);digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor1Pin1,HIGH);digitalWrite(motor2Pin2,LOW);
  delay(3200);stop();}
  else if(voice == "*right") 
  {digitalWrite(motor1Pin1,LOW);digitalWrite(motor2Pin2,LOW);
  digitalWrite(motor1Pin2,LOW);digitalWrite(motor2Pin1,HIGH);
  delay(3200);stop();}
  else if(voice == "*back") 
  {digitalWrite(motor2Pin2,HIGH);digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor1Pin1,LOW);digitalWrite(motor2Pin1,LOW);delay(2000);}
  else if(voice == "*stop") 
  {digitalWrite(motor2Pin2, LOW);digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin1, LOW);digitalWrite(motor2Pin1, LOW);delay(10000);}
  voice="";}}
int ultrasono(long duration, long distance)
{ digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}
