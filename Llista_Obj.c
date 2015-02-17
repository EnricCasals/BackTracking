#include "Llista_Obj.h"

//Demanem memoria per la llista
LlistaObj LOBJ_Crea(){
	LlistaObj l;
	
	//Demanem memoria
	l.pPdi = (NodeO *)malloc(sizeof(NodeO));
	if(l.pPdi != NULL){
		l.pPdi->pSeg = NULL;
	}
	//En cas que no hiagi memoria els dos apuntaran a NULL
	//en cas que si que ens hagi donat memoria els dos apuntaran al fantasma
	l.pPri = l.pPdi;

	return l;
}
//Alliverem tota la memoria restant
void LOBJ_Destrueix(LlistaObj *l){

	l->pPdi = l->pPri;
	//alliverem memoria fins que els dos estiguin a NULL
	while(l->pPdi != NULL){
		l->pPdi = l->pPdi->pSeg;
		free(l->pPri);
		l->pPri = l->pPdi;
	}
}

//Per inserir una empresa a la llista
void LOBJ_Insereix(LlistaObj *l, Objecte e){
	NodeO *aux;
	//demanem memoria per el nou NodeO
	aux = (NodeO *)malloc(sizeof(NodeO));
	if(aux != NULL){
		l->pPdi = l->pPri;
		//busco la seva posicio idonea dintre de la llista ordenada
		while(l->pPdi->pSeg != NULL && l->pPdi->pSeg->e.fPreu > e.fPreu){
			l->pPdi = l->pPdi->pSeg;
		}		
		aux->e = e;
		aux->pSeg = l->pPdi->pSeg;
		l->pPdi->pSeg = aux;
	}
}

//Retorna lObjecte apuntat per el pdi
Objecte LOBJ_Consulta(LlistaObj l){
	Objecte e;
	//comprovem que la cua no estigui buida
	if(l.pPri->pSeg != NULL){
		e = l.pPdi->pSeg->e;
	}
	return e;
}

//Elimina l'Objecte apuntat per el pdi
void LOBJ_Elimina(LlistaObj *l){
	NodeO *aux;//NodeO auxiliar per alliverar memoria
	
	aux = l->pPdi->pSeg;
	//comprovem que el pdi no estigui apuntant a l'ultim NodeO	
	if(aux != NULL){
		l->pPdi->pSeg = l->pPdi->pSeg->pSeg;
		free(aux);
	}
}
//Avança el Pdi
void LOBJ_Seg(LlistaObj *l){
	if(l->pPdi->pSeg != NULL){
		l->pPdi = l->pPdi->pSeg;
	}
}

//Porta el pdi a la primera empresa
void LOBJ_Pri(LlistaObj *l){
	l->pPdi = l->pPri;
}

//Retorna 1 si el pdi esta en l'ultim Objecte
int LOBJ_Fi(LlistaObj l){
	int ret = 0;	
	if(l.pPdi->pSeg == NULL){
		ret = 1;
	}
	return ret;
}

//estimador del valor restant a la llista
float LOBJ_estimador(LlistaObj l){
	float estimacio = 0;
	NodeO *aux;

	aux = l.pPdi;
	while(aux->pSeg != NULL){
		estimacio += aux->pSeg->e.fPreu;
		aux = aux->pSeg;
	}
	return estimacio;
}
