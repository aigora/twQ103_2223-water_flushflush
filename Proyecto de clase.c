#include<stdio.h>
#define Tam_Max 200

struct CAgua{
	
	char parametros[Tam_Max];
	float PH;
	int conductividad;
	int turbidez;
	int coliformes;
	
};

int main() {
	
	
struct CAgua fuente[Tam_Max];
int i=1;
int Cfuentes=0,potable=0;

  FILE *ficheros;
  ficheros = fopen("Parametro_5.txt","r");
   if (ficheros == NULL)
           {
           	printf("Error,no puede abrir el fichero");
           	return 0;
		   }
   
   
    

	while(fscanf(ficheros,"%s %f %d %d %d ",fuente[i].parametros,&fuente[i].PH,&fuente[i].conductividad,&fuente[i].turbidez,&fuente[i].coliformes) !=EOF){//bUCLE HASTA el fin del fichero,cuando no sabes su tamañ
        
		
		   //printf("%s\t%f\t%d\t%d\t%d\t \n",fuente[i].parametros,fuente[i].PH,fuente[i].conductividad,fuente[i].turbidez,fuente[i].coliformes);
		   
		  if( fuente[i].coliformes<1 && (fuente[i].PH>6.5 && fuente[i].PH<9.5) && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1)// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        {
        	potable++;
        	printf("%s\t%.2f\t%d\t%d\t%d\t \n",fuente[i].parametros,fuente[i].PH,fuente[i].conductividad,fuente[i].turbidez,fuente[i].coliformes);
		   
        	
		}
		   i++;
		}
	printf("Hay una cantidad de agua potable de :%d ",potable);
	
	fclose(ficheros);
return 0;	
}
