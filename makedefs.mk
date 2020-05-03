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
CPPFLAGS:= -I $(INCDIR) 	# Add search path to hearder files
CFLAGS	:= -c -Wall -Wcomment -Werror -Wundef
LFLAGS	:= -L $(LIBDIR)		# Addsearch path to shared libraries
LDLIBS	:= -lm -lpthread	# Compile agains thirdparty libraries