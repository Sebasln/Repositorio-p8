#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cazador.h"

#define MIN_CAZADORES 3
#define MAX_CAZADORES 5



void inicializar_cazador(Cazador * cazadores, char* Nombre, int Fuerza, int Vida, int Oro){
	strcpy(cazadores->nombre, Nombre);
	cazadores->fuerza = Fuerza;
	cazadores->vida = Vida;
	cazadores->oro = Oro;
}

Cazador* cazador_predeterminado(){
 
Cazador * cazadores = (Cazador *)malloc(MIN_CAZADORES * sizeof(Cazador));
if(cazadores == NULL){
	printf("Error no se pudo reservar memoria\n");
	exit(EXIT_FAILURE);
}
	inicializar_cazador( &cazadores[0], "Roberto", 125, 75, 0);
	inicializar_cazador( &cazadores[1], "Miguel", 100, 100, 0);
	inicializar_cazador( &cazadores[2], "Sebas", 75, 125, 0);

	return cazadores;

}

void crear_cazador(){


}
