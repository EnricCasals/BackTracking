#ifndef _INTERPRET_H
#define _INTERPRET_H

#define TEXT 30

#include <string.h>
#include <stdlib.h>
#include "Lectura.h"
#include "BackTrack.h"
#include "Compra.h"

typedef struct{
			char Empreses[TEXT];
			float Llindar;
			char Objectes[TEXT];
			char Lots[TEXT];
			char Compra[TEXT];
			float Inversio;
			int Opcio;
		}Command;

//interpreta el que ha entrat per la lina de comandes l'usuari
Command Interpreta(int argc, char **argv);
//Executa el que toca 
void Executa(Command com);

#endif
