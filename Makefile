#-*- Makefile -*-

# creation of a variable to store the folder name
path:= ./GenerateRandomDataset

# in 'all' with list all the targets (executables) we want to build (useful when multiple targets)
# here it(s useless because just one target)
all: main

main: main.o $(path)/Point.o $(path)/GenerateRandomDataset.o Model/Model.o 
	g++ $(path)/Point.o $(path)/GenerateRandomDataset.o Model/Model.o main.o -o main 

main.o: main.cpp
	g++ -c main.cpp -o main.o

$(path)/Point.o: $(path)/Point.cpp
	g++ -c $(path)/Point.cpp -o $(path)/Point.o

$(path)/GenerateRandomDataset.o: $(path)/GenerateRandomDataset.cpp
	g++ -c $(path)/GenerateRandomDataset.cpp -o $(path)/GenerateRandomDataset.o

Model/Model.o : Model/Model.cpp
	g++ -std=c++11 -c Model/Model.cpp -o Model/Model.o

# you must enter explicitely the 'make clean' command in order to clean the project
clean:
	rm -f *.o $(path)/*.o Model/*.o

# do 'pip show numpy' to get the path
# -I/home/max/.local/lib/python3.10/site-packages/numpy/core/include -lpython3.10
# g++ -c ./GenerateRandomDataset/GenerateRandomDataset.cpp -o ./GenerateRandomDataset/GenerateRandomDataset.o
# g++ -c ./GenerateRandomDataset/Point.cpp -o ./GenerateRandomDataset/Point.o
# g++ -c main.cpp -o main.o
# g++ ./GenerateRandomDataset/Point.o ./GenerateRandomDataset/GenerateRandomDataset.o main.o -o main


