#include <stdio.h>
#include <string.h>
#include "Llista_Emp.h"

int main(){
	LlistaEmp l;
	Element e;

	l = LEMP_Crea();

	e.fDespesa = 20;
	strcpy(e.sNom, "Test1");
	LEMP_Insereix(&l, e);

	e.fDespesa = 10;
	strcpy(e.sNom, "Test2");
	LEMP_Insereix(&l, e);	

	LEMP_Seg(&l);

	e.fDespesa = 230;
	strcpy(e.sNom, "Test3");
	LEMP_Insereix(&l, e);

	e.fDespesa = 0;
	strcpy(e.sNom, "Test4");
	LEMP_Insereix(&l, e);

	LEMP_Pri(&l);
	while(!LEMP_Fi(l)){
		e = LEMP_Consulta(l);
		printf("Nom: %s Despesa: %f\n", e.sNom, e.fDespesa);
		LEMP_Seg(&l);
	}

	l.pPdi = l.pPri;
	while(!LEMP_Fi(l)){
		e = LEMP_Consulta(l);
		printf("Nom: %s Despesa: %f\n", e.sNom, e.fDespesa);
		LEMP_Seg(&l);
	}

	LEMP_Destrueix(&l);

	return 0;
}
