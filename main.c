#include "cazador.h"
#include "combate.h"
#include "dragon.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	char seleccion_c[10];
	int num_cazadores = 0;
	int num_dragones = 0;
	int eleccion_cazador = 0;
	int eleccion_dragon = 0;

	Cazador * cazadores;
	system("clear");
	printf("Comienza el juego: \n");
	
	do{
		printf("Elige una opción:\nSeleccionar cazador predeterminado (p) \nCrear nuevo cazador (n)\n");
		scanf(" %s", seleccion_c);
		if(strlen(seleccion_c) > 2){ 
			printf("Pon solo un caracter. \n");
		}
		if(seleccion_c[0] == 'p'){
			cazadores = cazador_predeterminado();
			for(int i = 0; i < 3; i++){
				mostrar_cazador(&cazadores[i]);
			}
			num_cazadores = 3;
			break;
		}else if(seleccion_c[0] == 'n'){
			cazadores = crear_cazador(&num_cazadores);
			break;
		}else{
			printf("Elige una opción valida. \n");
		}
	}while (1);
	
	


	Dragon * dragones;

	do{
		printf("Elige una opción:\nSeleccionar dragon predeterminado (p) \nCrear nuevo dragon (n)\n");
		scanf(" %s", seleccion_c);
		if(strlen(seleccion_c) > 2){
			printf("Pon solo un carácter. \n");
		}
		if(seleccion_c[0] == 'p'){
			dragones = dragon_predeterminado();
			for (int i = 0; i < 2; i++){
				mostrar_dragon(&dragones[i]);
			}
			num_dragones = 2;
			break;
		}else if(seleccion_c[0] == 'n'){
			dragones = crear_dragon(&num_dragones); 
			break;
		}else{
			printf("Elige una opción válida. \n");
		}
	}while (1);

	
	printf("\nPresiona Enter para continuar...");
	int c;
	while ((c = getchar()) != '\n' && c != EOF); // Limpia el buffer
	getchar(); // Espera un nuevo Enter


	
	system("clear");
	
	combate(cazadores, dragones, num_cazadores, num_dragones, &eleccion_cazador, &eleccion_dragon);
	
	free(cazadores);
	free(dragones);
	return 0;
}