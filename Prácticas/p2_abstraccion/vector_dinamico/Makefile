INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c 
AR = ar rvs		
AR_MACOS = libtool -static -o  

$(BIN)/ejemplo_vector_dinamico : $(OBJ)/ejemplo_vector_dinamico.o $(OBJ)/vector_dinamico.o
	$(CXX) -o $(BIN)/ejemplo_vector_dinamico $(OBJ)/ejemplo_vector_dinamico.o $(OBJ)/vector_dinamico.o -I$(INCLUDE) 

$(OBJ)/vector_dinamico.o : $(SRC)/vector_dinamico.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/vector_dinamico.o $(SRC)/vector_dinamico.cpp -I$(INCLUDE)

$(OBJ)/ejemplo_vector_dinamico.o : $(SRC)/ejemplo_vector_dinamico.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/ejemplo_vector_dinamico.o $(SRC)/ejemplo_vector_dinamico.cpp -I$(INCLUDE)
 #************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
