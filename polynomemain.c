#include "stdlib.h"
#include "stdio.h"
#include "polynome.h"



int main (){
  Poly P,P2;
  Monome M;
  int option,o,e;
  P=userPolynome();
  P2=userPolynome();
  M=creerMonomev1(0,0);
  do{
    printf("P = ");
    ecrirePolynome(P);
    printf("P2 = ");
    ecrirePolynome(P2);
    printf("Choisir une option \n");
    printf("1.creer un Monome \n");
    printf("2.ajouter un Monome a P \n");
    printf("22.ajouter un Monome a P2 \n");
    printf("3.supprimer Monome dans P \n" );
    printf("33.supprimer Monome dans P2 \n" );
    printf("4.deriver un monome\n" );
    printf("5.deriver le polynome P \n" );
    printf("55.deriver le polynome P2 \n" );
    printf("6.additionner les polynomes P et P2 (remplace P1 par P1+P2) \n" );
    printf("7.multiplier 2 polynome P et P2 (remplace P1 par P1*P2) \n" );
    printf("0. Pour quitter\n");
    scanf("%d\n",&option );

    switch (option) {
      case 1:
        M=creerMonomev2();
        ecrireMI(M);
        break;
      case 2:
        P=ajouterMonome(P,M);
        break;
      case 22:
        P2=ajouterMonome(P2,M);
        break;
      case 3:
        printf("La valeur du degré du Monome\n");
        scanf("%d\n",&o);
        P=supprimerMonome(P,o);
        break;
      case 33:

        printf("La valeur du degré du Monome\n");
        scanf("%d\n",&o);
        P2=supprimerMonome(P2,o);

        break;
      case 4:
        printf("Combien de fois souhaiter vous deriver le monome :\n");
        scanf("%d\n",&e);
        M=mderiverR(M,e);
        ecrireMI(M);
        break;
      case 5:
        printf("Combien de fois souhaiter vous deriver P :\n");
        scanf("%d\n",&e);
        P=pderiver(P,e);
        break;
      case 55:
        printf("Combien de fois souhaiter vous deriver P2 :\n");
        scanf("%d\n",&e);
        P2=pderiver(P2,e);
        break;
      case 6:
      P=additionner(P,P2);
        break;
      case 7:
      P=multiplier(P,P2);
        break;
    }
  }while (option!=0);
  return 0;
}
