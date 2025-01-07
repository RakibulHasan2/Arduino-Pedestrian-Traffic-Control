// Traffic Light Control with Pedestrian Crossing
const int RED_PIN = 8;       // Traffic Red LED
const int YELLOW_PIN = 9;    // Traffic Yellow LED
const int GREEN_PIN = 10;    // Traffic Green LED
const int PED_LED_PIN = 5;   // Pedestrian Walk LED
const int BUTTON_PIN = 2;    // Button Pin

bool pedestrianActive = false;  // Flag to track pedestrian crossing

void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(PED_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor
}

void loop() {
    // Check if pedestrian button is pressed
    if (digitalRead(BUTTON_PIN) == LOW) { // Button pressed
        pedestrianActive = true;   
        pedestrianCrossing();
        pedestrianActive = false;             // Set pedestrian crossing flag
    }
    digitalWrite(RED_PIN, HIGH);    // Traffic Red ON
    digitalWrite(YELLOW_PIN, LOW);  // Ensure Yellow is OFF
    digitalWrite(GREEN_PIN, LOW);   // Ensure Green is OFF
    delay(5000);   
    // Check if pedestrian button is pressed
    if (digitalRead(BUTTON_PIN) == LOW) { // Button pressed
        pedestrianActive = true;   
        pedestrianCrossing();
        pedestrianActive = false;             // Set pedestrian crossing flag
    }
    digitalWrite(RED_PIN, LOW);     // Traffic Red OFF
    digitalWrite(GREEN_PIN, HIGH);  // Traffic Green ON
    delay(5000);
    // Check if pedestrian button is pressed
    if (digitalRead(BUTTON_PIN) == LOW) { // Button pressed
        pedestrianActive = true;   
        pedestrianCrossing();
        pedestrianActive = false;             // Set pedestrian crossing flag
    }
    digitalWrite(GREEN_PIN, LOW);   // Traffic Green OFF
    digitalWrite(YELLOW_PIN, HIGH); // Traffic Yellow ON
    delay(2000);                    // Wait 2 seconds
    digitalWrite(YELLOW_PIN, LOW);
}


// Pedestrian Crossing Sequence
void pedestrianCrossing() {
    // Turn on pedestrian crossing lights
    digitalWrite(RED_PIN, HIGH);       // Traffic Red ON
    digitalWrite(GREEN_PIN, LOW);      // Traffic Green OFF
    digitalWrite(YELLOW_PIN, LOW);     // Traffic Yellow OFF
    digitalWrite(PED_LED_PIN, HIGH);   // Pedestrian Walk Light ON
    delay(5000);                       // Wait 5 seconds for crossing

    // Turn off pedestrian lights and resume normal cycle
    digitalWrite(PED_LED_PIN, LOW);    // Pedestrian Walk Light OFF
}
