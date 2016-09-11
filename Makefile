BIN=game1
SRC=$(shell find src/ -name "*.cpp")
OBJ=$(patsubst src/%.cpp,obj/%.o,$(SRC))

CC=g++
LD_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
CPP_FLAGS=-std=c++0x -ggdb -Iinc/

PRINT=printf
RM=rm -f

all: $(BIN)

$(BIN): $(OBJ)
	@$(PRINT) "Building $@.\n"
	@$(CC) $(OBJ) -o $@ $(LD_FLAGS)
	@$(PRINT) "Done : launch with ./$@\n"

obj/%.o: src/%.cpp
	@$(PRINT) "Compiling $< to $@.\n"
	@$(CC) $(CPP_FLAGS) -c $< -o $@

clean:
	@$(PRINT) "Removing $(OBJ).\n"
	@$(RM) $(OBJ)

fclean: clean
	@$(PRINT) "Removing $(BIN).\n"
	@$(RM) $(BIN)

debug:
	@$(PRINT) "SRC : $(SRC), OBJ : $(OBJ)"

re: fclean all
