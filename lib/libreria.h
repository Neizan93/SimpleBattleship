#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#include<direct.h>
#include<ctype.h>

#define DEBUG  	printf("\n"); 	printf("Nombre del archivo actual: %s",strrchr(__FILE__,'\\')+1); 	printf("\n"); 	printf("Funcion actual: %s",__func__); printf("\n"); printf("Linea actual: %d",__LINE__); 	printf("\n"); 	printf("Ruta completa al archivo actual: %s",__FILE__);

//ARRAYS

	//VECTORES
	
extern void introducirElementoAVectorEnRango(int size, int vector[size], int x, int y, int valor){
	int i=0;
	for(i=0;i<size;i++){
		if(i<=x && i>=y){
			vector[i]=valor;
		}
	};
}

extern void inicializarArray1DAValor(int x, int matriz[x], int valor){
	int i;
	for(i=0;i<x;i++){
			matriz[i]=valor;
	}	
}

extern void imprimirVector(int x, int matriz[x]){
	int i=0;
	
	printf("\t");
	for(i=0;i<x;i++){
		//printf("Pos%d:\t ",++k);
	}
	printf("\n");
	for(i=0;i<x;i++){
		printf("%d", matriz[i]);
		printf("\t");
	}
}

extern void eliminarDuplicadosDeVector1d(int size, int arr[size]){
   int i=0, j=0, k=0;
   for(i=0; i<size; i++){
   		for(j=i+1; j<size; j++){
            if(arr[i] == arr[j]){
                for(k=j; k<size; k++){
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
	    }
    }

}

extern void imprimirElementosRepetidos1d(int x, int array[x]){
	int i=0, j=0, count=1;
	int freq[x];
    for(i=0; i<x; i++){
        count = 1;
        for(j=i+1; j<x; j++){
            if(array[i]==array[j]){
                count++;
                freq[j] = 0;
            }
        }

        if(freq[i] != 0){
            freq[i] = count;
        }
    }

    printf("\nFrecuencia de todos los elementos de array: \n");
    for(i=0; i<x; i++){
        if(freq[i]!=0){
            printf("%d se repite %d veces\n", array[i], freq[i]);
        }
    }
}

	//MATRICES

extern void introducirElementoEnMatrizEnArea(int sizeY, int sizeX, int matriz[sizeX][sizeY], int xA, int xB, int yA, int yB, int valor){
//Ejemplo de uso: introducirElementoEnMatrizEnArea(8, 8, matriz, 2, 5, 3, 4, 48);
	/*
	xA = posición inicial/arriba (rows)
	xB = posición final/bajo (rows)
	yA = posición incial/izquierda (columns)
	yB = posición final/derecha (columns)
	*/
	int i=0, j=0;
	for(i=0;i<sizeX;i++){
		for(j=0;j<sizeY;j++){
			if((i<=xB && i>=xA) && (j<=yB && j>=yA)){
				matriz[i][j]=valor;
			}
		}
	}
}

extern void inicializarMatrizAValor(int x, int y, int matriz[x][y], int valor){
	int i, j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			matriz[i][j]=valor;
		}
	}
}

extern void imprimirMatrizEnTabla(int y, int x, int matriz[x][y]){ //Ejemplo de uso imprimirMatrizEnTabla(8, 8, matriz);
	
	int i=0, j=0;
	
	printf("\t");
	for(i=0;i<x;i++){
	//	printf("Col%d:\t ",++k);
	}
	
	printf("\n");
	for(i=0;i<x;i++){
	//	printf("Fila %d:\t ",i+1);
		for(j=0;j<y;j++){
			printf("%d", matriz[i][j]);
			printf("\t");
		}
	printf("\n");
	}
}

extern void imprimirMatrizEnTabla2Players(int y, int x, int matriz1[x][y], int matriz2[x][y]){ //Ejemplo de uso imprimirMatrizEnTabla(8, 8, matriz);
	
	int i=0, j=0;
	
	//printf("\t");
	//for(i=0;i<x;i++){
	//	printf("Col%d:\t ",++k);
	//}
	
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
			printf("%c", matriz1[i][j]);
			printf(" ");
		}
			printf("\t||\t");
	if(i<9){
		printf("%d | ",i+1);
	}
	if(i>=9){
		printf("%d| ",i+1);
	}
		for(j=0;j<y;j++){
			printf("%c", matriz2[i][j]);
			printf(" ");
		}
	printf("\n");
	}
}

extern void imprimirMatrizEnTabla2PlayersInGame(int y, int x, int matriz1[x][y], int matriz2[x][y]){ //Ejemplo de uso imprimirMatrizEnTabla(8, 8, matriz);
	
	int i=0, j=0;
	
	//printf("\t");
	//for(i=0;i<x;i++){
	//	printf("Col%d:\t ",++k);
	//}
	
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
			printf("%c", matriz1[i][j]);
			printf(" ");
		}
			printf("\t||\t");
	if(i<9){
		printf("%d | ",i+1);
	}
	if(i>=9){
		printf("%d| ",i+1);
	}
		for(j=0;j<y;j++){
			if(matriz2[i][j]==120){
				printf("%c", 254);
				printf(" ");
			}
			else{
				printf("%c", matriz2[i][j]);
				printf(" ");
			}
		}
	printf("\n");
	}
}

extern void imprimirMatrizComoAscii(int y, int x, int matriz[x][y]){ //Ejemplo de uso imprimirMatrizEnTabla(8, 8, matriz);
	
	int i=0, j=0;
	
	//printf("\t");
		//for(i=0;i<x;i++){
			//	printf("Col%d:\t ",++k);
		//}
	
	//printf("\n");
	for(i=0;i<x;i++){
	//	printf("Fila %d:\t ",i+1);
		for(j=0;j<y;j++){
			printf("%c", matriz[i][j]);
	//		printf("\t");
		}
	printf("\n");
	}
}

extern void imprimirNoRepetidosDeMatriz2d(int x, int y, int array[x][y]){	
	int t=0, i=0, repetido=0;
	printf("Elementos no repetidos del array: ");
	for (t=0; t<x; t++) {	
		for (i=0; i<y; i++) {
			if (array[t] == array[i]) {
				repetido=repetido+1;
			}
			
		}	

		if(repetido==1){
			for (i=0; i<y; i++) {
				printf("%i ", array[t][i]);				
			}
		}
		
		/*if(repetido==1){
			printf("%d ", array[t]);
		}*/
		
		repetido=0;
 	}
}

extern int sumarElementosDelArray(int x, int y, int array[x][y]){
	int i=0,j=0;
	int suma=0;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			suma+=(array[i][j]);
		}
	}
	return suma;
}

extern void borrarElementoDeUnArray1d(int x, int array[x]){
   int i=0, position=0;
   printf("Ingrese la ubicación donde desea eliminar el elemento\n");
   fflush(stdin);
   scanf("%d", &position);
   if (position>=x+1){
		printf("Eliminación no posible\n");
   }
	else{
		for(i=position-1;i<x-1;i++){
			array[i]=array[i+1];
		}
   }
}

//RAND
extern int aleatorio(int min, int max){
	//time_t t;                      //añadir antes del primer rand en el programa
	//srand((unsigned) time(&t));	 //añadir antes del primer rand en el programa
	return rand()%(max+1-min)+min;
}

//DELAYS
extern void delay(){
		int c=1, d=1; 						 
		for ( c = 1 ; c <= 40000 ; c++ ) 
			for ( d = 1 ; d <= 40000 ; d++ ) {}								 
}

extern void customDelay(int number){	
		int c=1, d=1; 						 
		for ( c = 1 ; c <= number ; c++ ) 
			for ( d = 1 ; d <= number ; d++ ) {}	
}

extern void shortDelay(){	
		int c=1, d=1;						 
		for ( c = 1 ; c <= 20000 ; c++ ) 
			for ( d = 1 ; d <= 20000 ; d++ ) {}	
}

extern void superShortDelay(){	
		int c=1, d=1;						 
		for ( c = 1 ; c <= 1000 ; c++ ) 
			for ( d = 1 ; d <= 1000 ; d++ ) {}	
}

//UTILITIES
extern void scans(char mystring[]){
	scanf(" %[^\n]s",mystring);
}

extern void prints(char text[]) {
  printf("%s",text);
}

extern void limpiarPantalla(){
	system("cls");
}

extern void pausePulsaTecla(){
	system("pause");
	//getch();
}

extern int contarDigitos(int n){
	int digitos=1;
	while(n/10>0){
		digitos+=1;
		n/=10;
	}
	return digitos;	
}

extern void limpiarBuffer(){
	char aux='\0';
	do{
		scanf("%c",&aux);
	}
	while(aux!='\n');
}


//MENU
extern int scanMenuStaticSize(int numElementos, int maxSize, char printMenu[numElementos][maxSize]){
	int o=0,i=0;
	do{
		system("cls");
		for(i=0;i<numElementos;i++){
			printf("%s\n",printMenu[i]);
		}
		fflush(stdin);
		scanf("%i",&o);
		printf("\n\n");
		if(o<1 || o>numElementos){
			printf("\nNo has introducido una opcion correcta, intentalo otra vez\n");
		}
	}while(o<1 || o>numElementos);
	return o;
}

extern int scanMenuDynamicSize(char *printMenu[]){
	int o=0, i=0, numElementos=0;
	
	while(printMenu[numElementos++]!=NULL){};
	numElementos--; //Usar si hay título en el char *printMenu
	numElementos--; //Usar si hay pie de menu en el char *printMenu
	do{
		//system("cls");	//comentar si hay algo encima que no debe ser limpiado
		for(i=0;i<=numElementos;i++){
			printf("%s\n",printMenu[i]);
		}
		fflush(stdin);
		printf("\n\t\t\t Escoge una opci%cn: ",162);
		scanf("%i",&o);
		/*if(o<1 || o>numElementos){
			printf("\nNo has introducido una opcion correcta, intentalo otra vez\n");
		}*/
	}while(o<1 || o>=numElementos);
	return o;
	
	/*EJEMPLO:
	
#include "libreria.h"

int main(){
	int optMenu=0;
	char *textoMenu[]={
		"Opcion1- Esta es una opcion",
		"Opcion2- Esta es otra opcion mas",
		"Opcion3- probando...",
		"Opcion4 - text",
		"Opcion5- testing 5555",
		NULL
	};
		
	optMenu=scanMenuUsingPointers(textoMenu);
	
	printf("La opcion marcada es %i",optMenu);
	
	return 0;
}

*/
	
}

extern int scanMenuDynamicSizeWithMatrixAsAscii(int x, int y, int panel[x][y], char *printMenu[]){
	int o=0, i=0, j=0, numElementos=0;
		
	while(printMenu[numElementos++]!=NULL){};
	numElementos--; //Usar si hay título en el char *printMenu
	numElementos--; //Usar si hay pie de menu en el char *printMenu
	do{
		system("cls");
		
		for(i=0;i<y;i++){
			for(j=0;j<x;j++){
				printf("%c", panel[i][j]);
			}
			printf("\n");
		}
		
		for(i=0;i<=numElementos;i++){
			printf("%s\n",printMenu[i]);
		}
		fflush(stdin);
		scanf("%i",&o);
		/*if(o<1 || o>numElementos){
			printf("\nNo has introducido una opcion correcta, intentalo otra vez\n");
		}*/
	}while(o<1 || o>=numElementos);
	return o;
	
	/*EJEMPLO:
	
#include "libreria.h"

int main(){
	int optMenu=0;
	char *textoMenu[]={
		"Opcion1- Esta es una opcion",
		"Opcion2- Esta es otra opcion mas",
		"Opcion3- probando...",
		"Opcion4 - text",
		"Opcion5- testing 5555",
		NULL
	};
		
	optMenu=scanMenuUsingPointers(textoMenu);
	
	printf("La opcion marcada es %i",optMenu);
	
	return 0;
}

*/
	
}

extern int scanMenuDynamicSizeWithClear(char *printMenu[]){
	int o=0, i=0, numElementos=0;
	
	while(printMenu[numElementos++]!=NULL){};
	numElementos--; //Usar si hay título en el char *printMenu
	numElementos--; //Usar si hay pie de menu en el char *printMenu
	do{
		system("cls");
		for(i=0;i<=numElementos;i++){
			printf("%s\n",printMenu[i]);
		}
		fflush(stdin);
		scanf("%i",&o);
		/*if(o<1 || o>numElementos){
			printf("\nNo has introducido una opcion correcta, intentalo otra vez\n");
		}*/
	}while(o<1 || o>=numElementos);
	return o;
	
	/*EJEMPLO:
	
#include "libreria.h"

int main(){
	int optMenu=0;
	char *textoMenu[]={
		"Opcion1- Esta es una opcion",
		"Opcion2- Esta es otra opcion mas",
		"Opcion3- probando...",
		"Opcion4 - text",
		"Opcion5- testing 5555",
		NULL
	};
		
	optMenu=scanMenuUsingPointers(textoMenu);
	
	printf("La opcion marcada es %i",optMenu);
	
	return 0;
}

*/
	
}

//MATHS
extern int potenciaInt(int a, int b){
	return pow(a, b);
}

extern float potenciaFloat(float a, float b){
	return pow(a, b);
}

extern int comprobarNumeroPrimo(int n){
    int j=2, flag=1;
    for(j=2;j<= n/2;++j){
        if(n%j==0){
            flag=0;
            break;
        }
    }
    return flag; //Si es primo flag=1 - Si NO es primo flag=0
}

extern int sumarNumerosHastaNumeroRecursivamente(int n){
    if(n!=0){
        return n + sumarNumerosHastaNumeroRecursivamente(n-1);
    }
    else{
    	return n;
	}
}

extern long factorial(int n){
  int c=1;
  long result=1;
  for(c = 1; c <= n; c++){
  	result=result*c;
  }
  return result;
}

//OTHER
extern int numMasAltoDeDos(int num1, int num2){
	int result=0;
	if (num1 > num2){
		result=num1;
	}
	else{
		result=num2;
	}
	return result;
}

extern int numMasAltoDeTres(int a, int b, int c){
	a = (a > b) ? a : b;
	b = (c > b) ? c : b;
	c = (a > b) ? a : b;
   return c;
}

extern int comprobarNumEntre(int num, int min, int max){
	while(num<min || num>max){
		printf("No es posible introducir ese valor, prueba otra vez: ");
		scanf("%d",&num);
		return num;
	}
	return num;
}

extern float euroAdolar(float euros){
	return euros*1.1;
}

extern float euroAlibras(float euros){
	return euros*0.9;
}

//Strings
extern void imprimirLongitudString(char text[]){
	int longitud=0;
	longitud = strlen(text);
	printf("%d", longitud);
}

extern void copiarString(char origen[], char destino[]){
   strcpy(destino, origen);
}

extern void frecuenciaDeCaracter(char texto[]){
	
   char ch={'\0'};
   int i=0, frequency=0;

   printf("Introducir un caracter para saber su frecuencia: ");
   scanf(" %c",&ch);

   for(i = 0; texto[i] != '\0'; ++i){
       if(ch == texto[i])
           ++frequency;
   }
   
   printf("Frequencia of %c = %d", ch, frequency);
}

extern void ordenarAlfabeticamente(int x, int y, char str[x][y]){
	char temp[y];
	int i=0, j=0;
	
    for(i=0; i<2; ++i){
    	for(j=i+1; j<3 ; ++j){
            if(strcmp(str[i], str[j])>0){
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
	}
}

	//MAS

extern void girar_cadena(char frase[], int i, char lletra){
	if(i<strlen(frase)/2){
	 	girar_cadena(frase, i+1, lletra);//llegamos al centro de la cadena, ya no secumplirá la llamada recursiva y finalizarán los procedimientos
        lletra=frase[i];
        frase[i]=frase[strlen(frase)-1-i];//cambio de valores del centro a los extremos.
        frase[strlen(frase)-1-i]=lletra;
	}
}

extern int buscarPosicionDeUnValorEnVector(int vector[], int tamanio, int valor){
	int centro=0,izq=0,der=tamanio-1;
	int pos=-1;
		while(izq<=der){
			centro=(izq+der)/2;
			if (valor==vector[centro]){
				pos = centro;
			}
			if (valor<vector[centro]){
				der=centro-1;
			}
		    else{
		    	izq=centro+1;
			}
	   }
	return pos;
}

int letraANumero(char letra) {
	switch(letra){
		case 'A':
		case 'a':
			return 0;
		case 'B':
		case 'b':
			return 1;
		case 'C':
		case 'c':
			return 2;
		case 'D':
		case 'd':
			return 3;
		case 'E':
		case 'e':
			return 4;
		case 'F':
		case 'f':
			return 5;
		case 'G':
		case 'g':
			return 6;
		case 'H':
		case 'h':
			return 7;
		case 'I':
		case 'i':
			return 8;
		case 'J':
		case 'j':
			return 9;
	}
	return 100;
}
