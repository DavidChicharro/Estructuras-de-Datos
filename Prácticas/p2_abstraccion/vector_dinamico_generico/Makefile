INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c 
AR = ar rvs		
AR_MACOS = libtool -static -o  

$(BIN)/ejemplo_vector_dinamico : $(OBJ)/ejemplo_vector_dinamico.o
	$(CXX) -o $(BIN)/ejemplo_vector_dinamico $(OBJ)/ejemplo_vector_dinamico.o -I$(INCLUDE)  

$(OBJ)/ejemplo_vector_dinamico.o : $(SRC)/ejemplo_vector_dinamico.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/ejemplo_vector_dinamico.o $(SRC)/ejemplo_vector_dinamico.cpp -I$(INCLUDE)

# Nótese que como vector_dinamico es una clase genérica (template), no la hemos compilado explícitamente ni enlazado con ejemplo_vector_dinamico.o 
# Como hemos incluido el código de vector_dinamico.tpp en el fichero de cabeceras vector_dinamico.h, cuando hagamos #include "Vector_Dinamico.h" desde otro fichero de código (por ejemplo, desde ejemplo_vector_dinamico.cpp) 
# tanto la definición como la implementación de vector_dinamico están disponibles al compilador, con lo que puede generar el código objeto ejemplo_vector_dinamico.o. 
# La desventaja es que renunciamos al principio de ocultamiento de información (el fichero de cabeceras incluye la implementación de los métodos)


#************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
