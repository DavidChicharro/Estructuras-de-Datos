SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o
	$(CXX) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o

$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/fecha_historica.o : $(SRC)/fecha_historica.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/fecha_historica.o $(SRC)/fecha_historica.cpp


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
