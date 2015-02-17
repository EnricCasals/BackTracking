#ifndef _BACKTRACK_H
#define _BACKTRACK_H

#include "Lot.h"
#include "Llista_Obj.h"
#include "Group.h"

void BackTrack(LlistaObj Objectes, Lot lot, Grup *solucio, float fInversio, int K);
int Solucio(Lot lot, float fInversio, float fPreu);
int Factible(Lot lot, Grup *solucio);

#endif
