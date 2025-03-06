#include "historia.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void escribirGradualmente(const char *texto, int delay) {
    while (*texto) {
        putchar(*texto);        
        fflush(stdout);         
        usleep(delay);          
        texto++;                
    }
}


void historia_inicial(){

    escribirGradualmente("Hace muchos años, el reino de Drakoria fue sumido en el caos,\n", 9000);
    escribirGradualmente("bajo el poder destructivo de tres temibles dragones: Shenlong,\n", 9000);
    escribirGradualmente("Kaido, y Yilin, la dragona de la tormenta. Estos monstruos\n", 9000);
    escribirGradualmente("destruyeron ciudades, arrasaron aldeas y sumieron a la humanidad\n", 9000);
    escribirGradualmente("en la desesperación.\n", 9000);
  

    escribirGradualmente("Sin embargo, un valiente grupo de guerreros logró sellar a los\n", 9000);
    escribirGradualmente("dragones en un abismo oscuro, donde permanecieron por generaciones.\n", 9000);
    escribirGradualmente("La humanidad, finalmente libre de la amenaza dracónica, comenzó a\n", 9000);
    escribirGradualmente("recuperarse y prosperar. Durante siglos, el reino vivió en paz.\n", 9000);
  

    escribirGradualmente("Pero esa paz se rompió cuando, un día, los tres dragones regresaron.\n", 9000);
    escribirGradualmente("Shenlong, el dragón de los deseos, resurgió con más poder que nunca,\n", 9000);
    escribirGradualmente("y Kaido, el destructor, trajo consigo un ejército de criaturas\n", 9000);
    escribirGradualmente("desgarradoras. Pero lo peor estaba por llegar... Yilin, la dragona\n", 9000);
    escribirGradualmente("de la tormenta, fue liberada, trayendo consigo vientos furiosos\n", 9000);
    escribirGradualmente("y tormentas que devastaban todo a su paso.\n", 9000);
  

    escribirGradualmente("El reino de Drakoria, ahora nuevamente amenazado, se encuentra\n", 9000);
    escribirGradualmente("al borde de la extinción. Las ciudades se derrumban bajo el poder\n", 9000);
    escribirGradualmente("de los dragones, y la desesperación se apodera de sus habitantes.\n", 9000);
  

    escribirGradualmente("Pero, en medio de esta oscuridad, tres cazadores se levantan\n", 9000);
    escribirGradualmente("como la última esperanza del reino: Roberto, un experto espadachín;\n", 9000);
    escribirGradualmente("Miguel, un mago de fuego con un gran deseo de venganza; y Sebas,\n", 9000);
    escribirGradualmente("un luchador con habilidades místicas que se conecta con la naturaleza.\n", 9000);
  

    escribirGradualmente("Ellos han jurado derrotar a los dragones y salvar Drakoria de la\n", 9000);
    escribirGradualmente("destrucción total. Sin embargo, deberán enfrentarse a tres de los\n", 9000);
    escribirGradualmente("enemigos más poderosos que el mundo haya conocido: Shenlong,\n", 9000);
    escribirGradualmente("Kaido y la furiosa Yilin.\n", 9000);
  

    escribirGradualmente("El futuro de Drakoria está en sus manos. ¿Serán capaces de\n", 9000);
    escribirGradualmente("detener la furia de los tres dragones? ¡La aventura comienza ahora!\n", 9000);

    printf("\nPresiona Enter para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

  
}

void historia_final_bueno(){
	escribirGradualmente("Tras muchas batallas difíciles, los cazadores finalmente logran\n", 9000);
    escribirGradualmente("derrotar a los tres dragones. Shenlong, Kaido y Yilin caen uno\n", 9000);
    escribirGradualmente("tras otro, derrotados por la valentía, astucia y coraje de los tres\n", 9000);
    escribirGradualmente("héroes.\n", 9000);


    escribirGradualmente("Shenlong, el dragón de los deseos, finalmente sucumbe a los golpes\n", 9000);
    escribirGradualmente("de Roberto, quien lo enfrenta con una espada afilada por su propio\n", 9000);
    escribirGradualmente("deseo de venganza. Kaido, el destructor, cae ante la magia de Miguel,\n", 9000);
    escribirGradualmente("quien canaliza toda su furia hacia el dragón, y Yilin, la dragona de\n", 9000);
    escribirGradualmente("la tormenta, es derrotada por Sebas, quien usa su conexión mística\n", 9000);
    escribirGradualmente("para calmar los vientos y neutralizar su poder devastador.\n", 9000);


    escribirGradualmente("El reino de Drakoria, finalmente libre de los dragones, comienza a\n", 9000);
    escribirGradualmente("recuperarse. Las ciudades, arrasadas por el caos, florecen nuevamente.\n", 9000);
    escribirGradualmente("Los cazadores son celebrados como héroes, y su valentía será recordada\n", 9000);
    escribirGradualmente("por generaciones.\n", 9000);


    escribirGradualmente("Sin embargo, los cazadores saben que su victoria no fue fácil. Cada uno\n", 9000);
    escribirGradualmente("de ellos tuvo que hacer sacrificios, pero el reino les está eternamente\n", 9000);
    escribirGradualmente("agradecido. Los tres héroes continúan su viaje, sabiendo que el reino\n", 9000);
    escribirGradualmente("está a salvo... por ahora.\n", 9000);


    escribirGradualmente("FIN - ¡El reino ha sido salvado!\n", 9000);
    printf("\nPresiona Enter para finalizar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

}

void historia_final_malo(){
	escribirGradualmente("A pesar de los esfuerzos de los cazadores, los tres dragones resultaron\n", 9000);
    escribirGradualmente("ser demasiado poderosos. Shenlong, Kaido y Yilin demostraron que\n", 9000);
    escribirGradualmente("sus fuerzas eran incontrolables, y los cazadores sucumbieron ante su poder.\n", 9000);
    

    escribirGradualmente("Roberto, con su espada, cayó ante Shenlong, cuyo poder sobre los deseos\n", 9000);
    escribirGradualmente("lo sumió en una ilusión mortal. Miguel, el mago de fuego, luchó con\n", 9000);
    escribirGradualmente("valentía, pero no pudo contener la furia destructiva de Kaido, el dragón\n", 9000);
    escribirGradualmente("de la destrucción. Yilin, la dragona de la tormenta, arrasó con Sebas,\n", 9000);
    escribirGradualmente("cuya conexión con la naturaleza no fue suficiente para calmar la furia de\n", 9000);
    escribirGradualmente("la tormenta.\n", 9000);
    

    escribirGradualmente("Los dragones dominaron el reino. Shenlong, Kaido y Yilin desataron su\n", 9000);
    escribirGradualmente("furia sobre las ciudades, destruyéndolo todo a su paso. Los pocos supervivientes\n", 9000);
    escribirGradualmente("se dispersaron por el mundo, huyendo de la destrucción total.\n", 9000);
    

    escribirGradualmente("La esperanza se desvaneció, y Drakoria quedó sumida en la oscuridad,\n", 9000);
    escribirGradualmente("bajo el yugo de los dragones. El reino nunca volverá a ser lo que fue,\n", 9000);
    escribirGradualmente("y la humanidad queda al borde de la extinción.\n", 9000);
    

    escribirGradualmente("FIN - El reino ha sucumbido al poder de los dragones.\n", 9000);
    printf("\nPresiona Enter para finalizar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}