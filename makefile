include makedefs.mk

# Project dependencies
SRC_DEPS := $(shell find $(SRCDIR) -name "*.cpp")
INC_DEPS := $(shell find $(INCDIR) -name "*.h")
OBJ_DEPS := $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(SRC_DEPS))

# Rules
.PHONY: all run clean

all: $(EXE)

$(EXE): $(OBJ_DEPS)
	@ echo 'Building binary using GCC linker: $@'
	@ $(COMPILER) $(LFLAGS) $^ $(LDLIBS) -o $@
	@ echo 'Finished building binary: $@'

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(INC_DEPS)
	@ echo 'Building target using $(COMPILER) compiler: $<'
	@ $(COMPILER) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

run:
	@ ./$(EXE)

clean:
	@ rm -rf $(EXE) $(OBJ_DEPS)