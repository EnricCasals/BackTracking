#include "Interpret.h"

//interpreta el que ha entrat per la lina de comandes l'usuari
Command Interpreta(int argc, char **argv){
	Command com;
	int c = 0;
	int correcte = 0;

	switch (argc){
		case 4:
			for(c = 1; c < argc; c++){
				if(!strcmp(argv[c], "-cli")){
					c++;
					strcpy(com.Empreses, argv[c]);
					correcte++;
					
				}
				if(!strcmp(argv[c], "-total")){
					correcte++;
				}
			}

			if(correcte == 2){
				com.Opcio = 1;
			}else{
				com.Opcio = -1;
			}
			break;
		case 5:
			for(c = 1; c < argc; c++){
				if(!strcmp(argv[c], "-cli")){
					c++;
					strcpy(com.Empreses, argv[c]);
					correcte++;
				}
				if(!strcmp(argv[c], "-llindar")){
					c++;
					com.Llindar = atof(argv[c]);
					correcte++;
				}
			}
			if(correcte == 2){
				com.Opcio = 2;
			}else{
				com.Opcio = -1;
			}
			break;
		case 13:
			for(c = 1; c < argc; c++){
				if(!strcmp(argv[c], "-cli")){
					c++;
					strcpy(com.Empreses, argv[c]);
					correcte++;
				}
				if(!strcmp(argv[c], "-llindar")){
					c++;
					com.Llindar = atof(argv[c]);
					correcte++;
				}
				if(!strcmp(argv[c], "-prod")){
					c++;
					strcpy(com.Objectes, argv[c]);
					correcte++;
				}
				if(!strcmp(argv[c], "-lots")){
					c++;
					strcpy(com.Lots, argv[c]);
					correcte++;
				}
				if(!strcmp(argv[c], "-compra")){
					c++;
					strcpy(com.Compra, argv[c]);
					correcte++;
				}
				if(!strcmp(argv[c], "-inv")){
					c++;
					com.Inversio = atof(argv[c]);
					correcte++;
				}
			}
			if(correcte == 6){
				com.Opcio = 3;
			}else{
				com.Opcio = -1;
			}
			break;
		default:
			com.Opcio = -1;
	}
	
	return com;
}

//Executa el que toca 
void Executa(Command com){
	Empresa e;
	LlistaEmp le;
	LlistaObj lo;
	Objecte o;
	Lot aux;
	Lot *sol;
	Grup *solucio;
	int c = 0;
	Compra compra;

	switch(com.Opcio){
		case 1:
			le = LlegeixEmpreses(com.Empreses , 0);
			LEMP_Pri(&le);
			while(!LEMP_Fi(le)){
				e = LEMP_Consulta(le);
				printf("Nom: %s Despesa: %.2f\n", e.sNom, e.fDespesa);
				LEMP_Seg(&le);
			}

			LEMP_Destrueix(&le);
			break;
		case 2:
			le = LlegeixEmpreses(com.Empreses , com.Llindar);
			LEMP_Pri(&le);
			while(!LEMP_Fi(le)){
				e = LEMP_Consulta(le);
				printf("Nom: %s Despesa: %.2f\n", e.sNom, e.fDespesa);
				LEMP_Seg(&le);
			}

			LEMP_Destrueix(&le);
			break;
		case 3:
			le = LlegeixEmpreses(com.Empreses , com.Llindar);
			lo = LlegeixObjecte(com.Objectes);
			
			solucio = (Grup *)malloc(sizeof(Grup) * le.nQuants);
			if(solucio != NULL){
				aux = LOT_Crea();
				LEMP_Pri(&le);
				for(c = 0; c < le.nQuants; c++){	
					solucio[c] = GRUP_Crea();	

					LOBJ_Pri(&lo);
					BackTrack(lo, aux, &(solucio[c]), LEMP_Inversio(le, com.Inversio), 0);

					solucio[c] = GRUP_Maxims(solucio[c]);
					LEMP_Seg(&le);
					
				}
				LOT_Destrueix(&aux);

				compra = COMPRA_Crea(lo.nQuants);
				sol = (Lot *)malloc(sizeof(Lot) * le.nQuants);
				if(sol != NULL){
					for(c = 0; c < le.nQuants; c++){
						aux = GRUP_Top(solucio[c]);
						GRUP_Pop(&(solucio[c]));
						sol[c] = aux;
						
					}
					LOT_fitxer(le, sol, com.Lots);
					for(c = 0; c < le.nQuants; c++){
						aux = sol[c];
						while(!LOT_buit(aux)){
							o = LOT_top(aux);
							COMPRA_Insereix(&compra, o.sNom);
							LOT_pop(&aux);
						}
					}
					COMPRA_fprintf(com.Compra, compra);
				}

				LOBJ_Destrueix(&lo);
				LEMP_Destrueix(&le);
			}else{
				printf("Error de memoria\n");
			}

			break;
		default:
			printf("Error!!\n");
	}
}
