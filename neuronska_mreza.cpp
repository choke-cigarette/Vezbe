#include <iostream>
#include <cmath>

using namespace std;

enum TipMreze{DUBOKA, OBICNA};

class NeuronskaMreza{
    private:
        int brSkrivenihSlojeva, brNeuronaPoSloju;
    public:
        NeuronskaMreza(int sloj, int neuron){
            if(sloj < 0){
                sloj = 0;
            }
            if(neuron < 0){
                neuron = 0;
            }
            brSkrivenihSlojeva = sloj;
            brNeuronaPoSloju = neuron;
        }
        void dodajSkriveniSloj(){
            brSkrivenihSlojeva++;
            cout << brSkrivenihSlojeva;
        }
        void dodajNeuron(){
            brNeuronaPoSloju++;
            cout << brNeuronaPoSloju;
        }
        double izracunajUspeh()const{
            return  1 - 1 / log(brSkrivenihSlojeva * brNeuronaPoSloju);
        }
        TipMreze getTipMreze()const{
            if(brSkrivenihSlojeva * brNeuronaPoSloju + 2 >= 1000){
                return DUBOKA;
            }
            return OBICNA;
        }

};

enum StanjeTesta{START, PROCESIRANJE, OPTIMIZACIJA, KRAJ};
enum TipOptimizacije{DODAJ_SLOJ, DODAJ_NEURON};

class Test{
    private:
        NeuronskaMreza nm;
        double zeljeniProcenatUspesnosti;
        int brOptimizacija;
        StanjeTesta stanje;
    public:
        Test(double uspesnost) : nm(3, 200){
            if(uspesnost < 0 || uspesnost > 1){
                uspesnost = 0.85;
            }
            zeljeniProcenatUspesnosti = uspesnost;
            stanje = START;
            brOptimizacija = 0;
        }
        bool procesiraj(){
            if(stanje == START || stanje == OPTIMIZACIJA){
                if(zeljeniProcenatUspesnosti > nm.izracunajUspeh()){
                    stanje = PROCESIRANJE;
                }
                else{
                    stanje = KRAJ;
                    cout << "Test uspesno zavrsen!" << endl;
                    cout << "\tBroj optimizacija: " << brOptimizacija << endl;
                    cout << "\tZeljeni procenat uspesnosti: " << zeljeniProcenatUspesnosti << endl;
                    cout << "\tPostignuti procenat uspenosti: " << nm.izracunajUspeh() << endl;
                }
                return true;
            }
            return false;
        }
        bool potrebnoOptimizovati(){
            if(stanje == PROCESIRANJE){
                stanje = OPTIMIZACIJA;
                return true;
            }
            return false;
        }
        bool optimizuj(TipOptimizacije tip){
            if(stanje == OPTIMIZACIJA){
                if(tip == DODAJ_SLOJ){
                    nm.dodajSkriveniSloj();
                }
                else{
                    nm.dodajNeuron();
                }
                brOptimizacija++;
                return true;
            }
            return false;
        }
        double izracunajUspeh()const{
            return nm.izracunajUspeh();
        }
        TipMreze getTipMreze()const{
            return nm.getTipMreze();
        }
        StanjeTesta getStanje()const{
            return stanje;
        }
};

void ispisiTest(const Test& t){
    cout << t.getStanje() << endl;
    cout << t.getTipMreze() << endl;
    cout << t.izracunajUspeh() << endl;
}

void meni(Test &t){
    char izbor = 0;
    while(izbor != 'q'){
        cout << "Funkcionalnosti:" << endl;
        cout << "\t1) Procesiraj" << endl;
        cout << "\t2) Potrebno Optimizovati" << endl;
        cout << "\t3) Optimizuj - dodaj sloj" << endl;
        cout << "\t4) Optimizuj - dodaj neuron" << endl;
        cout << "\t5) Izracunaj uspeh" << endl;
        cout << "\t6) Get tip mreze" << endl;
        cout << "\t7) Get stanje" << endl;
        cout << "Pritisni 'q' da bi zavrsio sa menijem" << endl << endl;
        cout << "Vi birate: ";
        izbor = getchar();
        fflush(stdin);
        if(izbor == 'q'){
            return;
        }
        cout << endl << "Ispis: ";
        switch(izbor){
        case '1':
            cout << t.procesiraj();
            break;
        case '2':
            cout << t.potrebnoOptimizovati();
            break;
        case '3':
            if(t.getStanje() == OPTIMIZACIJA){
                cout << "Dodat sloj. Sada ima ";
                t.optimizuj(DODAJ_SLOJ);
                cout << " slojeva";
            }
            else cout << t.optimizuj(DODAJ_SLOJ);
            break;
        case '4':
            if(t.getStanje() == OPTIMIZACIJA){
                cout << "Dodat neuron. Sada ima ";
                t.optimizuj(DODAJ_NEURON);
                cout << " neurona po sloju";
            }
            else cout << t.optimizuj(DODAJ_NEURON);
            break;
        case '5':
            cout << t.izracunajUspeh();
            break;
        case '6':
            cout << ((t.getTipMreze() == DUBOKA) ? "Duboka" : "Obicna");
            break;
        case '7':
            switch(t.getStanje()){
            case START:
                cout << "Start";
                break;
            case PROCESIRANJE:
                cout << "Procesiranje";
                break;
            case OPTIMIZACIJA:
                cout << "Optimizacija";
                break;
            case KRAJ:
                cout << "Kraj";
                break;
            }
        }
        cout << endl << endl;
    }

}

int main()
{
    Test t(-12);
    meni(t);
    return 0;
}
