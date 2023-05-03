#include <stdio.h>
#include <string.h>
#define MAXIMO 100 // Máximo número de usuarios registrados

struct DATOS {
    char usuario[100];
    char contra[100];
};

int main() {
    int modo = 0;
    int i;
    int numerousuarios = 0;
    int registrado = 0;
    struct DATOS users[MAXIMO];
    char usuario[50];
    char contra[50];

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

    // Bienvenida
    printf("Bienvenido a WaterFlushFlush!\n");

    do{
        // Menú de opciones
        fflush(stdin);
        printf("\nQue desea hacer?\n");
        printf("1. Iniciar sesion\n");
        printf("2. Registrarse\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &modo);

        switch (modo) {
            case 1: // Iniciar sesion
                if (numerousuarios == 0) {    // ERROR
                    printf("\nNo hay usuarios registrados.\n");
                    break;
                }

                printf("\nIntroduce tu nombre de usuario: ");
                scanf("%s", usuario);
                printf("Introduce tu contrasenya: ");
                scanf("%s", contra);

                // Comprobar si coincide con algún usuario registrado o pre-registrado
                for (i = 0; i < numerousuarios; i++) {
                    if (strcmp(users[i].usuario, usuario) == 0 && strcmp(users[i].contra, contra) == 0) {
                        fflush(stdin);
						printf("\nInicio de sesion exitoso!\n");//Lo de inicio de sesion esta 2 veces
                        registrado = 1;
                        break;
                    }
            	}

                // Comprobar usuarios pre-registrados
                if (strcmp(usuario, "Javi") == 0 && strcmp(contra, "1234") == 0) {
                    fflush(stdin);
					printf("\nInicio de sesion exitoso!\n");
                    registrado = 1;
                    break;
                } else if (strcmp(usuario, "Alvaro") == 0 && strcmp(contra, "1234") == 0) {
                    fflush(stdin);
					printf("\nInicio de sesion exitoso!\n");
                    registrado = 1;
                    break;
                } else if (strcmp(usuario, "Alicia") == 0 && strcmp(contra, "1234") == 0) {
                    fflush(stdin);
					printf("\nInicio de sesion exitoso!\n");
                    registrado = 1;
                    break;
                } else if (strcmp(usuario, "Senxue") == 0 && strcmp(contra, "1234") == 0) {
                    fflush(stdin);
					printf("\nInicio de sesion exitoso!\n");
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
			break;	
		
		default:
			printf ("\nLa opcion no es valida. Se le redigira al menu de inicio.\n");
		}
	} while ( modo !=3); // Funciona
	
	return 0;
}

