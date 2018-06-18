












int speakerPin = 14;

int length = 28; // the number of notes

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };

int tempo = 150;

void playTone(int tone, int duration) {

for (long i = 0; i < duration * 1000L; i += tone * 2) {

   digitalWrite(speakerPin, HIGH);

   delayMicroseconds(tone);

   digitalWrite(speakerPin, LOW);

   delayMicroseconds(tone);

}

}

void playNote(char note, int duration) {

char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           

                 'c', 'd', 'e', 'f', 'g', 'a', 'b',

                 'x', 'y' };

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,

                 956,  834,  765,  593,  468,  346,  224,

                 655 , 715 };

int SPEE = 5;

// play the tone corresponding to the note name

for (int i = 0; i < 17; i++) {

   if (names[i] == note) {
    int newduration = duration/SPEE;
     playTone(tones[i], newduration);

   }

}

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
pinMode(speakerPin, OUTPUT);
pinMode(18,OUTPUT);
pinMode(19,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
 Serial.begin(9600); 

 delay(10000);
}

void loop() {
  // put your main code here, to run repeatedly: 
   float ThermistorVal = analogRead(2);
  float ThermistorTempC;
  float ThermistorTempF;
 
  ThermistorTempC = logf(10000.0 * ((1024.0 / ThermistorVal - 1)));
  //         = logf(10000.0 / (1024.0 / ThermistorVal - 1)); // for pull-up configuration
  ThermistorTempC = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * ThermistorTempC 
                    * ThermistorTempC ))* ThermistorTempC );
  ThermistorTempC = ThermistorTempC - 273.15;            // Convert Kelvin to Celcius
  if(ThermistorTempC<16){
  digitalWrite(18,LOW);
  digitalWrite(19,LOW);
  analogWrite(8,random(120)+135);
  analogWrite(9,random(120)+135);
  analogWrite(10,random(120)+135);
  analogWrite(11,random(120)+135);
  analogWrite(12,random(120)+135);
  analogWrite(13,random(120)+135);
  delay(random(100));
  
  }
  else
  {
  
     digitalWrite(18,HIGH);
  digitalWrite(19,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  
   for (int i = 0; i < length; i++) {

   if (notes[i] == ' ') {

     delay(beats[i] * tempo); // rest

   } else {

     playNote(notes[i], beats[i] * tempo);

   }

   // pause between notes

   delay(tempo);
  }
}
  
}

