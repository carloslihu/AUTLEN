#include "palabra.h"

struct _Palabra {
    char** symbols;
    int size;
};

/* Crea una palabra nueva */
Palabra * palabraNueva() {
    Palabra* output;
    output = (Palabra*) malloc(sizeof (struct _Palabra));
    if (output == NULL)
        return NULL;
    output->size = 0;
    output->symbols = NULL;
    return output;
}

/* Libera la memoria asociada con la palabra */
void palabraElimina(Palabra * p_p) {
    int i;
    if (p_p) {
        if (p_p->symbols != NULL) {
            for (i = 0; i < p_p->size; i++) {
                free(p_p->symbols[i]);
            }
            free(p_p->symbols);
        }
        free(p_p);
    }
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
    if (p_p == NULL || letra == NULL)
        return NULL;

    p_p->size++;
    p_p->symbols = (char**) realloc(p_p->symbols, sizeof (char*)*p_p->size);
    if (p_p->symbols == NULL) {
        return NULL;
    }
    p_p->symbols[p_p->size - 1] = (char*) malloc(sizeof (char) * (strlen(letra) + 1));
    if (p_p->symbols[p_p->size - 1] == NULL) {
        return NULL;
    }
    strcpy(p_p->symbols[p_p->size - 1], letra);
    return p_p;
}

/* Devuelve la longitud de la palabra */
int palabraTamano(Palabra * p_p) {
    if (p_p != NULL)
        return p_p->size;
    return 0;
}

/* Hace en memoria nueva una copia de la palabra y la devuelve */
Palabra * palabraCopia(Palabra * p_p) {
    Palabra* output;
    int i;

    if (p_p == NULL)
        return NULL;

    output = palabraNueva();
    if (output == NULL)
        return NULL;

    output->symbols = (char**) calloc(p_p->size, sizeof (char*));
    if (output->symbols == NULL && p_p->size > 0) {
        palabraElimina(output);
        return NULL;
    }
    output->size = p_p->size;
    for (i = 0; i < output->size; i++) {
        output->symbols[i] = calloc(strlen(p_p->symbols[i]) + 1, sizeof (char));
        if (output->symbols[i] == NULL) { /*on calloc error, we free all calloc'd symbols[i], free the output and return*/
            output->size = i - 1; /*i-1 because the i-th element failed on calloc, thus is NULL, no need to be freed*/
            palabraElimina(output); /*this frees the rest of the structure for us*/
        }
        strcpy(output->symbols[i], p_p->symbols[i]);
    }

    return output;
}

/* Para comparar dos palabras, devuelve un valor negativo, cero o positivo en
función de que todas las letras de la misma posición y de izquierda a derecha
sean iguales. En el caso de que no lo sean, se devuelve el strcmp de la primera
pareja de letras que no sean iguales */
int palabraCompara(Palabra * p_p1, Palabra * p_p2) {
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

char* palabraPrimer(Palabra*p_p) {
    if(!p_p || !p_p->symbols || p_p->size==0)
        return NULL;
    return p_p->symbols[0];
}

/*Devuelve una copia de la palabra, pero sin el primer elemento*/
Palabra* palabraExtraePrimer(Palabra *p_p) {
    Palabra* output;
    int i;

    if (p_p == NULL)
        return NULL;

    output = palabraNueva();
    if (output == NULL)
        return NULL;

    output->symbols = (char**) calloc(p_p->size - 1, sizeof (char*));
    if (output->symbols == NULL) {
        palabraElimina(output);
        return NULL;
    }
    output->size = p_p->size - 1;

    for (i = 1; i < p_p->size; i++) {
        output->symbols[i - 1] = calloc(strlen(p_p->symbols[i]) + 1, sizeof (char));
        if (output->symbols[i - 1] == NULL) { /*on calloc error, we free all calloc'd symbols[i], free the output and return*/
            output->size = i - 1; /*i-1 because the i-th element failed on calloc, thus is NULL, no need to be freed*/
            palabraElimina(output); /*this frees the rest of the structure for us*/
        }
        strcpy(output->symbols[i - 1], p_p->symbols[i]);
    }

    return output;

}

Bool palabraVacia(Palabra* p_p) {
    if (p_p == NULL || p_p->symbols == NULL || p_p->size == 0)
        return TRUE;
    return FALSE;
}

void palabraVoltear(Palabra* p_p) {
    char** aux;
    int i;
    if (p_p == NULL)
        return;
    aux = (char**) calloc(p_p->size, sizeof (char*));
    for (i = 0; i < p_p->size; i++) {
        aux[i] = p_p->symbols[p_p->size - 1 - i];
    }
    free(p_p->symbols);
    p_p->symbols = aux;
}

char*palabraPop(Palabra* p_p) {
    char*letra;
    p_p->size--;
    letra = (char*) calloc(strlen(p_p->symbols[p_p->size]) + 1, sizeof (char));
    strcpy(letra, p_p->symbols[p_p->size]);
    free(p_p->symbols[p_p->size]);
    p_p->symbols = (char**) realloc(p_p->symbols, sizeof (char*)*p_p->size);
    return letra;

}