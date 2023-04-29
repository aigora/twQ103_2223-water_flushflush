#include<stdio.h>
#include<string.h>
#define Tam_Max 200
#define NumerodFuentes 25
#define MAXIMO 100 // M�ximo n�mero de usuarios registrados
/* COMENTARIOS:
	Hay que numerar las caracter�sticas obtenidas a partir de las funciones.

*/

struct DATOS {
    char usuario[100];
    char contra[100];
};
struct CAgua{
	char nombre_fuente[Tam_Max];
	float PH;
	int conductividad;
	int turbidez;
	int coliformes;
};

float mediaph(struct CAgua [],int num);

// void serapotable(struct CAgua [],int num);

void grafica(struct CAgua [],int num);

void potabilidad(struct CAgua [],int num);

int potable(char fuente);

int potable_col(int , char []); // Comprobar si el agua es potable de acuerdo con su valor de coliforme.

int imprimirdato(struct CAgua [], int);


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
// Variables para iniciar sesion o registrarse
	int modo = 0;
    int numerousuarios = 0;
    int registrado = 0;
    struct DATOS users[MAXIMO];
    char usuario[50];
    char contra[50];
	
//printf(""); // Ideas: "Bienvenidos al navegador Water_FlushFlush"...
	//printf(""); // Presentacion ? del grupo: Water_FlushFlush es una navegador que sirve para buscar informaci?n sobre la calidad de agua...

	// Usuarios pre-registrados
    struct DATOS user1 = {"Javi", "1234"};
    struct DATOS user2 = {"Alvaro", "1234"};
    struct DATOS user3 = {"Alicia", "1234"};
    struct DATOS user4 = {"Senxue", "1234"};

    // Guardar usuarios pre-registrados
    users[0] = user1;
    users[1] = user2;
    users[2] = user3;
    users[3] = user4;
    numerousuarios = 4;

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

// A�adir aqu� el iniciar sesi�n...

    do{ // El bucle do-while va a contener toda las programciones hasta el final, de manera que el usuario pueda hacer la b?squedad varias veces.
	   fflush(stdin);
		printf("A- Buscar por el nombre de la fuente.\n");
		printf("B- Buscar por un intervalo de pH.\n");
		printf("C- Mostrar la estadistica de las fuentes potables.\n");
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

						//serapotable(fuentes,i);
						imprimirdato(fuentes, i);

						// A?adir aqu? las otras caracter?sticas de la fuente: potable....
						printf("Segun los datos proporcionados, %s cumple las siguientes caracteristicas: \n", fuentes[i].nombre_fuente);
						potable_col(fuentes[i].coliformes, fuentes[i].nombre_fuente);
						break;
					} 
					
						 // ???? Que salga del programa (elegir otra vez la opcion) o que vuelva a introducir el nombre ???
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

						//serapotable(fuentes,i);
						
						imprimirdato(fuentes, i);

						// A?adir aqu? las otras caracter?sticas de la fuente: potable....
						printf("Segun los datos proporcionados, %s cumple las siguientes caracteristicas: \n", fuentes[i].nombre_fuente);
						potable_col(fuentes[i].coliformes, fuentes[i].nombre_fuente);
						
					}
					
					
				}
				 if(fuente_encontrado == 0) {
						printf("No encontrado\n");
						 // ???? Que salga del programa (elegir otra vez la opcion) o que vuelva a introducir el nombre ???
					}
				printf("\n");
				
				break;
			case 'C':
			case 'c':
				grafica(fuentes,NumerodFuentes);
				//Esto va al final como resumen
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
	} while (opcion != 'C');

		
		
		

		
		
	
	
	
	
	

	

return 0;	
}


int imprimirdato(struct CAgua fuentes[], int i) {
	printf("-----Fuente-----\n");
	printf("Nombre: %s\n", fuentes[i].nombre_fuente);
	printf("pH: %.2f\n", fuentes[i].PH);
	printf("Conductividad (microS/cm): %d\n", fuentes[i].conductividad);
	printf("Turbidez (NTU): %d\n", fuentes[i].turbidez);
	printf("Coliforme (UFC/100ml): %d\n", fuentes[i].coliformes);
	return ;
}

int potable_col(int dato, char nombre[]) { // dato=fuentes[i].coliforme   nombre=fuentes[i].nombre_fuente
	
	if(dato<2) {
		printf("1.-Es posible su consumicion.\n");
	}
	else if(dato==2) {
		printf("1.-El valor del coliforme ha llegado al limite.\nATENCiON: No es recomendable beber el agua del %s.\n", nombre);
	}
	else if(dato>2) {
		printf("1.-El valor del coliforme ha alcanzado el limite.\nATENCION:Prohibido beber el agua del %s.\n", nombre);
	}
	return ;
}
void serapotable(struct CAgua fuentes[],int num){
    char espotable[50] = "Es potable";
    char nopotable[50] = "NO es potable";
	int i;
		if( fuentes[num].coliformes<2 && (fuentes[num].PH>6.5 && fuentes[num].PH<9.5) && (fuentes[num].conductividad >50 && fuentes[num].conductividad <500) && fuentes[num].turbidez<1){
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
