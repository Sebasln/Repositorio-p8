#ifndef DRAGON_H
#define DRAGON_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 20

typedef struct {
    char nombre[MAX_NOMBRE];
    int fuerza;
    int vida;
    int oro;
} Dragon;

void mostrar_dragon(Dragon * dragones); 
Dragon* dragon_predeterminado();
Dragon* crear_dragon(int * num_dragones);
#endif


