# Proiect individual - Monitorizarea umiditatii aerului - Moldovan Bogdana Maria 235/1

## Project Description

Proiectul consta in monitorizarea nivelului de umiditate a aerului folosind o placuta Arduino UNO, un modul senzor de temperatura si umiditate DHT 11 si doua leduri. Valorile umiditatii sunt actualizate in fiecare secunda. O umiditate cu valoare mai mare de 65% determina luminarea unui led de culoare rosie, iar o umiditate cu valoare mai mica de 65% determina luminarea unui led de culoare verde.

## Schematics

![Schema](https://user-images.githubusercontent.com/100224995/230779901-2059ca1a-ccff-427f-be10-88869323588e.png)

## Pre-requisites
### Componente hardware
1 x placuta Arduino UNO  [Arduino Uno.pdf](https://github.com/at-cs-ubbcluj-ro/individual-project-mbir2969/files/11178687/Arduino.Uno.pdf)            
7 x fire tata-tata  
2 x LED-uri de 5 mm 
1 x modul senzor de umiditate DHT11         [DHT11-Datasheet.pdf](https://github.com/at-cs-ubbcluj-ro/individual-project-mbir2969/files/11178689/DHT11-Datasheet.pdf)   
1 x cablu USB 3.0 la USB B de conectare la o sursa de energie     
1 x breadboard cu 400 puncte     
2 x rezistente de 10k ohmi      

### Componente software
Arduino IDE https://www.arduino.cc/en/software

## Setup and Build
### Configurare hardware
Montajul se realizeaza urmand uramtorii pasi:
  1. se plaseaza pe breadbroard senzorul de umiditate
  2. se plaseaza pe breadboard cele doua leduri si cate o rezistenta in fata fiecaruia
  3. se face conexuinea dintre senzor si placa Arduino in urmatorul mod:                
          a. pinul VCC (+) al senzorului se conecteaza cu pinul 5V al placii                          
          b. pinul GND (-) al senzorului se conecteaza cu pinul GND al placii                            
          c. pinul Signal al senzorului se conecteaza cu pinul 7 digital al placii                         
  4. se face conexiunea dintre leduri si placa Arduino in urmatorul mod:                             
          a. pinul Anod (+) al ledului se conecteaza la pinul 12 digital al placii                          
          b. pinul Catod (-) al ledului se conecteaza la pinul GND al placii                               
  5. se face conexiunea dintre placuta si laptop folosind cablul de alimentare USB 3.0 la USB B                   

### Configurare software
Pentru scrierea codului s-a folosit Arduino IDE in care am setat ca ca port COM4 si ca board de lucru placuta Arduino Uno pe care am folosit-o. Codul este prezentat si specificat in sectiunea "Cod Arduino". Ca sa se poata dispuna de biblioteca C dht.h pentru lucrul cu senzorul de umiditate se dezarhiveaza folderul din arhiva [DHTLib.zip](https://github.com/at-cs-ubbcluj-ro/individual-project-mbir2969/files/11178698/DHTLib.zip). Acest folder care contine fisierele dht.h si dht.c se adauga in C:\Users\YOURUSERNAME\OneDrive\Documente\Arduino\libraries. 

## Running
Pentru functionarea montajului, codul este compilat in Arduino IDE, apoi este incarcat pe placuta. In momentul incarcarii, ledurile placutei se sting si aprind in mod alert. Dupa incarcare se poate urmari in Serial Monitor (accesat din coltul dreapta sus al mediului de dezvoltare Arduino IDE) valoarea umiditatii aerului actualizata la fiecare secunda. Fiecare valoare inregistrata de senzor este procesata in felul urmator: daca umiditatea este mai mare de 65%, in Serial Monitor se afiseaza mesajul "High humidity", iar ledul rosu de pe breadboard lumineaza; daca umiditatea este mai mica sau egala cu 65%, se afieaza mesajul "Low humidity" in Serial Monitor, iar ledul verde de pe breadboard lumineaza. Fiecare dintre cele doua leduri raman aprinse cate o secunda pentru fiecare valoare. 

## Demo - Video capture


https://user-images.githubusercontent.com/100224995/230737270-34bc3df8-c30a-461d-87bc-ec5716ff655f.mp4



## Cod Arduino
```
#include <dht.h>

dht DHT;  // initializam senzorul

#define DHT11_PIN 7  // se seteaza pinul unde este conectat senzorul
int ledRosu = 3;     // se seteaza pinul unde este conectat LED-ul Rosu (LED pentru umiditate mare)
int ledVerde = 13;   // se seteaza pinul unde este conectat LED-ul Verde (LED pentru umiditate scazuta)

void setup() {
  Serial.begin(9600);         // incepe comunicarea seriala cu o rata de transmisie de 9600 de biti pe secunda
  pinMode(DHT11_PIN, INPUT);  // seteaza pinul senzorului ca fiind de intrare (INPUT)
  pinMode(ledRosu, OUTPUT);   // seteaza pinul LED-ului rosu ca fiind de iesire (OUTPUT)
  pinMode(ledVerde, OUTPUT);  // seteaza pinul LED-ului verde ca fiind de iesire (OUTPUT)
}


void loop() {
  DHT.read11(DHT11_PIN);              // citeste valorile senzorului DHT11
  Serial.print("Humidity = ");        // afiseaza mesajul "Humidity = " pe monitorul serial
  Serial.println(DHT.humidity);       // afiseaza valoarea de umiditate citita de senzor
  if (DHT.humidity > 65) {            // daca valoarea umiditatii citita este mai mare de 65
    digitalWrite(ledRosu, HIGH);      // aprinde LED-ul rosu
    delay(1000);                      // asteapta o secunda
    long time = millis();             // obtine timpul curent in milisecunde
    Serial.println("High humidity");  // afiseaza mesajul "High humidity" pe monitorul serial
    digitalWrite(ledRosu, LOW);       // stinge LED-ul rosu
  }
  if (DHT.humidity <= 65) {          // daca valoarea umiditatii citita este mai mica sau egala cu 65
    digitalWrite(ledVerde, HIGH);    // aprinde LED-ul verde
    delay(1000);                     // asteapta o secunda
    long time = millis();            // obtine timpul curent in milisecunde
    Serial.println("Low humidity");  // afiseaza mesajul "Low humidity" pe monitorul serial
    digitalWrite(ledVerde, LOW);     // stinge LED-ul verde
  }
  delay(1000);  // asteapta o secunda inainte de a repeta bucla
}
```
