#include "Llista_Emp.h"

//Demanem memoria per la llista
LlistaEmp LEMP_Crea(float llindar){
	LlistaEmp l;
	

	l.nQuants = 0;
	//Demanem memoria
	l.pPdi = (Node *)malloc(sizeof(Node));
	if(l.pPdi != NULL){
		l.pPdi->pSeg = NULL;
	}
	//En cas que no hiagi memoria els dos apuntaran a NULL
	//en cas que si que ens hagi donat memoria els dos apuntaran al fantasma
	l.pPri = l.pPdi;
	l.llindar = llindar;	
	l.fTotal = 0;

	return l;
}
//Alliverem tota la memoria restant
void LEMP_Destrueix(LlistaEmp *l){

	l->pPdi = l->pPri;
	//alliverem memoria fins que els dos estiguin a NULL
	while(l->pPdi != NULL){
		l->pPdi = l->pPdi->pSeg;
		free(l->pPri);
		l->pPri = l->pPdi;
	}
}

//Per inserir una empresa a la llista
void LEMP_Insereix(LlistaEmp *l, Element e){
	Node *aux;

	if(e.fDespesa >= l->llindar){
		//demanem memoria per el nou node
		aux = (Node *)malloc(sizeof(Node));
		if(aux != NULL){
			//colocquem el pdi a la posicio que li toca estar lelement a inserir
			l->pPdi = l->pPri;
			while(l->pPdi->pSeg != NULL && l->pPdi->pSeg->e.fDespesa > e.fDespesa){
				l->pPdi = l->pPdi->pSeg;
			}
			aux->e = e;
			aux->pSeg = l->pPdi->pSeg;
			l->pPdi->pSeg = aux;
			l->nQuants++;
			l->fTotal += e.fDespesa;
		}
	}
}

//Retorna lelement apuntat per el pdi
Element LEMP_Consulta(LlistaEmp l){
	Element e;
	//comprovem que la cua no estigui buida
	if(l.pPri->pSeg != NULL){
		e = l.pPdi->pSeg->e;
	}
	return e;
}

//Elimina l'element apuntat per el pdi
void LEMP_Elimina(LlistaEmp *l){
	Node *aux;//node auxiliar per alliverar memoria
	
	aux = l->pPdi->pSeg;
	//comprovem que el pdi no estigui apuntant a l'ultim node	
	if(aux != NULL){
		l->pPdi->pSeg = l->pPdi->pSeg->pSeg;
		free(aux);
	}
}
//Avança el Pdi
void LEMP_Seg(LlistaEmp *l){
	if(l->pPdi->pSeg != NULL){
		l->pPdi = l->pPdi->pSeg;
	}
}

//Porta el pdi a la primera empresa
void LEMP_Pri(LlistaEmp *l){
	l->pPdi = l->pPri;
}

//Retorna 1 si el pdi esta en l'ultim element
int LEMP_Fi(LlistaEmp l){
	int ret = 0;	
	if(l.pPdi->pSeg == NULL){
		ret = 1;
	}
	return ret;
}

//Calcula quanta despesa per un client
float LEMP_Inversio(LlistaEmp l, float inv){
	float ret = 0;

	ret = (l.pPdi->pSeg->e.fDespesa)/l.fTotal;

	ret = ret * inv;
	return ret;
}

