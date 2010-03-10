# Makefile to make a MathLink liblib extension for Mathematica
# Once you have built it, you may include it with: Install["liblib"]
# Then you can use liblib as you know and love it from Mathematica!

VERSION=7.0
MLINKDIR = /usr/local/Wolfram/Mathematica/${VERSION}/SystemFiles/Links/MathLink/DeveloperKit

SYS  = Linux-x86-64
BITS = 64
  # Alternative, for 32-bit users:
#SYS  = Linux
#BITS = 32

EXTRA_CFLAGS=-ldl

INCDIR = $(MLINKDIR)/$(SYS)/CompilerAdditions
LIBDIR = $(MLINKDIR)/$(SYS)/CompilerAdditions

MPREP  = $(MLINKDIR)/$(SYS)/CompilerAdditions/mprep
RM     = rm

CC  = /usr/bin/gcc
CXX = /usr/bin/c++

BINARIES = liblib

all : $(BINARIES)

liblib : liblibtm.o liblib.o
	${CXX} ${EXTRA_CFLAGS} liblibtm.o liblib.o -L$(LIBDIR) -lML$(BITS)i3 -lm -lpthread -lrt -lstdc++ -o $@

.c.o :
	${CC} -l$(LIBDIR)/libML$(BITS)i3.so -I$(INCDIR) -c ${EXTRA_CFLAGS} $<

liblibtm.c : liblib.tm
	${MPREP} $? -o $@

clean :
	@ ${RM} -rf *.o *tm.c $(BINARIES)

