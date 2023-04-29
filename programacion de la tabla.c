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
void graficaPh(struct CAgua fuentes[],int num);
void serapotable(struct CAgua [],int num);
void potabilidad(struct CAgua fuentes[],int num);
int main() {
// Variables que se usan ...
	float mediaPh=0,media;
	struct CAgua fuentes[Tam_Max];
	int Cfuentes=0;
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
	// La primera línea del fichero no aporta
	i=0;
    
	while(fscanf(ficheros,"%s %f  %d %d  %d",fuentes[i].nombre_fuente,&fuentes[i].PH,&fuentes[i].conductividad,&fuentes[i].turbidez,&fuentes[i].coliformes) !=EOF){
		
    	i++;
	}
// Cerrar fichero
	fclose(ficheros);
	
	
	
	FILE*ftablita;
	
	ftablita= fopen("tablita.txt","w");
	
	
	if(ftablita == NULL)
    {
    	printf("No se ha podido crear el fichero\n");
    	return 0;

    }


   fprintf(ftablita,"PH potables:  \n");
   for(i=0;i<NumerodFuentes;i++){
   
   graficaPh(fuentes,i);
  fprintf(ftablita,graficaPh(fuentes,i));
     }
   
   fclose(ftablita);
return 0;

}
void serapotable(struct CAgua fuentes[],int num){
 
    char espotable[50] = "Es potable";
    char nopotable[50] = "NO es potable";
	int i;

	             
	           
	
				 if( fuentes[num].coliformes<1 && (fuentes[num].PH>6.5 && fuentes[num].PH<9.5) && (fuentes[num].conductividad >50 && fuentes[num].conductividad <500) && fuentes[num].turbidez<1)// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        		  
					{
        				
		           printf("%s\n",espotable);
		           
        				
					}
				else{
				 
				 printf("%s\n",nopotable);
				   
				    }
	}
void graficaPh(struct CAgua fuentes[],int num){

		int potable=0,i;
	
	//printf("GRAFICA DE FUENTES POTABLES\n");
	
	
	
				 if(  (fuentes[num].PH>6.5 && fuentes[num].PH<9.5) )// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        			{
        				 potable++;
        			   printf("%s\n",fuentes[num].nombre_fuente);
		   
		   
        			
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
