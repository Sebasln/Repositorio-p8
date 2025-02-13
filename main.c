#include "cazador.h"
#include "combate.h"
#include "dragon.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	char seleccion_c[10];

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
		printf("pito\n");
		break;
	}else if(seleccion_c[0] == 'n'){
		// crear_cazador();
		printf("pene\n");
		break;
	}else{
		printf("Elije una opción valida. \n");
	}
	}while (1);

	printf("Elije una opción:\nSeleccionar dragon predeterminado (p) \nCrear nuevo dragon (n)\n");
	
	free(cazadores);
	return 0;


}
