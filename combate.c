#include "combate.h"
#include "cazador.h"
#include "dragon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int eleccion_cazador = 0;
int eleccion_dragon = 0;

void seleccion_personaje(Cazador * cazadores, int n){
	
	printf("Elije un personaje(1 - %d):\n", n);
	scanf("%d", &eleccion_cazador);
	eleccion_cazador -= 1;


}
void seleccion_dragon(Dragon * dragones, int n){

	printf("Elije un dragón(1 - %d):\n", n);
	scanf("%d", &eleccion_dragon);
	eleccion_dragon -= 1;

}

void combate(eleccion_cazador, ){

}