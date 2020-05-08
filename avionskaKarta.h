#ifndef AVIONSKAKARTA_H_INCLUDED
#define AVIONSKAKARTA_H_INCLUDED
#include <iostream>
#include "karta.h"

using namespace std;

class AvionskaKarta : Karta{
    public:
        void ispisi()const;
        virtual bool jeftinaKarta();
};

void AvionskaKarta::ispisi()const{
    cout << "Mesto polaska: ";
    cout << mestoPolaska;
    cout << endl;
    cout << "Mesto dolaska: ";
    cout << mestoDolaska;
    cout << endl;
    cout << "Duzina putovanja: " << duzinaPutovanja << endl;
    cout << "Cena karte: " << cenaKarte << endl;
    cout << "Identifikator karte: " << identifikatorKarte << endl;
}

bool AvionskaKarta::jeftinaKarta(){
    if(cenaKarte / duzinaPutovanja < 1){
        return true;
    }
    return false;
}


#endif // AVIONSKAKARTA_H_INCLUDED
