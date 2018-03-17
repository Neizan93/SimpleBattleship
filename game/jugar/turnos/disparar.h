int tocarBarco(int posX, int posY, int x, int y, int jugador, int b1_barco1_2C[x][y], int b1_barco2_3C[x][y], int b1_barco3_3C[x][y], int b1_barco4_4C[x][y], int b1_barco5_5C[x][y], int b2_barco1_2C[x][y], int b2_barco2_3C[x][y], int b2_barco3_3C[x][y], int b2_barco4_4C[x][y], int b2_barco5_5C[x][y]);
int checkContinue(int jugador, int x, int y, int tablero1[x][y], int tablero2[x][y]);

//comprobarHundido: Si es hundido return 1 || Si no, return 0
int comprobarHundido(int barco, int x, int y, int jugador, int b1_barco1_2C[x][y], int b1_barco2_3C[x][y], int b1_barco3_3C[x][y], int b1_barco4_4C[x][y], int b1_barco5_5C[x][y], int b2_barco1_2C[x][y], int b2_barco2_3C[x][y], int b2_barco3_3C[x][y], int b2_barco4_4C[x][y], int b2_barco5_5C[x][y]);

extern int realizarDisparo(int y, int x,
						int jugador,
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
						int b2_barco5_5C[x][y]
						){
	
	
	char letra='\0';
    int posY=0, posX=0, comprobar=0, barco=0, ocupado=0, hundido=0, ganador=0;
	
	do{
		if(ocupado==0){
			limpiarPantalla();
			printf("\n\n\n\n\t\tTurno del jugador %d\n\t\t", jugador);
			printf("\n\t\t");
			pause();
		}
		ocupado=0;
		
		limpiarPantalla();
		imprimirMatrizEnTabla2PlayersInGame(y, x, tablero1, tablero2);
		
		
		
		//Realizar disparo
		do{
			printf("\n\t\t Donde desea realizar el disparo: ");
			scanf(" %c%i",&letra,&posY);
			posX=letraANumero(letra);
		    posY=posY-1;
		    
		    if((posX>x && posY>y) && (posX<0 && posY<0)){
		    	printf("\n\t\t El disparo debe de ser dentro del tablero \n\t\t Int%cntelo otra vez:", 130);
			}
	    }while((posX>x || posY>y) || (posX<0 || posY<0));
		
		//Comprobar Disparo
		comprobar=tablero2[posY][posX];
		
		
		/*
			254 - No hay nada (por defecto)
			120 - Parte de barco
			126 - Agua
			111	- Tocado
		*/
		switch(comprobar){
			case 254:
				tablero2[posY][posX]=126;
				ocupado=0;
			
				limpiarPantalla();
				imprimirMatrizEnTabla2PlayersInGame(y, x, tablero1, tablero2);
				printf("\n\n\t\t Has tocado AGUA\n");
				
				break;
			
			case 120:
				tablero2[posY][posX]=111;
				barco=0;
				do{
					barco=tocarBarco(posX, posY, x, y, jugador, b1_barco1_2C, b1_barco2_3C, b1_barco3_3C, b1_barco4_4C, b1_barco5_5C, b2_barco1_2C, b2_barco2_3C, b2_barco3_3C, b2_barco4_4C, b2_barco5_5C);
				}while(barco==0);
				
				ocupado=1;
				
				limpiarPantalla();
				imprimirMatrizEnTabla2PlayersInGame(y, x, tablero1, tablero2);
				
				printf("\n\n\t\t Has TOCADO un barco");
				hundido=0;
				hundido=comprobarHundido(barco, x, y, jugador, b1_barco1_2C, b1_barco2_3C, b1_barco3_3C, b1_barco4_4C, b1_barco5_5C, b2_barco1_2C, b2_barco2_3C, b2_barco3_3C, b2_barco4_4C, b2_barco5_5C);//1=hundido, 0=tocado
					if(hundido==1){
						printf("\n\t\t y adem%cs lo has HUNDIDO\n",160);
					}
					ganador=checkContinue(jugador, x, y, tablero1, tablero2);
					if(ganador==0){
						printf("\n\n\t\t Vuelves a disparar hasta que falles!\n");
					}
				break;	
			
			case 126:
			case 111:
				limpiarPantalla();
				imprimirMatrizEnTabla2PlayersInGame(y, x, tablero1, tablero2);
				
				printf("\n\n\t\t Ya has realizado un disparo aqui.\n");
				ocupado=1;
				break;
			default:
				printf("\n\n\t\t ERROR!,");
				printf("\n\n\t\t int%cntalo otra vez.",130);
				ocupado=1;
				break;
		}
		printf("\n\n\t\t");
		pause();	
	}while(ocupado==1 && ganador==0);

	if(jugador==1){
		return 2;
	}
	if(jugador==2){
		return 1;
	}
	
	return jugador;//Si hay un error en el cambio de turno, se repite el turno
}

int tocarBarco(	int posX, int posY,
				int x, int y,
				int jugador,
				int b1_barco1_2C[x][y],
				int b1_barco2_3C[x][y],
				int b1_barco3_3C[x][y],
				int b1_barco4_4C[x][y],
				int b1_barco5_5C[x][y],
				int b2_barco1_2C[x][y],
				int b2_barco2_3C[x][y],
				int b2_barco3_3C[x][y],
				int b2_barco4_4C[x][y],
				int b2_barco5_5C[x][y]
			){
	int i=0, j=0;
	
	if(jugador==1){
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				
				if(b2_barco1_2C[posY][posX]==120){
					b2_barco1_2C[posY][posX]=111;
					return 1;
				}
				
				if(b2_barco2_3C[posY][posX]==120){
					b2_barco2_3C[posY][posX]=111;
					return 2;		
				}
				
				if(b2_barco3_3C[posY][posX]==120){
					b2_barco3_3C[posY][posX]=111;
					return 3;
				}
				
				if(b2_barco4_4C[posY][posX]==120){
					b2_barco4_4C[posY][posX]=111;
					return 4;
				}
				
				if(b2_barco5_5C[posY][posX]==120){
					b2_barco5_5C[posY][posX]=111;
					return 5;
				}
			}
		}
	}
	
	if(jugador==2){
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				
				if(b1_barco1_2C[posY][posX]==120){
					b1_barco1_2C[posY][posX]=111;
					return 1;
				}
				
				if(b1_barco2_3C[posY][posX]==120){
					b1_barco2_3C[posY][posX]=111;
					return 2;		
				}
				
				if(b1_barco3_3C[posY][posX]==120){
					b1_barco3_3C[posY][posX]=111;
					return 3;
				}
				
				if(b1_barco4_4C[posY][posX]==120){
					b1_barco4_4C[posY][posX]=111;
					return 4;
				}
				
				if(b1_barco5_5C[posY][posX]==120){
					b1_barco5_5C[posY][posX]=111;
					return 5;
				}
			}
		}
	}
	return 0; // return 0 -> Error al detectar barco
}

int comprobarHundido(	int barco,			//Si es hundido return 1 || Si no, return 0
						int x, int y,
						int jugador,
						int b1_barco1_2C[x][y],
						int b1_barco2_3C[x][y],
						int b1_barco3_3C[x][y],
						int b1_barco4_4C[x][y],
						int b1_barco5_5C[x][y],
						int b2_barco1_2C[x][y],
						int b2_barco2_3C[x][y],
						int b2_barco3_3C[x][y],
						int b2_barco4_4C[x][y],
						int b2_barco5_5C[x][y]
					){
	int i=0, j=0;
	
	int barcoAuxiliar[x][y];
	inicializarMatrizAValor(x,y,barcoAuxiliar, 254);
	
	//Comprobar el barco tocado y pasarlo al barcoAuxiliar
	if(jugador==1){
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				if(barco==1){
					barcoAuxiliar[i][j]=b2_barco1_2C[i][j];
				}
				if(barco==2){
					barcoAuxiliar[i][j]=b2_barco2_3C[i][j];		
				}
				if(barco==3){
					barcoAuxiliar[i][j]=b2_barco3_3C[i][j];
				}
				if(barco==4){
					barcoAuxiliar[i][j]=b2_barco4_4C[i][j];
				}
				if(barco==5){
					barcoAuxiliar[i][j]=b2_barco5_5C[i][j];
				}
			}
		}
	}
	if(jugador==2){
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				if(barco==1){
					barcoAuxiliar[i][j]=b1_barco1_2C[i][j];
				}
				if(barco==2){
					barcoAuxiliar[i][j]=b1_barco2_3C[i][j];		
				}
				if(barco==3){
					barcoAuxiliar[i][j]=b1_barco3_3C[i][j];
				}
				if(barco==4){
					barcoAuxiliar[i][j]=b1_barco4_4C[i][j];
				}
				if(barco==5){
					barcoAuxiliar[i][j]=b1_barco5_5C[i][j];
				}
			}
		}
	}
	

	//Comprobar si el barco está hundido
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(barcoAuxiliar[i][j]==120){
				return 0; //Ha encontrado parte del barco intacta, devuelve 0
			}
		}
	}
	
	return 1; //No ha encontrado parte del barco intacta, devuelve 1
}

int checkContinue(int jugador, int x, int y, int tablero1[x][y], int tablero2[x][y]){//Si hay ganador return 1, sino return 0
	int i=0, j=0;
	
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				if(tablero1[i][j]==120){//Si encuentra parte de un barco enemigo intacta, return 0
					return 0;
				}
				else if(tablero2[i][j]==120){//Si encuentra parte de un barco enemigo intacta, return 0
					return 0;
				}
			}
			
		}
	return 1; //No se ha encontrado un barco intacto en el tablero enemigo, el jugador actual ha ganado.
}
