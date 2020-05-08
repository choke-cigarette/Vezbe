#ifndef PUTOVANJE_H_INCLUDED
#define PUTOVANJE_H_INCLUDED
#include <iostream>
#include "list.hpp"
#include "avionskaKarta.h"

using namespace std;


class Putovanje{
    private:
        DinString nazivPutovanja;
        int maksimalnaCena;
        List<AvionskaKarta> karte;
    public:
        Putovanje();
        Putovanje(DinString, int, List<AvionskaKarta>);
        DinString getNaziv()const;
        int getMaksimalnaCena()const;
        bool dodajKartu(AvionskaKarta&);
        void izbaciKartu(int);
        void ispisi()const;
};

Putovanje::Putovanje() : nazivPutovanja(), karte(){
    maksimalnaCena = 0;
}

Putovanje::Putovanje(DinString n, int maks, List<AvionskaKarta> k){
    nazivPutovanja = n;
    maksimalnaCena = maks;
    karte = k;
}

DinString Putovanje::getNaziv()const{
    return nazivPutovanja;
}

int Putovanje::getMaksimalnaCena()const{
    return maksimalnaCena;
}

bool Putovanje::dodajKartu(AvionskaKarta &a){

}

void Putovanje::izbaciKartu(int b){
    karte.remove(b);
}

void Putovanje::ispisi()const{
    cout << "Maksimalna cena putovanja: " << maksimalnaCena << endl;
    cout << "Naziv putovanja: ";
    cout << nazivPutovanja;
    cout << endl;
    cout << "Broj karti: " << karte.size() << endl;
    for(short i = 1; i < karte.size(); i++){
        AvionskaKarta b;
        karte.read(i, b);
        if(b.jeftinaKarta()){
            b.ispisi();
        }
    }
}


#endif // PUTOVANJE_H_INCLUDED
