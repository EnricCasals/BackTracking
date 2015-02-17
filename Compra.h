#ifndef _COMPRA_H
#define _COMPRA_H


#define TEXT 30

#include <stdio.h>
#include <stdlib.h>
#include "Lot.h"

typedef struct w{
			char sNom[TEXT];
			int  nQuants;
		}Prod;

typedef struct{
			Prod *pPri;
			int nQuants;
		}Compra; 

//crea la llista de la compra
Compra COMPRA_Crea(int nQuants);
//insereix
void COMPRA_Insereix(Compra *com, char *o);
//escriu la llista en un fitxer
void COMPRA_fprintf(char *sNomFitxer, Compra com);


#endif
