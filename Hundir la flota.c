#include "lib/libreria.h"
#include "game/funciones.h"

/*
	254 - No hay nada (por defecto)
	120 - Parte de barco
	126 - Agua
	111 - Tocado
*/

int main(){
	
	const int x=10;
	const int y=10;
	
	int tablero1[x][y];
	int tablero2[x][y];
	inicializarMatrizAValor(x, y, tablero1, 254);
	inicializarMatrizAValor(x, y, tablero2, 254);
	
	int opcion=0;
	
	system("COLOR 1A");
	
	printf("\n\n\n                                        # #  ( )\n                                  ___#_#___|__\n                                 _  |____________|  _\n                          _=====| | |            | | |==== _\n                    =====| |.---------------------------. | |====\n      <--------------------'   .  .  .  .  .  .  .  .   '--------------/\n        \\                                                             /\n         \\___________________________________________________________/\n     wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n    wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n      wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww \n\n\t\t");
	system("pause");
	limpiarPantalla();
	
	while(opcion!=3){
		limpiarPantalla();
		opcion=menuPrincipal(x, y, tablero1, tablero2);
		switch(opcion){
		case 1 :
			inicializarMatrizAValor(x, y, tablero1, 254);
			inicializarMatrizAValor(x, y, tablero2, 254);
			playMenu(x, y, tablero1, tablero2);
			break;
		case 2 :
			system("start https://es.wikipedia.org/wiki/Batalla_naval_(juego)");
			break;
		case 3 :
			default:
				return 0;
				break;
		}
	}
	
	getch();
	return 0;
}
