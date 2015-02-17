#ifndef _LECTURA_H
#define _LECTURA_H


#include <string.h>
#include <stdlib.h>
#include "Llista_Emp.h"
#include "Llista_Obj.h"

//pasa duna cadena (Nom despesa) a una estructura del tipus Empresa
Empresa ParseEmpresa(char *input);
//Llegeix empreses des de un fitxer i retorna una llista de les empreses
LlistaEmp LlegeixEmpreses(char *nom, float llindar);
//pasa duna cadena (Nom despesa) a una estructura del tipus Empresa
Objecte ParseObjecte(char *input);
//Llegeix empreses des de un fitxer i retorna una llista de les empreses
LlistaObj LlegeixObjecte(char *nom);

#endif
