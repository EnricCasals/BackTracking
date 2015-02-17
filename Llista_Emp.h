#ifndef _LLISTAEMP_H
#define _LLISTAEMP_H

#define TEXT 30

#include <stdio.h>

//tipus amb el que definirem l'empresa
typedef struct{
			char sNom[TEXT];
			float fDespesa
		}Empresa;

typedef Empresa Element;

typedef struct n{
			struct n *pSeg;
			Element e; 
		}Node;

typedef struct{
			Node *pPri;
			Node *pPdi;
			float llindar;
			int nQuants;
			float fTotal;
		}LlistaEmp;

//Demanem memoria per la llista
LlistaEmp LEMP_Crea(float llindar);
//Alliverem tota la memoria restant
void LEMP_Destrueix(LlistaEmp *l);
//Per inserir una empresa a la llista
void LEMP_Insereix(LlistaEmp *l, Element e);
//Retorna lelement apuntat per el pdi
Element LEMP_Consulta(LlistaEmp l);
//Elimina l'element apuntat per el pdi
void LEMP_Elimina(LlistaEmp *l);
//Avança el Pdi
void LEMP_Seg(LlistaEmp *l);
//Porta el pdi a la primera empresa
void LEMP_Pri(LlistaEmp *l);
//Retorna 1 si el pdi esta en l'ultim element
int LEMP_Fi(LlistaEmp l);
//Calcula quanta despesa per un client
float LEMP_Inversio(LlistaEmp l, float inv);

#endif
