char Incoming_value = 0;

//incase you want to control speed you can use use the motor diriver enable pins.
//const int ENA = 3;
//const int ENB = 11;
                
void setup() 
{
  Serial.begin(9600);         
  pinMode(13, OUTPUT);   

  //Connect 4 motors wire from motor driver L2n8 to 4,5,6,7

  // connect bluetooth HC05 you should maintain cross connection on tx and rx check on google images bluetooth wiring.
  //install the bluetooth controller app from playstore linked on decription below.
  
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    
    if(Incoming_value == '1') {   
      Serial.println("forward");         
      forward();
      
    }
    else if(Incoming_value == '2'){       
       
      Serial.println("backward");
      backward();
     
      
  } 
    else if(Incoming_value == '3'){       
       
      Serial.println("left");
      left();
     
      
  }   
    else if(Incoming_value == '4'){       
       
      Serial.println("right");
      right();
     
      
  }    
    else if(Incoming_value == '9'){       
       
      Serial.println("rotote");
      rotate();
     
      
  }   
  else
  stopit();                    
} 
}

 void forward(){
    Serial.println("forward");
//      analogWrite(ENA, 255);
//      analogWrite(ENB, 255); 
                      digitalWrite(4, LOW);
                      digitalWrite(5, HIGH);
                      digitalWrite(6, LOW);
                      digitalWrite(7, HIGH);
 }


 void backward(){
    Serial.println("backward");
//      analogWrite(ENA, 255);
//      analogWrite(ENB, 255); 
                      digitalWrite(4, HIGH);
                      digitalWrite(5, LOW);
                      digitalWrite(6, HIGH);
                      digitalWrite(7, LOW);
  }

  void left(){
    Serial.println("left");
//      analogWrite(ENA, 255);
//      analogWrite(ENB, 255); 
                   digitalWrite(5, LOW);
                    digitalWrite(4, HIGH);
                    digitalWrite(5, LOW);
                    digitalWrite(7, HIGH);
  }

  void right(){
    Serial.println("right");
//      analogWrite(ENA, 255);
//      analogWrite(ENB, 255); 
                   digitalWrite(5, HIGH);
                    digitalWrite(4, LOW);
                    digitalWrite(6, HIGH);
                    digitalWrite(7, LOW);
  }


 void rotate(){
    Serial.println("rotating");
//      analogWrite(ENA, 255);
//      analogWrite(ENB, 255); 
                    digitalWrite(5, LOW);
                    digitalWrite(4, HIGH);
                    digitalWrite(6, LOW);
                    digitalWrite(7, HIGH);
    
    
  }

void stopit(){
    Serial.println("stop");
                        digitalWrite(4, LOW);
                        digitalWrite(5, LOW);
                        digitalWrite(6, LOW);
                        digitalWrite(7, LOW);
   
  }
