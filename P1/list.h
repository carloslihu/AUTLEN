#ifndef LIST_H
#define	LIST_H

#include "basic_types.h"
#include "generic_collections_types.h"


typedef struct _List List;


/* Inicializa la lista reservando memoria e inicializa todos sus elementos. */
List* list_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3, cmp_element_function_type f4);
/* Libera la lista y todos sus elementos. */
void list_destroy(List* list);

/* Inserta al principio de la lista realizando una copia del elemento. */
List* list_insertFirst(List* list, const void *elem);
/* Inserta al final de la lista realizando una copia del elemento. */
List* list_insertLast(List* list, const void *elem);
/* Inserta en orden en la lista realizando una copia del elemento. */
List* list_insertInOrder(List *list, const void *pElem);

/* Extrae del principio de la lista realizando una copia del elemento almacenado en dicho nodo. */
void * list_extractFirst(List* list);
/* Extrae del final de la lista realizando una copia del elemento almacenado en dicho nodo. */
void * list_extractLast(List* list);

/* Comprueba si una lista está vacía o no. */
Bool list_isEmpty(const List* list);

/* Devuelve el elemento i-ésimo almacenado en la lista. En caso de error, devuelve NULL. */
const void* list_get(const List* list, int i);
/* Devuelve el tamaño de una lista. */
int list_size(const List* list);

/* Imprime una lista devolviendo el número de caracteres escritos. */
int list_print(FILE *fd, const List* list);

/* Devuelve 1 si el elemento está en la lista */
int list_belongs(const List * list, void * p_elem);




#endif
