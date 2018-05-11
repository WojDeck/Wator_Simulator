
#Authors: Wojciech Teodorowicz, Sahan Ekanayake
CC=g++
CFLAGS= -std=c++11 -pthread
Cfiles= wator.cpp
#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: $(Cfiles)
	$(CC) -o wator $(Cfiles) $(CFLAGS)


#this is customary and just deletes all .o files
CLEAN:
	rm *.oCC=g++
