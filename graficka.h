#ifndef GRAFICKA_H_INCLUDED
#define GRAFICKA_H_INCLUDED
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "artikal.h"

enum GrafickaMemorija{DDR, DDR2, GDDR3, GDDR4, GDDR5, GDDR5X, GDDR6};

enum TipHladjenja{PASIVNO, AKTIVNO, LIKVIDNO, HIBRIDNO};

class Graficka : public Artikal{
    private:
        GrafickaMemorija tipMemorije;
        TipHladjenja hladjenje;
        char *interfejs, *GPU, *konektor;
        short kolicinaMemorije, magistrala, brzinaMemorije, brzinaGPU, streamProcesori, VGA, DVI, HDMI, displayPort, minimalnoNapajanje;
    public:
        Graficka();
        Graficka(GrafickaMemorija, TipHladjenja, char *, char*, char*, short, short, short, short, short, short, short, short, short, short, float, char*, char*, short, bool, bool, FILE*);
        Graficka(Graficka &);
        GrafickaMemorija getTipMemorije()const;
        TipHladjenja getHladjenje()const;
        char* getInterfejs()const;
        char* getGPU()const;
        char* getKonektor()const;
        short getKolicinaMemorije()const;
        short getMagistrala()const;
        short getBrzinaMemorije()const;
        short getBrzinaGPU()const;
        short getStream()const;
        short getVGA()const;
        short getDVI()const;
        short getHDMI()const;
        short getDisplayPort()const;
        short getMinimalnoNapajanje()const;
        void setTipMemorije(GrafickaMemorija);
        void setHladjenje(TipHladjenja);
        void setInterfejs(char *);
        void setGPU(char *);
        void setKonektor(char *);
        void setKolicinaMemorije(short);
        void setMagistrala(short);
        void setBrzinaMemorije(short);
        void setBrzinaGPU(short);
        void setStream(short);
        void setVGA(short);
        void setDVI(short);
        void setHDMI(short);
        void setDisplayPort(short);
        void setMinimalnoNapajanje(short);
};

Graficka::Graficka() : Artikal(){
    tipMemorije = DDR2;
    hladjenje = AKTIVNO;
    interfejs = nullptr;
    GPU = nullptr;
    konektor = nullptr;
    kolicinaMemorije = 0;
    magistrala = 0;
    brzinaMemorije = 0;
    brzinaGPU = 0;
    streamProcesori = 0;
    VGA = 0;
    DVI = 0;
    HDMI = 0;
    displayPort = 0;
    minimalnoNapajanje = 0;
}

Graficka::Graficka(GrafickaMemorija g, TipHladjenja h, char *i, char *gpu, char *k, short m, short mag, short bm, short bg, short s,
    short v, short d, short hdmi, short dis, short n, float c, char *ma, char *na, short a, bool sa, bool da, FILE *f)
  : Artikal(c, ma, na, a, sa, da, f){
    tipMemorije = g;
    hladjenje = h;
    interfejs = i;
    GPU = gpu;
    konektor = k;
    kolicinaMemorije = m;
    magistrala = mag;
    brzinaMemorije = bm;
    brzinaGPU = bg;
    streamProcesori = s;
    VGA = v;
    DVI = d;
    HDMI = hdmi;
    displayPort = dis;
    minimalnoNapajanje = n;
}

Graficka::Graficka(Graficka &g) : Artikal(g.getCena(), g.getProizvodjac(), g.getNazivArtikla(), g.getAkcija(), g.imaLiNaStanju(), g.imaLiBesplatnuDostavu(), g.getSlika()->getFajl()){
    tipMemorije = g.tipMemorije;
    hladjenje = g.hladjenje;
    interfejs = g.interfejs;
    GPU = g.GPU;
    konektor = g.konektor;
    kolicinaMemorije = g.kolicinaMemorije;
    magistrala = g.magistrala;
    brzinaMemorije = g.brzinaMemorije;
    brzinaGPU = g.brzinaGPU;
    streamProcesori = g.streamProcesori;
    VGA = g.VGA;
    DVI = g.DVI;
    HDMI = g.HDMI;
    displayPort = g.displayPort;
    minimalnoNapajanje = g.minimalnoNapajanje;
}

GrafickaMemorija Graficka::getTipMemorije()const{
    return tipMemorije;
}

TipHladjenja Graficka::getHladjenje()const{
    return hladjenje;
}

char* Graficka::getInterfejs()const{
    return interfejs;
}

char* Graficka::getGPU()const{
    return GPU;
}

char* Graficka::getKonektor()const{
    return konektor;
}

short Graficka::getKolicinaMemorije()const{
    return kolicinaMemorije;
}

short Graficka::getMagistrala()const{
    return magistrala;
}

short Graficka::getBrzinaMemorije()const{
    return brzinaMemorije;
}

short Graficka::getBrzinaGPU()const{
    return brzinaGPU;
}

short Graficka::getStream()const{
    return streamProcesori;
}

short Graficka::getVGA()const{
    return VGA;
}

short Graficka::getHDMI()const{
    return HDMI;
}

short Graficka::getDVI()const{
    return DVI;
}

short Graficka::getDisplayPort()const{
    return displayPort;
}

short Graficka::getMinimalnoNapajanje()const{
    return minimalnoNapajanje;
}

void Graficka::setTipMemorije(GrafickaMemorija a){
    tipMemorije = a;
}

void Graficka::setHladjenje(TipHladjenja a){
    hladjenje = a;
}

void Graficka::setInterfejs(char * a){
    interfejs = a;
}

void Graficka::setGPU(char * a){
    GPU = a;
}

void Graficka::setKonektor(char * a){
    konektor = a;
}

void Graficka::setKolicinaMemorije(short a){
    kolicinaMemorije = a;
}

void Graficka::setMagistrala(short a){
    magistrala = a;
}

void Graficka::setBrzinaMemorije(short a){
    brzinaMemorije = a;
}

void Graficka::setBrzinaGPU(short a){
    brzinaGPU = a;
}

void Graficka::setStream(short a){
    streamProcesori = a;
}

void Graficka::setVGA(short a){
    VGA = a;
}

void Graficka::setDVI(short a){
    DVI = a;
}

void Graficka::setHDMI(short a){
    HDMI = a;
}

void Graficka::setDisplayPort(short a){
    displayPort = a;
}

void Graficka::setMinimalnoNapajanje(short a){
    minimalnoNapajanje = a;
}

#endif // GRAFICKA_H_INCLUDED
