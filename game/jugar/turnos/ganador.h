extern int comprobarGanador(int jugador, int x, int y, int tablero1[x][y], int tablero2[x][y]){//Si hay ganador return 1, sino return 0
	int i=0, j=0;
	
	if(jugador==1){
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				if(tablero1[i][j]==120){//Si encuentra parte de un barco enemigo intacta, return 0
					return 0;
				}
			}
		}
	}
	
	if(jugador==2){
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				if(tablero2[i][j]==120){//Si encuentra parte de un barco enemigo intacta, return 0
					return 0;
				}
			}
		}
	}
	
	return 1; //No se ha encontrado un barco intacto en el tablero enemigo, el jugador actual ha ganado.
}

extern void anunciarGanador(int jugador){
	printf("\n\n\t\t");
	printf("Ha ganado el jugador %d\n", jugador);
} 
