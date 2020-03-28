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

enum StanjeTesta{START};

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

        }

};
int main()
{


    return 0;
}
