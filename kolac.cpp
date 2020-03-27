#include <iostream>

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
        bool staviDaSePece()
        bool ispeciKolac()
        bool zavrsiKolac()
        bool povecajTemperaturu()
        bool smanjiTemperaturu()
        bool dodajSlag(){
            if(stanje == U_PRIPREMI){
                return preliv.dodajSlag();
            }
            else return false;
        }
        bool ukloniSlag(){
            if(stanje == U_PRIPREMI){
                return preliv.ukloniSlag();
            }
            else return false;
        }
};

int main()
{

    return 0;
}
