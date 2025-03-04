#include "combate.h"
#include "cazador.h"
#include "dragon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



void seleccion_personaje(Cazador * cazadores, int n, int * eleccion_cazador, int * eleccion_dragon){
	
	printf("Elije un personaje(1 - %d):\n", n);
	scanf("%d", eleccion_cazador);
	(*eleccion_cazador) -= 1;


}
void seleccion_dragon(Dragon * dragones, int n, int * eleccion_cazador, int * eleccion_dragon){

	printf("Elije un dragón(1 - %d):\n", n);
	scanf("%d", eleccion_dragon);
	(*eleccion_dragon) -= 1;

}

void combate(Cazador * cazadores, Dragon * dragones, int * eleccion_cazador, int * eleccion_dragon){
	printf("Empieza el combate entre el cazador %s y el dragón %s.\n", cazadores[*eleccion_cazador].nombre, dragones[*eleccion_dragon].nombre);
	
	while (cazadores[*eleccion_cazador].vida > 0 && dragones[*eleccion_dragon].vida > 0) {
        // Turno del cazador
        dragones[*eleccion_dragon].vida -= cazadores[*eleccion_cazador].fuerza;
        printf("%s ataca a %s. Vida del dragón: %d\n",
               cazadores[*eleccion_cazador].nombre,
               dragones[*eleccion_dragon].nombre,
               dragones[*eleccion_dragon].vida);

        if (dragones[*eleccion_dragon].vida <= 0) {
            printf("¡%s ha derrotado al dragón %s!\n",
                   cazadores[*eleccion_cazador].nombre,
                   dragones[*eleccion_dragon].nombre);
            return;
        }

        // Turno del dragón
        cazadores[*eleccion_cazador].vida -= dragones[*eleccion_dragon].fuerza;
        printf("%s ataca a %s. Vida del cazador: %d\n",
               dragones[*eleccion_dragon].nombre,
               cazadores[*eleccion_cazador].nombre,
               cazadores[*eleccion_cazador].vida);

        if (cazadores[*eleccion_cazador].vida <= 0) {
            printf("¡El dragón %s ha derrotado a %s!\n",
                   dragones[*eleccion_dragon].nombre,
                   cazadores[*eleccion_cazador].nombre);
            return;
        }
    }
}