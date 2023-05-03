#include<stdio.h>
#include<string.h>
#define Tam_Max 200
#define NumerodFuentes 25
/* Comentario sobre la programci�n:
	-Necesita hacer un salto de l�nea cuando acaba una busquedad.
*/

struct CAgua{
	char nombre_fuente[Tam_Max];
	float PH;
	int conductividad;
	int turbidez;
	int coliformes;

};

int potable(char fuente);
int calidad_del_agua(int);


int main() {
// Variables que se usan ...
	float mediaPh=0,media;
	struct CAgua fuentes[Tam_Max];
	int Cfuentes=0,potable=0;
	float porcentaje;
// Variables para leer ficheros
	char parametro[100], pH[100], conductividad[100], turbidez[100], coliforme[100];
// Variables para el buscador con switch-case
	int i, fuente_encontrado=0, orden;
	char opcion;
	char nombrebuscar[100];
	int pH_inicio, pH_final;
	
	
//printf(""); // Ideas: "Bienvenidos al navegador Water_FlushFlush"...
	//printf(""); // Presentacion ? del grupo: Water_FlushFlush es una navegador que sirve para buscar informaci?n sobre la calidad de agua...







  FILE *ficheros;
// Abrir fichero
  ficheros = fopen("Parametro_5.txt","r");
   if (ficheros == NULL)
           {
           	printf("Error,no puede abrir el fichero");
           	return 0;
		   }
// Leer fichero
	fscanf(ficheros,"%s %s %s %s %s",parametro,pH,conductividad,turbidez,coliforme); 
	// La primera l�nea del fichero no aporta
	i=0;
    
	while(fscanf(ficheros,"%s %f  %d %d  %d",fuentes[i].nombre_fuente,&fuentes[i].PH,&fuentes[i].conductividad,&fuentes[i].turbidez,&fuentes[i].coliformes) !=EOF){
		
    	i++;
	}
// Cerrar fichero
	fclose(ficheros);

// Programacion
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
										
						printf("Aportaciones de conductividad sobre la calidad del agua: %d \n",fuentes[i].conductividad);
						calidad_del_agua(fuentes[i].conductividad);
					
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
						printf("Aportaciones de conductividad sobre la calidad del agua: \n",fuentes[i].conductividad,fuentes[i].nombre_fuente);
					

						
					}
					
					
				}
				 if(fuente_encontrado == 0) {
						printf("No encontrado\n");
						 // ???? Que salga del programa (elegir otra vez la opcion) o que vuelva a introducir el nombre ???
					}
				
				break;
			case 'C':
				printf("Has salido del programa.\n");
				break;
			default:
				printf("Opcion incorrecta.\n");
				break;	   
		}
	}
	 
	while (opcion != 'C');

		
		
		

		
		
		
		//Esto va al final como resumen
		for(i=0;i<=NumerodFuentes;i++){
	
				 if( fuentes[i].coliformes<1 && (fuentes[i].PH>6.5 && fuentes[i].PH<9.5) && (fuentes[i].conductividad >50 && fuentes[i].conductividad <500) && fuentes[i].turbidez<1)// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        			{
        				potable++;
        				printf("%s\t%.2f\t%d\t%d\t%d\t \n",fuentes[i].nombre_fuente,fuentes[i].PH,fuentes[i].conductividad,fuentes[i].turbidez,fuentes[i].coliformes);
		   
		   
        				mediaPh=mediaPh + fuentes[i].PH;
					}
		}
	printf("Hay una cantidad de agua potable de :%d \n",potable);
	porcentaje = (float)potable/ NumerodFuentes;
	printf("El porcentaje de las fuentes :%f \n",porcentaje);
	
	
	printf("de las cuales el ph de las fuentes  es: %f",mediaPh/NumerodFuentes);
	
	
	

	

return 0;	
}

int calidad_del_agua(int conductividad) {
		
		if ( 50 <= conductividad <= 250) {
			printf("conductividad Bajo:  Carece de minerales, como calcio, magnesio y zinc\n");
		} else if (300<=conductividad && conductividad<=500) {
			printf("conductividad Ideal: este nivel es el punto �ptimo para los TDS en el agua potable. Lo m�s probable es que el agua contenga minerales y no tenga un sabor plano\n");
		} else if (600<=conductividad && conductividad<=900) {
			printf("conductividad No muy bien:considere un sistema de �smosis inversa para filtrar TDS.\n");
		} else if (1000<=conductividad && conductividad<=2000) {
			printf("conductividad Malo:no se recomienda beber agua a este nivel de TDS\n");
		} else if (conductividad>2000) {
			printf("conductividad Inaceptable:Un nivel de TDS superior a 2000 ppm no es seguro y los filtros dom�sticos no pueden filtrar adecuadamente este nivel de contaminaci�n\n");
		} else {
			printf("Error. cantidad de solidos disuelto totales no esta en el rango");
		}
	return ;
	 }


