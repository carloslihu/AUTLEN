/**
 * @authors Javier Gomez Martinez
 * @authors Carlos Li Hu
 */

#include "stack.h"

struct _Stack {
    int size;
    void** items;

    destroy_element_function_type destroy_element_function;
    copy_element_function_type copy_element_function;
    print_element_function_type print_element_function;
    cmp_element_function_type cmp_element_function;
};

/*
 * returns the index of the top element of the stack. if the stack is empty, returns -1
 */

/* David: Es realmente necesaria esta funcion? Se va a utilizar fuera de este paquete?
 * Por que no utilizar directamente size-1?
 */

int top(const Stack* s) {
    if (s == NULL)
        return -1;
    return s->size - 1;
}

/**------------------------------------------------------------------
Inicializa la pila reservando memoria y almacenando los tres punteros a funcion pasados como parametro (el primero para destruir elementos, el segundo para copiar elementos y el tercero para imprimir elementos). Salida: NULL si ha habido error o la pila si ha ido bien
------------------------------------------------------------------*/
Stack * stack_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3, cmp_element_function_type f4) {
    Stack* s;
    if (f1 == NULL || f2 == NULL || f3 == NULL)
        return NULL;
    /*David: Se puede hacer directamente s = (Stack*) malloc(sizeof (struct _Stack));*/
    s = (Stack*) malloc(sizeof (struct _Stack));
    if (s == NULL)
        return NULL;
    s->destroy_element_function = f1;
    s->copy_element_function = f2;
    s->print_element_function = f3;
    s->cmp_element_function = f4;
    s->size = 0;
    /* David: Falta la reserva de memoria para ** items*/
    s->items = NULL;
    /*David:  Inicializar la lista entera o solo el top?*/

    return s;
}

/**------------------------------------------------------------------
Elimina la pila Entrada: la pila que se va a eliminar
------------------------------------------------------------------*/
void stack_destroy(Stack * s) {
    int i;
    if (s == NULL)
        return;
    if (s->items != NULL)
        for (i = top(s); i >= 0; i--)
            s->destroy_element_function(s->items[i]);
    free(s->items);
    free(s);
}

/**------------------------------------------------------------------
Inserta un elemento en la pila. Entrada: un elemento y la pila donde insertarlo. Salida: NULL si no logra insertarlo o la pila resultante si lo logra
------------------------------------------------------------------*/
Stack * stack_push(Stack * s, const void *obj) {
    void** aux;
    if (s == NULL || obj == NULL || s->size < 0)
        return NULL;
    /*obtenemos pila mas grande*/

    s->size++;
    aux = (void**) realloc(s->items, s->size * sizeof (void*));
    if (aux == NULL) {
        /*if the realloc call did not work (returning NULL) we don't just lose all the stack. we act as if no push was made
        the user of this implementation of a stack is responsible of checking the return value of this function to detect any unexpected error.*/
        s->size--;
        return NULL;
    }
    s->items = aux;
    s->items[top(s)] = s->copy_element_function(obj);
    return s;
}

/**------------------------------------------------------------------
Extrae un elemento en la pila. Entrada: la pila de donde extraerlo. Salida: NULL si no logra extraerlo o el elemento extraido si lo logra. Notese que la pila quedara modificada
------------------------------------------------------------------*/
void * stack_pop(Stack *s) {
    void* obj;
    void** aux;
    if (s == NULL || s->size <= 0 || s->items == NULL)
        return NULL;
    obj = s->items[top(s)];
    s->size--;
    /*David: Considerar si habria que poner la posicion top a NULL -> s->items[top(s)] = NULL */
    aux = (void**) realloc(s->items, s->size * sizeof (void*));
    if (aux == NULL && s->size > 0) {
        s->size++;
        return NULL;
    }
    s->items = aux;
    return obj;
}

/**------------------------------------------------------------------
Copia un elemento (reservando memoria) sin modificar el top de la pila. Entrada: la pila de donde copiarlo. Salida: NULL si no logra copiarlo o el elemento si lo logra
------------------------------------------------------------------*/
void * stack_top(const Stack *s) {
    void* obj;
    if (s == NULL || s->size <= 0 || s->items == NULL)
        return NULL;
    /*David:  obj = s->copy_element_function(s->items[top(s)])*/
    obj = s->copy_element_function(s->items[top(s)]); /*README I'm assuming that on error, this will return NULL*/
    return obj;
}

/**------------------------------------------------------------------
Comprueba si la pila esta vacia. Entrada: pila. Salida: TRUE si esta vacia o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isEmpty(const Stack *s) {
    if (s == NULL || s->size <= 0 || s->items == NULL)
        return TRUE;
    return FALSE;
}

/**------------------------------------------------------------------
Comprueba si la pila esta llena. Entrada: pila. Salida: TRUE si esta llena o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isFull(const Stack * s) {
    return FALSE;
}

/**------------------------------------------------------------------
Imprime toda la pila, colocando el elemento en la cima al principio de la impresion (y un elemento por linea). Entrada: pila y fichero donde imprimirla. Salida: Devuelve el numero de caracteres escritos.
------------------------------------------------------------------*/
int stack_print(FILE* fp, const Stack* s) {
    int printedChars;
    int i;
    if (fp == NULL || s == NULL || s->items == NULL || s->size <= 0)
        return 0;
    /* David: Cual es el proposito de printedChars? A la hora de imprimir, es print_element_function quien se encarga por lo que
     * s->print_element_function(fp, s->items[i]) seria suficiente. Esta funcion devolveria siempre 0
     */
    for (i = top(s), printedChars = 0; i >= 0; i--) {
        printedChars += s->print_element_function(fp, s->items[i]);
    }
    return printedChars;
}

int stack_size(const Stack* s) {
    if (s == NULL || s->size < 0)
        return -1;
    return s->size;
}