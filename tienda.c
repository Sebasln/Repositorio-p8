#include "tienda.h"
#include "combate.h"
#include "cazador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_POCIONES 2


void inicializar_pocion(Pocion * pociones, char* Nombre, int Curacion, int Aumento_fuerza, int Stock, int Coste){
	strcpy(pociones->nombre, Nombre);
	pociones->curacion = Curacion;
	pociones->aumento_fuerza = Aumento_fuerza;
	pociones->stock = Stock;
	pociones->coste = Coste;
}

Pocion* pocion_predeterminada(){		
	Pocion * pociones = (Pocion *)malloc(NUM_POCIONES * sizeof(Pocion));
	if(pociones == NULL){
		printf("Error no se pudo reservar memoria\n");
		exit(EXIT_FAILURE);
	}
	inicializar_pocion( &pociones[0], "Pocion de curación", 100, 0, 1, 2500);
	inicializar_pocion( &pociones[1], "Pocion de fuerza", 0, 100, 1, 2500);

	return pociones;
}




void mostrar_pociones(Pocion * pociones){
	printf("Nombre: %s\n \tCoste:%d\n \tAumento Vida:%d\n \tAumento Fuerza:%d\n\n", pociones->nombre, pociones->coste, pociones->curacion, pociones->aumento_fuerza);
}	

void tienda(Pocion * pociones, Cazador * cazadores, int num_cazadores){
	int compra_cazador = 0;
	printf("🏪¡¡Bienvenido a la tienda de pociones!!🏪\n");

	printf("Deberas elejir una de estas pociones, recuerda solo existen una de cada en todo el mundo(elige bien)\n");

	for(int i = 0; i < NUM_POCIONES; i++){
		mostrar_pociones(&pociones[i]);
	}

	int eleccion_pocion = 0;
	printf("¿Qué poción deseas comprar?(1 o 2)\n");
	scanf("%d", &eleccion_pocion);
	eleccion_pocion -= 1;
	if (eleccion_pocion < 0 || eleccion_pocion > 1){
		printf("Por elegir mal te has quedado sin poción\n");
		return;
	}

	printf("¿A que cazador deseas dar la poción? (1 - %d)\n", num_cazadores);
	do {
        printf("Elige un nuevo cazador (1 - %d):\n", num_cazadores);
        for(int i = 0; i < num_cazadores; i++){
            mostrar_cazador(&cazadores[i]);
        }
        if (scanf("%d", &compra_cazador) != 1 || compra_cazador < 1 || compra_cazador > num_cazadores) {
            printf("Selección inválida. Intenta de nuevo.\n");
            while (getchar() != '\n');
        } else if (cazadores[compra_cazador - 1].vida <= 0) {
            printf("Ese cazador está muerto. Elige otro.\n");
        } else {
            (compra_cazador) -= 1;

            cazadores[compra_cazador].vida += pociones[eleccion_pocion].curacion;
            cazadores[compra_cazador].fuerza += pociones[eleccion_pocion].aumento_fuerza;
            break; 
        }
    } while (1);

    if(eleccion_pocion == 0){
    	printf("Se le ha curado 100 puntos de vida al cazador %s. \n", cazadores[compra_cazador].nombre);
    	pociones[eleccion_pocion].stock --;
    }else if(eleccion_pocion == 1){
    	printf("El ataque del cazador %s ha sido aumentada 100 puntos.\n", cazadores[compra_cazador].nombre);
    	pociones[eleccion_pocion].stock --;
    }
}