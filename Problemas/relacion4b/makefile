SRC = ./src
OBJ = ./obj
BIN = ./bin
INC = ./include
CXX = g++
CPPFLAGS = -g  -I$(INC) -std=c++11


all: ejercicio11 ejercicio15 ejercicio16

	
ejercicio11: $(OBJ)/ejercicio11.o
	${CXX} -o $(BIN)/ejercicio11 $(OBJ)/ejercicio11.o

$(OBJ)/ejercicio11.o: $(SRC)/ejercicio11.cpp
	${CXX} -c $(SRC)/ejercicio11.cpp -o $(OBJ)/ejercicio11.o $(CPPFLAGS)

	
ejercicio15: $(OBJ)/ejercicio15.o
	${CXX} -o $(BIN)/ejercicio15 $(OBJ)/ejercicio15.o

$(OBJ)/ejercicio15.o: $(SRC)/ejercicio15.cpp
	${CXX} -c $(SRC)/ejercicio15.cpp -o $(OBJ)/ejercicio15.o $(CPPFLAGS)

	
ejercicio16: $(OBJ)/ejercicio16.o
	${CXX} -o $(BIN)/ejercicio16 $(OBJ)/ejercicio16.o

$(OBJ)/ejercicio16.o: $(SRC)/ejercicio16.cpp
	${CXX} -c $(SRC)/ejercicio16.cpp -o $(OBJ)/ejercicio16.o $(CPPFLAGS)



# ************ Limpieza  ************
clean :
	-rm -r $(OBJ)/* $(BIN)/* #$(ZIP)/*