/*
AUTOR:      Luis Adrian Villalobos Rivera
CURSO:      Teoría de la Computación
PROGRAMA:   Implementación del Sistema R
FECHA:      12 de noviembre del 2024
*/

#include <iostream>
#include "automata.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

    Automata a;

    set<string> s;
    set<string> r;
    set<string> e;

    int n;
    string w;

    cin >> n;
    cin.ignore();
    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        getline(cin, w);
        s.insert(w);
    }

    for (set<string>::iterator it = s.begin(); it != s.end(); it++)
    {
        if (a.test(*it))
        {
            r.insert(*it);
        }
        else
        {
            e.insert(*it);
        }
    }

    cout <<endl<< "Cadenas reconocidas: " << endl;
    for (set<string>::iterator it = r.begin(); it != r.end(); it++)
    {
        cout << *it << endl;
    }

    cout <<endl<< "Cadenas rechazadas: " << endl;
    for (set<string>::iterator it = e.begin(); it != e.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}