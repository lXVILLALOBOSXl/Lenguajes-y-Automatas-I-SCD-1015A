/*
AUTOR:      Luis Villalobos
CURSO:      Estructura de Datos
PROGRAMA:   Sort Algorithms
FECHA:      29 de marzo del 2023
*/

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

// Funcion de transicion de estados
typedef map<char, unsigned> event;
typedef map<unsigned, event> transition;

// Conjunto de estados (para los estados finales)
typedef set<unsigned> states;

string crearcadena(int len){
    string a;

    while (len--) a += (char) (rand() % 2 ) + 'a';

    return a;
    
}

bool process(string w, unsigned init, transition delta, states F){

    unsigned state = init;

    for (int i = 0; i < w.length(); i++) state = delta[state][w[i]];

    return F.find(state) != F.end();
}

int main(int argc, char const *argv[])
{
    srand((unsigned) time(nullptr));

    // Estado inicial
    unsigned init = 0;

    // Funcion de transicion
    transition delta;

    delta[0]['a'] = 0;
    delta[0]['b'] = 1;
    delta[1]['a'] = 2;
    delta[1]['b'] = 1;
    delta[2]['a'] = 0;
    delta[2]['b'] = 1;

    // Estados finales
    states F;

    F.insert(0);

    // Cadena que vamos a procesar
    string s = crearcadena(rand() % 11);
    cout << "Cadena que voy a procesar, a ver si sirve: \n" << s << "\n\n";

    if  (process(s, init, delta, F)) cout << "Aceptada\n";
    else cout << "Rechazada, siga participando\n";
    return 0;
}