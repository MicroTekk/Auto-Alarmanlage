//Ultraschallsensor basis code
//Arduino Uno + ultraschallsensor hc-sr04 + piezo lautsprecher   
const int LEDgr =2;
const int LEDge =3;
const int LEDro =4;
const int piezo =5;
const int echo =6;
const int trigger =7;
const int LEDbl =8;
const int RGBg =9;
const int RGBb =10;
const int RGBr =11;
const int Sensor =12;
const int Led =13;      

long dauer =0;
long entfernung =0;

int notes[] = {262,294,330,349,500}; // eine tonfrequenz von 1-1023
int val;

void setup()

{

Serial.begin (9600);

pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(piezo, OUTPUT);
pinMode(LEDgr, OUTPUT);
pinMode(LEDge, OUTPUT);
pinMode(LEDro, OUTPUT);
pinMode(LEDbl, OUTPUT);
pinMode(RGBg, OUTPUT);
pinMode(RGBb, OUTPUT);
pinMode(RGBr, OUTPUT);
pinMode(Led, OUTPUT);
pinMode(Sensor, INPUT) ;
digitalWrite(Sensor, HIGH); // Aktivierung interner Pull-Up Widerstand

}

void loop()

{
  val = digitalRead(Sensor) ; // Das gegenwärtige Signal am Sensor wird ausgelesen
  
 if (val == HIGH) // Falls ein Signal erkannt werden konnte, wird die LED eingeschaltet.
 {
   digitalWrite(Led, LOW);
 }
 else
  {
    digitalWrite(Led, HIGH);
  }
digitalWrite(trigger, LOW);

delay(5);

digitalWrite(trigger, HIGH);

delay(10);

digitalWrite(trigger, LOW);

dauer = pulseIn(echo, HIGH);
entfernung = (dauer/2) * 0.03432;

if (entfernung >= 500 || entfernung <= 0)
{
Serial.println("Kein Messwert");

digitalWrite(RGBb, LOW);
digitalWrite(RGBg, HIGH);
digitalWrite(RGBr, HIGH);
}

else
{
Serial.print(entfernung);
Serial.println(" cm");
}
 
if (entfernung <= 5)//Wenn der Wert für die Entfernung unter oder gleich 5cm ist, dann...  (kürzere distanzen können mit empfindlicheren sensoren erreicht werden hier geht es runter bis 3 cm)
{
    tone(piezo, notes[4]); // gebe ton 5 wieder
    
    digitalWrite(RGBb, HIGH);
    digitalWrite(RGBg, HIGH);
    digitalWrite(RGBr, HIGH);
    digitalWrite(LEDbl, HIGH);
    digitalWrite(LEDro, HIGH);
    digitalWrite(LEDge, HIGH);
    digitalWrite(LEDgr, HIGH);
}

else if (entfernung <= 10)//Wenn der Wert für die Entfernung unter oder gleich 10cm ist, dann...  
{
    tone(piezo, notes[3]); // gebe ton 4 wieder
    digitalWrite(RGBb, LOW);
    digitalWrite(RGBg, LOW);
    digitalWrite(RGBr, LOW);
    digitalWrite(LEDbl, HIGH);
    digitalWrite(LEDro, HIGH);
    digitalWrite(LEDge, HIGH);
    digitalWrite(LEDgr, HIGH);
}

else if (entfernung <= 15)//Wenn der Wert für die Entfernung unter oder gleich 15cm ist, dann...  
{
    tone(piezo, notes[2]); // gebe ton 3 wieder
    digitalWrite(RGBb, LOW);
    digitalWrite(RGBg, LOW);
    digitalWrite(RGBr, LOW);
    digitalWrite(LEDbl, LOW);
    digitalWrite(LEDro, HIGH);
    digitalWrite(LEDge, HIGH);
    digitalWrite(LEDgr, HIGH);
}

else if (entfernung <= 20)//Wenn der Wert für die Entfernung unter oder gleich 20cm ist, dann...  
{
    tone(piezo, notes[1]); // gebe ton 2 wieder
    digitalWrite(RGBb, LOW);
    digitalWrite(RGBg, LOW);
    digitalWrite(RGBr, LOW);
    digitalWrite(LEDbl, LOW);
    digitalWrite(LEDro, LOW);
    digitalWrite(LEDge, HIGH);
    digitalWrite(LEDgr, HIGH);
}

else if (entfernung <= 25)//Wenn der Wert für die Entfernung unter oder gleich 25cm ist, dann...  
{
    tone(piezo, notes[0]); // gebe ton 1 wieder
    digitalWrite(RGBb, LOW);
    digitalWrite(RGBg, LOW);
    digitalWrite(RGBr, LOW);
    digitalWrite(LEDbl, LOW);
    digitalWrite(LEDro, LOW);
    digitalWrite(LEDge, LOW);
    digitalWrite(LEDgr, HIGH);
}

else  //Und wenn das nicht so ist... 
{
noTone(piezo); //Es soll kein Ton wieder gegeben werden.
digitalWrite(RGBb, LOW);
digitalWrite(RGBg, LOW);
digitalWrite(RGBr, LOW);
digitalWrite(LEDbl, LOW);
digitalWrite(LEDro, LOW);
digitalWrite(LEDge, LOW);
digitalWrite(LEDgr, LOW);
}
delay(500);

}
