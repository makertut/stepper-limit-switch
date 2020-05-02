// defines pins numbers

const int stepPin = 5;

const int dirPin = 2;

const int enPin = 8;

const int homeSwitchPin = 7;


void setup() {


   Serial.begin(9600);


  // Sets the two pins as Outputs

  pinMode(stepPin,OUTPUT);

  pinMode(dirPin,OUTPUT);

  pinMode(homeSwitchPin , INPUT);

  pinMode(enPin,OUTPUT);

  digitalWrite(enPin,LOW);



  // Set Dir to Home switch

  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction

}

void loop() {

    int homeSw = digitalRead( homeSwitchPin);

    if( homeSw == HIGH && (digitalRead(dirPin) == LOW) ){

        motorStep(1);

    }

    else if( homeSw == LOW && (digitalRead(dirPin) == LOW) ){

          digitalWrite(dirPin,HIGH);

          delay(2000);

    }



    if( (digitalRead(dirPin) == HIGH) ){

        motorStep(2000);

        digitalWrite(dirPin,LOW);

        delay(2000);

    }

 
}

void motorStep( int MAX){


   for(int x = 0; x < MAX; x++) {

        digitalWrite(stepPin,HIGH);

        delayMicroseconds(500);

        digitalWrite(stepPin,LOW);

        delayMicroseconds(500);

      }

}
