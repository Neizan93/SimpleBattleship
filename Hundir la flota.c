#include "lib/libreria.h"
#include "game/funciones.h"

/*
	254 - No hay nada (por defecto)
	120 - Parte de barco
	126 - Agua
	111 - Tocado
*/

int cambiarIdioma(int idioma, int y, int x, int tablero1[x][y], int tablero2[x][y]);

int main(){
	fflush(stdin);
	const int x=10;
	const int y=10;
	
	int lang=2;//Idioma por defecto: 1- Ingles, 2- Español (por defecto, inglés).
	
	int tablero1[x][y];
	int tablero2[x][y];
	inicializarMatrizAValor(x, y, tablero1, 254);
	inicializarMatrizAValor(x, y, tablero2, 254);
	
	int opcion=0;
	
	system("COLOR 1A");
	
	printf("\n\n\n                                        # #  ( )\n                                  ___#_#___|__\n                                 _  |____________|  _\n                          _=====| | |            | | |==== _\n                    =====| |.---------------------------. | |====\n      <--------------------'   .  .  .  .  .  .  .  .   '--------------/\n        \\                                                             /\n         \\___________________________________________________________/\n     wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n    wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n      wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww \n\n\t\t\t");
	pauseLang(lang);
	limpiarPantalla();
	
	while(opcion!=4){
		limpiarPantalla();
		opcion=menuPrincipal(lang, x, y, tablero1, tablero2);
		switch(opcion){
		case 1 :
			inicializarMatrizAValor(x, y, tablero1, 254);
			inicializarMatrizAValor(x, y, tablero2, 254);
			playMenu(lang, x, y, tablero1, tablero2);
			break;
		case 2 :
			if(lang==1){
				system("start https://en.wikipedia.org/wiki/Battleship_(game)");
			}
			if(lang==2){
				system("start https://es.wikipedia.org/wiki/Batalla_naval_(juego)");
			}
			break;
		case 3:
			lang=cambiarIdioma(lang, y, x, tablero1, tablero2);
			break;
		case 4 :
			default:
				return 0;
				break;
		}
	}
	
	getch();
	return 0;
}

int cambiarIdioma(int idioma, int y, int x, int tablero1[x][y], int tablero2[x][y]){
	limpiarPantalla();
	imprimirMatrizEnTabla2Players(y, x, tablero1, tablero2);
	if(idioma==1){
		printf("\n\t\t\t\tLanguage:\n\n");
		printf("\t\t\t\t1.- English\n\n");
		printf("\t\t\t\t2.- Spanish\n\n");
		printf("\n\t\t\t\tChoose language: ");
		
	}
	else if(idioma==2){
		printf("\n\t\t\t\tIdioma:\n\n");
		printf("\t\t\t\t1.- Ingl%cs\n\n",130);
		printf("\t\t\t\t2.- Espa%col\n\n",164);
		printf("\n\t\t\t\tEscoge idioma: ");
	}
	fflush(stdin);
	do{
		scanf("%d",&idioma);
	}while(idioma<1 && idioma>2);
	
	return idioma;
}
