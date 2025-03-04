#ifndef CAZADOR_H
#define CAZADOR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 20

typedef struct {
    char nombre[MAX_NOMBRE];
    int fuerza;
    int vida;
    int oro;
} Cazador;
void mostrar_cazador(Cazador * cazadores);
Cazador* cazador_predeterminado();
Cazador* crear_cazador(int * num_cazadores);
#endif