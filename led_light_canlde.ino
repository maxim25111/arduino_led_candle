
const int pin = 10;
long dom;
long random_time;
int difer_time();

void setup() {
  pinMode(pin, OUTPUT);
  randomSeed(analogRead(A3));
  Serial.begin(9600);
}

int min_led = 200;
int max_led = 1024;

void loop() {
  dom = random(min_led, max_led); // random number to shine led
  random_time = difer_time(dom); // convert stranght to time
  analogWrite(pin, dom); // set pin to value PWM
  delay(random_time); // set delay depending of the stranght

}

int difer_time(int s){
  int a, b, wait;
  
  b = map(s, min_led, max_led, 1, 100); // remap stranght to 100%
  // 3 stages of random speed. If more light then longer delay
  if (b > 80){
    wait = random(80, 100);
  }
  else if (b > 20 && b < 60){
    wait = random(20, 80);
  }
  else{
    wait = random(1, 20); // led almost turned of, time very short.
  }
  
  Print(80); Print(40); Print(20); // print base line
  Print(b); Print(wait); Print(s); // print values to the screen
  Serial.println(""); // make new line.

  return wait;
}

void Print(int d){
  // print function is alowing make code above shorter
  Serial.print(d); Serial.print(" ");
}
