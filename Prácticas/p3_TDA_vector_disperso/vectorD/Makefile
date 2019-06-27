INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c 
AR = ar rvs		
AR_MACOS = libtool -static -o  


all: $(BIN)/ejemplo_vectorD $(BIN)/frecuencias 

# Binario: ejemplo_vectorD
$(BIN)/ejemplo_vectorD : $(OBJ)/ejemplo_vectorD.o
	$(CXX) -o $(BIN)/ejemplo_vectorD $(OBJ)/ejemplo_vectorD.o -I$(INCLUDE)  

$(OBJ)/ejemplo_vectorD.o : $(SRC)/ejemplo_vectorD.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/ejemplo_vectorD.o $(SRC)/ejemplo_vectorD.cpp -I$(INCLUDE)

# Binario: frecuencias
$(BIN)/frecuencias : $(OBJ)/frecuencias.o
	$(CXX) -o $(BIN)/frecuencias $(OBJ)/frecuencias.o -I$(INCLUDE)  

$(OBJ)/frecuencias.o : $(SRC)/frecuencias.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/frecuencias.o $(SRC)/frecuencias.cpp -I$(INCLUDE)


# Nótese que como vectorD es una clase genérica (template), no la hemos compilado explícitamente ni enlazado con ejemplo_vectorD.o 
# Como hemos incluido el código de vectorD.hxx en el fichero de cabeceras vectorD.h, cuando hagamos #include "VectorD.h" desde otro fichero de código (por ejemplo, desde ejemplo_vectorD.cpp) 
# tanto la definición como la implementación de vectorD están disponibles al compilador, con lo que puede generar el código objeto ejemplo_vectorD.o. 
# La desventaja es que renunciamos al principio de ocultamiento de información (el fichero de cabeceras incluye la implementación de los métodos)


#************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
