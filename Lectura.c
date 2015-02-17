#include "Lectura.h"

Empresa ParseEmpresa(char *input){
	Empresa e;
	char aux[TEXT];
	char nom[TEXT];
	float despesa = 0;
	int c = 0;
	int i = 0;
	int end = 0;
	int num = 0;
	//busquem el final
	c = 0;
	while(input[c] != '\0'){
		end++;
		c++;	
	}
	c = c - 2;
	end = end - 2;
	
	//retrocedim fins el que acabi el nombre
	while(input[c] == '.' || (input[c] <= '9' && input[c] >= '0')){
		num++;
		c--;
	}

	//copiem el nombre a aux
	i = 0;
	c++;
	while(input[c] != '\0' && input[c] != '\n'){
		aux[i] = input[c];
		i++;
		c++;	
	}
	aux[i] = '\0';
	//fem l'atof de de aux que es on teni el nombre
	despesa = atof(aux);
	input[end - num] = '\0';
	//finalment ho copiem a la empresa i la retornem
	e.fDespesa = despesa;
	strcpy(e.sNom, input);

	return e;
}

//LLegeix les empreses des de un fitxer
LlistaEmp LlegeixEmpreses(char *nom, float llindar){
	LlistaEmp l;
	FILE *f;
	char aux[TEXT];
	Empresa e;


	f = fopen(nom, "r");	
	if(f != NULL){
		l = LEMP_Crea(llindar);
		
		//anem llegin cada linea i ta convertim a una empresa que sera inserida a la llista		
		fgets(aux, TEXT, f);
		while(!feof(f)){
			e = ParseEmpresa(aux);
			LEMP_Insereix(&l, e);
			fgets(aux, TEXT, f);
		}
		fclose(f);

	}
	return l;
}

Objecte ParseObjecte(char *input){
	Objecte e;
	char aux[TEXT];
	char nom[TEXT];
	float despesa = 0;
	int c = 0;
	int i = 0;
	//primer copien la primera part de la cadena a Nom
	c = 0;
	while(input[c] != '(' && input[c] != '\0'){
		nom[c] = input[c];
		c++;
	}
	nom[c] = '\0';
	c++;
	//llabors copiem la part numerica a una cadena auxiliar 
	i = 0;
	while(input[c] != '\0' && input[c] != ')'){
		aux[i] = input[c];
		c++;
		i++;	
	}
	aux[i] = '\0';
	//fem l'atof d'aquesta cadena auxiliar
	despesa = (float)atof(aux);
	
	//finalment ho copiem a la empresa i la retornem
	e.fPreu = despesa;
	strcpy(e.sNom, nom);

	return e;
}

//LLegeix les empreses des de un fitxer
LlistaObj LlegeixObjecte(char *nom){
	LlistaObj l;
	FILE *f;
	char aux[TEXT];
	Objecte e;


	f = fopen(nom, "r");	
	if(f != NULL){
		l = LOBJ_Crea();
		
		//anem llegin cada linea i ta convertim a una empresa que sera inserida a la llista		
		fgets(aux, TEXT, f);
		while(!feof(f)){
			e = ParseObjecte(aux);
			LOBJ_Insereix(&l, e);
			fgets(aux, TEXT, f);
		}
		fclose(f);

	}
	return l;
}
