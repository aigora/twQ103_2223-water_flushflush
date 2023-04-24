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
    
	
	char Bfuente[50];
    float Bph;
    
    
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
//No es necesario ahora
/*	FILE *comprobacion;
	comprobacion=fopen("Comprobacion.txt","w");
	
	for(i=0; i<NumerodFuentes; i++) {
		fprintf(comprobacion,"%s %f %d %d %d\n", fuentes[i].nombre_fuente,fuentes[i].PH,fuentes[i].conductividad,fuentes[i].turbidez,fuentes[i].coliformes);
	}

	fclose(comprobacion);
*/



//Programacion

	do{ // El bucle do-while va a contener toda las programciones hasta el final, de manera que el usuario pueda hacer la b?squedad varias veces.
	   fflush(stdin);
		printf("A- Buscar por el nombre de la fuente.\n");
		printf("B- Buscar por un intervalo de pH.\n");
		printf("C- Salir del programa.\n");	
		printf("Introduzca la opcion deseada: ");
		scanf("%c", &opcion);
		switch (opcion) {
			case 'A':
			case 'a':
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
					
						 // ???? Que salga del programa (elegir otra vez la opcion) o que vuelva a introducir el nombre ???
					}
					
					if(fuente_encontrado == 0) {
						printf("%s no existe.\n", nombrebuscar);
				}
				
				
				break;
			case 'B':
			case 'b':
				printf("Introducir el intervalo de pH: desde ");
				scanf("%d", &pH_inicio);
				printf("hasta ");
				scanf("%d", &pH_final);
				for(i=0;i<=NumerodFuentes;i++){
				
					if((pH_inicio<=fuentes[i].PH) && (pH_final>=fuentes[i].PH)){
						
						fuente_encontrado=1;
						printf("-----Fuente-----\n");
						printf("Nombre: %s\n", fuentes[i].nombre_fuente);
						printf("pH: %.2f\n", fuentes[i].PH);
						printf("Conductividad (microS/cm): %d\n", fuentes[i].conductividad);
						printf("Turbidez (NTU): %d\n", fuentes[i].turbidez);
						printf("Coliforme (UFC/100ml): %d\n", fuentes[i].coliformes);
						// A?adir aqu? las otras caracter?sticas de la fuente: potable....
						
					}
					
					
				}
				 if(fuente_encontrado == 0) {
						printf("No encontrado\n");
						 // ???? Que salga del programa (elegir otra vez la opcion) o que vuelva a introducir el nombre ???
					}
				
				break;
			case 'C':
			case 'c':
				printf("Has salido del programa.\n");
				break;
			default:
				printf("Opcion incorrecta.\n");
				break;	   
		}
	}
	 
	while (opcion != 'C' || opcion != 'c');

	return 0;	
}
