#define enA 10     // Enable1 L293 Pin enA 
#define in1 9      // Motor1 L293 Pin in1 
#define in2 8      // Motor1 L293 Pin in2 
#define in3 7      // Motor2 L293 Pin in3 
#define in4 6      // Motor2 L293 Pin in4 
#define enB 5      // Enable2 L293 Pin enB 
#define R_S A1     // IR sensor Right
#define L_S A0     // IR sensor Left

void setup() { 
    Serial.begin(9600);
    pinMode(R_S, INPUT); 
    pinMode(L_S, INPUT); 
    pinMode(enA, OUTPUT); 
    pinMode(in1, OUTPUT); 
    pinMode(in2, OUTPUT); 
    pinMode(in3, OUTPUT); 
    pinMode(in4, OUTPUT); 
    pinMode(enB, OUTPUT);
    digitalWrite(enA, HIGH); 
    digitalWrite(enB, HIGH); 
    delay(1000);
}

void loop() {
    int rightSensor = digitalRead(R_S);
    int leftSensor = digitalRead(L_S);

    if (rightSensor == 0 && leftSensor == 0) {
        forward();   // Both sensors on white
    } 
    else if (rightSensor == 1 && leftSensor == 0) {
        turnRight(); // Right sensor on black, left on white
    } 
    else if (rightSensor == 0 && leftSensor == 1) {
        turnLeft();  // Right sensor on white, left on black
    } 
    else if (rightSensor == 1 && leftSensor == 1) {
        Stop();      // Both sensors on black
    }
}

void forward() {  
    analogWrite(enA, 180);
    analogWrite(enB, 180);
    analogWrite(in1, 120);  // Right Motor forward Pin 
    analogWrite(in2, 0);    // Right Motor backward Pin 
    analogWrite(in3, 128);  // Left Motor forward Pin 
    analogWrite(in4, 0);    // Left Motor backward Pin 
    Serial.println("forward");
}

void turnRight() {
    analogWrite(enA, 180);
    analogWrite(enB, 180);
    analogWrite(in1, 0);    // Right Motor forward Pin 
    analogWrite(in2, 0);    // Right Motor backward Pin 
    analogWrite(in3, 0);    // Left Motor forward Pin 
    analogWrite(in4, 120);  // Left Motor backward Pin 
    Serial.println("turn right");
}

void turnLeft() {
    analogWrite(enA, 180);
    analogWrite(enB, 180);
    analogWrite(in1, 0);    // Right Motor forward Pin 
    analogWrite(in2, 128);  // Right Motor backward Pin  
    analogWrite(in3, 0);    // Left Motor forward Pin 
    analogWrite(in4, 0);    // Left Motor backward Pin 
    Serial.println("turn left");
}

void Stop() {
    analogWrite(enA, 180);
    analogWrite(enB, 180);
    analogWrite(in1, 0);    // Right Motor forward Pin 
    analogWrite(in2, 0);    // Right Motor backward Pin 
    analogWrite(in3, 0);    // Left Motor forward Pin 
    analogWrite(in4, 0);    // Left Motor backward Pin 
    Serial.println("stop");
}
