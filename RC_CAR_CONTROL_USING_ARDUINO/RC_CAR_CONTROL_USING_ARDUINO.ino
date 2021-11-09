char t;

void setup() {
pinMode(9,OUTPUT); //left motors forward
pinMode(8,OUTPUT); //left motors reverse
pinMode(7,OUTPUT); //right motors forward
pinMode(6,OUTPUT); //right motors reverse
pinMode(5,OUTPUT); //Enable motor

pinMode(10,OUTPUT); //Motor 1
//pinMode(9,OUTPUT); //Led
Serial.begin(9600);
digitalWrite(5,HIGH);
digitalWrite(10,HIGH);




}

void loop() {
if(Serial.available()){
t = Serial.read();
Serial.println(t);
}

if(t == 'F'){ //move forward(all motors rotate in forward direction)
digitalWrite(9,HIGH);
digitalWrite(7,HIGH);
}

else if(t == 'B'){ //move reverse (all motors rotate in reverse direction)
digitalWrite(8,HIGH);
digitalWrite(6,HIGH);
}

else if(t == 'L'){ //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
digitalWrite(7,HIGH);
}

else if(t == 'R'){ //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
digitalWrite(9,HIGH);
}




else if(t == 'S'){ //STOP (all motors stop)
digitalWrite(9,LOW);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
}
delay(100);
}
