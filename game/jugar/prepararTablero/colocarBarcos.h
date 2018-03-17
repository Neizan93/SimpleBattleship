#include "verificarBarcos.h"

void colocarUnBarco(int tamanyo, char nombreBarco[], int x, int y, int barco[x][y], int tablero1[x][y], int tablero2[x][y]);
void imprimirMatrizEnTabla2PlayersContinuacion(int y, int x, int matriz1[x][y], int matriz2[x][y], int posXant, int posYant, int posXorigen, int posYorigen, int pos, int parte);

extern void colocarBarcos(int x,int y,int tablero1[x][y], int tablero2[x][y], int barco1_2C[x][y], int barco2_3C[x][y],int barco3_3C[x][y],int barco4_4C[x][y],int barco5_5C[x][y]) {
	int tamanyoBarco=0;
	int flag=0;
	char lancha[]={"Lancha"};
	char bote[]={"Bote"};
	char sub[]={"Submarino"};
	char tran[]={"Transanlantico"};
	char guerr[]={"Barco de guerra"};
	
	int tableroVacio[x][y];
	inicializarMatrizAValor(x, y, tableroVacio, 254);
		
	limpiarPantalla();
	imprimirMatrizEnTabla2Players(y, x, tablero1, tableroVacio);
	
	printf("\n\t\t == ES EL MOMENTO DE COLOCAR TUS BARCOS == \n");
	printf("\n\t\t ======= INTRODUCE LAS COORDENADAS ======= \n");
	
	do{
		tamanyoBarco=2;
		colocarUnBarco(tamanyoBarco, lancha, x, y, barco1_2C, tablero1, tableroVacio);
		
		flag=postVerificarBarco(tamanyoBarco, x, y, barco1_2C, tablero1);
		//printError(flag);
	}while(flag==1);
		
	do{
		tamanyoBarco=3;
		colocarUnBarco(tamanyoBarco, bote, x, y, barco2_3C, tablero1, tableroVacio);
		
		flag=postVerificarBarco(tamanyoBarco, x, y, barco2_3C, tablero1);
		//printError(flag);
	}while(flag==1);
		
	do{
		tamanyoBarco=3;
		colocarUnBarco(tamanyoBarco, sub, x, y, barco3_3C, tablero1, tableroVacio);
		
		flag=postVerificarBarco(tamanyoBarco, x, y, barco3_3C, tablero1);
		//printError(flag);
	}while(flag==1);
		
	do{
		tamanyoBarco=4;
		colocarUnBarco(tamanyoBarco, tran, x, y, barco4_4C, tablero1, tableroVacio);
		
		flag=postVerificarBarco(tamanyoBarco, x, y, barco4_4C, tablero1);
		//printError(flag);
	}while(flag==1);
	
	do{
		tamanyoBarco=5;
		colocarUnBarco(tamanyoBarco, guerr, x, y, barco5_5C, tablero1, tableroVacio);
		
		flag=postVerificarBarco(tamanyoBarco, x, y, barco5_5C, tablero1);
		//printError(flag);
	}while(flag==1);
	
}

void colocarUnBarco(int tamanyo, char nombreBarco[], int x, int y, int barco[x][y], int tablero1[x][y], int tablero2[x][y]){
/*	Un barco debe ocupar tantas casillas como este mide
	las casillas deben ser consecutivas, vertical o horizontalmente
	además debe verificarse que la posición del barco se encuentra dentro del rango del tablero.
	ni tampoco ocupar un espacio ya ocupado
*/
	int pos=0; //pos=0 sin definir aun | pos=1 vertical | pos=2 horizontal
	char letra;
	int posX=0,posY=0,i=0,posXant=0,posYant=0, posXorigen=0, posYorigen=0;
	int check=0;
	
	printf("\n\t\t\t %s (%d casillas):\n",nombreBarco, tamanyo);
	
	for (i=0;i<tamanyo;i++){
		if(i==0){
			do{
				printf("\n \t\t\t  Casilla %d/%d: ", i+1,tamanyo);
				scanf(" %c%i",&letra,&posY);
				
				posX=letraANumero(letra);
				posY=posY-1;
				
				check=0;
				check=preVerificarBarco(pos, tamanyo, posX, posY, posXant, posYant, posXorigen, posYorigen, x, y, tablero1, i);
			}while(check==1 || posX==100);
			posXorigen=posX;
			posYorigen=posY;
		}
		else if(i==1){
			do{
				limpiarPantalla();
				imprimirMatrizEnTabla2PlayersContinuacion(y, x, tablero1, tablero2, posXant, posYant, posXorigen, posYorigen, pos, i);
				printf("\n \t\t\t  Casilla %d/%d: ", i+1,tamanyo);
				scanf(" %c%i",&letra,&posY);
			
				posX=letraANumero(letra);
				posY=posY-1;
				
				check=0;
				
				pos=obtenerPosicionBarco(posX, posY, posXant, posYant);//pos=1 vertical | pos=2 horizontal | pos=0 error
				
				check=preVerificarBarco(pos, tamanyo, posX, posY, posXant, posYant, posXorigen, posYorigen, x, y, tablero1, i);//pos=1 vertical | pos=2 horizontal
				
			}while(check==1 || posX==100 || pos==0);
		}
		else if(i!=0 && i!=1){
			do{
				limpiarPantalla();
				imprimirMatrizEnTabla2PlayersContinuacion(y, x, tablero1, tablero2, posXant, posYant, posXorigen, posYorigen, pos, i);
				printf("\n \t\t\t  Casilla %d/%d: ", i+1,tamanyo);
				scanf(" %c%i",&letra,&posY);
			
				posX=letraANumero(letra);
				posY=posY-1;
				
				check=0;
				check=preVerificarBarco(pos, tamanyo, posX, posY, posXant, posYant, posXorigen, posYorigen, x, y, tablero1, i);
					if(check==0){
						check=verificarPosicionBarco(pos, posX, posY, posXant, posYant);
					}				
			}while(check==1 || posX==100);
			
		}
		barco[posY][posX]=120;
		tablero1[posY][posX]=120;
		posXant=posX;
		posYant=posY;
	}
	
	limpiarPantalla();
	imprimirMatrizEnTabla2Players(y, x, tablero1, tablero2);
}

void imprimirMatrizEnTabla2PlayersContinuacion(int y, int x, int matriz1[x][y], int matriz2[x][y], int posXant, int posYant, int posXorigen, int posYorigen, int pos, int parte){ //Ejemplo de uso imprimirMatrizEnTabla(8, 8, matriz);
	
	int i=0, j=0;
	
	printf("\n\t    A B C D E F G H I J \t\t    A B C D E F G H I J \n");
	printf("\t   --------------------\t\t\t   -------------------- \n");
	for(i=0;i<x;i++){
		printf("\t");
		if(i<9){
			printf("%d | ",i+1);
		}
		if(i>=9){
			printf("%d| ",i+1);
		}
		for(j=0;j<y;j++){
			if(pos==1){//vertical
				if((j==posXant &&  (i==posYant-1 || i==posYant+1)) && matriz1[i][j]==254){		
					printf("*");
					printf(" ");	
				}
				else{
					printf("%c", matriz1[i][j]);
					printf(" ");	
				}
			}
			if(pos==2){//horizontal
				if((i==posYant &&  (j==posXant-1 || j==posXant+1)) && matriz1[i][j]==254){		
					printf("*");
					printf(" ");	
				}
				else{
					printf("%c", matriz1[i][j]);
					printf(" ");	
				}
			}
			if(pos==0){//sin definir
				if(((j==posXant &&  (i==posYant-1 || i==posYant+1)) || (i==posYant &&  (j==posXant-1 || j==posXant+1))) && matriz1[i][j]==254){		
					printf("*");
					printf(" ");	
				}
				else{
					printf("%c", matriz1[i][j]);
					printf(" ");	
				}
			}
		}
				printf("\t||\t");
				
		if(i<9){
			printf("%d | ",i+1);
		}
		if(i>=9){
			printf("%d| ",i+1);
		}
		for(j=0;j<y;j++){
			printf("%c", 254);
			printf(" ");
		}
		printf("\n");
	}
}
