#ifndef RACUNAR_H_INCLUDED
#define RACUNAR_H_INCLUDED
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "artikal.h"

enum Memorija{HDD, SSD};

class Racunar : public Artikal{
    private:
        Memorija memorija;
        short RAM, memorija_GB;
        char *graficka, *procesor, *konektori, *OS, *boja;
        bool optickiUredjaj;
    public:
        Racunar();
        Racunar(Memorija, short, short, char*, char*, char*, char*, char*, bool, float, char*, char*, short, bool, bool, FILE *);
        Racunar(Racunar &);
        Memorija getMemorija()const;
        short getGB()const;
        short getRAM()const;
        char* getGraficka()const;
        char* getProcesor()const;
        char* getKonektori()const;
        char* getOS()const;
        char* getBoja()const;
        bool daLiImaOptickiUredjaj()const;
        void setMemorija(const Memorija);
        void setGB(const short);
        void setRAM(const short);
        void setProcesor(const char*);
        void setKonektori(const char*);
        void setOS(const char*);
        void setBoja(const char*);
        void setOpticki(const bool);
        virtual void ispisiInfo() = 0;
        virtual bool gamingApproved() = 0;
};

Racunar::Racunar() : Artikal(){
    memorija = HDD;
    RAM = 0;
    memorija_GB = 0;
    graficka = nullptr;
    procesor = nullptr;
    konektori = nullptr;
    OS = nullptr;
    boja = nullptr;
    optickiUredjaj = false;
}

Racunar::Racunar(Memorija mem, short r, short gb, char* g, char* p, char* k, char* os, char* b, bool opt, float c, char *m, char *n, short a, bool s, bool d, FILE *f) : Artikal(c, m, b, a, s, d, f){
    memorija = mem;
    RAM = r;
    memorija_GB = gb;
    graficka = g;
    procesor = p;
    konektori = k;
    OS = os;
    boja = b;
    optickiUredjaj = opt;
}

Memorija Racunar::getMemorija()const{
    return memorija;
}

short Racunar::getGB()const{
    return memorija_GB;
}

short Racunar::getRAM()const{
    return RAM;
}

char* Racunar::getGraficka()const{
    return graficka;
}

char* Racunar::getProcesor()const{
    return procesor;
}

char* Racunar::getKonektori()const{
    return konektori;
}

char* Racunar::getOS()const{
    return OS;
}

char* Racunar::getBoja()const{
    return boja;
}

bool Racunar::daLiImaOptickiUredjaj()const{
    return optickiUredjaj;
}

void Racunar::setMemorija(const Memorija m){
    memorija = m;
}

void Racunar::setGB(const short gb){
    memorija_GB = gb;
}

void Racunar::setRAM(const short r){
    RAM = r;
}

void Racunar::setProcesor(const char *p){
    strcpy(procesor, p);
}

void Racunar::setKonektori(const char *k){
    strcpy(konektori, k);
}

void Racunar::setOS(const char *os){
    strcpy(OS, os);
}

void Racunar::setBoja(const char *b){
    strcpy(boja, b);
}

void Racunar::setOpticki(const bool o){
    optickiUredjaj = o;
}

#endif // RACUNAR_H_INCLUDED
