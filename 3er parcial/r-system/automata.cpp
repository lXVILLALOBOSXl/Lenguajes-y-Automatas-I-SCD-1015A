/*
AUTOR:      Luis Adrian Villalobos Rivera
CURSO:      Teoría de la Computación
PROGRAMA:   Implementación del Sistema R
FECHA:      12 de noviembre del 2024
*/

#include "automata.hpp" 

Automata::Automata()
{

    init = 0;

    delta[0]['0'] = 1;
    delta[0]['1'] = 2;
    delta[0]['2'] = 2;
    delta[0]['3'] = 2;
    delta[0]['4'] = 2;
    delta[0]['5'] = 2;
    delta[0]['6'] = 2;
    delta[0]['7'] = 2;
    delta[0]['8'] = 2;
    delta[0]['9'] = 2;

    delta[1]['.'] = 4;
    delta[1]['e'] = 5;
    delta[1]['E'] = 6;

    delta[2]['0'] = 3;
    delta[2]['1'] = 3;
    delta[2]['2'] = 3;
    delta[2]['3'] = 3;
    delta[2]['4'] = 3;
    delta[2]['5'] = 3;
    delta[2]['6'] = 3;
    delta[2]['7'] = 3;
    delta[2]['8'] = 3;
    delta[2]['9'] = 3;
    delta[2]['.'] = 4;
    delta[2]['e'] = 5;
    delta[2]['E'] = 6;

    delta[3]['0'] = 3;
    delta[3]['1'] = 3;
    delta[3]['2'] = 3;
    delta[3]['3'] = 3;
    delta[3]['4'] = 3;
    delta[3]['5'] = 3;
    delta[3]['6'] = 3;
    delta[3]['7'] = 3;
    delta[3]['8'] = 3;
    delta[3]['9'] = 3;
    delta[3]['.'] = 4;
    delta[3]['e'] = 5;
    delta[3]['E'] = 6;

    delta[4]['0'] = 7;
    delta[4]['1'] = 7;
    delta[4]['2'] = 7;
    delta[4]['3'] = 7;
    delta[4]['4'] = 7;
    delta[4]['5'] = 7;
    delta[4]['6'] = 7;
    delta[4]['7'] = 7;
    delta[4]['8'] = 7;
    delta[4]['9'] = 7;

    delta[5]['+'] = 9;
    delta[5]['-'] = 10;
    delta[5]['0'] = 8;
    delta[5]['1'] = 8;
    delta[5]['2'] = 8;
    delta[5]['3'] = 8;
    delta[5]['4'] = 8;
    delta[5]['5'] = 8;
    delta[5]['6'] = 8;
    delta[5]['7'] = 8;
    delta[5]['8'] = 8;
    delta[5]['9'] = 8;

    delta[6]['+'] = 9;
    delta[6]['-'] = 10;
    delta[6]['0'] = 8;
    delta[6]['1'] = 8;
    delta[6]['2'] = 8;
    delta[6]['3'] = 8;
    delta[6]['4'] = 8;
    delta[6]['5'] = 8;
    delta[6]['6'] = 8;
    delta[6]['7'] = 8;
    delta[6]['8'] = 8;
    delta[6]['9'] = 8;

    delta[7]['0'] = 7;
    delta[7]['1'] = 7;
    delta[7]['2'] = 7;
    delta[7]['3'] = 7;
    delta[7]['4'] = 7;
    delta[7]['5'] = 7;
    delta[7]['6'] = 7;
    delta[7]['7'] = 7;
    delta[7]['8'] = 7;
    delta[7]['9'] = 7;
    delta[7]['e'] = 5;
    delta[7]['E'] = 6;

    delta[8]['0'] = 8;
    delta[8]['1'] = 8;
    delta[8]['2'] = 8;
    delta[8]['3'] = 8;
    delta[8]['4'] = 8;
    delta[8]['5'] = 8;
    delta[8]['6'] = 8;
    delta[8]['7'] = 8;
    delta[8]['8'] = 8;
    delta[8]['9'] = 8;

    delta[9]['0'] = 8;
    delta[9]['1'] = 8;
    delta[9]['2'] = 8;
    delta[9]['3'] = 8;
    delta[9]['4'] = 8;
    delta[9]['5'] = 8;
    delta[9]['6'] = 8;
    delta[9]['7'] = 8;
    delta[9]['8'] = 8;
    delta[9]['9'] = 8;

    delta[10]['0'] = 8;
    delta[10]['1'] = 8;
    delta[10]['2'] = 8;
    delta[10]['3'] = 8;
    delta[10]['4'] = 8;
    delta[10]['5'] = 8;
    delta[10]['6'] = 8;
    delta[10]['7'] = 8;
    delta[10]['8'] = 8;
    delta[10]['9'] = 8;

    F.insert(1);
    F.insert(2);
    F.insert(3);
    F.insert(7);
    F.insert(8);
}

Automata::~Automata(){}

bool Automata::test(string w)
{
    unsigned state = init;

    for (int i = 0; i < w.length(); i++){
        if (delta[state].find(w[i]) == delta[state].end()){
            return false;
        }
        state = delta[state][w[i]];
    }

    return F.find(state) != F.end();
}