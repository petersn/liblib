# This makefile can be used to build all or some of the sample
# programs.  To build all of them, use the command
# 'make all'.  To build one, say addtwo, use the command
# 'make addtwo'.

VERSION=7.0
#MLINKDIR = /usr/local/Wolfram/Mathematica/${VERSION}/SystemFiles/Links/MathLink/DeveloperKit
MLINKDIR = /home/peter/.cells/mathematica/mathematica/SystemFiles/Links/MathLink/DeveloperKit
SYS = Linux-x86-64

EXTRA_CFLAGS=-ldl

INCDIR = ${CADDSDIR}
LIBDIR = ${CADDSDIR}

#MPREP = ${CADDSDIR}/mprep
MPREP = /home/peter/.cells/mathematica/mathematica/SystemFiles/Links/MathLink/DeveloperKit/Linux-x86-64/CompilerAdditions/mprep
RM = rm

CC = /usr/bin/gcc
CXX = /usr/bin/c++

BINARIES = liblib

all : $(BINARIES)

liblib : liblibtm.o liblib.o
	${CXX} ${EXTRA_CFLAGS} liblibtm.o liblib.o -L/home/peter/.cells/mathematica/mathematica/SystemFiles/Links/MathLink/DeveloperKit/Linux-x86-64/CompilerAdditions -lML64i3 -lm -lpthread -lrt -lstdc++ -o $@
#-I${INCDIR} addtwotm.o addtwo.o -L${LIBDIR} -lML64i3 -lm -lpthread -lrt -lstdc++ -o $@

.c.o :
	${CC} -l/home/peter/.cells/mathematica/mathematica/SystemFiles/Links/MathLink/DeveloperKit/Linux-x86-64/CompilerAdditions/libML64i3.so -I/home/peter/.cells/mathematica/mathematica/SystemFiles/Links/MathLink/DeveloperKit/Linux-x86-64/CompilerAdditions -c ${EXTRA_CFLAGS} $< #-I${INCDIR} $<

liblibtm.c : liblib.tm
	${MPREP} $? -o $@

clean :
	@ ${RM} -rf *.o *tm.c $(BINARIES)
