
#include "pitches.h"
int trigPin=11;
//int trigPin=2;//D4
//int echoPin=0;//D3
int echoPin=12;
const int buzzer = 9; //buzzer to arduino pin 9

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4,NOTE_G4,NOTE_F4,
  NOTE_C4, NOTE_C4,NOTE_C5,NOTE_A4,NOTE_F4, NOTE_E4,NOTE_D4,
  NOTE_AS4,NOTE_AS4,NOTE_A4,NOTE_F4,NOTE_G4,NOTE_F4,
   NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4,NOTE_G4,NOTE_F4,
  NOTE_C4, NOTE_C4,NOTE_C5,NOTE_A4,NOTE_F4, NOTE_E4,NOTE_D4,
  NOTE_AS4,NOTE_AS4,NOTE_A4,NOTE_F4,NOTE_G4,NOTE_F4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4,2,2,2,2,
   4, 4,2,2,2,2,
    4, 4,2,2,2,2,2,
     4, 4,2,2,2,2,
     4, 4,2,2,2,2,
   4, 4,2,2,2,2,
    4, 4,2,2,2,2,2,
     4, 4,2,2,2,2
};

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
while(true){
    digitalWrite(trigPin,HIGH);//setting trigPin High to move sound wave towards object
  delay(2000);
  digitalWrite(trigPin,LOW);
long duration=pulseIn(echoPin,HIGH);
  long distance=duration*0.034/2;//converting speed of sound 340m/s into cm/microsec

  Serial.print("Distance is:");//in cm
  /*if(distance<=40)//since a ultasonic can capture only between 5cm to 40cm
  {*/
    Serial.print(distance);
  /*}
  else
    Serial.print("Distance is out of range");//in cm*/
 if (distance>7 && distance<200){
 
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 52; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
                          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration +50;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzer);

  }

 }
   }
}


void loop() {
  // no need to repeat the melody.
}
