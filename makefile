#Macros
CC = g++
CPPFLAGS = -g -std=c++11 -pthread
SRC = src/main.cpp
OBJ = src/main.o

#Reglas explicitas
all:	$(OBJ)
			$(CC) $(CPPFLAGS) -o bin/sum $(OBJ)
clean:
	$(RM) $(OBJ) bin/sum

main.o: src/main.cpp
