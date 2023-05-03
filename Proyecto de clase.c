#include<stdio.h>
#include<string.h>
#define Tam_Max 200
#define NumerodFuentes 25
/* COMENTARIOS:
	Hay que numerar las características obtenidas a partir de las funciones.
*/

struct CAgua{
	char nombre_fuente[Tam_Max];
	float PH;
	int conductividad;
	int turbidez;
	int coliformes;

};


float mediaph(struct CAgua [],int num);

void serapotable(struct CAgua [],int num);

void grafica(struct CAgua [],int num);

void potabilidad(struct CAgua [],int num);

int potable(char fuente);

int potable_col(int , char []); // Comprobar si el agua es potable de acuerdo con su valor de coliforme.

int ecosist_turbi(int, char[]); 

void imprimir_dato(struct CAgua [], int );

int calidad_del_agua(int);

void potable_Ph(struct CAgua fuentes[],int num);


int main() {
// Variables para leer ficheros
	char parametro[100], pH[100], conductividad[100], turbidez[100], coliforme[100];
// Variables para el buscador con switch-case
	int i, fuente_encontrado=0, orden;
	char opcion;	
	char nombrebuscar[100];
	int pH_inicio, pH_final;
// Variables que se usan para mostrar la estadística en conjunto
	float mediaPh=0,media;
	struct CAgua fuentes[Tam_Max];
		
// Bienvenido
	printf("Bienvenidos al navegador Water_FlushFlush!\n"); 
	printf("Water_FlushFlush es un navegador que sirve para buscar informacion sobre la calidad del agua en su consumo,\nlos datos recogidos pertenece al mes de mayo situado en los barrios de Madrid.\n"); 

// Abrir fichero
	FILE *ficheros;
	ficheros = fopen("Parametro_5.txt","r");
	if (ficheros == NULL)
           {
           	printf("Error,no puede abrir el fichero");
           	return 0;
		   }
// Leer fichero
	fscanf(ficheros,"%s %s %s %s %s",parametro,pH,conductividad,turbidez,coliforme); // La primera línea del fichero no aporta
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
						serapotable(fuentes,i);

						printf("Segun los datos proporcionados, %s cumple las siguientes caracteristicas: \n", fuentes[i].nombre_fuente);
						potable_Ph(fuentes,i);
						potable_cond(fuentes[i].conductividad);
						ecosist_turbi(fuentes[i].turbidez, fuentes[i].nombre_fuente);
						potable_col(fuentes[i].coliformes, fuentes[i].nombre_fuente);	
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
				
					if((pH_inicio<=fuentes[i].PH) && (pH_final>=fuentes[i].PH)){
						
						fuente_encontrado=1;
				     	imprimir_dato(fuentes, i);
						serapotable(fuentes,i);
						 
						printf("Segun los datos proporcionados, %s cumple las siguientes caracteristicas: \n", fuentes[i].nombre_fuente);
						potable_Ph(fuentes,i);
						potable_cond(fuentes[i].conductividad);
						ecosist_turbi(fuentes[i].turbidez, fuentes[i].nombre_fuente);
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
	} 
	while(opcion != 'D'); 

	return 0;	
}

// Función para imprimir datos del fichero 
void imprimir_dato(struct CAgua fuentes[], int i) {
	printf("----------Fuente----------\n");
	printf("Nombre: %s\n", fuentes[i].nombre_fuente);
	printf("pH: %.2f\n", fuentes[i].PH);
	printf("Conductividad (microS/cm): %d\n", fuentes[i].conductividad);
	printf("Turbidez (NTU): %d\n", fuentes[i].turbidez);
	printf("Coliforme (UFC/100ml): %d\n", fuentes[i].coliformes);
	
}

// Funciones para conocer la característica de la fuente de acuerdo con su valor de los parámetros
// potable_PH
int potable_cond(int conductividad) {
		
		if ( 50 <= conductividad <= 250) {
			printf("2.-Conductividad Bajo:  Carece de minerales, como calcio, magnesio y zinc\n");
		} else if (300<=conductividad && conductividad<=500) {
			printf("2.-Conductividad Ideal: este nivel es el punto óptimo para los TDS en el agua potable. Lo más probable es que el agua contenga minerales y no tenga un sabor plano\n");
		} else if (600<=conductividad && conductividad<=900) {
			printf("2.-Conductividad No muy bien:considere un sistema de ósmosis inversa para filtrar TDS.\n");
		} else if (1000<=conductividad && conductividad<=2000) {
			printf("2.-Conductividad Malo:no se recomienda beber agua a este nivel de TDS\n");
		} else if (conductividad>2000) {
			printf("2.-Conductividad Inaceptable:Un nivel de TDS superior a 2000 ppm no es seguro y los filtros domésticos no pueden filtrar adecuadamente este nivel de contaminación\n");
		} else {
			printf("Error. cantidad de solidos disuelto totales no esta en el rango");
		}
		return ;
	 }
// potable_turb
int potable_col(int dato, char nombre[]) { // dato=fuentes[i].coliforme   nombre=fuentes[i].nombre_fuente
	
	if(dato<2) {
		printf("4.-Es posible su consumicion.\n");
	}
	else if(dato==2) {
		printf("4.-El valor del coliforme ha llegado al limite.\nATENCiON: No es recomendable beber el agua del %s.\n", nombre);
	}
	else if(dato>2) {
		printf("4.-El valor del coliforme ha alcanzado el limite.\nATENCION:Prohibido beber el agua del %s.\n", nombre);
	}
	
	return ;
}

int ecosist_turbi(int dato, char nombre[]) { // dato=fuentes[i].coliforme   nombre=fuentes[i].nombre_fuente
	
	if(dato<1) {
		printf("2.-Teniendo en cuenta el nivel de turbidez de la %s, esta fuente si tiene la capacidad para crear ecosistemas.\n", nombre);
	}
	else if(dato==1) {
		printf("2.-Teniendo en cuenta el nivel de turbidez de la %s, esta fuente no tiene la capacidad para crear ecosistemas y es algo poco probable que ocurra.\n", nombre);
	}
	else if(dato>1) {
		printf("2.-Teniendo en cuenta el nivel de turbidez de la %s, esta fuente no tiene la capacidad para crear ecosistemas y es algo poco probable que ocurra.\n", nombre);
	}
	
	return ;
}

// Funciones utilizados para mostrar la gráfica
void serapotable(struct CAgua fuentes[],int num){
 
    char espotable[50] = "Es potable";
    char nopotable[50] = "NO es potable";
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
	
	for(i=0;i<num;i++){
		
		suma +=  fuentes[i].PH;
		
	}
	printf("La media de ph es de : ");
	return (suma/num);
}

void grafica(struct CAgua fuentes[],int num){

	int i;
	
	printf("GRAFICA DE FUENTES POTABLES\n");
	
	for(i=0;i<=NumerodFuentes;i++){
	
				 if( fuentes[i].coliformes<1 && (fuentes[i].PH>6.5 && fuentes[i].PH<9.5) && (fuentes[i].conductividad >50 && fuentes[i].conductividad <500) && fuentes[i].turbidez<1)// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        			{
        				
        				printf("%s\t%.2f\t%d\t%d\t%d\t \n",fuentes[i].nombre_fuente,fuentes[i].PH,fuentes[i].conductividad,fuentes[i].turbidez,fuentes[i].coliformes);
		   
		   
        			
					}
		}

}
void potabilidad(struct CAgua fuentes[],int num){
	
	
	int potable=0,i;
	
	
	
	
	
	for(i=0;i<num;i++){
	
			if( fuentes[i].coliformes<1 && (fuentes[i].PH>6.5 && fuentes[i].PH<9.5) && (fuentes[i].conductividad >50 && fuentes[i].conductividad <500) && fuentes[i].turbidez<1)// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        		  
			{
        				
		          potable++;
		           
        				
			}
	}
	
	printf("\n Como se puede ver :\nHay una cantidad de agua potable de  %d fuentes \n ",potable);
	
	printf("El porcentaje de las fuentes  que son potables es de :%f  \n",100*(float)potable/ NumerodFuentes);
	

}
void potable_Ph(struct CAgua fuentes[],int num){
	
	
	      if (fuentes[num].PH<=6.5 )// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        		  
			{
        		printf("No es recomendable el consumo de agua\n");
				printf(" El agua dura, o el agua con un pH alto contiene \nuna gran concentraci�n de minerales disueltos.");
		         printf("\n ademas,puede poseer  minerales como el calcio los cuales pueden causar \n problemas con su posicionamiento en superficies de ceramica y por su gusto agrio.\n");
		    }
	
	
	 
	
			else if (fuentes[num].PH>6.5 && fuentes[num].PH<8.5)// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        		  
			{
        		printf("Es posible el consumo de agua\n");		
		         
		    }
		    else if(fuentes[num].PH>=8.5){
		    	
		    	printf("NO es posible el consumo de agua\n");
		    	printf("ya que esta fuente tiende a llevar grandes concentraciones de metales como el manganeso y hierro.\n");
		    	printf("Esto se puede dar como consecuencia de tuberias oxidadas\n");
		    	
			}
	
	
	
	
}


