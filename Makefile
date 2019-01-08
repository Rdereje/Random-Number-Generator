# valid makes:
#	'make' : makes all
#	'make clean' : deletes all files specified by OUT and OBJ

# $< == first dependency, $^ == all dependencies, $@ == target

# declaring paths for source files

SRC = $(wildcard src/*.cpp)
DEP = $(wildcard src/*.h )


OBJ := $(patsubst src/%.cpp, obj/%.o, $(SRC))


CC = g++
CFLAGS = -c 
MAIN = main

.PHONY: clean

# our main build rules
all: $(MAIN)
	
# target : dependencies
# 	recipe
$(MAIN): $(OBJ)
	$(CC) $^ -o $(MAIN)


# compile source files to /obj/ (no linking)
# if a header changes, src will recompile

obj/%.o: src/%.cpp $(DEP)
	$(CC) $< $(CFLAGS) -o $@
	
clean:
	rm -f $(OBJ) $(MAIN).exe 

