#ifndef ARTIKAL_H_INCLUDED
#define ARTIKAL_H_INCLUDED
using namespace std;
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cstring>
#include "slika.h"

class Artikal{
    private:
        Slika *slika;
        float cena, ocena;
        char *proizvodjac, *nazivArtikla;
        short akcija, brOcena, naStanju;
        bool besplatnaDostava;
        FILE *komentari;
    public:
        Artikal();
        Artikal(float, char*, char*, short, bool, bool, FILE *);
        Slika* getSlika()const;
        float getCena()const;
        float getOcena()const; //  postavice je neki izmisljeni kupci
        char* getProizvodjac()const;
        short getBrOcena()const;
        char* getNazivArtikla()const;
        short getAkcija()const;
        void ispisiKomentare()const; //  nece postojati komentari jer nema user interface-a
        bool imaLiNaStanju()const;
        bool imaLiBesplatnuDostavu()const;
        void setProizvodjac(const char*);
        void setNaziv(const char*);
        void setCena(const float);
        void setAkcija(const short);
        void setNaStanju(const short);
        void setBesplatnaDostava(const bool);
        bool kupi();
        double dodajOcenu(double);
        virtual void ispisiInfo() = 0;
};

Artikal::Artikal(){
    slika = new Slika;
    cena = 0;
    ocena = 0;
    brOcena = 0;
    proizvodjac = nullptr;
    nazivArtikla = nullptr;
    akcija = 0;
    naStanju = false;
    besplatnaDostava = false;
    komentari = nullptr;
}

Artikal::Artikal(float c, char *p, char *n, short a, bool s, bool d, FILE *f){
    slika = new Slika(f);   // nije radilo kao kompozicija : slika(f)
    cena = c;
    ocena = 0;
    brOcena = 0;
    proizvodjac = new char[strlen(p)];
    nazivArtikla = new char[strlen(n)];
    strcpy(proizvodjac, p);
    strcpy(nazivArtikla, n);
    akcija = a;
    naStanju = s;
    besplatnaDostava = d;
    komentari = nullptr;
}
    //nema konstruktora kopije jer je klasa apstraktna

Slika* Artikal::getSlika()const{
    return slika;
}

float Artikal::getCena()const{
    return cena;
}

short Artikal::getBrOcena()const{
    return brOcena;
}

float Artikal::getOcena()const{
    return ocena;
}

char* Artikal::getProizvodjac()const{
    return proizvodjac;
}

char* Artikal::getNazivArtikla()const{
    return nazivArtikla;
}

short Artikal::getAkcija()const{
    return akcija;
}

bool Artikal::imaLiNaStanju()const{
    return naStanju;
}

bool Artikal::imaLiBesplatnuDostavu()const{
    return besplatnaDostava;
}

void Artikal::setCena(const float c){
    cena = c;
}

void Artikal::setProizvodjac(const char *p){
    strcpy(proizvodjac, p);
}

void Artikal::setNaziv(const char *n){
    strcpy(nazivArtikla, n);
}

void Artikal::setAkcija(const short a){
    akcija = a;
}

void Artikal::setNaStanju(const short s){
    naStanju = s;
}

void Artikal::setBesplatnaDostava(const bool d){
    besplatnaDostava = d;
}

bool Artikal::kupi(){
    if(naStanju){
        naStanju--;
        return true;
    }
    else return false;
}

double Artikal::dodajOcenu(double o){
    o = fabs(o);
    if(o > 10){
        o = 10;
    }
    ocena = (brOcena * ocena + o) / ++brOcena;
    return ocena;
}

#endif // ARTIKAL_H_INCLUDED
