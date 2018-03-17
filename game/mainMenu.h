extern int menuPrincipal(int y, int x, int matriz1[x][y], int matriz2[x][y]){
	int opcion=0;
	char *menu1[]={
		"\n\t\t\t======  HUNDIR LA FLOTA ======",
		"\t\t\t\t1.- Jugar",
		"\t\t\t\t2.- Reglas",
		"\t\t\t\t3.- Salir",
		"\t\t\t==============================",
		NULL
	};
	imprimirMatrizEnTabla2Players(y, x, matriz1, matriz2);
	opcion=scanMenuDynamicSize(menu1);
	return opcion;
}
