#include "BackTrack.h"
//funcio que resol el problema
//PRECONDICIO Objectes ha de tindre el pdi al inici
//PRECONDICIO punter solucio apuntant a null la primera crida 
//fInversio sera la inversio que vol fer l'empresa en aquest client
void BackTrack(LlistaObj Objectes, Lot lot, Grup *solucio, float fInversio, int K){
	Objecte aux;
	int flag = 0; 
	int i = 0;

	
	if(K != 0)LOBJ_Seg(&Objectes);	
	while(!LOBJ_Fi(Objectes) && (LOT_preu(lot) + LOBJ_estimador(Objectes)) > fInversio){		
		aux = LOBJ_Consulta(Objectes);

		if(Solucio(lot, fInversio, aux.fPreu)){
			if(!flag){
				flag = 1;	
				switch(Factible(lot, solucio)){
					case 0:	
						printf("No solucio\n");
						break;			
					case 1:
						GRUP_Push(solucio, LOT_copia(lot));
						break;
					case 2:
						GRUP_Push(solucio, LOT_copia(lot));
						break;
					default:				
						printf("Error\n");
			
				}
			}
						
		}else{
			LOT_push(&lot, aux);
			BackTrack(Objectes, lot, solucio, fInversio, K + 1);
			LOT_pop(&lot);
		}
		LOBJ_Seg(&Objectes);
	}
	if((LOT_preu(lot) + LOBJ_estimador(Objectes)) <= fInversio){
		while(!LOBJ_Fi(Objectes)){
			aux = LOBJ_Consulta(Objectes);
			LOT_push(&lot, aux);
			LOBJ_Seg(&Objectes);
		}
		GRUP_Push(solucio, LOT_copia(lot));
	}	
}

//comproba si es solucio
int Solucio(Lot lot, float fInversio, float fPreu){
	int ret = 0;
	if(LOT_preu(lot) + fPreu > fInversio){
		ret = 1;
	}
	return ret;
}

//comproba si es millor solucio que l'actual
//si retorna 0 es que lot te un preu inferior a solucio
//si retorna un 1 es que lot te un preu superior a solucio
//si retorna un 2 es que lot te un preu igual a solucio
int Factible(Lot lot, Grup *solucio){
	int ret = 0;
	
	if(LOT_preu(lot) >= GRUP_Preu(*solucio)){
		ret++;
	}
	if(LOT_preu(lot) == GRUP_Preu(*solucio)){
		ret++;
	}
	return ret;
}
