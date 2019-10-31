#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_RULETA 1
#define PAUSA 2
#define MAX_RULETA 36
#define ENDEVINAR 1
#define PARELL_SENAR 2
#define NO_JUGAR 0
#define CAPITAL_INICIAL 1000
void mostraMenu();
void clrscr();
void simulacioCarrega();
int seleccio = -1,numero_escollit = -1;
int numero_ruleta = 0;

int main() {

    while(seleccio != NO_JUGAR && seleccio != ENDEVINAR && seleccio != PARELL_SENAR){
        if(seleccio != -1)
            printf("\nEl numero insertat no es correcte!!!!\n\n\n");
        mostraMenu();
        printf("Insereix el numero del que vols fer: ");
        scanf("%i",&seleccio);
        clrscr();
    }

    while (seleccio != NO_JUGAR)
    {
        if(seleccio == ENDEVINAR || seleccio == PARELL_SENAR){
            srand(time(NULL)); // Inicialitzaci´o, nom´es s’ha de fer una vegada al principi
            if(seleccio == ENDEVINAR){
                printf("Insereix el numero escollit entre [%i-%i] : ",MIN_RULETA,MAX_RULETA);
                scanf("%i",&numero_escollit);
                while(numero_escollit<MIN_RULETA && numero_escollit>MAX_RULETA){
                    printf("\nEl numero escollit no es correcte!!\n\n Ha de ser un numero entre %i i %i");
                    printf("Torna a inserir el numero: ");
                    scanf("%i",&numero_escollit);
                }
                simulacioCarrega();
                numero_ruleta = rand() % MAX_RULETA + MIN_RULETA; // Genera n´umeros de l’1 al 36
                if(numero_ruleta == numero_escollit){
                    printf("Has guanyat!!!!");
                    printf("El numero ha sigut: %i i el te unmero es: %i",numero_ruleta,numero_escollit);
                }else{
                    printf("Has perdut pringao!!!!");
                    printf("El numero ha sigut: %i i el te unmero es: %i",numero_ruleta,numero_escollit);
                }

            }else //Com ja s'ha comprovat anteriorment que sol es pot seleccionar 'ENDEVINAR' o 'PARELL_SENAR' else es correcte
            {
                /* code */
            }

        }
    }

    return 0;
}

void mostraMenu(){
    printf(" - - - - - - - - - - - - \n");
    printf("| Endevinar numero : %i  |\n",ENDEVINAR);
    printf("| Parell/Senar : %i      |\n",PARELL_SENAR);
    printf("| Sortir : %i            |\n",NO_JUGAR);
    printf(" - - - - - - - - - - - - \n\n");
}

//Neteja la pantalla
void clrscr()
{
    system("@cls||clear");
}

//Simula una carrega i fa esperar a l'usuari una mica
void simulacioCarrega(){
    printf("\n\n\n\n\n                    |                           |");
    clrscr();
    printf("\n\n\n\n\n                    |-                          |");
    clrscr();
    printf("\n\n\n\n\n                    |--                         |");
    clrscr();
    printf("\n\n\n\n\n                    |---                        |");
    clrscr();
    printf("\n\n\n\n\n                    |----                       |");
    clrscr();
    printf("\n\n\n\n\n                    |-----                      |");
    clrscr();
    printf("\n\n\n\n\n                    |------                     |");
    clrscr();
    printf("\n\n\n\n\n                    |-------                    |");
    clrscr();
    printf("\n\n\n\n\n                    |--------                   |");
    clrscr();
    printf("\n\n\n\n\n                    |---------                  |");
    clrscr();
    printf("\n\n\n\n\n                    |----------                 |");
    clrscr();
    printf("\n\n\n\n\n                    |-----------                |");
    clrscr();
    printf("\n\n\n\n\n                    |------------               |");
    clrscr();
    printf("\n\n\n\n\n                    |-------------              |");
    clrscr();
    printf("\n\n\n\n\n                    |--------------             |");
    clrscr();
    printf("\n\n\n\n\n                    |---------------            |");
    clrscr();
    printf("\n\n\n\n\n                    |----------------           |");
    clrscr();
    printf("\n\n\n\n\n                    |-----------------          |");
    clrscr();
    printf("\n\n\n\n\n                    |------------------         |");
    clrscr();
    printf("\n\n\n\n\n                    |-------------------        |");
    clrscr();
    printf("\n\n\n\n\n                    |--------------------       |");
    clrscr();
    printf("\n\n\n\n\n                    |---------------------      |");
    clrscr();
    printf("\n\n\n\n\n                    |----------------------     |");
    clrscr();
    printf("\n\n\n\n\n                    |-----------------------    |");
    clrscr();
    printf("\n\n\n\n\n                    |------------------------   |");
    clrscr();
    printf("\n\n\n\n\n                    |-------------------------  |");
    clrscr();
    printf("\n\n\n\n\n                    |-------------------------- |");
    clrscr();
    printf("\n\n\n\n\n                    |---------------------------|");
    clrscr();
    printf("\n\n\n\n\n                    D  O  N  E  ! ! !");
    clrscr();
}
