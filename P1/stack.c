#include "stack.h"

#define REALLOC_FROM_TOP 2

struct _Stack{
	int size;
	void** items;

	destroy_element_function_type   destroy_element_function;
    copy_element_function_type      copy_element_function;
    print_element_function_type     print_element_function;
};


/**------------------------------------------------------------------
Inicializa la pila reservando memoria y almacenando los tres punteros a función pasados como parámetro (el primero para destruir elementos, el segundo para copiar elementos y el tercero para imprimir elementos). Salida: NULL si ha habido error o la pila si ha ido bien
------------------------------------------------------------------*/
Stack * stack_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3) {
	if(f1 == NULL || f2 == NULL || f3 == NULL)
		return NULL;
	Stack* s = (Stack*)malloc(sizeof(struct _Stack));
	if(s == NULL)
		return NULL;
	s->destroy_element_function = f1;
	s->copy_element_function = f2;
	s->print_element_function = f3;
	s->size = 0;
	s->items = NULL;

	return s;
}
/**------------------------------------------------------------------
Elimina la pila Entrada: la pila que se va a eliminar
------------------------------------------------------------------*/
void stack_destroy(Stack * s) {
	int i;

	if(s == NULL)
		return;
	if(s->items != NULL)
		for(i = s->size - 1; i >= 0; i--)
			s->destroy_element_function(s->items[i]);
	free(s);
}
/**------------------------------------------------------------------
Inserta un elemento en la pila. Entrada: un elemento y la pila donde insertarlo. Salida: NULL si no logra insertarlo o la pila resultante si lo logra
------------------------------------------------------------------*/
Stack * stack_push(Stack * s, const void *obj) {
	void ** aux;
	if(s == NULL || obj == NULL)
		return NULL;
	//this +2 is because to

	aux = (void**)realloc(s->items,s->size + 1);
	if(aux == NULL)
		return NULL;
	s->items = aux;
	s->size++;
	s->items[s->size] = obj;
	return s; 
}
/**------------------------------------------------------------------
Extrae un elemento en la pila. Entrada: la pila de donde extraerlo. Salida: NULL si no logra extraerlo o el elemento extraido si lo logra. Nótese que la pila quedará modificada
------------------------------------------------------------------*/
void * stack_pop(Stack *s) {
	void* obj;
	void** aux;
	if(s == NULL || s->size <= 0)
		return NULL
	obj = s->items[s->size-1];
	s->size--;
	if(s->size == 0)
		aux = NULL;
	else
		aux = (void**)realloc(s->items, s->size);
	s->items = aux;
	return obj;
}
/**------------------------------------------------------------------
Copia un elemento (reservando memoria) sin modificar el top de la pila. Entrada: la pila de donde copiarlo. Salida: NULL si no logra copiarlo o el elemento si lo logra
------------------------------------------------------------------*/
void * stack_top(const Stack *) { }
/**------------------------------------------------------------------
Comprueba si la pila esta vacia. Entrada: pila. Salida: TRUE si está vacia o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isEmpty(const Stack *) { }
/**------------------------------------------------------------------
Comprueba si la pila esta llena. Entrada: pila. Salida: TRUE si está llena o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isFull(const Stack *) { }
/**------------------------------------------------------------------
Imprime toda la pila, colocando el elemento en la cima al principio de la impresión (y un elemento por línea). Entrada: pila y fichero donde imprimirla. Salida: Devuelve el número de caracteres escritos.
------------------------------------------------------------------*/
int stack_print(FILE*, const Stack*) { }


int stack_size(const Stack* ) { }