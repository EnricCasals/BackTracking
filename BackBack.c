#include "BackBack.h"

//troba la millor distribucio de les solucions
void BackBack(Grup *info, Lot *lots, Lot *sol, int K, int nEmpreses, float *delta, LlistaObj lo){
	//Compra compra;
	float aux;
	int i = 0;

	while(!GRUP_Buit(info[K])){
		lots[K] = GRUP_Top(info[K]);
		GRUP_Pop(&(info[K]));
		if(K == nEmpreses - 1){
			aux = CALC_Desv(lots, nEmpreses, lo);
			if(aux < *delta){
				//compra = COMPRA_Crea(lots);
				*delta = aux;
				for(i = 0; i < lo.nQuants; i++){
					sol[i] = lots[i];
				}
			}

		else{
			BackBack(info, lots, sol, K + 1, nEmpreses, delta, lo);
		}
	}
	//return compra;
}

float CALC_Desv(Lot *lots, int nEmpreses, LlistaObj lo){
	float *aux;
	Objecte o;
	int i = 0;
	int c = 0;
	float mitjana = 0;
	float delta = 0;

	aux = (float *)malloc(sizeof(float) * lo.nQuants);
	if(aux != NULL){
		LOBJ_Pri(&lo);
		while(!LOBJ_Fi(lo)){
			o = LOBJ_Consulta(lo);
			for(i = 0; i < lo.nQuants; i++){
				aux[c] += LOT_Te(lo, o.sNom);
			}
			c++;
			LOBJ_Seg(&lo);	
		}
		for(i = 0; i < lo.nQuants; i++){
			mitjana += aux[i]/lo.nQuants;
		}
		for(i = 0; i < lo.nQuants; i++){
			delta += mitjana - aux[i];
		}

	}else{ 
		delta = 1000000000;
	}
	
	return delta;
}
