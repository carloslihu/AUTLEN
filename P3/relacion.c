#include "relacion.h"

typedef struct{
	char *nombre;
	int num_elementos;
	int **inicial;
	int **cierre;
} _Relacion;

/*
Crea una nueva relación a la que se le da como nombre el proporcionado como argumento para un conjunto con el número de elementos que se prorpociona como argumento.
Debe reservar memoria propia para todas las componentes que decidas utilizar en la relación.
*/
Relacion * relacionNueva(char * nombre, int num_elementos){
	Relacion* output;
	int i;
	/*control de errores*/
	if(nombre == NULL || num_elementos <= 0)
		return NULL;

	/*reserva de memorias*/
	output = (Relacion*)malloc(sizeof(struct _Relacion));
	if(output == NULL)
		return NULL;
	output->nombre = (char*)malloc(sizeof(char)*(strlen(nombre)+1));
	if(output->nombre == NULL){
		free(output);
		return NULL;
	}
	output->inicial = (int**)calloc(num_elementos,sizeof(int*));
	if(output->inicial == NULL){
		free(output->nombre);
		free(output);
		return NULL;
	}
	output->cierre = (int**)calloc(num_elementos,sizeof(int*));
	if(output->inicial == NULL){
		free(output->nombre);
		free(output->inicial);
		free(output);
		return NULL;
	}
	for(i=0;i<num_elementos;i++){
		output->inicial[i] = (int*)calloc(num_elementos, sizeof(int));
		output->cierre[i] = (int*)calloc(num_elementos, sizeof(int));
		if(output->cierre[i] == NULL || output->inicial[i] == NULL){
			for(;i>=0;i--){
				free(output->inicial[i]);
				free(output->cierre[i]);
			}
			free(output->nombre);
			free(output->inicial);
			free(output->cierre);
			free(output);
			return NULL;
		}
	}
	
	/*introduccion de datos*/
	output->num_elementos = num_elementos;
	strcpy(output->nombre,nombre);

	/*retorno*/
	return output;
}
void relacionImprime(FILE * fd, Relacion * p_r);
/*
Muestra por el FILE * la relación. Puedes suponer el formato de salida utilizado en los ejemplos.
*/
void relacionElimina(Relacion * p_r){
	int i;
	if(p_r == NULL)
		return;
	for(i=0;i<p_r->num_elementos;i++){
		free(p_r->inicial[i]);
		free(p_r->cierre[i]);
	}
	free(p_r->inicial);
	free(p_r->cierre);
	free(p_r->nombre);
	free(p_r);
}
/*
Libera toda la memoria asociada con la relación.
*/
Relacion * relacionCopia(Relacion * p_r1);
/*
Genera en memoria nueva una copia de la relación proporcionada como argumento y la devuelve.
*/
Relacion * relacionInserta(Relacion * p_r, int i, int j){
	if(p_r == NULL || i >= p_r->num_elementos || j >= p_r->num_elementos)
		return NULL;
	p_r->inicial[i][j] = 1;
	p_r->cierre[i][j] = 1;
	return p_r;
}
/*
Modifica la relación proporcionada como argumento para que tenga constancia de que el elemento i está relacionado con el j. 
Se está suponiendo que los elementos están dispuestos en un orden precondebido y conocido por el usuario de la librería. 
Una vez modificada, la relación es también devuelta.
*/
int  relacionTamano(Relacion * p_r);
/*
Devuelve el cardinal del conjunto sobre el que está definida la relación.
BY JAVI: en lugar de comparar las matrices, tenemos un flag de "modificado" que si llega al final de la funcion siendo false, entonces hemos encontrado la matriz
*/
Relacion * relacionCierreTransitivo(Relacion * p_r);
/*
Modifica la relación para conservar el ella su cierre transitivo. Devuelve la relación como retorno.
*/
int  relacionIJ(Relacion * p_r,int i, int j);
/*
Devuelve 1 si el elemento i está relacionado originalmente con el j y 0 en caso contrario.
*/
int relacionCierreIJ(Relacion * p_r, int i, int j);
/*
Devuelve 1 si el elemento i está relacionado (en el cierre transitivo) con el j y 0 en el caso contrario.
*/
