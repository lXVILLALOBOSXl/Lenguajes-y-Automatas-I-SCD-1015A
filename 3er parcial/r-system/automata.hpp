/*
AUTOR:      Luis Adrian Villalobos Rivera
CURSO:      Teoría de la Computación
PROGRAMA:   Implementación del Sistema R
FECHA:      12 de noviembre del 2024
*/

#ifndef automata_hpp
#define automata_hpp

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

class Automata
{
    // Estado inicial
    unsigned init;
    
    transition delta;
    states F;

public:
    Automata();
    ~Automata();

    bool test(string);
    
};

#endif