################################################################################################
# Makefile based on
# 	http://arantxa.ii.uam.es/~mcorella/teaching/mtp20506/Makefile
#	and
# 	https://stackoverflow.com/questions/1484817/how-do-i-make-a-simple-makefile-for-gcc-on-linux
# Author: Borja Gil Perez, borja.gil@uam.es
################################################################################################
LIBS = -lm -pthread
CC = gcc
CFLAGS = -g -Wall -ansi -pedantic
EXE=pr_enunciado
NAMES=ap configuracion_ap configuracion_apnd dynamic_node estado generic_string list palabra relacion stack transicion_ap
DEPS=$(patsubst %,%.h,$(NAMES)) basic_types.h generic_collection_types.h
OBJ=$(patsubst %,%.o,$(NAMES))
P4 = p4
# $ make
# $ make all
all: pr_enunciado pr_enunciado_lambda pr_enunciado_lambda_0_estrella

########################################################################
# P4
########################################################################
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

pr_enunciado: pr_enunciado.o $(OBJ)
	$(CC) $^ -Wall $(LIBS) -o $@

pr_enunciado_lambda: pr_enunciado_lambda.o $(OBJ)
	$(CC) $^ -Wall $(LIBS) -o $@

pr_enunciado_lambda_0_estrella: pr_enunciado_lambda_0_estrella.o $(OBJ)
	$(CC) $^ -Wall $(LIBS) -o $@
	
########################################################################
# Information and Clean
########################################################################
# $ make info
info:
	@echo
	@echo "<Autómatas y Lenguajes>, <Doble Grado>"
	@echo "<Codigo de la entrega>"
	@echo
	@echo "Autores:"
	@echo "	<Javier Gómez Martínez, Correo electronico>"
	@echo "	<Carlos Li Hu, Correo electronico>"
	@echo
	@echo "Ejecutables:"
	@echo "	all"
	@echo "		p4"
	@echo "			$(P4)"
	@echo
# $ make clean
clean:
	@echo "Borrando objetos, ejecutables, etc."
	@rm -fr Doxyfile latex html
	@rm -f *~ *.o core p4 pr_enunciado pr_enunciado_lambda pr_enunciado_lambda_0_estrella
	
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

valgrind:
	@valgrind --leak-check=full ./$(EXE)

zip:
	zip -r 1401_JavierGomez_CarlosLi_P4.zip *.c *.h Makefile
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
