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

// Funcion para imprimir los datos del fihcero
void imprimir_dato(struct CAgua [], int );
// Funciones para conocer la caracterastica de la fuente de acuerdo con su valor de los parametros
void potable_Ph(struct CAgua fuentes[],int num);
int potable_cond(int);
int potable_turbi(int, char[]); 
int potable_col(int , char []);
// Funciones para mostrar las graficas
float mediaph(struct CAgua [],int num);
void serapotable(struct CAgua [],int num);
void grafica(struct CAgua [],int num);
void potabilidad(struct CAgua [],int num);
int potable(char fuente);

// FUNCION PRINCIPAL
int main() {
// Variables para leer ficheros
	char parametro[100], pH[100], conductividad[100], turbidez[100], coliforme[100];
// Variables para el buscador con switch-case
	int i, fuente_encontrado=0, orden;
	char opcion;	
	char nombrebuscar[100];
	int pH_inicio, pH_final;
// Variables que se usan para mostrar la estadistica en conjunto
	float mediaPh=0,media;
	struct CAgua fuentes[Tam_Max];
		
// Bienvenido
	printf("Bienvenidos al navegador Water_FlushFlush!\n"); 
	printf("Water_FlushFlush es un navegador que sirve para buscar informacion sobre la calidad del agua en su consumo,\nlos datos recogidos pertenecen al mes de mayo situado en los barrios de Madrid.\n"); 

// Abrir fichero
	FILE *ficheros;
	ficheros = fopen("202304_Lavapies.txt","r");
	if (ficheros == NULL)
           {
           	printf("Error,no puede abrir el fichero");
           	return 0;
		   }
// Leer fichero
	fscanf(ficheros,"%s %s %s %s %s",parametro,pH,conductividad,turbidez,coliforme); // La primera linea del fichero no aporta
	i=0;
	while(fscanf(ficheros,"%s %f  %d %d  %d",fuentes[i].nombre_fuente,&fuentes[i].PH,&fuentes[i].conductividad,&fuentes[i].turbidez,&fuentes[i].coliformes) !=EOF) {
    	i++;
	}
// Cerrar fichero
	fclose(ficheros);

// Programacion
    do{ 
		fflush(stdin);
		printf("A- Buscar por el nombre de la fuente.\n");
		printf("B- Buscar por un intervalo de pH.\n");
		printf("C- Mostrar la estadistica de todas las fuentes potables.\n");	
		printf("D- Salir del programa.\n");	
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
						imprimir_dato(fuentes, i);
						printf("Segun los datos proporcionados, %s cumple las siguientes caracteristicas: \n", fuentes[i].nombre_fuente);
						potable_Ph(fuentes,i);
						potable_cond(fuentes[i].conductividad);
						potable_turbi(fuentes[i].turbidez, fuentes[i].nombre_fuente);
						potable_col(fuentes[i].coliformes, fuentes[i].nombre_fuente);	
						printf("En resumen, el agua del %s ", fuentes[i].nombre_fuente);
						serapotable(fuentes,i);	
						break;
					}
				}	
				if(fuente_encontrado == 0) {
					printf("%s no existe.\n", nombrebuscar);
				}
				printf("\n");
				break;
				
			case 'B':
			case 'b':
				printf("Introducir el intervalo de pH: desde ");
				scanf("%d", &pH_inicio);
				printf("hasta ");
				scanf("%d", &pH_final);
				for(i=0;i<=NumerodFuentes;i++){
					if((pH_inicio<=fuentes[i].PH) && (pH_final>=fuentes[i].PH)) {
						fuente_encontrado=1;
				     	imprimir_dato(fuentes, i);
						serapotable(fuentes,i); // Comprueba que cumple con todas las condiciones
						printf("Segun los datos proporcionados, %s cumple las siguientes caracteristicas: \n", fuentes[i].nombre_fuente);
						potable_Ph(fuentes,i);
						potable_cond(fuentes[i].conductividad);
						potable_turbi(fuentes[i].turbidez, fuentes[i].nombre_fuente);
						potable_col(fuentes[i].coliformes, fuentes[i].nombre_fuente);
					}
				}
				if(fuente_encontrado == 0) {
					printf("No encontrado\n");
				}
				printf("\n");
				break;
				
			case 'C':
			case 'c':
				grafica(fuentes,NumerodFuentes);
				printf("%f",mediaph(fuentes,NumerodFuentes));
				potabilidad(fuentes,NumerodFuentes);
				break;
				
			case 'D':
			case 'd':
				printf("Has salido del programa.\n");
				printf("\n");
				break;
				
			default:
				printf("Opcion incorrecta.\n");
				printf("\n");
				break; 
		}
	} while(opcion != 'D'); 

	return 0;	
}

// Funcion para imprimir los datos del fichero 
void imprimir_dato(struct CAgua fuentes[], int i) {
	printf("----------Fuente----------\n");
	printf("Nombre: %s\n", fuentes[i].nombre_fuente);
	printf("pH: %.2f\n", fuentes[i].PH);
	printf("Conductividad (microS/cm): %d\n", fuentes[i].conductividad);
	printf("Turbidez (NTU): %d\n", fuentes[i].turbidez);
	printf("Coliforme (UFC/100ml): %d\n", fuentes[i].coliformes);	
}

// Funciones para conocer la caracterastica de la fuente de acuerdo con su valor de los parametros
void potable_Ph(struct CAgua fuentes[],int num){
	if (fuentes[num].PH<=6.5 ) {
    	printf("\t1.-No es recomendable el consumo de agua\n");
		printf("\t   El agua dura, o el agua con un pH alto contiene \n\t   una gran concentración de minerales disueltos.\n");
		printf("\t   ademas,puede poseer  minerales como el calcio los cuales pueden causar \n\t   problemas con su posicionamiento en superficies de ceramica y por su gusto agrio.\n");
	}
	else if (fuentes[num].PH>6.5 && fuentes[num].PH<8.5) {
        printf("\t1.-Es posible el consumo de agua\n");   
	}
	else if(fuentes[num].PH>=8.5){
		printf("\t1.-NO es posible el consumo de agua\n");
		printf("\t   ya que esta fuente tiende a llevar grandes concentraciones de metales como el manganeso y hierro.\n");
		printf("\t   Esto se puede dar como consecuencia de tuberias oxidadas\n");	
	}	
}

int potable_cond(int conductividad) {
		if ( 50 <= conductividad <= 250) {
			printf("\t2.-Conductividad Bajo:  Carece de minerales, como calcio, magnesio y zinc\n");
		} else if (300<=conductividad && conductividad<=500) {
			printf("\t2.-Conductividad Ideal: este nivel es el punto optimo para los TDS en el agua potable.\t   Lo mas probable es que el agua contenga minerales y no tenga un sabor plano\n");
		} else if (600<=conductividad && conductividad<=900) {
			printf("\t2.-Conductividad No muy bien:considere un sistema de osmosis inversa para filtrar TDS.\n");
		} else if (1000<=conductividad && conductividad<=2000) {
			printf("\t2.-Conductividad Malo:no se recomienda beber agua a este nivel de TDS\n");
		} else if (conductividad>2000) {
			printf("\t2.-Conductividad Inaceptable:Un nivel de TDS superior a 2000 ppm no es seguro y los \t   filtros domesticos no pueden filtrar adecuadamente este nivel de contaminacion\n");
		} else {
			printf("Error. cantidad de solidos disuelto totales no esta en el rango");
		}
	return ;
}
	 
int potable_turbi(int dato, char nombre[]) { 
	if(dato<1) {
		printf("\t3.-Teniendo en cuenta el nivel de turbidez de la %s, esta fuente si tiene la capacidad \n\t   para crear ecosistemas.\n", nombre);
	}
	else if(dato==1) {
		printf("\t3.-Teniendo en cuenta el nivel de turbidez de la %s, esta fuente no tiene la capacidad \n\t   para crear ecosistemas y es algo poco probable que ocurra.\n", nombre);
	}
	else if(dato>1) {
		printf("\t3.-Teniendo en cuenta el nivel de turbidez de la %s, esta fuente no tiene la capacidad \n\t   para crear ecosistemas y es algo poco probable que ocurra.\n", nombre);
	}
	return ;
}

int potable_col(int dato, char nombre[]) {
	if(dato<2) {
		printf("\t4.-Es posible su consumicion de acuerdo con el valor del coliforme.\n");
	}
	else if(dato==2) {
		printf("\t4.-El valor del coliforme ha llegado al limite. No es recomendable \n\t   beber el agua del %s.\n", nombre);
	}
	else if(dato>2) {
		printf("\t4.-El valor del coliforme ha alcanzado el limite. Beber agua del %s es \n\t   posible causar enfermedades.\n", nombre);
	}
	return ;
}

// Funciones utilizados para mostrar la estadistica
void serapotable(struct CAgua fuentes[],int num){
    char espotable[100] = "es totalmente potable y puedes beber sin precaucion.";
    char nopotable[100] = "no es recomendable su consumo debido a las causas comentadas previamente.";
	int i;
	
	if( fuentes[num].coliformes<1 && (fuentes[num].PH>6.5 && fuentes[num].PH<9.5) && (fuentes[num].conductividad >50 && fuentes[num].conductividad <500) && fuentes[num].turbidez<1) {	
		printf("%s\n",espotable);		
	}
	else{
		printf("%s\n",nopotable);
	}	
}
		
float mediaph(struct CAgua fuentes[],int num){
	float suma=0;
	int i;
	
	for(i=0;i<num;i++) {
		suma += fuentes[i].PH;
	}
	printf("La media de ph es de : ");
	return (suma/num);
}

void grafica(struct CAgua fuentes[],int num) {
	int i;
	
	printf("GRAFICA DE FUENTES POTABLES\n");
	for(i=0;i<=NumerodFuentes;i++) {
		if( fuentes[i].coliformes<1 && (fuentes[i].PH>6.5 && fuentes[i].PH<9.5) && (fuentes[i].conductividad >50 && fuentes[i].conductividad <500) && fuentes[i].turbidez<1) {
        	printf("%s\t%.2f\t%d\t%d\t%d\t \n",fuentes[i].nombre_fuente,fuentes[i].PH,fuentes[i].conductividad,fuentes[i].turbidez,fuentes[i].coliformes);
		}
	}
}

void potabilidad(struct CAgua fuentes[],int num) {
	int potable=0,i;
	
	for(i=0;i<num;i++) {
		if( fuentes[i].coliformes<1 && (fuentes[i].PH>6.5 && fuentes[i].PH<9.5) && (fuentes[i].conductividad >50 && fuentes[i].conductividad <500) && fuentes[i].turbidez<1) {		
			potable++;			
		}
	}
	printf("\n Como se puede ver :\nHay una cantidad de agua potable de  %d fuentes \n ",potable);
	printf("El porcentaje de las fuentes  que son potables es de :%f  \n",100*(float)potable/ NumerodFuentes);
}

