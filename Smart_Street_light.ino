#define IR1 2
#define IR2 3
#define IR3 4

#define LED1 9
#define LED2 10
#define LED3 12

#define LDR A0

#define ON HIGH
#define OFF LOW

boolean isDay = true;

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(LDR, INPUT);

  // Turn off all LEDs at start
  digitalWrite(LED1, OFF);
  digitalWrite(LED2, OFF);
  digitalWrite(LED3, OFF);
}

void loop() {
  int ldrValue = analogRead(LDR);

  // Set threshold: above 700 = daytime, below 200 = night
  if (ldrValue > 700) {
    isDay = true;
  } else if (ldrValue < 200) {
    isDay = false;
  }

  if (isDay) {
    // Turn off all LEDs during daytime
    digitalWrite(LED1, ON);
    digitalWrite(LED2, ON);
    digitalWrite(LED3, ON);
  } else {
    // Nighttime behavior — IR-based control
    if (digitalRead(IR1) == HIGH) {
      digitalWrite(LED1, OFF);
      delay(500);
    } else {
      digitalWrite(LED1, ON);
    }

    if (digitalRead(IR2) == HIGH) {
      digitalWrite(LED2, OFF);
      delay(500);
    } else {
      digitalWrite(LED2, ON);
    }

    if (digitalRead(IR3) == HIGH) {
      digitalWrite(LED3, OFF);
      delay(500);
    } else {
      digitalWrite(LED3, ON);
    }
  }

  delay(100); // Small delay to stabilize the loop
}