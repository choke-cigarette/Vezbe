#ifndef SLIKA_H_INCLUDED
#define SLIKA_H_INCLUDED
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cstring>

class Slika{
    private:
        Slika *prosla, *sledeca;
        FILE *fajl;
    public:
        Slika();
        Slika(FILE *&);
        Slika(Slika *&);
        Slika* getProsla()const;
        Slika* getSledeca()const;
        FILE* getFajl()const;
        void setProsla(Slika *&);
        void setSledeca(Slika *&);
        void setFajl(FILE *&);
        void dodajSliku(FILE *&);
        void izbrisiSliku();
};

Slika::Slika(){
    prosla = this;
    sledeca = nullptr;
    fajl = nullptr;
}

Slika::Slika(FILE *&f){
    prosla = this;
    sledeca = nullptr;
    fajl = f;
}

Slika::Slika(Slika *&s){
    prosla = new Slika;
    sledeca = new Slika;
    prosla = s->prosla;
    sledeca = s->sledeca;
    fajl = s->fajl;
}

Slika* Slika::getProsla()const{
    return prosla;
}

Slika* Slika::getSledeca()const{
    return sledeca;
}

FILE* Slika::getFajl()const{
    return fajl;
}

void Slika::setProsla(Slika *&p){
    prosla = p;
}

void Slika::setSledeca(Slika *&s){
    sledeca = s;
}

void Slika::setFajl(FILE *&f){
    fajl = f;
}

void Slika::dodajSliku(FILE *&f){
    Slika *pok = this;
    while(pok->sledeca != nullptr){
        pok = pok->sledeca;
    }
    pok->sledeca = new Slika(f);
    pok->sledeca->prosla = pok;
    pok->sledeca->sledeca = nullptr;
    this->prosla = pok->sledeca;
}

void Slika::izbrisiSliku(){
    if(this->sledeca == nullptr){
        delete this;
        return;
    }
    Slika *pok = this;
    while(pok->sledeca != nullptr){
        pok = pok->sledeca;
    }
    pok = pok->prosla;
    delete pok->sledeca;
    pok->sledeca = nullptr;
    this->prosla = pok;
}

#endif // SLIKA_H_INCLUDED
