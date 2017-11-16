#include "estado.h"

struct _Estado {
    char* nombre;
    int tipo;
};

/* Reserva memoria nueva para el estado y para la cadena de su nombre, crea un
estado con las dos componentes que se le proporcionan como argumento */
Estado * estadoNuevo(char * nombre, int tipo) {
    Estado* p_s;
    if (!nombre || tipo < 0)
        return NULL;
    p_s = (Estado*) malloc(sizeof (Estado));
    if(p_s==NULL){
    	return NULL;
    }
    p_s->nombre = (char*) calloc(strlen(nombre) + 1, sizeof (char));
    if(p_s->nombre==NULL){
    	return NULL;
    }
    strcpy(p_s->nombre, nombre);
    p_s->tipo = tipo;
    return p_s;
}

/* Libera la memoria asociada con el estado */
void estadoElimina(Estado * p_s) {
    if (p_s) {
        free(p_s->nombre);
        free(p_s);
    }
}

/* Muestra por el FILE * el estado */
void estadoImprime(FILE * fd, Estado * p_s) {
    if (fd && p_s) {
        if (p_s->tipo == 0 || p_s->tipo == 2)
            fprintf(fd, "->");

        fprintf(fd, "%s", p_s->nombre);

        if (p_s->tipo == 1 || p_s->tipo == 2)
            fprintf(fd, "*");
    }
}

/* Función de comparación de estados por nombre, devuelve 1 si el estado tiene el
nombre proporcionado */
int estadoEs(Estado * p_s, char * nombre) {
    if (!p_s || !nombre)
        return -1;
    if (strcmp(p_s->nombre, nombre) == 0)
        return 1;
    else
        return 0;
}

/* Devuelve (un puntero) al nombre del estado */
char * estadoNombre(Estado * p_s) {
    if (!p_s)
        return NULL;
    return p_s->nombre;
}

/* Devuelve el tipo de estado */
int estadoTipo(Estado * p_s) {
    if (!p_s)
        return -1;
    return p_s->tipo;
}

/* Se usa para comparar estados por su nombre y devuelve el strcmp de sus nombres
 */
int estadoCompara(Estado * p_s1, Estado * p_s2) {
    if (!p_s1 || !p_s2)
        return -1;
    return strcmp(p_s1->nombre, p_s2->nombre);
}

/* Se crea una copia en memoria nueva del estado proporcionado como argumento */
Estado * estado_copy(Estado * p_s) {
    Estado* p_s2;
    if (!p_s)
        return NULL;
    p_s2 = (Estado*) malloc(sizeof (Estado));
    if(p_s2 == NULL){
    	return NULL;
    }
    p_s2->nombre = (char*) calloc(strlen(p_s->nombre) + 1, sizeof (char));
    if(p_s2->nombre == NULL){
    	return NULL;
    }
    strcpy(p_s2->nombre, p_s->nombre);
    p_s2->tipo = p_s->tipo;
    return p_s2;
}
