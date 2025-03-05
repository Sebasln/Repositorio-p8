#ifndef COMBATE_H
#define COMBATE_H
#include "cazador.h"
#include "dragon.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void esperar_enter();
void seleccion_personaje(Cazador * cazadores, int num_cazadores, int * eleccion_cazador);
void seleccion_dragon(Dragon * dragones, int num_dragones, int * eleccion_dragon);
void combate(Cazador *cazadores, Dragon *dragones, int num_cazadores, int num_dragones, int * eleccion_cazador, int * eleccion_dragon );
#endif