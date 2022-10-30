#-*- Makefile -*-

# creation of a variable to store the folder name
path:= ./GenerateRandomDataset

main: main.o $(path)/Point.o  $(path)/GenerateRandomDataset.o
	g++ $(path)/Point.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

$(path)/Point.o: $(path)/Point.cpp
	g++ -c $(path)/Point.cpp -o $(path)/Point.o

$(path)/GenerateRandomDataset.o: $(path)/GenerateRandomDataset.cpp
	g++ -c $(path)/GenerateRandomDataset.cpp -o $(path)/GenerateRandomDataset.o

clean :
	rm *.o 
	rm $(path)/Point.o


# g++ $(path)/Point.cpp main.cpp -o main


