#include "prepararTablero/colocarBarcos.h"
#include "turnos/gestionarTurnos.h"
extern void playMenu(int lang, int x, int y, int tablero1[x][y], int tablero2[x][y]){
	/*
         A           B          C          D          E          F          G          H          I          J
    1    0,0        0,1        0,2        0,3        0,4        0,5        0,6        0,7        0,8        0,9
    2    1,0        1,1        1,2        1,3        1,4        1,5        1,6        1,7        1,8        1,9
    3    2,0        2,1        2,2        2,3        2,4        2,5        2,6        2,7        2,8        2,9
    4    3,0        3,1        3,2        3,3        3,4        3,5        3,6        3,7        3,8        3,9
    5    4,0        4,1        4,2        4,3        4,4        4,5        4,6        4,7        4,8        4,9
    6    5,0        5,1        5,2        5,3        5,4        5,5        5,6        5,7        5,8        5,9
    7    6,0        6,1        6,2        6,3        6,4        6,5        6,6        6,7        6,8        6,9
    8    7,0        7,1        7,2        7,3        7,4        7,5        7,6        7,7        7,8        7,9
    9    8,0        8,1        8,2        8,3        8,4        8,5        8,6        8,7        8,8        8,9
   10    9,0        9,1        9,2        9,3        9,4        9,5        9,6        9,7        9,8        9,9
    */
	
	int b1_barco1_2C[x][y];
	int b1_barco2_3C[x][y];
	int b1_barco3_3C[x][y];
	int b1_barco4_4C[x][y];
	int b1_barco5_5C[x][y];
	
	int b2_barco1_2C[x][y];
	int b2_barco2_3C[x][y];
	int b2_barco3_3C[x][y];
	int b2_barco4_4C[x][y];
	int b2_barco5_5C[x][y];
	
	inicializarMatrizAValor(x,y,b1_barco1_2C, 254);
	inicializarMatrizAValor(x,y,b1_barco2_3C, 254);
	inicializarMatrizAValor(x,y,b1_barco3_3C, 254);
	inicializarMatrizAValor(x,y,b1_barco4_4C, 254);
	inicializarMatrizAValor(x,y,b1_barco5_5C, 254);
	
	inicializarMatrizAValor(x,y,b2_barco1_2C, 254);
	inicializarMatrizAValor(x,y,b2_barco2_3C, 254);
	inicializarMatrizAValor(x,y,b2_barco3_3C, 254);
	inicializarMatrizAValor(x,y,b2_barco4_4C, 254);
	inicializarMatrizAValor(x,y,b2_barco5_5C, 254);
	
	limpiarPantalla();
	if(lang==1){//1- Ingles
		printf("\n\n\n\n\t\tIt's player 1's turn\n\t\t");
	}
	if(lang==2){//2- Español
		printf("\n\n\n\n\t\tTurno del jugador 1\n\t\t");
	}
    
    pauseLang(lang);
    colocarBarcos(lang, x, y, tablero1, tablero2, b1_barco1_2C, b1_barco2_3C, b1_barco3_3C, b1_barco4_4C, b1_barco5_5C);

    limpiarPantalla();
    if(lang==1){
		printf("\n\n\n\n\t\tIt's player 2's turn\n\t\t");
	}
	if(lang==2){
		printf("\n\n\n\n\t\tTurno del jugador 2\n\t\t");
	}
    pauseLang(lang);
    colocarBarcos(lang, x, y, tablero2, tablero1, b2_barco1_2C, b2_barco2_3C, b2_barco3_3C, b2_barco4_4C, b2_barco5_5C);
	
	gestionarTurnos(lang,
					x,y,
					tablero1,
					tablero2,
					
					b1_barco1_2C,
					b1_barco2_3C,
					b1_barco3_3C,
					b1_barco4_4C,
					b1_barco5_5C,
					
					b2_barco1_2C,
					b2_barco2_3C,
					b2_barco3_3C,
					b2_barco4_4C,
					b2_barco5_5C
					
					);
}
