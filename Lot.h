#ifndef _LOT_H
#define _LOT_H

#define TEXT 30

#include <string.h>
#include "Llista_Obj.h"
#include "Llista_Emp.h"

//Estructura auxiliar per montar la pila
typedef struct p{
			struct p *seg;
			Objecte sProd;
		}NodeP;
//Estructura que tindra la informacio del lot
typedef struct{
			NodeP *pila;
			int	  nProductes;
			float fPreu;
			int	  padding;
		}Lot;
//Prepara la informacio per a comensar un Lot
Lot LOT_Crea();
//Allivera la memoria de la pila
void LOT_Destrueix(Lot *l);
//Insereix un producte en un Lot
void LOT_push(Lot *l, Objecte nou);
//Consulta l'ultim element inserit al Lot
Objecte LOT_top(Lot l);
//treu l'ultim element inserit al Lot
void LOT_pop(Lot *l);
//Comproba si un lot esta buit
int LOT_buit(Lot l);
//Consulta el preu d'un producte
float LOT_preu(Lot l);
//Consulta els elements d'un Objecte
int LOT_productes(Lot l);
//Consulta el valor d'un producte (Preu / Quantitat)
float LOT_valor(Lot l);
//funcio que ens copia un lot en un de nou
Lot LOT_copia(Lot lot);
//funcio que ens printa un lot per pantalla
void LOT_printf(Lot lot);
//funcio que ens printa un lot per pantalla
void LOT_fprintf(Lot lot, FILE *f);
//retorna 1 si conte Padding
int LOT_Padding(Lot lot);
//Comproba si existeix un objecte en un Lot
int LOT_Te(Lot l, char *sNom);
//procediment que monta els lots
void LOT_fitxer(LlistaEmp le, Lot *sol, char *Nom);

#endif
