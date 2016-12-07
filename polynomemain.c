#include "stdlib.h"
#include "stdio.h"
#include "polynome.h"



int main (){
  Monome M,X,F;
  Poly P,P1,P2,P3;
  ecrireMonome(M);
  ecrireMonome(X);
  ecrireMonome(F);
  M=creerMonomev2();
  X=creerMonomev2();
  F=creerMonomev2();
  ecrireMonome(M);
  ecrireMonome(X);
  ecrireMonome(F);
  printf("***********************************************\n");
  P=creerPolynome();
  P1=creerPolynome();
  P2=creerPolynome();
  ecrirePolynome(P2);
  ecrirePolynome(P);
  ecrirePolynome(P1);
  printf("***********************************************\n");
  P1=ajouterMonome(P1,F);
  P1=ajouterMonome(P1,X);
  P2=ajouterMonome(P2,X);
  P2=ajouterMonome(P2,M);
  P=ajouterMonome(P,M);
  P=ajouterMonome(P,F);
  printf("***********************************************\n");
  ecrirePolynome(P2);
  ecrirePolynome(P);
  ecrirePolynome(P1);
  printf("***********************************************\n");
  P3=multiplier(P1,P);
  ecrirePolynome(P3);
  return 0;
}
