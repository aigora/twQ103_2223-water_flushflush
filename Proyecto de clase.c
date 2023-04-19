#include<stdio.h>
#include<string.h>
#define Tam_Max 200
#define NumerodFuentes 25

struct CAgua{
	
	char parametros[Tam_Max];
	float PH;
	int conductividad;
	int turbidez;
	int coliformes;
	
};

int main() {
	int bandera=0;
	char Bfuente[50];
	float Bph,mediaPh=0,media;
	char eleccion;
	struct CAgua fuente[Tam_Max];
	int i=0;
	int Cfuentes=0,potable=0;
	float porcentaje;

	
	
//printf(""); // Ideas: "Bienvenidos al navegador Water_FlushFlush"...
	//printf(""); // Presentacion ? del grupo: Water_FlushFlush es una navegador que sirve para buscar informaci?n sobre la calidad de agua...







  FILE *ficheros;
  ficheros = fopen("Parametro_5.txt","r");
   if (ficheros == NULL)
           {
           	printf("Error,no puede abrir el fichero");
           	return 0;
		   }
   
     //Buscador alicia todavia no funciona
	
	
	while(fscanf(ficheros,"%s %f %d %d %d ",fuente[i].parametros,&fuente[i].PH,&fuente[i].conductividad,&fuente[i].turbidez,&fuente[i].coliformes) !=EOF){//bUCLE HASTA el fin del fichero,cuando no sabes su tamañ
        
		
		   //printf("%s\t%f\t%d\t%d\t%d\t \n",fuente[i].parametros,fuente[i].PH,fuente[i].conductividad,fuente[i].turbidez,fuente[i].coliformes);
		   
		  if( fuente[i].coliformes<1 && (fuente[i].PH>6.5 && fuente[i].PH<9.5) && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1)// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        {
        	potable++;
        	printf("%s\t%.2f\t%d\t%d\t%d\t \n",fuente[i].parametros,fuente[i].PH,fuente[i].conductividad,fuente[i].turbidez,fuente[i].coliformes);
		   
		   
        	mediaPh=mediaPh + fuente[i].PH;
		}
		
		   i++;
		}
	printf("Hay una cantidad de agua potable de :%d \n",potable);
	porcentaje = (float)potable/ NumerodFuentes;
	printf("El porcentaje de las fuentes :%f \n",porcentaje);
	
	
	printf("de las cuales el ph de las fuentes  es: %f",mediaPh/NumerodFuentes);
	
	
	

	
	fclose(ficheros);
return 0;	
}
