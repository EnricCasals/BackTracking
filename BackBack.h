#ifndef _BACKBACK_H
#define _BACKBACK_H

#include "Lectura.h"
#include "Group.h"

//troba la millor distribucio de les solucions
void BackBack(Grup *info, Lot *lots, Lot *sol, int K, int nEmpreses, float *delta, LlistaObj lo);
//Calcula la delta
float CALC_Desv(Lot *lots, int nEmpreses, LlistaObj lo);

#endif
