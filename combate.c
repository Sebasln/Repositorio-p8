#include "combate.h"
#include "cazador.h"
#include "dragon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Función para esperar a que el usuario presione Enter
void esperar_enter() {
    printf("\nPresiona Enter para continuar...");
    while (getchar() != '\n'); // Espera hasta que se presione Enter
}

// Función para determinar si el ataque es un golpe crítico (20% de probabilidad)
int es_critico() {
    return (rand() % 100) < 20;
}

// Verifica si quedan cazadores vivos
int quedan_cazadores_vivos(Cazador *cazadores, int num_cazadores) {
    for (int i = 0; i < num_cazadores; i++) {
        if (cazadores[i].vida > 0) {
            return 1;
        }
    }
    return 0;
}

int quedan_dragones_vivos(Dragon * dragones, int num_dragones) {
    for (int i = 0; i < num_dragones; i++) {
        if (dragones[i].vida > 0) {
            return 1;
        }
    }
    return 0;
}

// Elegir un cazador vivo
void seleccion_personaje(Cazador * cazadores, int num_cazadores, int * eleccion_cazador){
    do {
        printf("Elige un nuevo cazador (1 - %d): ", num_cazadores);
        if (scanf("%d", eleccion_cazador) != 1 || *eleccion_cazador < 1 || *eleccion_cazador > num_cazadores) {
            printf("Selección inválida. Intenta de nuevo.\n");
            while (getchar() != '\n');
        } else if (cazadores[*eleccion_cazador - 1].vida <= 0) {
            printf("Ese cazador está muerto. Elige otro.\n");
        } else {
            (*eleccion_cazador) -= 1;
            break;
        }
    } while (1);
}

// Elegir un dragón vivo
void seleccion_dragon(Dragon * dragones, int num_dragones, int * eleccion_dragon) {
    do {
        printf("Elige un nuevo dragón (1 - %d): ", num_dragones);
        if (scanf("%d", eleccion_dragon) != 1 || *eleccion_dragon < 1 || *eleccion_dragon > num_dragones) {
            printf("Selección inválida. Intenta de nuevo.\n");
            while (getchar() != '\n');
        } else if (dragones[*eleccion_dragon - 1].vida <= 0) {
            printf("Ese dragón ya está muerto. Elige otro.\n");
        } else {
            (*eleccion_dragon) -= 1;
            break;
        }
    } while (1);
}

// Combate con opción de golpes críticos y pausa entre ataques
void combate(Cazador *cazadores, Dragon *dragones, int num_cazadores, int num_dragones, int * eleccion_cazador, int * eleccion_dragon ) {
    srand(time(NULL));


    while (quedan_cazadores_vivos(cazadores, num_cazadores) && quedan_dragones_vivos(dragones, num_dragones)) {
        seleccion_personaje(cazadores, num_cazadores, eleccion_cazador);
        seleccion_dragon(dragones, num_dragones, eleccion_dragon);

        system("clear");
        printf("\n=== ¡Comienza el combate entre %s y %s! ===\n",
               cazadores[*eleccion_cazador].nombre,
               dragones[*eleccion_dragon].nombre);

        while (cazadores[*eleccion_cazador].vida > 0 && dragones[*eleccion_dragon].vida > 0) {
            esperar_enter(); // Pausa antes de cada turno

            // Turno del cazador
            int daño = cazadores[*eleccion_cazador].fuerza;
            if (es_critico()) {
                daño *= 2;
                printf("🔥 ¡Golpe CRÍTICO de %s! Hace %d de daño a %s.\n",
                       cazadores[*eleccion_cazador].nombre, daño, dragones[*eleccion_dragon].nombre);
            } else {
                printf("⚔️ %s ataca a %s. Hace %d de daño.\n",
                       cazadores[*eleccion_cazador].nombre, dragones[*eleccion_dragon].nombre, daño);
            }
            dragones[*eleccion_dragon].vida -= daño;

            if (dragones[*eleccion_dragon].vida <= 0) {
                printf("🎉 ¡%s ha derrotado al dragón %s!\n",
                       cazadores[*eleccion_cazador].nombre,
                       dragones[*eleccion_dragon].nombre);
                break;
            }

            esperar_enter(); // Pausa antes del turno del dragón

            // Turno del dragón
            daño = dragones[*eleccion_dragon].fuerza;
            if (es_critico()) {
                daño *= 2;
                printf("🔥 ¡Golpe CRÍTICO del dragón %s! Hace %d de daño a %s.\n",
                       dragones[*eleccion_dragon].nombre, daño, cazadores[*eleccion_cazador].nombre);
            } else {
                printf("🐉 %s ataca a %s. Hace %d de daño.\n",
                       dragones[*eleccion_dragon].nombre, cazadores[*eleccion_cazador].nombre, daño);
            }
            cazadores[*eleccion_cazador].vida -= daño;

            if (cazadores[*eleccion_cazador].vida <= 0) {
                printf("💀 ¡El dragón %s ha derrotado a %s!\n",
                       dragones[*eleccion_dragon].nombre,
                       cazadores[*eleccion_cazador].nombre);
                break;
            }
        }
    }

    if(quedan_cazadores_vivos(cazadores, num_cazadores) != 1){
    	printf("\n⚠️ No quedan cazadores vivos. ¡El juego ha terminado!\n");
	}else{
		printf("\n🥳 No quedan dragones vivos. ¡El juego ha terminado!\n");
	}
}
