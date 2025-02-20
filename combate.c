#include "combate.h"
#include "cazador.h"
#include "dragon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void seleccion_personaje(Cazador * cazadores, int n){
	int eleccion = 0;
	printf("Elije un personaje(1 - %d)", n);
	scanf("%d", &eleccion);
	eleccion -= 1;
	printf("Personaje elejido: \n");
		mostrar_cazador(&cazadores[eleccion]);

}