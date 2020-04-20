#ifndef TELEVIZOR_H_INCLUDED
#define TELEVIZOR_H_INCLUDED
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "artikal.h"

enum TipTelevizora{LED, LCD, OLED, PLASMA};

class Televizor : public Artikal{
    private:
        TipTelevizora tip;

    public:


};


#endif // TELEVIZOR_H_INCLUDED
