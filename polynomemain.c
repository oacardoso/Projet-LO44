#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "polynome.h"

int main (){
  Poly P,P2,P3=NULL,temp=NULL;
  Monome M;
  int option,o,e;
  printf("***********************************************************\n");
  printf("SI VOUS TAPEZ UNE LETTRE ELLE SERA CONSIDERER COMME NULLE\n");
  printf("***********************************************************\n");
  printf("Selectionner le premier polynome :\n");
  P=userPolynome();
  printf("Selectionner le second polynome :\n");
  P2=userPolynome();
  M=creerMonomev1(0,0);
  do{
    if (temp != NULL){
      printf("***************************************************\n");
      printf("Ancien P = ");
      ecrirePolynome(temp);
    }
    temp=NULL;
    if (P3 != NULL){
      ecrirePolynome(P3);
    }
    P3=NULL;
    printf("\n***************************************************\n\n");
    printf("P = ");
    ecrirePolynome(P);
    printf("P2 = ");
    ecrirePolynome(P2);
    printf("\n***************************************************\n\n");
    printf("Choisir une option \n");
    printf("1.ajouter un Monome a P \n");
    printf("2.ajouter un Monome a P2 \n");
    printf("3.supprimer Monome dans P \n" );
    printf("4.supprimer Monome dans P2 \n" );
    printf("5.deriver le polynome P \n" );
    printf("6.deriver le polynome P2 \n" );
    printf("7.additionner les polynomes P et P2 (Le polynome sera écrit au dessus des 2 autres) \n" );
    printf("8.multiplier 2 polynome P et P2 (Le polynome sera écrit au dessus des 2 autres) \n" );
    printf("9. Pour quitter\n");
    option=lireLong();
    printf("\n");
    switch (option) {
      case 1:
        M=creerMonomev2();
        P=ajouterMonome(P,M);
        break;
      case 2:
        M=creerMonomev2();
        P2=ajouterMonome(P2,M);
        break;
      case 3:
        printf("***************************************************\n");
        printf("La valeur du degré du Monome :\n");
        o=lireLong();
        P=supprimerMonome(P,o);
        break;
      case 4:
        printf("***************************************************\n");
        printf("La valeur du degré du Monome :\n");
        o=lireLong();
        P2=supprimerMonome(P2,o);
        break;
      case 5:
        printf("***************************************************\n");
        printf("Combien de fois souhaitez vous deriver P :\n");
        e=lireLong();
        P=pderiver(P,e);
        break;
      case 6:
        printf("Combien de fois souhaitez vous deriver P2 :\n");
        e=lireLong();
        P2=pderiver(P2,e);
        break;
      case 7:
        P3=additionner(P,P2);
        break;
      case 8:
        P3=multiplier(P,P2);
        break;
      default:
        printf("Votre choix est invalide, veuillez selectionner une option valide \n" );
        break;
    }
  }while (option!=9);
  return 0;
}
