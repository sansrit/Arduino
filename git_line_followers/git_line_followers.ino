// use 4 motors wires to pin  4, 5, 6, 7 
const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;

//use it as enable pin on motor driver.
const int ENA = 3;
const int ENB = 11;



void setup() {
  Serial.begin(9600);
  //connect 3 lines ir sensor to pin 8,9 ,10.
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  
  
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

  
}

void loop() {
 Serial.print("IRL ");
 Serial.print(digitalRead(8));
 Serial.print("   IRC");
 Serial.print(digitalRead(9));
 Serial.print("   IRR");
 Serial.println(digitalRead(10));

 if(digitalRead(8)== 1 && digitalRead(9)==0 && digitalRead(10) == 1){

  forward();
 }
 else if(digitalRead(8)== 0 && digitalRead(9)==1 && digitalRead(10) == 1){
 
  left();
 }
 
  else if(digitalRead(8)== 1 && digitalRead(9)==1 && digitalRead(10) == 0){

  right();
 }

 else if(digitalRead(8)== 0 && digitalRead(9)== 0 && digitalRead(10) == 0){
  chup();
 }
 
 
 


  


}

void forward(){
      Serial.println("forward");
      //calibrate enable values as per you battery performance.
      analogWrite(ENA, 100);
      analogWrite(ENB, 100); 
                      digitalWrite(IN1, LOW);
                      digitalWrite(IN2, HIGH);
                      digitalWrite(IN3, LOW);
                      digitalWrite(IN4, HIGH);
  }

 void left(){
      
      Serial.println("left");
      analogWrite(ENA, 110);
      analogWrite(ENB, 110);
                  

                      digitalWrite(IN1, HIGH);
                      digitalWrite(IN2, LOW);
                      digitalWrite(IN3, HIGH);
                      digitalWrite(IN4, HIGH);
                     
  }

   void right(){
      
      Serial.println("right");
      analogWrite(ENA, 110);
      analogWrite(ENB, 110); 

                    digitalWrite(IN1, LOW);
                    digitalWrite(IN2, LOW);
                    digitalWrite(IN3, HIGH);
                    digitalWrite(IN4, LOW);
                    
                      
  }

    void chup(){
      Serial.println("stop");
                      digitalWrite(IN1, LOW);
                      digitalWrite(IN2, LOW);
                      digitalWrite(IN3, LOW);
                      digitalWrite(IN4, LOW);
  }

  
