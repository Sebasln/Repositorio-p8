#ifndef COMBATE_H
#define COMBATE_H
#include "cazador.h"
#include "dragon.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void seleccion_personaje(Cazador * cazadores, int n, int * eleccion_cazador, int * eleccion_dragon);
void seleccion_dragon(Dragon * dragones, int n, int * eleccion_cazador, int * eleccion_dragon);
void combate(Cazador * cazadores, Dragon * dragones,int * eleccion_cazador, int * eleccion_dragon);
#endif