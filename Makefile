all: test
Llista_Obj.o: Llista_Obj.c Llista_Obj.h
	gcc -c Llista_Obj.c
Llista_Emp.o: Llista_Emp.c Llista_Emp.h
	gcc -c Llista_Emp.c
Lectura.o: Lectura.c Lectura.h Llista_Emp.h Llista_Obj.h
	gcc -c Lectura.c  
Lot.o: Lot.h Lot.c Llista_Obj.h Llista_Emp.h
	gcc -c Lot.c
Compra.o: Compra.c Compra.h Lot.h Llista_Obj.h 
	gcc -c Compra.c
Group.o: Group.h Group.c Lot.h
	gcc -c Group.c
Interpret.o: Interpret.c Interpret.h Lectura.h BackTrack.h Compra.h
	gcc -c Interpret.c
BackTrack.o: BackTrack.c BackTrack.h Llista_Obj.h Lot.h Group.h
	gcc -c BackTrack.c
main_Parse.o: main_Parse.c Lectura.h BackTrack.h Group.h Interpret.h
	gcc -c main_Parse.c
test: Llista_Emp.o Llista_Obj.o Lectura.o Lot.o BackTrack.o Group.o Interpret.o  Compra.o main_Parse.o
	gcc Llista_Emp.o Llista_Obj.o Lectura.o Lot.o BackTrack.o Group.o Interpret.o Compra.o main_Parse.o -o test 
