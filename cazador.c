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

Cazador* crear_cazador(Cazador* cazadores){
	int n = 0;
	cazadores = cazador_predeterminado();

	printf("Se han añadido 3 cazadores predeterminados.\n");

	printf("¿Cuántos cazadores quieres añadir? ");
	scanf("%d", &n);

	cazadores = (Cazador *)realloc(cazadores, (n + MIN_CAZADORES) * sizeof(Cazador));

	if(cazadores == NULL){
		printf("Error, no se pudo reservar la memoria.\n");

		return NULL;
	}

	printf("Introduce los datos de los cazadores(Ten en cuenta que la fuerza y la vida no deben sumar más de 200 puntos):\n");

	for (int i = MIN_CAZADORES; i < n + MIN_CAZADORES; i++){
		printf("\tIntroduce el nombre del cazador %d: ", i + 1);
		scanf(" %[^\n]", cazadores[i].nombre);
		
		do {
			printf("\tIntroduce la fuerza del cazador %d:", i + 1);
			scanf("%d", &cazadores[i].fuerza);

			printf("\tIntroduce la vida del cazador %d:", i + 1);
			scanf("%d", &cazadores[i].vida);


			if(cazadores[i].fuerza + cazadores[i].vida > 200){
				printf("Los valores de fuerza o vida sobrepasan el límite, vuelve a introducir los datos.\n");
			}
		} while (cazadores[i].fuerza + cazadores[i].vida > 200);

		printf("\tEl oro del cazador %d está predeterminado en 0.\n", i);
		cazadores[i].oro = 0;
		
	}
	return cazadores;
}
