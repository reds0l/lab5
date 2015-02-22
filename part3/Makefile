# Object files:
OBJ = main.o

# Header files:
HDR = Puzzle.h

# Libraries
LIBS = 

# Executable
EXEC = main.out

# One rule to rule them all
all: $(EXEC)

# Compile
CPP = g++ -c -o $@ $<
LINK = g++ -o $@ ${LIBS}

# Rules
%.o : %.cpp ${HDRS}
	${CPP}

# Executable rule
$(EXEC) : ${OBJ}
	${LINK} ${OBJ}

# Cleaning
clean:
	rm *.o $(EXEC)
