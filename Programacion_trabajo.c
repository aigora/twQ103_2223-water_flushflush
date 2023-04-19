#include<stdio.h>
#include<string.h>
#define Tam_Max 200
#define NumerodFuentes 25

struct CAgua{
	char nombre_fuente[Tam_Max];
	float PH;
	int conductividad;
	int turbidez;
	int coliformes;
};

int main() {
	struct CAgua fuentes[NumerodFuentes];
// Variables para leer ficheros
	char parametro[100], pH[100], conductividad[100], turbidez[100], coliforme[100];
// Variables para el buscador con switch-case
	int i, fuente_encontrado=0, orden;
	char opcion;
	char nombrebuscar[100];
	int pH_inicio, pH_final;

	FILE *ficheros;
// Abrir fichero
	ficheros = fopen("Parametro_5.txt","r");
	if (ficheros == NULL) {
      	printf("Error,no puede abrir el fichero.\n");
       	return 0;
	}
// Leer el fichero
	fscanf(ficheros,"%s %s %s %s %s",parametro,pH,conductividad,turbidez,coliforme); 
	// La primera línea del fichero no aporta
	
    while(fscanf(ficheros,"%s %f  %d %d  %d",fuentes[i].nombre_fuente,&fuentes[i].PH,&fuentes[i].conductividad,&fuentes[i].turbidez,&fuentes[i].coliformes) !=EOF){
		
    	i++;
	}
// Cerrar fichero
	fclose(ficheros);
	
//Comprobación si ha leido bien el fichero
	FILE *comprobacion;
	comprobacion=fopen("Comprobacion.txt","w");
	
	for(i=0; i<NumerodFuentes; i++) {
		fprintf(comprobacion,"%s %f %d %d %d\n", fuentes[i].nombre_fuente,fuentes[i].PH,fuentes[i].conductividad,fuentes[i].turbidez,fuentes[i].coliformes);
	}

	fclose(comprobacion);




//Programacion
/*do{
	fflush(stdin);

	printf("Que opcion eliges? \n (A)buscar por ph \n (B) Buscar por fuente\n (S) salir\n");
	scanf("%c",&eleccion);

	if(eleccion =='A' || eleccion =='a')
	{
		printf("Introduce codigo\n");
		scanf("%f",&Bph);
		for(i=0;i<25;i++)
		{
			if((Bph==fuente[i].PH) ==Bph  ){
			
			  printf(" %s ph de  %f %d %d %d\n",fuente[i].parametros,fuente[i].PH,fuente[i].conductividad,fuente[i].turbidez,fuente[i].coliformes);
			  bandera = 1;
			}
		}
		if(bandera==0)
		printf("No encontrado\n");
		
	}
	else if(eleccion =='B' || eleccion =='b')
	{
		fflush(stdin);
		printf("Introduce nombre de la fuente \n");
		gets(Bfuente);
		
			for(i=0;i<25;i++)
		{
			if(strcmp(fuente[i].parametros,Bfuente) ==0 ) {
			
			  printf(" %s %f %d %d %d\n",fuente[i].parametros,fuente[i].PH,fuente[i].conductividad,fuente[i].turbidez,fuente[i].coliformes);
			  bandera = 1;
			}
		}
		if(bandera==0)
		printf("No encontrado\n");
		
		
	}
		else if(eleccion =='S' || eleccion =='s')
		{
			return 0;
		}
	else
	{
		printf("Error\n");
		
	}	
	
	i++;

}

while(eleccion != 'S' || eleccion != 'S');*/
	do{ // El bucle do-while va a contener toda las programciones hasta el final, de manera que el usuario pueda hacer la b?squedad varias veces.
		printf("A- Buscar por el nombre de la fuente.\n");
		printf("B- Buscar por un intervalo de pH.\n");
		printf("C- Salir del programa.\n");	
		printf("Introduzca la opcion deseada: ");
		scanf("%c", &opcion);
		switch (opcion) {
			case 'A':
				printf("Introducir el nombre de la fuente: ");
				scanf("%s", nombrebuscar);
				
				for(i=0; i<Tam_Max; i++) {
					orden=strcmp(fuentes[i].nombre_fuente, nombrebuscar);
					if(orden==0) {
						fuente_encontrado=1;
						printf("-----Fuente-----\n");
						printf("Nombre: %s\n", fuentes[i].nombre_fuente);
						printf("pH: %.2f\n", fuentes[i].PH);
						printf("Conductividad (microS/cm): %d\n", fuentes[i].conductividad);
						printf("Turbidez (NTU): %d\n", fuentes[i].turbidez);
						printf("Coliforme (UFC/100ml): %d\n", fuentes[i].coliformes);
						// A?adir aqu? las otras caracter?sticas de la fuente: potable....
						break;
					} 
					if(fuente_encontrado == 0) {
						printf("%s no existe.\n", nombrebuscar);
						break; // ???? Que salga del programa (elegir otra vez la opcion) o que vuelva a introducir el nombre ???
					}
				}
				
				
				break;
			case 'B':
				printf("Introducir el intervalo de pH: desde ");
				scanf("%d", &pH_inicio);
				printf("hasta ");
				scanf("%d", &pH_final);
				
				
				break;
			case 'C':
				printf("Has salido del programa.\n");
				break;
			default:
				printf("Opcion incorrecta.\n");
				break;	   
		}
	} while (opcion<'A' && opcion>'B');

	return 0;	
}
