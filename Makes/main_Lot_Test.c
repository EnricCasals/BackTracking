
#include <stdio.h>
#include "Lot.h"

void main(){
	Lot l;
	Producte p;
	
	printf("Comen");
	
	l = LOT_Crea();
	printf("Inserim\n");
	p.fPreu = 1;
	strcpy(p.sNom,"Test1");
	LOT_push(&l, p);

	p.fPreu = 1;
	strcpy(p.sNom,"Test2");
	LOT_push(&l, p);
	
	p.fPreu = 1;
	strcpy(p.sNom,"Test3");
	LOT_push(&l, p);

	p.fPreu = 1;
	strcpy(p.sNom,"Test4");
	LOT_push(&l, p);
	
	LOT_Destrueix(&l);	
	
	while(!LOT_buit(l)){
		p = LOT_top(l);		
		printf("Nom(producte): %s  Preu(producte): %.2f Valor: %.2f\n", p.sNom, p.fPreu, LOT_valor(l));
		LOT_pop(&l);
	}
	
}
