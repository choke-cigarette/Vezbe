#ifndef KARTA_H_INCLUDED
#define KARTA_H_INCLUDED
#include <iostream>
#include "dinstring.cpp"

using namespace std;


class Karta{
    protected:
        DinString mestoPolaska, mestoDolaska;
        float duzinaPutovanja, cenaKarte;
        int identifikatorKarte;
    public:
        Karta();
        Karta(DinString, DinString, float, float, int);
        virtual bool jeftinaKarta() = 0;
        DinString getMestoPolaska()const;
        DinString getMestoDolaska()const;
        float getDuzinaPutovanja()const;
        float getCenaKarte()const;
        int getIdentifikatorKarte()const;
};

Karta::Karta() : mestoPolaska(), mestoDolaska(){
    duzinaPutovanja = 0;
    cenaKarte = 0;
    identifikatorKarte = 0;
}

Karta::Karta(DinString polazak, DinString dolazak, float d, float c, int id){
    mestoPolaska = polazak;
    mestoDolaska = dolazak;
    duzinaPutovanja = d;
    cenaKarte = c;
    identifikatorKarte = id;
}

DinString Karta::getMestoPolaska()const{
    return mestoPolaska;
}

DinString Karta::getMestoDolaska()const{
    return mestoDolaska;
}

float Karta::getDuzinaPutovanja()const{
    return duzinaPutovanja;
}

float Karta::getCenaKarte()const{
    return cenaKarte;
}

int Karta::getIdentifikatorKarte()const{
    return identifikatorKarte;
}

#endif // KARTA_H_INCLUDED
