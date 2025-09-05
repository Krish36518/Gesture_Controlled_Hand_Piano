int speaker = 8;
int trig1 = 3;
int echo1 = 5;
int trig2 = 12;
int echo2 = 13;
int trig3 = 10;
int echo3 = 11;
int trig4 = 2;
int echo4 = 4;
#define NOTE_A4 261
#define NOTE_A5 329
#define NOTE_A6 523
#define NOTE_A7 392

void setup() {
  Serial.begin(9600); 
  pinMode(speaker, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig4, OUTPUT);
  pinMode(echo4, INPUT);
}

void loop() {
  int distance1, duration1, fixdistance1, s1 = 0;
  int distance2, duration2, fixdistance2, s2 = 0;
  int distance3, duration3, fixdistance3, s3 = 0;
  int distance4, duration4, fixdistance4, s4 = 0;

  // Calculate fixed distance for sensor 1
  for (int i = 0; i < 5; i++) {
    digitalWrite(trig1, LOW);
    delayMicroseconds(5);
    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig1, LOW);
    
    duration1 = pulseIn(echo1, HIGH);
    distance1 = (duration1 / 2) / 29.1;
    s1 += distance1;
    
    digitalWrite(trig2, LOW);
    delayMicroseconds(5);
    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2, LOW);
    
    duration2 = pulseIn(echo2, HIGH);
    distance2 = (duration2 / 2) / 29.1;
    s2 += distance2;
    
    digitalWrite(trig3, LOW);
    delayMicroseconds(5);
    digitalWrite(trig3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig3, LOW);
    
    duration3 = pulseIn(echo3, HIGH);
    distance3 = (duration3 / 2) / 29.1;
    s3 += distance3;
    
    
    digitalWrite(trig4, LOW);
    delayMicroseconds(5);
    digitalWrite(trig4, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig4, LOW);
    
    duration4 = pulseIn(echo4, HIGH);
    distance4 = (duration4 / 2) / 29.1;
    s4 += distance4;
    delay(5);
    
    
    
  }
  fixdistance1 = s1 / 5; 
  Serial.print("FIX DISTANCE 1 IS ");
  Serial.println(fixdistance1);

  fixdistance2 = s2 / 5; 
  Serial.print("FIX DISTANCE 2 IS ");
  Serial.println(fixdistance2);

  fixdistance3 = s3 / 5; 
  Serial.print("FIX DISTANCE 3 IS ");
  Serial.println(fixdistance3);
 
  fixdistance4 = s4 / 5; 
  Serial.print("FIX DISTANCE 4 IS ");
  Serial.println(fixdistance4);
  delay(1000);

  // Measure current distance for each sensor and check against fixed distances
  digitalWrite(trig1, LOW);
  delayMicroseconds(5);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  int duration11 = pulseIn(echo1, HIGH);
  int distance11 = (duration11 / 2) / 29.1;
  Serial.print("Distance 1 is ");
  Serial.println(distance11);

  digitalWrite(trig2, LOW);
  delayMicroseconds(5);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  int duration22 = pulseIn(echo2, HIGH);
  int distance22 = (duration22 / 2) / 29.1;
  Serial.print("Distance 2 is ");
  Serial.println(distance22);

  digitalWrite(trig3, LOW);
  delayMicroseconds(5);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  int duration33 = pulseIn(echo3, HIGH);
  int distance33 = (duration33 / 2) / 29.1;
  Serial.print("Distance 3 is ");
  Serial.println(distance33);

  digitalWrite(trig4, LOW);
  delayMicroseconds(5);
  digitalWrite(trig4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig4, LOW);
  int duration44 = pulseIn(echo4, HIGH);
  int distance44 = (duration44 / 2) / 29.1;
  Serial.print("Distance 4 is ");
  Serial.println(distance44);

  // Sound alert if distance changes by more than 3 cm
  if (distance11 < (fixdistance1 - 1)) {
    tone(speaker, NOTE_A4);
    delay(300);
    noTone(speaker);
  }


  else if (distance22 < (fixdistance2 - 1)) {
    tone(speaker, NOTE_A5);
    delay(300);
    noTone(speaker);
  }
 
  else if (distance33 < (fixdistance3 - 1)) {
    tone(speaker, NOTE_A6);
    delay(300);
    noTone(speaker);
  }
  else if (distance44 < (fixdistance4 - 1)) {
    tone(speaker, NOTE_A7);
    delay(300);
    noTone(speaker);
  }
  delay(50);
}
