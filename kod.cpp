#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

string capitalize(string a){
    a[0] = toupper(a[0]);
    return a;
}

void getset(string klasa, string tip, string prom){
    cout << tip <<" " << "get" << capitalize(prom) << "()const;\n";
    cout << "\t\tvoid" <<" " << "set" << capitalize(prom) << "(" << tip << ");\n";
    cout << tip <<" "<< klasa << "::" << "get" << capitalize(prom) << "()const{\n\treturn " << prom << ";\n}\n\n";
    cout << "void" <<" "<< klasa << "::" << "set" << capitalize(prom) << "(" << tip << " a){\n\t" << prom << " = a;\n}\n\n";
}

int main()
{
    string klasa, tip, prom;
    {
        cin >> klasa >> tip >> prom;
        getset(klasa, tip, prom);
    }
}
