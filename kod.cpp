#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

int main()
{
    vector<string> tipovi;
    string text;
    char slovo = '0';
    while(slovo != '~'){
        slovo = getch();
        text += slovo;
    }
    slovo = text[0];
    int i = 0;
    while(slovo != '~'){
        while(slovo == ' '){
            slovo = text[++i];
        }
        while(slovo != ',' || slovo != ';'){
            slovo = text[++i];
        }
    }
    cout << text;
}
