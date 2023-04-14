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
/*char nombrebuscar[100];
	int pH_inicio, pH_final*/
	
	
//printf(""); // Ideas: "Bienvenidos al navegador Water_FlushFlush"...
	//printf(""); // Presentacion ? del grupo: Water_FlushFlush es una navegador que sirve para buscar informaci?n sobre la calidad de agua...







  FILE *ficheros;
  ficheros = fopen("Parametro_5.txt","r");
   if (ficheros == NULL)
           {
           	printf("Error,no puede abrir el fichero");
           	return 0;
		   }
   
     //Buscador alicia todavia no funcionA
     /*	while(fscanf(ficheros,"%s %f %d %d %d ",fuente[i].parametros,&fuente[i].PH,&fuente[i].conductividad,&fuente[i].turbidez,&fuente[i].coliformes) !=EOF){
	 do{ // El bucle do-while va a contener toda las programciones hasta el final, de manera que el usuario pueda hacer la b?squedad varias veces.
		while(fscanf(ficheros,"%s %f %d %d %d ",fuente[i].parametros,&fuente[i].PH,&fuente[i].conductividad,&fuente[i].turbidez,&fuente[i].coliformes) !=EOF){//bUCLE HASTA el fin del fichero,cuando no sabes su tama?o

			printf("1-Buscar por el nombre de la fuente.\n2-Buscar por un intervalo de pH.\n3-Salir del programa.\n");	// !!!! Hacemos con n?meros o con letras?	
			printf("Introduzca la opci?n deseada: ");
			scanf("%d", &opcion);
			   switch (opcion) {
			case 1:
				printf("Introducir el nombre de la fuente: ");
				scanf("%s", nombrebuscar);
				
				for(i=0; i<Tam_Max; i++) {
					if(strcmp(fuente[i].nombre_fuente,nombrebuscar)==0) {
						fuente_encontrado=1;
						printf("-----Fuente-----\n");
						printf("Nombre: %s\n", fuente[i].nombre_fuente);
						printf("pH: %.2f\n", fuente[i].PH);
						printf("Conductividad (microS/cm): %d\n", fuente[i].conductividad);
						printf("Turbidez (NTU): %d\n", fuente[i].turbidez);
						printf("Coliforme (UFC/100ml): %d\n", fuente[i].coliformes);
						// A?adir aqu? las otras caracter?sticas de la fuente: potable....
					} 
					if(fuente_encontrado == 0) {
						printf("El fuente %s no existe.\n", nombrebuscar); // ???? Que salga del programa (elegir otra vez la opcion) o que vuelva a introducir el nombre ???
					}
				}
				
				
				break;
			case 2:
				printf("Introducir el intervalo de pH: desde ");
				scanf("%d", &pH_inicio);
				printf("hasta ");
				scanf("%d", &pH_final);
				
				
				break;
			case 3:
				printf("Has salido del programa.\n");
				break;
			default:
				printf("Opcion incorrecta.\n");
			   
			   
			   
			   
			   
			   
			   i++;
		}
		
		
		*/
	
	
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
	
	printf("El porcentaje de las fuentes :%d \n",potable);
	
	
	printf("La media del ph de las fuentes  es: %f",mediaPh/NumerodFuentes);
	
	
	
	
	
	
	
	
	
	
	
	
	fclose(ficheros);
return 0;	
}
