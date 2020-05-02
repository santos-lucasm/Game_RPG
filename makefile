TOPDIR	:= ./
SRCDIR	:= $(TOPDIR)src/
LIBDIR	:= $(TOPDIR)include/
OBJDIR	:= $(TOPDIR)obj/
BINDIR  := $(TOPDIR)bin/

NAME 	:= exe
EXE		:= $(BINDIR)$(NAME)

COMPILER = g++
CFLAGS	:= -c

SRC_DEPS := $(SRCDIR)main.cpp
LIB_DEPS := $(LIBDIR)pokemonlib.h $(LIBDIR)pokemons/cyndaquil.h
OBJ_DEPS := $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(SRC_DEPS))

all: $(EXE)

$(EXE): $(OBJ_DEPS)
	@ echo 'Building binary using GCC linker: $@'
	@ $(COMPILER) $^ -o $@
	@ echo 'Finished building binary: $@'

$(OBJDIR)%.o: $(SRC_DEPS) $(LIB_DEPS)
	@ echo 'Building target using $(COMPILER) compiler: $<'
	@ $(COMPILER) $(CFLAGS) $< -o $@

run:
	@ ./$(EXE)

clean:
	@ rm -rf $(EXE) $(OBJ_DEPS)

.PHONY: all run clean