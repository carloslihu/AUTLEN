#include <stdio.h>

typedef struct _clase 
{
	void * elemento;
	void (*print_elemento)(FILE *, void *);
} Clase ;


void print_int(FILE * fd, void * p_int)
{
	fprintf(fd,"(INT) %d \n",*((int*)p_int));


}


void print_double(FILE * fd, void * p_double)
{
	fprintf(fd,"(DOUBLE) %E \n",*((double*)p_double));


}






int main(int argc, char ** argv)
{

	int i = 100;
	double d = 3.1415;
	char * texto = "Hola mundo \n";

	Clase c1;
	Clase c2;
	Clase c3;

	c1.elemento = &i;
	c1.print_elemento = print_int;	


	c2.elemento = &d;
	c2.print_elemento = print_double;	


	/*
	c3.elemento = ;
	c3.print_elemento = ;	
	*/

	c1.print_elemento(stdout,c1.elemento);
	c2.print_elemento(stdout,c2.elemento);

   /***Añade aquí el código necesario para imprimir una cadena de caracteres***/


	return 0;


}