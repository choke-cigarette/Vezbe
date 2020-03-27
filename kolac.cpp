#include <iostream>
#define KORAK 20
using namespace std;

enum TipPreliva{COKOLADNI = 1, COKOLADNI_SA_SLAGOM};

class Preliv{
    private:
        TipPreliva tip;
    public:
        Preliv(TipPreliva t = COKOLADNI){
            tip = t;
        }
        bool dodajSlag(){
            return (tip == COKOLADNI) ? tip = COKOLADNI_SA_SLAGOM : false;
        }
        bool ukloniSlag(){
            return (tip == COKOLADNI_SA_SLAGOM) ? tip = COKOLADNI : false;
        }
        TipPreliva getTip()const{
            return tip;
        }
        friend void ispisiPreliv(const Preliv&);
};

void ispisiPreliv(const Preliv& p){
    cout << "Preliv: " << ((p.tip == COKOLADNI) ? "COKOLADNI" : "COKOLADNI SA SLAGOM") << endl;
}

enum KolacStanje{U_PRIPREMI, PECE_SE, ZAGOREO, PRIPREMLJEN};

class Kolac{
    private:
        KolacStanje stanje;
        int temperatura;
        Preliv preliv;
    public:
        Kolac() : preliv(), temperatura(20), stanje(U_PRIPREMI){}
        Kolac(Kolac &k) : temperatura(k.getTemperatura()), preliv(k.preliv.getTip()), stanje(k.getStanje()){}
        int getTemperatura()const{
            return temperatura;
        }
        KolacStanje getStanje()const{
            return stanje;
        }
        TipPreliva getTipPreliva()const{
            return preliv.getTip();
        }
        bool staviDaSePece(){
            if(preliv.getTip() == COKOLADNI){
                stanje = PECE_SE;
                temperatura += KORAK;
                return true;
            }
            return false;
        }
        bool ispeciKolac(){
            if(stanje == PECE_SE){
                stanje = U_PRIPREMI;
                temperatura = 20;
                return true;
            }
            return false;
        }
        bool zavrsiKolac(){
            if(stanje == U_PRIPREMI){
                stanje = PRIPREMLJEN;
                return true;
            }
            return false;
        }
        bool povecajTemperaturu(){
            if(stanje == PECE_SE){
                temperatura += KORAK;
                if(temperatura > 100){
                    temperatura = 20;
                    stanje = ZAGOREO;
                }
                return true;
            }
            return false;
        }
        bool smanjiTemperaturu(){
            if(stanje == PECE_SE){
                temperatura -= KORAK;
                if(temperatura < 40){
                    temperatura = 40;
                }
                return true;
            }
            return false;
        }
        bool dodajSlag(){
            if(stanje == U_PRIPREMI){
                return preliv.dodajSlag();
            }
            return false;
        }
        bool ukloniSlag(){
            if(stanje == U_PRIPREMI){
                return preliv.ukloniSlag();
            }
            return false;
        }
};

void meni(Kolac &k){
    char izbor = 0;
    while(izbor != 'q'){
        cout << "Funkcionalnosti:" << endl;
        cout << "\t0) Get temperatura" << endl;
        cout << "\t1) Get stanje" << endl;
        cout << "\t2) Get tip preliva" << endl;
        cout << "\t3) Stavi da se pece" << endl;
        cout << "\t4) Skloni sa pecenja" << endl;
        cout << "\t5) Zavrsi sa kolacem" << endl;
        cout << "\t6) Povecaj temperaturu" << endl;
        cout << "\t7) Smanji temperaturu" << endl;
        cout << "\t8) Dodaj slag" << endl;
        cout << "\t9) Ukloni slag" << endl;
        cout << "Pritisni 'q' da bi zavrsio sa menijem" << endl << endl;
        cout << "Vi birate: ";
        izbor = getchar();
        fflush(stdin);
        cout << endl << "Ispis: ";
        switch(izbor){
        case '0':
            cout << k.getTemperatura();
            break;
        case '1':
            cout << k.getStanje();
            break;
        case '2':
            cout << k.getTipPreliva();
            break;
        case '3':
            cout << k.staviDaSePece();
            break;
        case '4':
            cout << k.ispeciKolac();
            break;
        case '5':
            cout << k.zavrsiKolac();
            break;
        case '6':
            cout << k.povecajTemperaturu();
            break;
        case '7':
            cout << k.smanjiTemperaturu();
            break;
        case '8':
            cout << k.dodajSlag();
            break;
        case '9':
            cout << k.ukloniSlag();
            break;
        case 'q':
            return;
        }
        cout << endl << endl;
    }

}

int main()
{
    Kolac k;
    meni(k);
    return 0;
}
