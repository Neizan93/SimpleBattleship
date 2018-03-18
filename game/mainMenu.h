extern int menuPrincipal(int lang, int y, int x, int matriz1[x][y], int matriz2[x][y]){
	int opcion=0;

	char *menu1en[]={
		"\n\t\t\t======  BATTLESHIP ======",
		"\t\t\t\t1.- Play",
		"\t\t\t\t2.- Rules",
		"\t\t\t\t3.- Language",
		"\t\t\t\t4.- Exit",
		"\t\t\t=========================",
		NULL
	};
	
	char *menu1es[]={
		"\n\t\t\t======  HUNDIR LA FLOTA ======",
		"\t\t\t\t1.- Jugar",
		"\t\t\t\t2.- Reglas",
		"\t\t\t\t3.- Idioma",
		"\t\t\t\t4.- Salir",
		"\t\t\t==============================",
		NULL
	};	

	imprimirMatrizEnTabla2Players(y, x, matriz1, matriz2);
	
	if(lang==1){
		opcion=scanMenuDynamicSizeLang(lang, menu1en);
	}
	else if(lang==2){
		opcion=scanMenuDynamicSizeLang(lang, menu1es);
	}
	
	return opcion;
}
