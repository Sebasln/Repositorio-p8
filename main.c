#include "cazador.h"
#include "combate.h"
#include "dragon.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
	


int main(){
	char seleccion_c[10];
	int num_cazadores = 0;


	Cazador * cazadores;
	system("clear");
	printf("Comienza el juego: \n");
	
	do{
		printf("Elije una opción:\nSeleccionar cazador predeterminado (p) \nCrear nuevo cazador (n)\n");
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
			printf("Elije una opción valida. \n");
		}
	}while (1);
		seleccion_personaje(cazadores, num_cazadores);
		//system("clear");

	Dragon * dragones;

	do{
		printf("Elije una opción:\nSeleccionar dragon predeterminado (p) \nCrear nuevo dragon (n)\n");
		scanf(" %s", seleccion_c);
		if(strlen(seleccion_c) > 2){
			printf("Pon solo un carácter. \n");
		}
		if(seleccion_c[0] == 'p'){
			dragones = dragon_predeterminado();
			for (int i = 0; i < 2; i++){
				mostrar_dragon(&dragones[i]);
			}
			break;
		}else if(seleccion_c[0] == 'n'){
			dragones = crear_dragon(dragones);
			
			break;
		}else{
			printf("Elije una opción válida. \n");
		}
	}while (1);


	free(cazadores);
	free(dragones);
	return 0;
}