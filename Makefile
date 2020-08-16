FindMax.out : FindMax.o RunFind.o Intersection.o
	g++ -ansi -Wall -g -o FindMax.out FindMax.o RunFind.o Intersection.o

FindMax.o : FindMax.cpp FindMax.h Intersection.h
	g++ -ansi -Wall -g -c FindMax.cpp

RunFind.o : RunFind.cpp RunFind.h CPUTimer.h FindMax.h 
	g++ -ansi -Wall -g -c RunFind.cpp

Intersection.o : Intersection.cpp Intersection.h
	g++ -ansi -Wall -g -c Intersection.cpp


clean : 
	rm -f FindMax.out FindMax.o  RunFind.o   
