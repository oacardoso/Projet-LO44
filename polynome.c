#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "polynome.h"

Monome creerMonomev1(float a,int b){
  Monome M;
  M.coef=a;
  M.degr=b;
  return M;
}
Monome creerMonomev2(){
  Monome M;
  float a;
  double b;
  printf("Choisissez le coefficient puis le degre : \n");
  a=lireLong();
  b=liredouble();
  M.coef=a;
  M.degr=b;
  if (a==0){
    return creerMonomev1(0,0);
  }
  else
    return M;
}
Poly creerPolynome(){
  Poly P;
  return P=NULL;
}
Poly userPolynome(){
  Monome M;
  Poly P;
  int a=1;
  P=(Polynome *)malloc(sizeof(Polynome));
  M=creerMonomev2();
  P->valeur = M;
  P->suivant=NULL;
  while(a!=0){
    ecrirePolynome(P);
    printf("Voulez vous ajouter un monome si oui taper 1 sinon 0 : \n" );
    a=lireLong();
    if (a==1){
      P=ajouterMonome(P,creerMonomev2());
    }
    else {
      if (a!=1 && a!= 0){
        printf("********* Selection invalide *********\n");
      }
    }
  }
  return P;
}
int existe (Poly P,int e){
  Poly temp=P;
  int OK=0;
  while(temp!=NULL && OK!=1){
    if (temp->valeur.degr==e){
      OK=1;
    }
    else{
      temp=temp->suivant;
    }
  }
  return OK;
}
Poly ajouterMonome(Poly P,Monome M){
  Poly temp=P;
  if (M.coef==0)
    return P;
  else{
    if(existe(P,M.degr)==0){
      Poly temp2;
      temp2=(Polynome *)malloc(sizeof(Polynome));
      temp2->valeur=M;
      temp2->suivant = NULL;
      if(P==NULL){
        P=temp2;
      }
      else{
        while(temp->suivant!=NULL){
         temp=temp->suivant;
        }
        temp->suivant= temp2;
      }
     }
     else{
       while(temp->valeur.degr!=M.degr){
         temp=temp->suivant;
       }
       temp->valeur.coef=(temp->valeur.coef)+(M.coef);
     }
     return P;
   }
 }
Monome mderiverI(Monome M,int e){
  int i;
  for (i = 0; i < e; i++) {
    if (M.degr==0){
      M.coef=0;
    }
    else{
      M.coef=(M.degr)*(M.coef);
      M.degr=(M.degr)-1;
    }
    if (M.coef==0)
      return creerMonomev1(0,0);
  }
  return M;
}
Monome mderiverR(Monome M,int e){
  if (M.coef==0)
    return creerMonomev1(0,0);
  else{
    if (e==0) {
      return M;
    }
    M.coef=(M.degr)*(M.coef);
    M.degr=(M.degr)-1;
    return mderiverR(M,e-1);
  }
}
Poly pderiver(Poly P,int e){
  Poly P1 = P;
  if (P!=NULL){
    while (P1!=NULL) {
      P1->valeur=mderiverI(P1->valeur,e);
      P1=P1->suivant;
    }
  }
  return P;
}
void ecrireMI(Monome M){
  if(M.degr==0){
    printf("%f \n",M.coef);
  }
  else{
    printf("%f X^ %d \n",M.coef,M.degr);
  }
}
void ecrirePolynome(Poly P){
  Poly temp=P;
  if(P==NULL){
    printf("******** Le polynome est vide ********* \n");
    }
  else{
    printf("Le polynome est :");
    while (temp->suivant!= NULL){
      ecrireMI(temp->valeur);
      if (temp->suivant!=NULL) {
        printf("   +   ");
      temp=temp->suivant;

      }
    }
    ecrireMI(temp->valeur);
  }
}
Poly additionner(Poly P1,Poly P2){
  Poly temp=P1,temp2=P2,P3;
  P3=(Polynome *)malloc(sizeof(Polynome));
  P3=NULL;
  if (P1==NULL && P2==NULL)
    printf("******** P1 ET P2 VIDES *********\n");
  while(temp!=NULL){
    P3=ajouterMonome(P3,temp->valeur);
    temp=temp->suivant;
  }
  while(temp2!=NULL){
    P3=ajouterMonome(P3,temp2->valeur);
    temp2=temp2->suivant;
  }
  return P3;

}
Poly multiplier(Poly P1,Poly P2){
  Poly temp=P1,tp2=P2,P3;
  Monome M;
  float newcoef;
  int newdeg;
  P3=(Polynome *)malloc(sizeof(Polynome));
  P3=creerPolynome();
  if (temp == NULL || tp2 == NULL){
    return P3=NULL;
  }
  else{
    while(temp!=NULL){
      tp2=P2;
      while(tp2!=NULL){
        newdeg=((tp2->valeur.degr)+(temp->valeur.degr));
        newcoef=((tp2->valeur.coef)*(temp->valeur.coef));
        M=creerMonomev1(newcoef, newdeg);
        P3=ajouterMonome(P3,M);
        tp2=tp2->suivant;
      }
      temp=temp->suivant;
    }
    return P3;
  }
}
void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}
int lire(char *chaine, int longueur){
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else{
        viderBuffer();
        return 0;
    }
}
long lireLong(){
    char nombreTexte[100] = {0};
    if (lire(nombreTexte, 100))
        return strtol(nombreTexte, NULL, 10);
    else
        return 0;
  }
double liredouble(){
    char nombreTexte[100] = {0};
    if (lire(nombreTexte, 100))
        return strtod(nombreTexte, NULL);
    else
        return 0;
    }
Poly supprimerMonome(Poly P,int e){
  if (!existe(P,e)){
    printf(" ***********************   NEXISTE PAS   ***************** \n");
    return P;
  }
  else{
    Poly temp=P,temp2=P;
    int OK=0;
    if (P->suivant==NULL) {
      return P=NULL;
    }
    while(temp!=NULL && OK!=1){
      if (temp->valeur.degr==e){
        OK=1;
      }
      else{
        temp2=temp;
        temp=temp->suivant;
      }
    }
    if (temp->suivant==NULL){
      temp2->suivant=NULL;
      temp=NULL;
      return P;
    }
    else{
      temp=P->suivant;
      free(P);
      return temp;
    }
  }
}
