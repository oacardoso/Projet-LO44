#ifndef POLYNOME_H
#define POLYNOME_H


typedef struct Monome {
  double coef;
  int degr;
} Monome;

typedef struct elt {
  Monome valeur;
  struct elt * suivant;
} Polynome;
typedef Polynome *Poly;

void ecrirePolynomeRec(Poly P);
Monome creerMonomev2();
Poly creerPolynome();
Poly userPolynome();
Poly ajouterMonome(Poly P,Monome M);
Poly supprimerMonome(Poly P,int e);
Monome mderiverI(Monome M,int e);
Monome mderiverR(Monome M,int e);
Poly pderiver(Poly P,int e);
void ecrireMI(Monome M);
void ecrirePolynome(Poly P);
Poly additionner(Poly P1,Poly P2);
Poly multiplier(Poly P1,Poly P2);
int existe (Poly P,int e);
Monome creerMonomev1(double a,int b);
void viderBuffer();
int lire(char *chaine, int longueur);
long lireLong();
double liredouble();

#endif
