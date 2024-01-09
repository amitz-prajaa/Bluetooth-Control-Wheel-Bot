 #include<SoftwareSerial.h>

/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial BT(12 , 14); /* (Rx,Tx) */ 
String readdata;

int m1a=2;
int m1b=4;

int m2a=6;
int m2b=8;

int buzzer = 22;



void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);
  Serial.begin(9600);
  Serial.println("Bluetooth Started! Ready to pair...");
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);

pinMode(buzzer , OUTPUT);
}

void horn(){
  digitalWrite(buzzer , 1);
  delay(1000);
  digitalWrite(buzzer , 0);
}
void moveForward() {
  // Code to make the robot move forward
    digitalWrite(m1a, HIGH);    // motor 1 forward
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);    // motor 2 forward
    digitalWrite(m2b, LOW);
}

void moveBackward() {
  // Code to make the robot move backward
    digitalWrite(m1a, LOW);    // Backward
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);   
    digitalWrite(m2b, HIGH);
}

void turnLeft() {
  // Code to make the robot turn left
      digitalWrite(m1a, LOW);    // LEFT
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);   
      digitalWrite(m2b, LOW);
}

void turnRight() {
  // Code to make the robot turn right
      digitalWrite(m1a, HIGH);    // Right
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);   
      digitalWrite(m2b, LOW);
    
}

void stopMoving() {
  // Code to stop the robot
    digitalWrite(m1a, LOW);    // Stop
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);    
    digitalWrite(m2b, LOW);
}
void allDirection() {
  // Code to rotate 360 degree the robot
      digitalWrite(m1a, HIGH);    // 360 rotation
digitalWrite(m1b, LOW);
digitalWrite(m2a, LOW);    
digitalWrite(m2b, HIGH);
}


void loop() {

  while (BT.available())
  {
    delay(10);
    char c = BT.read();
    readdata += c;
  }
  
  if (readdata.length() > 0)
  {
    Serial.print("data=");
    Serial.print(readdata);
    Serial.println("");
    
    if (readdata == "F") {
      moveForward();
    }

    if (readdata == "U") {
      moveBackward();
    }

    if (readdata == "S") {
      stopMoving();
    }
    if (readdata == "L") {
      turnLeft();
    }
    if (readdata == "R") {
      turnRight();
    }
    if (readdata == "AA") {
      allDirection();
    }
    if(readdata == "SvS"){
      horn();
    }
    
    readdata = "";
  }
}
 
