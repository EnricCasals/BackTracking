#ifndef _GROUP_H
#define _GROUP_H

#include "Lot.h"


typedef struct g{
			Lot e;
			struct g *pSeg;
		}NodeG;

typedef struct{
			NodeG *pPri;
			int nQuants;
			float fMax;
			float fValor;
		}Grup;

//Creem un grup de lots
Grup GRUP_Crea();
//inserim un nou Lot al grup
void GRUP_Push(Grup *g, Lot l);
//consultem un nou lot del grup
Lot GRUP_Top(Grup g);
//eliminem el primer lot del grup
void GRUP_Pop(Grup *g);
//Retornem la memoria ocupada per el grup
void GRUP_Destrueix(Grup *g);
//retorna el preu maxim
float GRUP_Preu(Grup g);
//retorna cart si el grup esta buit
int GRUP_Buit(Grup g);
//Elimina inferiors al maxim
Grup GRUP_Maxims(Grup g);

#endif
