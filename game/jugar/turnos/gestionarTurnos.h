#include "disparar.h"
#include "ganador.h"

extern void gestionarTurnos(
	int y, int x,
	int tablero1[x][y],
	int tablero2[x][y],
	int b1_barco1_2C[x][y],
	int b1_barco2_3C[x][y],
	int b1_barco3_3C[x][y],
	int b1_barco4_4C[x][y],
	int b1_barco5_5C[x][y],
	int b2_barco1_2C[x][y],
	int b2_barco2_3C[x][y],
	int b2_barco3_3C[x][y],
	int b2_barco4_4C[x][y],
	int b2_barco5_5C[x][y]){
		
	int ganador=0;
	
	int turno=0;
	time_t t;
	srand((unsigned) time(&t));
	turno=aleatorio(1,2);
	 
	do{
		switch(turno){
			case 1 :
				turno=realizarDisparo(x,y,
						turno,
				
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
				break;
			case 2 : 
				turno=realizarDisparo(x,y,
						turno,
	
						tablero2,
						tablero1,
						
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
					break;
			default :
				break;
		}
		
		ganador=comprobarGanador(turno, x, y, tablero1, tablero2); //Si hay ganador return 1, sino return 0

		if(ganador==1){
			limpiarPantalla();
			imprimirMatrizEnTabla2Players(x, y, tablero1, tablero2);
			anunciarGanador(turno);
			printf("\n\t\t");
			getch();
			turno=3;
		}
		
	}while(turno!=3);//Turno 3 = Fin de partida
	
}
