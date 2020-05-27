# Directory structure
TOPDIR	:= ./
BINDIR  := $(TOPDIR)bin/
INCDIR	:= $(TOPDIR)include/
LIBDIR	:= $(TOPDIR)lib/
OBJDIR	:= $(TOPDIR)obj/
SRCDIR	:= $(TOPDIR)src/

# Executable info
NAME 	:= exe
EXE		:= $(BINDIR)$(NAME)

# Compilation and linking flags
COMPILER = g++
CPPFLAGS:= -I $(INCDIR)												# Add search path to hearder files
CFLAGS	:= -Wall -Wcomment -Werror -Wundef -std=c++17 -ggdb3# Add compilation flags
LFLAGS	:= -L $(LIBDIR)												# Add search path to shared libraries
LDLIBS	:= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system	# Linking flags against shared libraries