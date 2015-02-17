#include "Group.h"

//Creem un grup de lots
Grup GRUP_Crea(){
	Grup g;
	
	g.fMax = 0;
	g.nQuants = 0;
	g.pPri = NULL;
	g.fValor = 0;
	
	return g;
}


//inserim un nou Lot al grup
void GRUP_Push(Grup *g, Lot l){
	NodeG *aux;

	aux = (NodeG *)malloc(sizeof(NodeG));
	if(aux != NULL){
		g->nQuants++;

		if(LOT_preu(l) > g->fMax){ 
			g->fMax = LOT_preu(l); 			
			g->fValor = LOT_valor(l); 
		}
		if(LOT_preu(l) == g->fMax){ 
			g->fMax = LOT_preu(l); 			
			 
			if(LOT_valor(l) > g->fValor){
				g->fValor = LOT_valor(l);
			}
		}
		
		aux->pSeg = g->pPri;
		g->pPri = aux;
		aux->e = l;
	}

}

//consultem un nou lot del grup
Lot GRUP_Top(Grup g){
	Lot l;
	if(g.pPri != NULL){
		l = g.pPri->e;
	}

	return l;
}

//eliminem el primer lot del grup
void GRUP_Pop(Grup *g){
	NodeG *aux;	

	if(g->pPri != NULL){
		aux = g->pPri;
		g->pPri = g->pPri->pSeg;
		free(aux);
	}
}

//Retornem la memoria ocupada per el grup
void GRUP_Destrueix(Grup *g){
	NodeG *aux;

	while(g->pPri != NULL){
		aux = g->pPri;
		g->pPri = g->pPri->pSeg;
		free(aux);
	}
}

//retorna el preu maxim
float GRUP_Preu(Grup g){
	return g.fMax;
}

//retorna cart si el grup esta buit
int GRUP_Buit(Grup g){
	int ret = 0;
	
	if(g.pPri == NULL) ret = 1;

	return ret;
}

//Elimina inferiors al maxim
Grup GRUP_Maxims(Grup g){
	Grup out;
	Lot aux;

	out = GRUP_Crea();

	while(!GRUP_Buit(g)){
		aux = GRUP_Top(g);
		GRUP_Pop(&g);
		
		if(g.fMax <= LOT_preu(aux) && LOT_Padding(aux)){
			if(g.fValor <= LOT_valor(aux)){
				GRUP_Push(&out, aux);
			}
		}
	}	
	return out;
}

