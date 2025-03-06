#include "historia.h"
#include "cazador.h"
#include "combate.h"
#include "dragon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main(){
	char seleccion_c[10];
	int num_cazadores = 0;
	int num_dragones = 0;
	int eleccion_cazador = 0;
	int eleccion_dragon = 0;
	Cazador * cazadores;
	system("clear");
	for(int i = 0; i < 2; i++) {
    	printf("  ____    _    ____   ____    _    _   _ ____   ___               \n"
               " / ___|  / \\  |  _ \\ / ___|  / \\  | \\ | |  _ \\ / _ \\ \n"
               "| |     / _ \\ | |_) | |  _  / _ \\ |  \\| | | | | | | | \n"
               "| |___ / ___ \\|  _ <| |_| |/ ___ \\| |\\  | |_| | |_| |  _ \n"
               " \\____/_/   \\_\\_| \\_\\\\____/_/   \\_\\_| \\_|____/ \\___/  (_)\n");
		fflush(stdout); 
		sleep(1);

        system("clear");
        printf("  ____    _    ____   ____    _    _   _ ____   ___               \n"
               " / ___|  / \\  |  _ \\ / ___|  / \\  | \\ | |  _ \\ / _ \\              \n"
               "| |     / _ \\ | |_) | |  _  / _ \\ |  \\| | | | | | | |            \n"
               "| |___ / ___ \\|  _ <| |_| |/ ___ \\| |\\  | |_| | |_| |  _   _ \n"
               " \\____/_/   \\_\\_| \\_\\\\____/_/   \\_\\_| \\_|____/ \\___/  (_) (_)\n");
        fflush(stdout); 
        sleep(1);

        system("clear");
        printf("  ____    _    ____   ____    _    _   _ ____   ___               \n"
               " / ___|  / \\  |  _ \\ / ___|  / \\  | \\ | |  _ \\ / _ \\              \n"
               "| |     / _ \\ | |_) | |  _  / _ \\ |  \\| | | | | | | |            \n"
               "| |___ / ___ \\|  _ <| |_| |/ ___ \\| |\\  | |_| | |_| |  _   _   _ \n"
               " \\____/_/   \\_\\_| \\_\\\\____/_/   \\_\\_| \\_|____/ \\___/  (_) (_) (_)\n");
        fflush(stdout); 
        sleep(1);
        system("clear");
	}

	historia_inicial();
	

	system("clear");
	printf("\t  _____ ____  __  __ _____ ______ _   _ ______           ______ _             _ _    _ ______ _____  ____  \n");
    printf("\t / ____/ __ \\|  \\/  |_   _|  ____| \\ | |___  /   /\\     |  ____| |           | | |  | |  ____/ ____|/ __ \\ \n");
    printf("\t| |   | |  | | \\  / | | | | |__  |  \\| |  / /   /  \\    | |__  | |           | | |  | | |__ | |  __| |  | |\n");
    printf("\t| |   | |  | | |\\/| | | | |  __| | . ` | / /   / /\\ \\   |  __| | |       _   | | |  | |  __|| | |_ | |  | |\n");
    printf("\t| |___| |__| | |  | |_| |_| |____| |\\  |/ /__ / ____ \\  | |____| |____  | |__| | |__| | |___| |__| | |__| |\n");
    printf("\t \\_____\\____/|_|  |_|_____|______|_| \\_/_____/_/    \\_\\ |______|______|  \\____/ \\____/|______\\_____|\\____/ \n");


	
	do{
		printf("Elige una opción:\nSeleccionar cazador predeterminado (p) \nCrear nuevo cazador (n)\n");
		scanf(" %s", seleccion_c);
		if(strlen(seleccion_c) > 2){ 
			printf("Pon solo un caracter. \n");
		}
		if(seleccion_c[0] == 'p'|| seleccion_c[0] == 'P'){
			cazadores = cazador_predeterminado();
			for(int i = 0; i < 3; i++){
				mostrar_cazador(&cazadores[i]);
			}
			num_cazadores = 3;
			break;
		}else if(seleccion_c[0] == 'n' || seleccion_c[0] == 'N'){
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
		if(seleccion_c[0] == 'p'|| seleccion_c[0] == 'P'){
			dragones = dragon_predeterminado();
			for (int i = 0; i < 2; i++){
				mostrar_dragon(&dragones[i]);
			}
			num_dragones = 2;
			break;
		}else if(seleccion_c[0] == 'n'|| seleccion_c[0] == 'N'){
			dragones = crear_dragon(&num_dragones); 
			break;
		}else{
			printf("Elige una opción válida. \n");
		}
	}while (1);

	
	esperar_enter(); 

	system("clear");
	
	combate(cazadores, dragones, num_cazadores, num_dragones, &eleccion_cazador, &eleccion_dragon);
	
	printf("Demo terminada. Gracias por jugar.\n");

	free(cazadores);
	free(dragones);
	return 0;
}