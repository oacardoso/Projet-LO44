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
  int b;
  printf("Choisissez le coeffiscient puis le degre : \n");
  scanf("%f%d",&a,&b);
  M.coef=a;
  M.degr=b;
  viderBuffer();
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
    printf("Voulez vous ajouter un Monome si oui taper 1 sinon 0\n" );
    scanf("%d",&a);
    if (a==1){
      P=ajouterMonome(P,creerMonomev2());
    }
    else {
      if (a!=1 && a!= 0){
        printf("Séléction invalide\n");
      }
    }
  }
  viderBuffer();
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
  }
  return M;
}
Monome mderiverR(Monome M,int e){
  if (e==0)
    return M;
  else{
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
    printf("Le polynome est vide \n");
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
void viderBuffer(void){
  int c;
  while((c=getchar()) != EOF && c != '\n');

}
Poly supprimerMonome(Poly P,int e){
  Poly temp=P,temp2;
  if (P==NULL)
    return P;
  else {
    if (P->suivant == NULL && e==P->valeur.degr)
    return P=NULL;
    else{
      while (temp!=NULL || temp->valeur.degr!=e) {
        temp2=temp;
        temp=temp->suivant;
      }
      if (temp->valeur.degr==e){
        temp2->suivant=NULL;
        free(temp);
        }
      else{
        printf("Le Polynome na aucun monome de ce degré \n");
      }
      return P;
      }
    }
  }
