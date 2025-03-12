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
	printf("Nombre: %s\n \tCoste:%d\n \tAumento Vida:%d\n \tAumento Fuerza:%d\n \tStock:%d\n\n", pociones->nombre, pociones->coste, pociones->curacion, pociones->aumento_fuerza, pociones->stock);
}	

void tienda(Pocion * pociones, Cazador * cazadores, int num_cazadores, int eleccion_cazador){
	int compra_cazador = 0;
	system("clear");
	printf(" ____ ___ _____ _   ___     _______  _   _ ___ ____   ___  \n");
	printf("| __ )_ _| ____| \\ | \\ \\   / / ____|| \\ | |_ _|  _ \\ / _ \\ \n");
	printf("|  _ \\| ||  _| |  \\| |\\ \\ / /|  _|  |  \\| || || | | | | | | \n");
	printf("| |_) | || |___| |\\  | \\ V / | |___ | |\\  || || |_| | |_| | \n");
	printf("|____/___|_____|_| \\_|  \\_/  |_____||_| \\_|___|____/ \\___/ \n");
	printf("                                   \n");
	printf("\t          _         _        _     \n");
	printf("\t         / \\       | |      / \\    \n");
	printf("\t        / _ \\      | |     / _ \\   \n");
	printf("\t       / ___ \\     | |___ / ___ \\  \n");
	printf("\t      /_/   \\_\\    |_____/_/   \\_\\\n");
	printf("                                   \n");
	printf("\t   _____ ___ _____ _   _ ____    _    \n");
	printf("\t  |_   _|_ _| ____| \\ | |  _ \\  / \\   \n");
	printf("\t    | |  | ||  _| |  \\| | | | |/ _ \\  \n");
	printf("\t    | |  | || |___| |\\  | |_| / ___ \\ \n");
	printf("\t    |_| |___|_____|_| \\_|____/_/   \\_\\\n");

	printf("Deberás elegir una de estas pociones, recuerda solo existen una de cada en todo el mundo(elige bien)\n");

	for(int i = 0; i < NUM_POCIONES; i++){
		mostrar_pociones(&pociones[i]);
	}
	if(pociones[0].stock == 0 && pociones[1].stock == 0){
		printf("No queda stock de ninguna poción.\n");
		return;
	}
	int eleccion_pocion = 0;

	do{
		
		printf("¿Qué poción deseas comprar?(1 o 2)\n");
		scanf("%d", &eleccion_pocion);
		while (getchar() != '\n');
		eleccion_pocion -= 1;
		if (eleccion_pocion < 0 || eleccion_pocion > 1){
			printf("Por elegir mal te has quedado sin poción\n");
			break;
		} 

		if (pociones[eleccion_pocion].stock <= 0){
			printf("Ya no queda stock para esta poción.\n");
			continue;
		}
		if(cazadores[eleccion_cazador].oro < pociones[eleccion_pocion].coste){
			printf("Pobre \n");
			break;
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
				compra_cazador -= 1;
				cazadores[compra_cazador].vida += pociones[eleccion_pocion].curacion;
				cazadores[compra_cazador].fuerza += pociones[eleccion_pocion].aumento_fuerza;
				break; 
			}
		} while (1);

		if(eleccion_pocion == 0){
			printf("Se le ha curado 100 puntos de vida al cazador %s. \n", cazadores[compra_cazador].nombre);

			
		}else if(eleccion_pocion == 1){
			printf("El ataque del cazador %s ha sido aumentada 100 puntos.\n", cazadores[compra_cazador].nombre);
			

		}

		pociones[eleccion_pocion].stock -= 1;
		cazadores[eleccion_cazador].oro -= pociones[eleccion_pocion].coste;
		break;

	}while (1);

}