########################################################################
# Makefile
# Author: Borja Gil Perez, borja.gil@uam.es
# based on http://arantxa.ii.uam.es/~mcorella/teaching/mtp20506/Makefile
########################################################################
# OBJFLAGS, las banderas para compilar objetos
# OBJINCLUDES, las librerias para compilar objetos
# EXEFLAGS, las banderas del ejecutable
# EXELIBS, las librerias del ejecutable
########################################################################
CC				= gcc
OBJFLAGS		= -c -g -Wall -lm
OBJINCLUDES 	=
EXEFLAGSDEBUG	= -g
EXEFLAGSQUICK	= -O2 -Wall
EXEFLAGS		= $(EXEFLAGSDEBUG)
EXELIBS			= -lm -pthread
########################################################################
# Executables
########################################################################
# $ make
# $ make all
all: p1 p2
# $ make p1
P1 = p1s1 p1s2
p1: $(P1)
# $ make p2
P2 = p2s1 p1s2
p2: $(P2)
########################################################################
# P1
########################################################################
# $ make p1s1
p1s1: src1.c src2.c src3.c
	@echo "Creando objetos para $@... "
	$(CC) $(OBJFLAGS) $^ $(OBJINCLUDES)
	@echo == OK ==
	@echo "Creando ejecutable $@..."
	$(CC) $(EXEFLAGS) $(^:.c=.o) $(EXELIBS) -o $@
	@echo == OK ==
# $ make p1s2
p1s2: src1.c src2.c src3.c src4.c
	@echo "Creando objetos para $@... "
	$(CC) $(OBJFLAGS) $^ $(OBJINCLUDES)
	@echo == OK ==
	@echo "Creando ejecutable $@..."
	$(CC) $(EXEFLAGS) $(^:.c=.o) $(EXELIBS) -o $@
	@echo == OK ==
########################################################################
# P2
########################################################################
# $ make p2s1
p2s1: src1.c
	@echo "Creando objetos para $@... "
	$(CC) $(OBJFLAGS) $^ $(OBJINCLUDES)
	@echo == OK ==
	@echo "Creando ejecutable $@..."
	$(CC) $(EXEFLAGS) $(^:.c=.o) $(EXELIBS) -o $@
	@echo == OK ==
# $ make p2s2
p2s2: src1.c src2.c
	@echo "Creando objetos para $@... "
	$(CC) $(OBJFLAGS) $^ $(OBJINCLUDES)
	@echo == OK ==
	@echo "Creando ejecutable $@..."
	$(CC) $(EXEFLAGS) $(^:.c=.o) $(EXELIBS) -o $@
	@echo == OK ==
########################################################################
# Information and Clean
########################################################################
# $ make info
info:
	@echo
	@echo "<Asignatura>, <Grado>"
	@echo "<Codigo de la entrega>"
	@echo
	@echo "Autores:"
	@echo "	<Autor, Correo electronico>"
	@echo "	<Autor, Correo electronico>"
	@echo
	@echo "Ejecutables:"
	@echo "	all"
	@echo "	p1 $(P1)"
	@echo "	p2 $(P2)"
	@echo
# $ make clean
clean:
	@echo "Borrando objetos, ejecutables, etc."
	@rm -fr Doxyfile latex html
	@rm -f *~ *.o core $(P1) $(P2)
########################################################################
# Using utilities
########################################################################
# $ make astyle-c
astyle-c:
	@echo "Applying Artistic Style to C programming files."
	@astyle *.h *.c
# $ make doxygen
doxygen:
	@rm -fr Doxyfile latex html
	@doxygen -g
	@doxygen Doxyfile
########################################################################
# Installation
########################################################################
# $ make dev-essential
dev-essential:
	@echo "Installing essential developer tools."
	sudo apt-get install astyle build-essential geany nemiver nmon terminator valgrind
	sudo apt-get install doxygen graphviz
# $ make lubuntu1404-custom
lubuntu1404-custom:
	@echo "Customizing Lubuntu 14.04"
	sudo apt-get purge abiword gnumeric
	sudo add-apt-repository ppa:indicator-brightness/ppa
	sudo add-apt-repository ppa:webupd8team/java
	sudo apt-get update
	sudo apt-get install language-selector-gnome libreoffice libreoffice-l10n-es lubuntu-restricted-extras thunderbird thunderbird-locale-es-es vlc
	sudo apt-get install indicator-brightness
	sudo apt-get install oracle-java8-installer && sudo apt-get install oracle-java8-set-default
	sudo apt-get autoremove && sudo apt-get autoclean
