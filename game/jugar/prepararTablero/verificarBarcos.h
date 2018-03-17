extern int preVerificarBarco(int VerticaloHorizontal, int tamanyo, int posX, int posY, int posXant, int posYant, int posXorigen, int posYorigen, int x, int y, int tablero[x][y], int casilla){			
	
	if(posX<0 || posX>x){
		return 1;
	}
	
	if(posY<0 || posY>y){
		return 1;
	}
	
	if(tablero[posY][posX]==120){
		return 1;
	}
	
	if(casilla>=1){
		if((posY!=posYant-1 || posX!=posXant) && (posY!=posYant+1 || posX!=posXant) && (posX!=posXant-1 || posY!=posYant) && (posX!=posXant+1 || posY!=posYant)){
			return 1;
		}
	}
	if(casilla!=0 && casilla!=1){
		if(VerticaloHorizontal==1){//vertical
			if(posX!=posXorigen){
				return 1;
			}
			if(posY==posYant || posY==posYorigen){
				return 1;
			}
			if(posY>(posYorigen+(tamanyo-1)) && posY<(posYorigen+(tamanyo-1))){
				return 1;
			}
		}
		if(VerticaloHorizontal==2){//horizontal
			if(posY!=posYorigen){
				return 1;
			}
			if(posX==posXant || posX==posXorigen){
				return 1;
			}
			if(posX>(posXorigen+(tamanyo-1)) && posX<(posXorigen+(tamanyo-1))){
				return 1;
			}
			
		}
	}
	
	
	return 0;
}

extern int postVerificarBarco(int tamanyoDelBarco, int x, int y, int barco[x][y], int tablero[x][y]){//flag=1, barco no válido || flag=0 barco válido

	int i=0, j=0, puntoInicialX=0, puntoInicialY=0, puntoFinalX=0, puntoFinalY=0, aux=0;
//Condiciones para no ser válido (cuando se cumple realiza un return 1)

	//Obtener posiciones del barco inicial/final
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(barco[i][j]==120 && aux==0){
				puntoInicialX=i;
				puntoInicialY=j;
				aux++;
			}
			if(barco[i][j]==120){
				puntoFinalX=i;
				puntoFinalY=j;
			}
		}
	}
	
	//Comprovar si es vertical o horizontal
		//Horizontal
	if(puntoInicialX==puntoFinalX){
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				if(i!=puntoInicialX && barco[i][j]==120){
					return 1;
				}
			}
		}
	}
		//Vertical
	if(puntoInicialY==puntoFinalY){
		for(i=0;i<x;i++){
			for(j=0;j<y;j++){
				if(j!=puntoInicialY && barco[i][j]==120){			
					return 1;
				}
			}
		}
	}
		
	//Error
	if(puntoInicialX!=puntoFinalX && puntoInicialY!=puntoFinalY){
		return 1;
	}
	  
//Si pasa todas las verificaciones realizará un return 0
	return 0;
}

extern int obtenerPosicionBarco(int posX, int posY, int posXant, int posYant){//return=1 vertical | return=2 horizontal
	if(posXant==posX){
		return 1;//vertical
	}
	else if(posYant==posY){
		return 2;//horizontal
	}
	return 0;
}

extern int verificarPosicionBarco(int pos, int posX, int posY, int posXant, int posYant){//pos=1 vertical | pos=2 horizontal
	if(pos==1){
		if(posXant!=posX){
			return 1;
		}
	}
	if(pos==2){
		if(posYant!=posY){
			return 1;
		}
	}
	return 0;
}
