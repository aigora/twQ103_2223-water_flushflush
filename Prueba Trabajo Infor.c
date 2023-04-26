#include <stdio.h>
#include <string.h>

int main() {
    char usu[200];
    char contra[200];
    char modo;
    char nuevousu[200];
    char nuevacontra[200];
    int registrado = 0;   
    
    do {
    	fflush(stdin);
        printf("Bienvenido a WaterFlushFlush.\n");
        printf("Seleccione una opcion, si pulsa una tecla erronea se le redigira al menu de inicio\n");
        printf("1. Iniciar sesion\n");
        printf("2. Registrarse\n");
        printf("3. Salir\n\n");
        scanf("%c", &modo);
        
        if (modo == '1') {
            printf("Ingrese su usuario y contraseña para iniciar sesion:\n");
            printf("Usuario: ");
            scanf("%s", usu);
            printf("Contraseña: ");
            scanf("%s", contra);
            
            // Verificar si el usuario y contraseña son correctos
            if (registrado && strcmp(usu, nuevousu) == 0 && strcmp(contra, nuevacontra) == 0) {
                printf("Bienvenido al programa %s!\n\n", usu);
                
            } else {
                printf("Usuario o contrasenya incorrectos, se le redigira al menu de inicio.\n\n");
            }
        } else if (modo=='2') {
            printf("Introduce tu nuevo usuario: ");
            scanf("%s", nuevousu);
            printf("Introduce tu nueva contrasenya: ");
            scanf("%s", nuevacontra);
            registrado = 1;
            
            printf("Registro completo con exito, se le redigira al menu de inicio\n\n");
        } else if (modo == '3') {
            printf("Gracias por usar el programa. Hasta luego!\n");
            break;
        }
    } while (modo!=3);
    
    return 0;
}
