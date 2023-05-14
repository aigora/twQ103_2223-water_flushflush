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
void potable_Ph(struct CAgua fuentes[],int num);
int main() {
	struct CAgua fuentes[NumerodFuentes];
// Variables para leer ficheros
	char parametro[100], pH[100], conductividad[100], turbidez[100], coliforme[100];
// Variables para el buscador con switch-case
	int i=0, fuente_encontrado=0, orden,tam;
	char opcion;
	char nombrebuscar[100];
	int pH_inicio, pH_final;
    
	
	char Bfuente[50];
    float Bph;
    
    
	FILE *ficheros;
// Abrir fichero
	ficheros = fopen("202304_Lavapies.txt","r");
	if (ficheros == NULL) {
      	printf("Error,no puede abrir el fichero.\n");
       	return 0;
	}
// Leer el fichero
	//fscanf(ficheros,"%s %s %s %s %s",parametro,pH,conductividad,turbidez,coliforme); 
	// La primera línea del fichero no aporta
	
    while(fscanf(ficheros,"%s %f  %d %d  %d",fuentes[i].nombre_fuente,&fuentes[i].PH,&fuentes[i].conductividad,&fuentes[i].turbidez,&fuentes[i].coliformes) !=EOF){
		
    	i++;
	  }
// Cerrar fichero
	fclose(ficheros);
	



	
	ficheros=freopen("tabla de la potabilidad.txt","w",stdout);
				if(ficheros == NULL) { 
    				printf("No se ha podido crear el nuevo fichero.\n");
    				return 0;
				}
				//Escribir en el nuevo fichero
			   
				fprintf(ficheros,"\t\t\tPH potables:");
				fprintf(ficheros,"\tcoliformes potables:");
     		    fprintf(ficheros,"\tconductividad potables:");
				fprintf(ficheros,"\t\tturbidez potables:");
				fprintf(ficheros,"\t\tpotable total:\n");
				for(i=0;i<NumerodFuentes;i++){
					printf("%s",fuentes[i].nombre_fuente);
					graficaPh(fuentes,i);
				
				}
			
				fclose(ficheros);
	
	
	

	return 0;	
}
	
void potable_Ph(struct CAgua fuentes[],int num){
	
	
	      if (fuentes[num].PH<=6.5 )// fuente[i].coliformes<0 && fuente[i].PH>6.5 && fuente[i].PH<9.5 && (fuente[i].conductividad >50 && fuente[i].conductividad <500) && fuente[i].turbidez<1
        		  
			{
        		printf("No es recomendable el consumo de agua\n");
				printf(" El agua dura, o el agua con un pH alto contiene \nuna gran concentración de minerales disueltos.");
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

void graficaPh(struct CAgua fuentes[],int num) {
	int i;
	
	if(  (fuentes[num].PH>6.5 && fuentes[num].PH<9.5) ) {
        printf("\tSi");
	}
	else 
	printf("\tNo");
	
	if(  (fuentes[num].coliformes<2 ) ) {
        printf("\t\t\t\tSi");
	}
	else 
	printf("   \t\t\t\tNo");
	if((fuentes[num].conductividad >50 && fuentes[num].conductividad <500)){
	    printf("   \t\t\t\t\tSi");
	}
	else 
	printf("\t\t\t\t\tNo");
	if((fuentes[num].turbidez<1)) {
		printf("\t\t\t\t\t\t\tSi");
	}
	else 
	printf("\t\t\t\t\t\t\tNo");
	if((fuentes[num].turbidez<1)&&(fuentes[num].conductividad >50 && fuentes[num].conductividad <500)&&(fuentes[num].coliformes<2 )&&(fuentes[num].PH>6.5 && fuentes[num].PH<9.5)){
		printf("   \t\t\t\t\tSi");
	}
	else 
	printf("   \t\t\t\t\tNo");
	
	if(i!=NumerodFuentes)
	printf("\n");
}
	
	
	

