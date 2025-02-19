	#include "dragon.h"
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>

	#define MIN_DRAGONES 2
	#define MAX_DRAGONES 5

	void inicializar_dragon(Dragon * dragones, char* Nombre, int Fuerza, int Vida, int Oro){
		strcpy(dragones->nombre, Nombre);
		dragones->fuerza = Fuerza;
		dragones->vida = Vida;
		dragones->oro = Oro;
	}

	Dragon* dragon_predeterminado(){
		
		Dragon * dragones = (Dragon *)malloc(MIN_DRAGONES * sizeof(Dragon));
		if(dragones == NULL){
			printf("Error no se pudo reservar memoria\n");
			exit(EXIT_FAILURE);
		}
		inicializar_dragon( &dragones[0], "Shenlong", 125, 75, 0);
		inicializar_dragon( &dragones[1], "Miguel", 100, 100, 0);

		for (int i = 0; i < MIN_DRAGONES; i++){
			mostrar_cazador(&dragones[i]);
		}
		return dragones;

	}

	Dragon* crear_dragon(Dragon* dragones){
		int n = 0;
		dragones = dragon_predeterminado();

		printf("Se han añadido 3 dragones predeterminados.\n");
		do{
			printf("¿Cuántos dragones quieres añadir?(Máximo 2) ");
			if (scanf("%d", &n) != 1){
				printf("Error introduce un número válido.\n");
				while(getchar() != '\n');
			}else if(n > 2 || n <= 0){
				printf("Error con la cantidad introducida, recuerda que debe ser mayor que 0 y menor o igual a 2.\n");

			}
		}while(n > 2 || n <= 0);
		

		dragones = (Dragon *)realloc(dragones, (n + MIN_DRAGONES) * sizeof(Dragon));

		if(dragones == NULL){
			printf("Error, no se pudo reservar la memoria.\n");

			return NULL;
		}

		printf("Introduce los datos de los dragones(Ten en cuenta que la fuerza y la vida no deben sumar más de 200 puntos):\n");

		for (int i = MIN_DRAGONES; i < n + MIN_DRAGONES; i++){
			printf("\tIntroduce el nombre del dragón %d: ", i + 1);
			scanf(" %[^\n]", dragones[i].nombre);
			
			do {
				printf("\tIntroduce la fuerza del dragón %d:", i + 1);
				scanf("%d", &dragones[i].fuerza);

				printf("\tIntroduce la vida del dragón %d:", i + 1);
				scanf("%d", &dragones[i].vida);


				if(dragones[i].fuerza + dragones[i].vida > 200){
					printf("Los valores de fuerza o vida sobrepasan el límite, vuelve a introducir los datos.\n");
				}
			} while (dragones[i].fuerza + dragones[i].vida > 200);

			printf("\tEl oro del dragón %d está predeterminado en 0.\n", i + 1);
			dragones[i].oro = 0;
			
		}
		for (int i = 0; i < MIN_DRAGONES + n; i++){
			mostrar_cazador(&dragones[i]);
		}
		return dragones;
	}