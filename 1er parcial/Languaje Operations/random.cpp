/*
    AUTOR:      Luis Villalobos
    CURSO:      Teoria de la computación
    PROGRAMA:   Operaciones con lenguajes
    FECHA:      18 de septiembre del 2024
*/
#include "random.h"

void initialize() { srand(time(NULL)); }

int random_int(int min, int max) {
  return rand() % (max - (min - 1)) + min;
}