#include "Compra.h"

//crea la llista de la compra
Compra COMPRA_Crea(int nQuants){
	Compra com;
	Prod *aux;
	

	aux = (Prod *)malloc(sizeof(Prod) * nQuants);
	if(aux != NULL){
		com.pPri = aux;
		com.nQuants = 0;
	}
	return com;
}

//insereix
void COMPRA_Insereix(Compra *com, char *Nom){
	int trobat = 0;
	int i = 0;
	int posicio = 0;;

	if(strcmp(Nom, "#PADD# ") != 0){
		while(i < com->nQuants && !trobat){
			if(!strcmp(com->pPri[i].sNom, Nom)){
				trobat = 1;
				posicio = i;
			}
			i++;
		}
		if(trobat){
			com->pPri[posicio].nQuants++;
		}else{
			strcpy(com->pPri[com->nQuants].sNom, Nom);
			com->pPri[com->nQuants].nQuants++;
			com->nQuants++;
		}
	}
}

//escriu la llista en un fitxer
void COMPRA_fprintf(char *sNomFitxer, Compra com){
	FILE *f;
	int i = 0;
	
	f = fopen(sNomFitxer, "w");
	if(f != NULL){
		while(i < com.nQuants){

			fprintf(f, "Nom: %s  - Cantitat: %d\n", com.pPri[i].sNom,  com.pPri[i].nQuants);
			i++;
		}
		fclose(f);
	}
	
}
