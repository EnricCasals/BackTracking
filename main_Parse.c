#include <stdio.h>
#include "Lectura.h"
#include "BackTrack.h"
#include "Interpret.h"
#include "BackBack.h"


void main(int argc, char **argv){
	Command com;

	com = Interpreta(argc, argv);
	Executa(com);

}
