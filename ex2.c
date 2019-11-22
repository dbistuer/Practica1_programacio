#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MIN_RULETA 1
#define PAUSA 2
#define MAX_RULETA 36
#define ENDEVINAR 1
#define PARELL_SENAR 2
#define NO_JUGAR 0
#define CAPITAL_INICIAL 1000
#define PARELL 2
#define SENAR 1

void mostraMenu(int monedero);
void clrscr(bool ubuntu);
int seleccioJoc(bool ubuntu, int seleccio,int monedero);
int jocEndevinar(bool ubuntu, int numero_escollit,int numero_ruleta,int aposta,int *patides_guanyades,int *patides_perdudes);
int jocParellSenar(bool ubuntu,int numero_escollit,int numero_ruleta,int aposta,int *patides_guanyades,int *patides_perdudes);
void seleccioSistemaOperatiu(bool *ubuntu);
void cantitatAposta(bool ubuntu,int *aposta,int monedero);


int main() {

// Variables
int
    seleccio = -1,
    numero_escollit = -1,
    monedero = CAPITAL_INICIAL,
    numero_ruleta = 0,
    aposta = 0,
    patides_guanyades = 0,
    patides_perdudes = 0;
bool ubuntu = true;
char pause;
//---------------------------

    srand(time(NULL)); // Inicialitzaci´o, nom´es s’ha de fer una vegada al principi
    seleccioSistemaOperatiu(&ubuntu);
    while (seleccio != NO_JUGAR && monedero > 0)
    {
        seleccio = seleccioJoc(ubuntu,seleccio,monedero);
        if (seleccio != NO_JUGAR){
            cantitatAposta(ubuntu,&aposta,monedero);

            if(seleccio == ENDEVINAR)
                monedero += jocEndevinar(ubuntu,numero_escollit,numero_ruleta,aposta,&patides_guanyades,&patides_perdudes);
            else if(seleccio == PARELL_SENAR)
                monedero += jocParellSenar(ubuntu,numero_escollit,numero_ruleta,aposta,&patides_guanyades,&patides_perdudes);
            if(monedero != 0){
                printf("\n\n\n\n\nPolsa ENTER per a continuar.");
                while(getchar() != '\n');
                scanf("%[^\n]",&pause);
            }
        }
    }
    if(monedero == 0){
        printf("\nHo has perdut tot!\n\n");
    }else{
        printf("El teu capital final es de %i Euros.\n",monedero);
    }
    printf("Has guanyat %i partides i n'has perdut %i\n\n",patides_guanyades,patides_perdudes);

    return 0;
}

void seleccioSistemaOperatiu(bool *ubuntu){
    int sistema = -1;
    do{
        printf("Benvingut al joc de la ruleta!\n\n");
        printf("Insereix 0 si el sistema es Ubuntu o 1 si es Windows:\n");
        scanf("%i",&sistema);
    }while(sistema<0 && sistema<1);
    clrscr(ubuntu);
    if(sistema == 0)
        *ubuntu = true;
    else
        *ubuntu = false;
}

void cantitatAposta(bool ubuntu,int *aposta,int monedero){
    int auxAposta = 0;
    *aposta = 0;
    while(*aposta < 1 || *aposta > monedero){
        printf("Tens un capital de %i Euros, quina quantitat vols apostar?\n",monedero);
        scanf("%i",&auxAposta);
        *aposta = auxAposta;
        clrscr(ubuntu);
        if(*aposta < 1 || *aposta > monedero){
            if(*aposta < 1){
                printf("L'aposta a realitzar no pot ser menor que 1.\n\n");
            }else if(*aposta > monedero){
                printf("L'aposta no pot ser mes gran que el capital que es disposa.\n\n");
            }
        }
    }
}

int jocParellSenar(bool ubuntu,int numero_escollit,int numero_ruleta,int aposta,int *patides_guanyades,int *patides_perdudes){
            numero_escollit = -1;
            while(numero_escollit != PARELL && numero_escollit != SENAR){
                printf("Prem %i per apostar a numero senar o %i per apostar a numero parell:\n",SENAR,PARELL);
                scanf("%i",&numero_escollit);
            }
            numero_ruleta = rand() % MAX_RULETA + MIN_RULETA; // Genera n´umeros de l’1 al 36
            clrscr(ubuntu);
            if(numero_escollit == PARELL)
                printf("\nHas apostat per parell i ha sortit %i\n",numero_ruleta);
            else
                printf("\nHas apostat per senar i ha sortit %i\n",numero_ruleta);
            if(numero_ruleta % 2 == 0){//parells
                if(numero_escollit == PARELL){
                    printf("Has guanyat %i Euros!",aposta);
                    *patides_guanyades += 1;
                    return aposta;
                }else{
                    printf("Has perdut %i Euros!",aposta);
                    *patides_perdudes += 1;
                    return -aposta;
                }
            }else{ //senars
                if(numero_escollit == SENAR){
                    printf("Has guanyat %i Euros!",aposta);
                    *patides_guanyades += 1;
                    return aposta;
                }else{
                    printf("Has perdut %i Euros!",aposta);
                    *patides_perdudes += 1;
                    return -aposta;
                }
            }
}

int jocEndevinar(bool ubuntu, int numero_escollit,int numero_ruleta,int aposta,int *patides_guanyades,int *patides_perdudes){
    printf("Introdueix el numero per la teva aposta (de l’%i al %i) : \n",MIN_RULETA,MAX_RULETA);
    scanf("%i",&numero_escollit);
    while(numero_escollit<MIN_RULETA || numero_escollit>MAX_RULETA){
        clrscr(ubuntu);
        printf("El numero escollit no es correcte!!\n\n Ha de ser un numero entre %i i %i\n\n",MIN_RULETA,MAX_RULETA);
        printf("Torna a inserir el numero: ");
        scanf("%i",&numero_escollit);
    }
    numero_ruleta = rand() % MAX_RULETA + MIN_RULETA; // Genera n´umeros de l’1 al 36
    clrscr(ubuntu);
    printf("Has apostat pel numero %i i ha sortit %i\n",numero_escollit,numero_ruleta);
    if(numero_ruleta == numero_escollit){
        printf("Has guanyat %i Euros!",aposta);
        *patides_guanyades += 1;
        return aposta;
    }else{
        printf("Has perdut %i Euros!",aposta);
        *patides_perdudes += 1;
        return -aposta;
    }
}

int seleccioJoc(bool ubuntu, int seleccio,int monedero){
    seleccio = -1;
    clrscr(ubuntu);
    while(seleccio != NO_JUGAR && seleccio != ENDEVINAR && seleccio != PARELL_SENAR){
            if(seleccio != -1)
                printf("\nEl numero insertat no es correcte!!!!\n\n\n");
            mostraMenu(monedero);
            scanf("%i",&seleccio);
            clrscr(ubuntu);
        }
        return seleccio;
}

//Mostra les opcions de joc
void mostraMenu(int monedero){
    printf("Tens un capital de %i Euros. A quin joc vols jugar?\n",monedero);
    printf("Prem %i per jugar a endevinar el numero de l’%i al %i\n",ENDEVINAR,MIN_RULETA,MAX_RULETA);
    printf("Prem %i per jugar a endevinar si sera parell o senar\n",PARELL_SENAR);
    printf("Prem %i per sortir\n",NO_JUGAR);
}

//Neteja la pantalla
void clrscr(bool ubuntu){
    if(ubuntu)
        system("clear");
    else
        system("@cls");
}
