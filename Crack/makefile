PARAM=-std=c99 -Wall -lpthread -lcrypt
passwordCracker: passwordCracker.o  crack.o
	gcc passwordCracker.o crack.o -o passwordCracker $(PARAM)
passwordCracker.o: passwordCracker.c
	gcc -c passwordCracker.c $(PARAM)
crack.o: crack.c crack.h
	gcc -c crack.c $(PARAM)
clean:
	rm -rf *.o
