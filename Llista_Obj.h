#ifndef _LLISTAOBJ_H
#define _LLISTAOBJ_H

#define TEXT 30

#include <stdio.h>

//tipus amb el que definirem l'empresa
typedef struct{
			char sNom[TEXT];
			float fPreu;
		}Objecte;

typedef struct t{
			struct t *pSeg;
			Objecte e; 
		}NodeO;

typedef struct{
			NodeO *pPri;
			NodeO *pPdi;
			int nQuants;
		}LlistaObj;

//Demanem memoria per la llista
LlistaObj LOBJ_Crea();
//Alliverem tota la memoria restant
void LOBJ_Destrueix(LlistaObj *l);
//Per inserir una empresa a la llista
void LOBJ_Insereix(LlistaObj *l, Objecte e);
//Retorna lObjecte apuntat per el pdi
Objecte LOBJ_Consulta(LlistaObj l);
//Elimina l'Objecte apuntat per el pdi
void LOBJ_Elimina(LlistaObj *l);
//Avança el Pdi
void LOBJ_Seg(LlistaObj *l);
//Porta el pdi a la primera empresa
void LOBJ_Pri(LlistaObj *l);
//Retorna 1 si el pdi esta en l'ultim Objecte
int LOBJ_Fi(LlistaObj l);
//estimador del valor restant a la llista
float LOBJ_estimador(LlistaObj l);

#endif
