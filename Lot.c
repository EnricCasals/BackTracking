#include "Lot.h"

//Prepara la informacio per a comensar un Lot
Lot LOT_Crea(){
	Lot l;
	//inicialitzem totes les variables
	l.pila = NULL;
	l.fPreu = 0;
	l.nProductes = 0;
	l.padding = 0;
	//Retornem el lot
	return l;
}

//Allivera la memoria de la pila
void LOT_Destrueix(Lot *l){
	NodeP *aux;
	while(l->pila != NULL){
		aux = l->pila;
		l->pila = l->pila->seg;
		free(aux);
	}
}

//Insereix un producte en un Lot
void LOT_push(Lot *l, Objecte nou){
	NodeP *aux;
	
	//mirem si inserim el padding
	if(strcmp(nou.sNom, "#PADD# ") == 0){
		l->padding = 1;
	}

	//demanem memoria per el nou node
	aux = (NodeP *)malloc(sizeof(NodeP));
	if(aux != NULL){

		//Inseriem el nou producte a la estructura 
		aux->sProd = nou;
		//insrim el node a la pila
		aux->seg = l->pila;
		l->pila = aux;
		//incrementem la cantitat de productes i el preu
		l->fPreu += nou.fPreu;
		if(strcmp(nou.sNom, "#PADD# ")) l->nProductes++;
	}

}

//Consulta l'ultim element inserit al Lot
Objecte LOT_top(Lot l){
	Objecte aux;
	//Asignem el valor que tindra per defecte el producte en cas que la pila esitgui buida
	aux.fPreu = 0;
	strcpy(aux.sNom, "");
	//mirem que la pila no estigui buida
	if(l.pila != NULL){
		//Asignem el primer objecte de la pila		
		aux = l.pila->sProd;
	}

	return aux;
}

//treu l'ultim element inserit al Lot
void LOT_pop(Lot *l){
	NodeP *aux;
	//treiem el preu de l'ultim producte i decrementem el comptador de productes
	l->fPreu -= l->pila->sProd.fPreu;
	l->nProductes--;
	//eliminem el node de la pila
	aux = l->pila;
	l->pila = l->pila->seg; 
	free(aux);
}

//Comproba si un lot esta buit
int LOT_buit(Lot l){
	return l.pila == NULL;
}

//Consulta el preu d'un producte
float LOT_preu(Lot l){
	return l.fPreu;
}

//Consulta els elements d'un Objecte
int LOT_productes(Lot l){
	return l.nProductes;
}

//Consulta el valor d'un producte (Preu / Quantitat)
float LOT_valor(Lot l){
	return (l.fPreu/(float)l.nProductes);
}


//funcio que ens copia un lot en un de nou
Lot LOT_copia(Lot lot){
	Lot copia;
	Objecte aux;
	NodeP *node;
	
	copia = LOT_Crea();

	node = lot.pila;
	while(node != NULL){
		aux = node->sProd;
		LOT_push(&copia, aux);
		node = node ->seg;
	}

	return copia;
}

//funcio que ens printa un lot per pantalla
void LOT_printf(Lot lot){
	Objecte aux;
	NodeP *node;
	
	printf("\n");
	node = lot.pila;
	while(node != NULL){
		aux = node->sProd;
		printf("\t\tNom: %s\n", aux.sNom);
		node = node ->seg;
	}
	printf("\n");
}

//funcio que ens printa un lot per pantalla
void LOT_fprintf(Lot lot, FILE *f){
	Objecte aux;
	NodeP *node;
	


	node = lot.pila;
	while(node != NULL){
		aux = node->sProd;
		if(strcmp(aux.sNom, "#PADD# "))
		fprintf(f, "\tProducte: %s\n", aux.sNom);
		node = node ->seg;
	}
		
	
}

//comprova si un lot te padding
int LOT_Padding(Lot lot){
	return lot.padding;	
}

//Comproba si existeix un objecte en un Lot
int LOT_Te(Lot l, char *sNom){
	NodeP *aux;
	int trobat = 0;

	aux = l.pila;

	while(aux != NULL && !trobat){
		if(!strcmp(aux->sProd.sNom, sNom )){
			trobat = 1;
		}
		aux = aux->seg;
	}
	return trobat;
}

//procediment que monta els lots
void LOT_fitxer(LlistaEmp le, Lot *sol, char *Nom){
	FILE *f;
	Empresa e;
	int i = 0;

	f = fopen(Nom, "w");
	if(f != NULL){
		LEMP_Pri(&le);
		while(!LEMP_Fi(le)){
			e = LEMP_Consulta(le);
			fprintf(f, "-- Lot %d Client %s --\n", i + 1, e.sNom);
			LOT_fprintf(sol[i], f);
			LEMP_Seg(&le);	
			i++;
		}
		fclose(f);
	}
}

