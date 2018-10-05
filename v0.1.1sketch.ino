//Ultraschallsensor basis code
//Arduino Uno + ultraschallsensor hc-sr04 + piezo lautsprecher
int trigger=7;
int echo=6;
int piezo=5;         
long dauer=0;
long entfernung=0;

int notes[] = {262,294,330,349,500}; // eine tonfrequenz von 1-1023

void setup()

{

Serial.begin (9600);

pinMode(trigger, OUTPUT);

pinMode(echo, INPUT);

pinMode(piezo, OUTPUT); //Der Piezo-Lautsprecher an Pin5 soll ein Ausgang sein (Logisch, weil der ja vom Mikrokontroller-Board ja eine Spannung benötigt um zu piepsen. 

}

void loop()

{
  
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

}

else

{

Serial.print(entfernung);

Serial.println(" cm");

}
//Es wird eine weitere IF-Bedingung erstellt: 
 
if (entfernung <= 5)//Wenn der Wert für die Entfernung unter oder gleich 5cm ist, dann...  (kürzere distanzen können mit empfindlicheren sensoren erreicht werden hier geht es runter bis 3 cm)
{
    tone(piezo, notes[4]); // gebe ton 5 wieder
}

else if (entfernung <= 10)//Wenn der Wert für die Entfernung unter oder gleich 10cm ist, dann...  
{
    tone(piezo, notes[3]); // gebe ton 4 wieder
}

else if (entfernung <= 15)//Wenn der Wert für die Entfernung unter oder gleich 15cm ist, dann...  
{
    tone(piezo, notes[2]); // gebe ton 3 wieder
}

else if (entfernung <= 20)//Wenn der Wert für die Entfernung unter oder gleich 20cm ist, dann...  
{
    tone(piezo, notes[1]); // gebe ton 2 wieder
}

else if (entfernung <= 25)//Wenn der Wert für die Entfernung unter oder gleich 25cm ist, dann...  
{
    tone(piezo, notes[0]); // gebe ton 1 wieder
}

else  //Und wenn das nicht so ist... 
{
noTone(piezo); //Es soll kein Ton wieder gegeben werden.
}

delay(500);
}
