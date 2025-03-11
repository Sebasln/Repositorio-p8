#ifndef TIENDA_H
#define TIENDA_H
#include "cazador.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 20

typedef struct {
    char nombre[MAX_NOMBRE];
    int curacion;
    int aumento_fuerza;
    int stock;
    int coste;
} Pocion;

Pocion* pocion_predeterminada();
void tienda(Pocion * pociones, Cazador * cazadores, int num_cazadores, int eleccion_cazador);

#endif