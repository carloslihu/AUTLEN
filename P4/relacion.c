#include "relacion.h"

struct _Relacion{
	char *nombre;
	int num_elementos;
	int **inicial;
	int **cierre;
};

/*
Crea una nueva relación a la que se le da como nombre el proporcionado como argumento para un conjunto con el número de elementos que se prorpociona como argumento.
Debe reservar memoria propia para todas las componentes que decidas utilizar en la relación.
 */
Relacion * relacionNueva(char * nombre, int num_elementos) {
	Relacion* output;
	int i;
	/*control de errores*/
	if (nombre == NULL || num_elementos <= 0)
		return NULL;

	/*reserva de memorias*/
	output = (Relacion*) malloc(sizeof (struct _Relacion));/*memoria para la estructura*/
	if (output == NULL)
		return NULL;
	output->nombre = (char*) malloc(sizeof (char) * (strlen(nombre) + 1));/*memoria para el nombre*/
	if (output->nombre == NULL) {
		free(output);
		return NULL;
	}
	output->inicial = (int**) calloc(num_elementos, sizeof (int*));/*memoria para el array de punteros a filas de la matriz inicial*/
	if (output->inicial == NULL) {
		free(output->nombre);
		free(output);
		return NULL;
	}
	output->cierre = (int**) calloc(num_elementos, sizeof (int*));/*memoria para el array de punteros a filas de la matriz del cierre*/
	if (output->inicial == NULL) {
		free(output->nombre);
		free(output->inicial);
		free(output);
		return NULL;
	}
	for (i = 0; i < num_elementos; i++) {/*bucle para reserva de memorias de cada fila*/
		output->inicial[i] = (int*) calloc(num_elementos, sizeof (int));/*memoria para cada fila de la matriz inicial*/
		output->cierre[i] = (int*) calloc(num_elementos, sizeof (int));/*memoria para cada fila de la matriz cierre*/
		if (output->cierre[i] == NULL || output->inicial[i] == NULL) {
			for (; i >= 0; i--) {
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
	strcpy(output->nombre, nombre);

	/*retorno*/
	return output;
}
/*si el flag es 0, imprimimos el cierre. si es 1 imprimimos la inicial*/
void matrizImprime(FILE * fd, int** matriz, int tam) {
	int i, j;
	for (i = 0; i < tam; i++) {/*recorremos filas*/
		fprintf(fd, "\t[%d]\t", i);
		for (j = 0; j < tam; j++) {/*recorremos elementos de las filas*/
			fprintf(fd, "%d\t", matriz[i][j]);
		}
		fprintf(fd,"\n");
	}
}

void relacionImprime(FILE * fd, Relacion * p_r) {
	int i;
	fprintf(fd, "%s={\n\t\t", p_r->nombre);
	for (i = 0; i < p_r->num_elementos; i++) {
		fprintf(fd, "[%d]\t", i);
	}
	fprintf(fd, "\n\t\t\tCIERRE\n");
	matrizImprime(fd, p_r->cierre, p_r->num_elementos);
	fprintf(fd, "\n\t\t\tRELACION INICIAL i\n");
	matrizImprime(fd, p_r->inicial, p_r->num_elementos);
	fprintf(fd, "\n}");
}

/*
Muestra por el FILE * la relación. Puedes suponer el formato de salida utilizado en los ejemplos.
 */
void relacionElimina(Relacion * p_r) {
	int i;
	if (p_r == NULL)
		return;
	for (i = 0; i < p_r->num_elementos; i++) {
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
int** copiaMatriz(int** output, int** matriz, int tam) {
	int col, row;
	if (matriz == NULL || tam <= 0 || output == NULL)
		return NULL;
	for (col = 0; col < tam; col++) {
		for (row = 0; row < tam; row++)
			output[col][row] = matriz[col][row];
	}
	return output;
}

Relacion * relacionCopia(Relacion * p_r1) {
	int nameLen;
	Relacion* output;
	if (p_r1 == NULL)
		return NULL;
	output = relacionNueva(p_r1->nombre, p_r1->num_elementos);/*creamos una relacion nueva*/
	if (output == NULL)
		return NULL;
	nameLen = strlen(output->nombre);
	output->nombre = (char*)realloc(output->nombre, nameLen + 2); /*+2 por el 0 de final de cadena y por el ' que hay que añadir al nombre*/
	output->nombre[nameLen] = '\''; /*escribilos la ' en la ultima posicion (sin contar con el 0 de final de cadena)*/
	output->nombre[nameLen+1] = 0; /*escribimos el final de cadena*/
	/*copiamos las matrices inicial y de cierre en la nueva relacion*/
	copiaMatriz(output->inicial, p_r1->inicial, p_r1->num_elementos);
	copiaMatriz(output->cierre, p_r1->cierre, p_r1->num_elementos);
	return output;
}

/*
Genera en memoria nueva una copia de la relación proporcionada como argumento y la devuelve.
 */
Relacion * relacionInserta(Relacion * p_r, int i, int j) {
	if (p_r == NULL || i >= p_r->num_elementos || j >= p_r->num_elementos)
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
int relacionTamano(Relacion * p_r) {
	if (p_r == NULL)
		return 0;
	return p_r->num_elementos;
}

/*
Devuelve el cardinal del conjunto sobre el que está definida la relación.
 */

Relacion * relacionCierreTransitivo(Relacion * p_r) {
	int** auxMatrix;
	int i, j, k;
	int flag = 1;
	int iter = 0;
	int prevLen, newLen;
	if (p_r == NULL)
		return NULL;
	auxMatrix = (int**)calloc(p_r->num_elementos, sizeof(int*));/*reservamos memoria para una matriz auxiliar*/
	if (auxMatrix == NULL)
		return NULL;
	for (i = 0; i < p_r->num_elementos; i++) {/*reservamos memoria para cada una de las filas de esta matriz auxiliar*/
		auxMatrix[i] = (int*)calloc(p_r->num_elementos, sizeof(int));/*calloc pone a 0 todos los bloques de memoria que reserva*/
		if (auxMatrix[i] == NULL) {
			for (; i >= 0; --i)
				free(auxMatrix[i]);
			free(auxMatrix);
			return NULL;
		}
	}
	/*al llegar aqui, auxMatrix esta llena de 0s*/
	/*ahora comienza el algoritmo*/
	while (flag == 1){/*si el flag esta a 1, iteramos una vez mas*/
		iter++;/*iter almacenara el numero de iteraciones necesarias para terminar el algoritmo*/
		flag = 0;/*flag a 0 en cada iteracion porque es posible que sea la ultima*/
		for (i = 0; i < p_r->num_elementos; i++) {/*recorremos las filas de la matriz*/
			for (j = 0; j < p_r->num_elementos; j++) {/*recorremos los elementos (columnas) de las filas*/
				if (p_r->cierre[i][j] == 1) { /*en caso de que haya un 1 en la j-esima columna, tenemos que acceder a la fila j*/
					for (k = 0; k < p_r->num_elementos; k++) {
					/*recorremos la fila j de la inicial, la fila i del cierre y la fila i de la auxiliar mediante el indice k, escribriendo en la matriz
					auxiliar un 1 cuando en alguna de las tres filas hay un 1*/
						auxMatrix[i][k] = p_r->cierre[i][k] | p_r->inicial[j][k] | auxMatrix[i][k];
					}
				}
			}
		}/*al terminar esto, tenemos en auxMatrix un cierre de un nivel superior*/
		/*ahora tenemos que copiar en cierre, auxMatrix*/

		/*
		------------------------DEBUG ONLY-------------------------------
		printf("aux:\n");
		matrizImprime(stdout,auxMatrix,p_r->num_elementos);
		printf("cierre:\n");
		matrizImprime(stdout,p_r->cierre, p_r->num_elementos);
		printf("---------------------------------------------------------\n");
		*/

		for (i = 0; i < p_r->num_elementos; i++) {/*recorremos las filas*/
			for (j = 0; j < p_r->num_elementos; j++) {/*recorremos los elementos de las filas*/
				if (p_r->cierre[i][j] != auxMatrix[i][j])/*si sucede que el cierre es distinto del aux en algun elemento*/
					flag = 1;/*ponemos el flag a 1 para continuar con el bucle while, porque puede que el de esta iteracion no sea el cierre del ultimo nivel*/
				p_r->cierre[i][j] = auxMatrix[i][j] | p_r->cierre[i][j];/*escribimos en la matriz del cierre 1 si lo habia en la auxiliar o en el cierre*/
			}
		}
		/*ahora tenemos copiada auxMatrix en cierre. Si el flag ha sido activado, regresamos al primer bucle for*/
	}

	/*al salir del bucle tendremos en p_r->cierre la matriz del cierre
	ahora arreglamos el nombre de la relacion para indicar el numero de iteraciones necesarias para realizar el cierre
	y luego liberamos la memoria de la matriz auxiliar*/
	prevLen = strlen(p_r->nombre);
	newLen = prevLen + iter;
	p_r->nombre = (char*)realloc(p_r->nombre, newLen+1);/*pedimos memoria extra para el nuevo nombre*/
	for(i=prevLen;i<=newLen;i++)
		p_r->nombre[i]='+';/*rellenamos con + el nombre*/
	p_r->nombre[newLen] = 0;/*caracter de final de cadena*/
	/*liberamos la memoria de la matriz auxiliar*/
	for (i = 0; i < p_r->num_elementos; i++)
		free(auxMatrix[i]);
	free(auxMatrix);
	return p_r;
}

/*
Modifica la relación para conservar el ella su cierre transitivo. Devuelve la relación como retorno.
 */
int relacionIJ(Relacion * p_r, int i, int j) {
	if (p_r == NULL || i < 0 || j < 0)
		return 0;
	return (p_r->inicial[i][j] != 0);
}

/*
Devuelve 1 si el elemento i está relacionado originalmente con el j y 0 en caso contrario.
 */
int relacionCierreIJ(Relacion * p_r, int i, int j) {
	if (p_r == NULL || i < 0 || j < 0)
		return 0;
	return (p_r->cierre[i][j] != 0);
}
/*
Devuelve 1 si el elemento i está relacionado (en el cierre transitivo) con el j y 0 en el caso contrario.
 */
