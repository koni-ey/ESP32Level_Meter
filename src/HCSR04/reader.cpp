#include "reader.h"


int empty = 30;
int full = 5;
queue<double> myqueue;


void readD();

void reader::init(){
    pinMode(TRIGGER, OUTPUT);
    pinMode(ECHO, INPUT);
    digitalWrite(TRIGGER, HIGH); //Signal abschalten
}

String reader::getDistance(){
    readD();
    double distance = 0;
    for(int i = 0; i < myqueue.size(); i++){
        distance += 1/myqueue.size() * myqueue.front();
        myqueue.pop();
    }
    distance = round(distance);
    return (String)distance + "cm";
}

String reader::getLevel(){
    readD();
    double distance = 0;
    for(int i = 0; i < myqueue.size(); i++){
        distance += 1/myqueue.size() * myqueue.front();
        myqueue.pop();
    }
    distance = round(distance);
    double level = 1 - (full - distance) / (full - empty);
    level *= 100;
    if(level > 100){
        return "Leeren!!";
    } else if(level <= 0){
        return "Zubba!";
    } else{
       return (String)level + "%"; 
    }
}

void readD(){
    double entfernung=0;
    double zeit=0;

    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(3);
    noInterrupts();
    digitalWrite(TRIGGER, HIGH); //Trigger Impuls 10 us
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);
    zeit = pulseIn(ECHO, HIGH); // Echo-Zeit messen
    interrupts();
    zeit = (zeit/2); // Zeit halbieren
    entfernung = zeit / 29.1; // Zeit in Zentimeter umrechnen
    if(entfernung > 300){
        entfernung = 0;
    }
    if(myqueue.size() <= 5){
        myqueue.push(entfernung);
    } else{
        myqueue.push(entfernung);
        myqueue.pop();
    }
}