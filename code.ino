# Obstacle Detection & Avoidance 

int trigPin = 6;
int echoPin = 5;
int buzzer = 7;

long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);         
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  distance = duration / 58.2; // distance in cm
  Serial.print(distance);
  Serial.println(" CM");

  // Object handling logic
  if (distance > 15) {
    digitalWrite(buzzer, HIGH);  // Turn on the buzzer if distance is greater than 15 cm
  } else {
    digitalWrite(buzzer, LOW);   // Turn off the buzzer if distance is 15 cm or less
  }

  delay(10);  // Small delay to avoid flooding the serial monitor
}
