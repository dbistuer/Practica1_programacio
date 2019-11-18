#include <stdio.h>
#define RELACIO_4_3 1
#define RELACIO_16_9 2
#define HIPOTENUSA_16_9 18.3575597507f
#define HIPOTENUSA_4_3 5
#define POLSADES 2.54


int main () {
    int polsades_usuari,relacio_usuari = -1,polzades;
	float  base, alcada,superficie;

	printf("Introdueix la mida de la TV en polzades per fer la taula de mides: \n");
	scanf("%i", &polsades_usuari);

	while(relacio_usuari != RELACIO_4_3 && relacio_usuari != RELACIO_16_9){
        printf("\nQuina relaci ́o d’aspecte vols utilitzar?\nPrem 1 per 4:3\nPrem 2 per 16:9\n");
        scanf("%i", &relacio_usuari);
	}

    printf("\nPolzades | Base  | Alçada | Superfície\n");
	for(int i=-2;i<=2;i++){
        polzades = i + polsades_usuari;
        if(relacio_usuari == RELACIO_4_3){
            base = polzades * POLSADES * 4/HIPOTENUSA_4_3;
            alcada = polzades * POLSADES * 3/HIPOTENUSA_4_3;
        }else{
            base = polzades * POLSADES * 16/HIPOTENUSA_16_9;
            alcada = polzades * POLSADES * 9/HIPOTENUSA_16_9;
        }
        superficie = base * alcada;

        printf("    %i   | %.2f | %.2f  | %.2f\n",polzades,base,alcada,superficie);
	}
}
