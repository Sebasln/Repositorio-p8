#include "dragon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN_DRAGONES 2
#define MAX_DRAGONES 5
#define MAX_VIDA 660
#define MAX_FUERZA 40

void mostrar_dragon(Dragon * dragones){
	printf("Dragón: %s\nStats:\n \tAtaque:%d\n \tVida:%d\n \tOro:%d\n\n", dragones->nombre, dragones->fuerza, dragones->vida, dragones->oro);
}

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
	inicializar_dragon( &dragones[0], "Shenlong", 20, 650, 3000);
	inicializar_dragon( &dragones[1], "Kaido", 40, 450, 5000);

		
	return dragones;

}

Dragon* crear_dragon(int * num_dragones){
	int n = 0;
	Dragon * dragones = dragon_predeterminado();

	printf("Se han añadido 2 dragones predeterminados.\n");
	do{
		printf("¿Cuántos dragones quieres añadir?(Máximo 2) ");
		if (scanf("%d", &n) != 1){
			printf("Error introduce un número válido.\n");
			while(getchar() != '\n');
		}else if(n > 2 || n <= 0){
			printf("Error con la cantidad introducida, recuerda que debe ser mayor que 0 y menor o igual a 2.\n");

		}else{
			*num_dragones = MIN_DRAGONES + n;
		}
	}while(n > 2 || n <= 0);
		

	dragones = (Dragon *)realloc(dragones, (n + MIN_DRAGONES) * sizeof(Dragon));

	if(dragones == NULL){
		printf("Error, no se pudo reservar la memoria.\n");

		return NULL;
	}

	printf("Introduce los datos de los dragones(Ten en cuenta que la fuerza no debe superar los 40 puntos y la vida no debe superar los 660 puntos):\n");

	for (int i = MIN_DRAGONES; i < n + MIN_DRAGONES; i++){
		printf("\tIntroduce el nombre del dragón %d: ", i + 1);
		scanf(" %[^\n]", dragones[i].nombre);
			
		do {
			printf("\tIntroduce la fuerza del dragón %d:", i + 1);
			scanf("%d", &dragones[i].fuerza);

			printf("\tIntroduce la vida del dragón %d:", i + 1);
			scanf("%d", &dragones[i].vida);

			if(dragones[i].vida > MAX_VIDA || dragones[i].fuerza > MAX_FUERZA ){
				printf("Los valores de fuerza o vida sobrepasan el límite, vuelve a introducir los datos.\n");
			}

			dragones[i].oro = (dragones[i].vida + dragones[i].fuerza) * 10;
		

		} while (dragones[i].vida > MAX_VIDA || dragones[i].fuerza > MAX_FUERZA );

		
			
	}
		
	for (int i = 0; i < MIN_DRAGONES + n; i++){
		mostrar_dragon(&dragones[i]);
	}

	return dragones;
}