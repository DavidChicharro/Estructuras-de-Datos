SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/pruebacronologia $(BIN)/union_cronologias $(BIN)/filtradoPalabraClave $(BIN)/filtradoIntervalo $(BIN)/estadisticaEventos
#all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o
	$(CXX) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o

$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(BIN)/union_cronologias: $(OBJ)/union_cronologias.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o
	$(CXX) -o $(BIN)/union_cronologias $(OBJ)/union_cronologias.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o

$(OBJ)/union_cronologias.o : $(SRC)/union_cronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/union_cronologias.o $(SRC)/union_cronologia.cpp

$(BIN)/filtradoPalabraClave: $(OBJ)/filtradoPalabraClave.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o
	$(CXX) -o $(BIN)/filtradoPalabraClave $(OBJ)/filtradoPalabraClave.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o

$(OBJ)/filtradoPalabraClave.o : $(SRC)/filtradoPalabraClave.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/filtradoPalabraClave.o $(SRC)/filtradoPalabraClave.cpp

$(BIN)/filtradoIntervalo: $(OBJ)/filtradoIntervalo.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o
	$(CXX) -o $(BIN)/filtradoIntervalo $(OBJ)/filtradoIntervalo.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o

$(OBJ)/filtradoIntervalo.o : $(SRC)/filtradoIntervalo.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/filtradoIntervalo.o $(SRC)/filtradoIntervalo.cpp

$(BIN)/estadisticaEventos: $(OBJ)/estadisticaEventos.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o
	$(CXX) -o $(BIN)/estadisticaEventos $(OBJ)/estadisticaEventos.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o

$(OBJ)/estadisticaEventos.o : $(SRC)/estadisticaEventos.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/estadisticaEventos.o $(SRC)/estadisticaEventos.cpp

$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/fecha_historica.o : $(SRC)/fecha_historica.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/fecha_historica.o $(SRC)/fecha_historica.cpp


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
