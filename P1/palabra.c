#include "palabra.h"

struct _Palabra {
	char** symbols;
	int size;
};

/*private function that copies the symbols from one Palabra to another*/
/*
Palabra* copySymbols(Palabra** dest, Palabra* src){
	int i;

	if(dest == NULL || src == NULL || dest->size < src->size)
		return NULL;

	for(i=0;i<dest->size;i++){
		if(src->symbols[i] != NULL){
			dest->symbols[i] = calloc(strlen(src->symbols[i])+1, sizeof(char));
			if(dest->symbols[i] == NULL){
				dest->size = i-1;
				palabraElimina(dest);
			}
			strcpy(output->symbols, p_p->symbols);
		} else {
			free(dest->symbols[i]);
			dest->symbols[i] = NULL;
		}
	}
}
*/

/* Crea una palabra nueva */
Palabra * palabraNueva() {
	Palabra* output;
	output = (Palabra*)malloc(sizeof(struct _Palabra));
	if (output == NULL)
		return NULL;
	output->size = 0;
	output->symbols = NULL;
	return output;
}

/* Libera la memoria asociada con la palabra */
void palabraElimina(Palabra * p_p) {
	int i;
	if (p_p == NULL)
		return;
	if (p_p->symbols != NULL) {
		for (i = 0; i < p_p->size; i++) {
			free(p_p->symbols[i]);
		}
		free(p_p->symbols);
	}
	free(p_p);
}

/* Muestra por el FILE * la palabra */
void palabraImprime(FILE * fd, Palabra * p_p) {
	int i;
	if (p_p == NULL || p_p->symbols == NULL)
		return;
	fprintf(fd, "[(%d)", p_p->size);
	for (i = 0; i < p_p->size; i++)
		fprintf(fd, " %s", p_p->symbols[i]);
	fprintf(fd, "]");
}

/* Inserta una letra (que es un string - char * - ) en la palabra proporcionada
como argumento (modificándola, por tanto) y devuelve la palabra resultante. Para
ello debe hacer una copia en memoria nueva para la nueva letra */
Palabra * palabraInsertaLetra(Palabra * p_p, char * letra) {
	Palabra* output;
	int i;
	if (p_p == NULL || letra == NULL)
		return NULL;

	output = palabraNueva();
	if (output == NULL)
		return NULL;

	output->size = p_p->size + 1;

	for (i = 0; i < p_p->size; i++) {
		output->symbols[i] = calloc(strlen(p_p->symbols[i]) + 1, sizeof(char));
		if (output->symbols[i] == NULL) { /*on calloc error, we free all calloc'd symbols[i], free the output and return*/
			output->size = i - 1; /*i-1 because the i-th element failed on calloc, thus is NULL, no need to be freed*/
			palabraElimina(output);/*this frees the rest of the structure for us*/
		}
		strcpy(output->symbols[i], p_p->symbols[i]);
	}
	output->symbols[output->size - 1] = calloc(strlen(letra) + 1, sizeof(char));
	if (output->symbols[output->size - 1] == NULL) {
		output->size = i - 1; /*i-1 because the i-th element failed on malloc, thus is NULL, no need to be freed => less operations*/
		palabraElimina(output);/*this frees the rest of the structure for us*/
	}
	strcpy(output->symbols[i], letra);

	return output;
}

/* Devuelve la longitud de la palabra */
int palabraTamano(Palabra * p_p) {
	if (p_p != NULL)
		return p_p->size;
	return 0;
}

/* Hace en memoria nueva una copia de la palabra y la devuelve */
Palabra * palabraCopia (Palabra * p_p) {
	Palabra* output;
	int i;

	if (p_p == NULL)
		return NULL;

	output = palabraNueva();
	if (output == NULL)
		return NULL;

	output->symbols = (char**)calloc(p_p->size, sizeof(char*));
	if (output->symbols == NULL) {
		palabraElimina(output);
		return NULL;
	}
	output->size = p_p->size;

	for (i = 0; i < output->size; i++) {
		output->symbols[i] = calloc(strlen(p_p->symbols[i]) + 1, sizeof(char));
		if (output->symbols[i] == NULL) { /*on calloc error, we free all calloc'd symbols[i], free the output and return*/
			output->size = i - 1; /*i-1 because the i-th element failed on calloc, thus is NULL, no need to be freed*/
			palabraElimina(output);/*this frees the rest of the structure for us*/
		}
		strcpy(output->symbols[i], p_p->symbols[i]);
	}

	return output;
}

/* Para comparar dos palabras, devuelve un valor negativo, cero o positivo en
función de que todas las letras de la misma posición y de izquierda a derecha
sean iguales. En el caso de que no lo sean, se devuelve el strcmp de la primera
pareja de letras que no sean iguales */
int palabraCompara( Palabra * p_p1, Palabra * p_p2) {
	int i;
	int retVal;
	/*en el caso de que alguno sea NULL, tratamos el error asi
		si ambos son NULL son iguales
		y si alguno es distinto de NULL entonces es mayor que el que es NULL*/
	if (p_p1 == NULL && p_p2 == NULL)
		return 0;
	else if (p_p1 != NULL && p_p2 == NULL)
		return 1;
	else if (p_p1 == NULL && p_p2 != NULL)
		return -1;

	if (p_p1->size != p_p2->size)
		return p_p1->size - p_p2->size;

	for (i = 0; i < p_p1->size; i++) {
		retVal = strcmp(p_p1->symbols[i], p_p2->symbols[i]);
		if (retVal != 0)
			return retVal;
	}

	return 0;
}