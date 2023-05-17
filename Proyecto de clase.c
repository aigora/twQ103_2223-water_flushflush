#include<stdio.h>
#include<string.h>
#define NumerodFuentes 25 // Numero de fuentes que hay en el fichero
#define MAXIMO 100 // Máximo número de usuarios que se puedan registrar

struct DATOS {
    char usuario[100];
    char contra[100];
};

struct CAgua{
	char nombre_fuente[100];
	float PH;
	int conductividad;
	int turbidez;
	int coliformes;
};

struct CPotable{ // Estructura utilizado para imprimir datos en el nuevo fichero
	char pH[20];
	char conductividad[20];
	char turbidez[20];
	char coliforme[20];
};

// Funcion para imprimir los datos del fihcero
void imprimir_dato(struct CAgua [], int );
// Funciones para conocer la caracterastica de la fuente de acuerdo con su valor de los parametros
void potable_Ph(struct CAgua fuentes[],int num);
int potable_cond(int);
int potable_turbi(int, char[]); 
int potable_col(int , char []);
void maxPh(struct CAgua fuentes[],int num);
// Funciones para mostrar las graficas
void serapotable(struct CAgua [],int num);  // Comprueba si la fuente es potable del cien por cien (cumple todas las condiciones)
void grafica(struct CAgua [],int num);  // Muestra una lista de las fuentes totalmente potables
void potabilidad(struct CAgua [],int num);  // Calcula la cantidad de fuentes potables + porcentaje respecto al total
float mediaph(struct CAgua [],int num);  // Calcula la media del pH entre todas las fuentes
// Función utilizado en la opcion E
void maxPh(struct CAgua fuentes[],int num);

				// FUNCION PRINCIPAL
int main() {
// Variables para leer ficheros
	char parametro[100], pH[100], conductividad[100], turbidez[100], coliforme[100];
// Variables para iniciar sesion
    struct DATOS users[MAXIMO];	
	int modo = 0, i;
    int numerousuarios = 0;
    int registrado = 0;
    char usuario[50], contra[50];
// Variables para el buscador con switch-case
	struct CAgua fuentes[NumerodFuentes];
	int fuente_encontrado=0, orden;
	char opcion;	
	char nombrebuscar[100];
	int pH_inicio, pH_final;
// Variables utilizados en el nuevo fichero
	struct CPotable origen[NumerodFuentes];

// Bienvenido
	printf("Bienvenidos al navegador Water_FlushFlush!\n"); 
	printf("Water_FlushFlush es un navegador que sirve para buscar informacion sobre la calidad del agua en su consumo,\nlos datos recogidos pertenecen al mes de mayo situado en los barrios de Lavapies (Madrid.\n"); 

// Abrir fichero
	FILE *ficheros;
	ficheros = fopen("202304_Lavapies.txt","r");
	if (ficheros == NULL)
           {
           	printf("Error,no puede abrir el fichero");
           	return 0;
		   }
// Leer fichero
	fscanf(ficheros,"%s %s %s %s %s",parametro,pH,conductividad,turbidez,coliforme); // La primera linea del fichero no va a ser guardado en un vector estructura
	i=0;
	while(fscanf(ficheros,"%s %f  %d %d  %d",fuentes[i].nombre_fuente,&fuentes[i].PH,&fuentes[i].conductividad,&fuentes[i].turbidez,&fuentes[i].coliformes) !=EOF) {
    	i++;
	}
// Cerrar fichero
	fclose(ficheros);

// Programacion
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
    
// Iniciar sesion
    do{		// Menú de opciones
        fflush(stdin);
        printf("\nQue desea hacer?\n"); 
        printf("1. Iniciar sesion\n");
        printf("2. Registrarse\n");
        printf("3. Salir del programa\n");
		printf("Introduzca la opcion deseada: ");
        scanf("%d", &modo);

        switch (modo) {
            case 1: 
                printf("\nIntroduce tu nombre de usuario: ");
                scanf("%s", usuario);
                printf("Introduce tu contrasenya: ");
                scanf("%s", contra);

                // Comprobar si coincide con algún usuario registrado o pre-registrado
                for (i = 0; i < numerousuarios; i++) {
                    if (strcmp(users[i].usuario, usuario) == 0 && strcmp(users[i].contra, contra) == 0) {
                        fflush(stdin);
						printf("\nInicio de sesion exitoso!\n");
                        registrado = 1;
                        break;
                    }
            	}

                // Comprobar usuarios pre-registrados
                if (strcmp(usuario, "Javi") == 0 && strcmp(contra, "1234") == 0) {
                    fflush(stdin);
                    registrado = 1;
                    break;
                } else if (strcmp(usuario, "Alvaro") == 0 && strcmp(contra, "1234") == 0) {
                    fflush(stdin);
                    registrado = 1;
                    break;
                } else if (strcmp(usuario, "Alicia") == 0 && strcmp(contra, "1234") == 0) {
                    fflush(stdin);
                    registrado = 1;
                    break;
                } else if (strcmp(usuario, "Senxue") == 0 && strcmp(contra, "1234") == 0) {
                    fflush(stdin);
                    registrado = 1;
                    break;
                }

                if (!registrado) {
                    printf("\nEl usuario o la contrasenya son incorrectos. Vuelve a intentarlo.\n");
                }

                break;

            case 2: // Registrarse
                if (numerousuarios == MAXIMO) {
                    printf("\nSe ha alcanzado el numero maximo de cuentas que podemos registrar.\n");
                    break;
                }
                printf ("Introduce un nuevo usuario: ");
				scanf("%s", usuario);
				printf ("Introduce tu contrasenya: ");
				scanf("%s", contra);
			
				struct DATOS nuevo;
				strcpy(nuevo.usuario, usuario);
				strcpy(nuevo.contra, contra);
				users[numerousuarios] = nuevo;
				numerousuarios++;
			
			printf("\nGracias por registrarse. Se le redigira al menu de inicio.\n\n");
			break;
		case 3:
			printf("\nHas salido del programa, vuelva pronto :)");
			return 0;
			break;	
		
		default:
			printf ("\nLa opcion no es valida. Se le redigira al menu de inicio.\n");
		}
	} while (registrado == 0);
	printf("\n");
// Buscador
    do{ 
		fflush(stdin);
		printf("A- Buscar por el nombre de la fuente.\n");
		printf("B- Buscar por un intervalo de pH.\n");
		printf("C- Mostrar la estadistica de todas las fuentes potables.\n");
		printf("D- Desea tener un fichero que muestre  las fuentes potables dependiendo de \n   los parametros(pH, conductividad, turbidez y coliforme) y salir del programa.\n");
		printf("E- Mostrar las fuentes con mayor y menor acidez.\n");	
		printf("F- Salir del programa.\n");
		printf("Introduzca la opcion deseada: ");
		scanf("%c", &opcion);
		switch (opcion) {
			case 'A':
			case 'a':
				printf("Introducir el nombre de la fuente: ");
				scanf("%s", nombrebuscar);
				for(i=0; i<NumerodFuentes; i++) {
					orden=strcmp(fuentes[i].nombre_fuente, nombrebuscar);
					if(orden==0) {
						fuente_encontrado=1;
						imprimir_dato(fuentes, i);
						printf("Segun los datos proporcionados, %s cumple con las siguientes caracteristicas: \n", fuentes[i].nombre_fuente);
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
						printf("Segun los datos proporcionados, %s cumple con las siguientes caracteristicas: \n", fuentes[i].nombre_fuente);
						potable_Ph(fuentes,i);
						potable_cond(fuentes[i].conductividad);
						potable_turbi(fuentes[i].turbidez, fuentes[i].nombre_fuente);
						potable_col(fuentes[i].coliformes, fuentes[i].nombre_fuente);
						printf("En resumen, el agua del %s ", fuentes[i].nombre_fuente);
						serapotable(fuentes,i);	
					}
				}
				if(fuente_encontrado == 0) {  
					printf("No encontrado\n");
				}
				printf("\n");
				break;
				
			case 'C':
			case 'c':
				printf("\n");
				grafica(fuentes,NumerodFuentes);
				printf("-----Resultados-----\n");
				printf("%f",mediaph(fuentes,NumerodFuentes));
				potabilidad(fuentes,NumerodFuentes);
				printf("\n");
				break;
				
			case 'D':
			case 'd':
				for(i=0; i<NumerodFuentes; i++) {
					if (fuentes[i].PH > 6.5 && fuentes[i].PH < 9.5) {
						strcpy(origen[i].pH, "Si");
					}
					else {
						strcpy(origen[i].pH, "No");
					}
					if (fuentes[i].conductividad > 50 && fuentes[i].conductividad < 500) {
						strcpy(origen[i].conductividad, "Si");
					}
					else {
						strcpy(origen[i].conductividad, "No");
					}
					if (fuentes[i].turbidez < 1) {
						strcpy(origen[i].turbidez, "Si");
					}
					else {
						strcpy(origen[i].turbidez, "No");
					}
					if (fuentes[i].coliformes < 2) {
						strcpy(origen[i].coliforme, "Si");
					}
					else {
						strcpy(origen[i].coliforme, "No");
					} 
				}
				// Crear un nuevo fichero
				ficheros=fopen("tabla.txt","w");
				if(ficheros == NULL) { 
    				printf("No se ha podido crear el nuevo fichero.\n");
    				return 0;
				}
				// Escribir en el nuevo fichero
				fprintf(ficheros,"%s   %s %s %s %s\n",parametro,pH,conductividad,turbidez,coliforme);
				for (i=0; i<NumerodFuentes; i++) {
					fprintf(ficheros, "%s\t %s\t  %s\t\t %s\t\t %s\n", fuentes[i].nombre_fuente, origen[i].pH, origen[i].conductividad, origen[i].turbidez, origen[i].coliforme);
				}
				// Cerrar el nuevo fichero
				fclose(ficheros);
				printf("Has salido del buscador\n");
				
				return 0;
				break;
			case 'E':
			case 'e':
				maxPh(fuentes,NumerodFuentes);
			     break;	
			case 'F':
			case 'f':
				printf("Has salido del buscador.\n");
				return 0;
				
			default:
				printf("Opcion incorrecta.\n");
				printf("\n");
				break; 
		}
	} while(opcion != 'F' && opcion != 'f'); 

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
	
	if( fuentes[num].coliformes<2 && (fuentes[num].PH>6.5 && fuentes[num].PH<9.5) && (fuentes[num].conductividad >50 && fuentes[num].conductividad <500) && fuentes[num].turbidez<1) {	
		printf("%s\n",espotable);		
	}
	else{
		printf("%s\n",nopotable);
	}	
}

void grafica(struct CAgua fuentes[],int num) {
	int i;
	
	printf("-----GRAFICA DE FUENTES POTABLES-----\n");
	printf("Nombre\t\tpH\tConductividad\tTurbidez\tColiforme\n");
	for(i=0;i<=NumerodFuentes;i++) {
		if( fuentes[i].coliformes<2 && (fuentes[i].PH>6.5 && fuentes[i].PH<9.5) && (fuentes[i].conductividad >50 && fuentes[i].conductividad <500) && fuentes[i].turbidez<1) {
        	printf("%s\t%.2f\t%d\t\t%d\t\t%d\t \n",fuentes[i].nombre_fuente,fuentes[i].PH,fuentes[i].conductividad,fuentes[i].turbidez,fuentes[i].coliformes);
		}
	}
}

void potabilidad(struct CAgua fuentes[],int num) {
	int potable=0, i;
	
	for(i=0;i<num;i++) {
		if( fuentes[i].coliformes<2 && (fuentes[i].PH>6.5 && fuentes[i].PH<9.5) && (fuentes[i].conductividad >50 && fuentes[i].conductividad <500) && fuentes[i].turbidez<1) {		
			potable++;			
		}
	}
	printf("\nNumero de fuentes con agua potable: %d \n",potable);
	printf("Porcentaje de las fuentes potables: %f  \n",100*(float)potable/ NumerodFuentes);
}

float mediaph(struct CAgua fuentes[],int num){
	float suma=0;
	int i;
	
	for(i=0;i<num;i++) {
		suma += fuentes[i].PH;
	}
	printf("Media del pH: ");
	return (suma/num);
}

// Funcion utilizado en la opcion E
void maxPh(struct CAgua fuentes[],int num){
	float max=fuentes[0].PH;
	float min=fuentes[0].PH;
	int i=0,localizador1,localizador2;
	
	for(i=1;i<NumerodFuentes;i++){
		if(max<fuentes[i].PH){
			max=fuentes[i].PH;
			localizador1=i;	
		}
	}
    for(i=1;i<NumerodFuentes;i++){
		if(min>fuentes[i].PH){
			min=fuentes[i].PH;
			localizador2=i;
		}
	}
	printf("La fuente %s con un ph de %f es la mas acida(menor ph)\n",fuentes[localizador2].nombre_fuente,fuentes[localizador2].PH);
	printf("Mientras que\nLa fuente %s con un ph de %f es la menos acida(mayor ph )\n\n",fuentes[localizador1].nombre_fuente,fuentes[localizador1].PH);
	
}
