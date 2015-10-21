#include <IRremote.h>
#include <IRremoteInt.h>
#include <SPI.h>
#include "RF24.h"

// --------------------------------------------------------------------------- Motors
int motor_left[] = {5, 6};
int motor_right[] = {7, 8};
int currentAction = 0;
// --------------------------------------------------------------------------- Setup
RF24 radio(9,10);
byte addresses[][6] = {"1Node","2Node"};

int redPin =19;
int greenPin = 18;
int bluePin = 17;
int isDead = 0;
int numHits = 0;
int maxHits = 5;

const int RECV_PIN = 2;
uint16_t lastCode = 0; // This keeps track of the last code RX'd

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;
void setup() {
  Serial.begin(57600);
  
  radio.begin();
  radio.setRetries(15,15);
  
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1,addresses[1]);
  radio.startListening();
  //radio.printDetails();

  // Setup motors
  int i;
  for(i = 0; i < 2; i++){
  pinMode(motor_left[i], OUTPUT);
  pinMode(motor_right[i], OUTPUT);
  }
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Everything enabled...receiving data and ir codes.");
}

// --------------------------------------------------------------------------- Loop
void loop() {

  if (numHits<maxHits)
  {
  
    int myData;
    
    if( radio.available()){
                                                                    // Variable for the received timestamp
      while (radio.available()) {                                   // While there is data ready
        radio.read( &myData, sizeof(int) );             // Get the payload
      }
     
      //radio.stopListening();                                        // First, stop listening so we can talk   
      //radio.write( &got_time, sizeof(unsigned long) );              // Send the final one back.      
      //radio.startListening();      // Now, resume listening so we catch the next packets.     
      Serial.print("Got ");
      Serial.println(myData);       
     }
   
     if (irrecv.decode(&results)) 
      {
        /* read the RX'd IR into a 16-bit variable: */
        uint16_t resultCode = (results.value & 0xFFFF);
    
        /* The remote will continue to spit out 0xFFFFFFFF if a 
         button is held down. If we get 0xFFFFFFF, let's just
         assume the previously pressed button is being held down */
        if (resultCode == 0xFFFF)
          resultCode = lastCode;
        else
          lastCode = resultCode;
      
        switch (resultCode)
        {
          case 0xB92:
            Serial.println("Hit");
            numHits++;
            setColor(255, 153, 204);  
            delay(500);
            break;
          case 0x20DF22DD:
            Serial.println("Hitremote");
            numHits++;
            setColor(255, 153, 204);
            delay(500);
            break; 
          
          default:
            Serial.print("Unrecognized code received: 0x");
            Serial.println(results.value, HEX);
            break;        
        }    
      
        irrecv.resume(); // Receive the next value
      }
  
      switch (myData) {
        case 1:
          Serial.println("Forward");
          drive_forward();
          delay(500);
          break;
        case 2:
          Serial.println("Back");
          drive_backward();
          delay(500);
          break;
        case 3:
          Serial.println("Left");
          turn_left();
          delay(500);
          break;
        case 4:
          Serial.println("Right");
          turn_right();
          delay(500);
          break;
        case 5:
          Serial.println("Stop");
          motor_stop();
          delay(500);
          break;
        case 6:
          Serial.println("FIRE");
          irsend.sendSony(0xa90, 12); 
          irrecv.enableIRIn();
          setColor(0,255,0);
          delay(500);
          break;  
        default:  
          break;        
      }
    ledupdate(numHits);
  }
  else
  {
    if (isDead==0)
    {
      isDead=1;
       Serial.println("Dead");
    }
   //game over
   setColor(255,0,0);
   delay(500);
   setColor(0,0,0);
   delay(500);

  }
}

// --------------------------------------------------------------------------- Drive



void motor_stop(){
    digitalWrite(motor_left[0], LOW);
    digitalWrite(motor_left[1], LOW);

    digitalWrite(motor_right[0], LOW);
    digitalWrite(motor_right[1], LOW);
    delay(25);
}

void turn_right(){
    digitalWrite(motor_left[0], HIGH);
    digitalWrite(motor_left[1], LOW);

    digitalWrite(motor_right[0], HIGH);
    digitalWrite(motor_right[1], LOW);
}

void turn_left(){
    digitalWrite(motor_left[0], LOW);
    digitalWrite(motor_left[1], HIGH);

    digitalWrite(motor_right[0], LOW);
    digitalWrite(motor_right[1], HIGH);
}

void drive_forward(){
    digitalWrite(motor_left[0], LOW);
    digitalWrite(motor_left[1], HIGH);

    digitalWrite(motor_right[0], HIGH);
    digitalWrite(motor_right[1], LOW);
}

void drive_backward(){
    digitalWrite(motor_left[0], HIGH);
    digitalWrite(motor_left[1], LOW);

    digitalWrite(motor_right[0], LOW);
    digitalWrite(motor_right[1], HIGH);
}


void setColor(int red, int green, int blue)
{
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);  
}

void ledupdate(int numHits) {
   switch (numHits) {
     case 0: 
        setColor(0,0,255);
        break;
     case 1:
        setColor(30,144,128);
        break;
      case 2:
        setColor(255,0,255);
        break;
      case 3:
        setColor(173,216,230);
        break;
      case 4:       
        setColor(255,255,255);
        break;
      case 5:
        setColor(255,128,0);
        break;
      default:  
        setColor(0,0,0);
        break;        
    }
}
