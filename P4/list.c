#include "generic_collections_types.h"
#include "dynamic_node.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct _List {
    DynamicNode *node;

    destroy_element_function_type destroy_element_function;
    copy_element_function_type copy_element_function;
    print_element_function_type print_element_function;
    cmp_element_function_type cmp_element_function;
};

List* list_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3, cmp_element_function_type f4) {
    List* l;

    if ((l = (List *) malloc(sizeof (List))) == NULL)
        return NULL;

    l->node = NULL;
    l->destroy_element_function = f1;
    l->copy_element_function = f2;
    l->print_element_function = f3;
    l->cmp_element_function = f4;


    return l;

}

void list_destroy(List* list) {
    void *extracted;

    if (!list)
        return;

    while (!list_isEmpty(list)) {
        extracted = list_extractFirst(list);
        list->destroy_element_function(extracted);
    }

    free(list);
}

List* list_insertFirst(List* list, const void *pElem) {
    DynamicNode *node;

    if (!list || !pElem)
        return NULL;

    node = dynamicNode_ini();
    dynamicNode_setData(node, list->copy_element_function(pElem));
    dynamicNode_setNext(node, list->node);
    list->node = node;

    return list;
}

List* list_insertLast(List* list, const void *pElem) {
    DynamicNode *node, *aux;

    if (!list || !pElem)
        return NULL;

    node = dynamicNode_ini();
    dynamicNode_setData(node, list->copy_element_function(pElem));

    if (list_isEmpty(list)) {
        list->node = node;
        return list;
    }

    for (aux = list->node; dynamicNode_getNext(aux) != NULL; aux = dynamicNode_getNext(aux));

    dynamicNode_setNext(aux, node);

    return list;
}

List* list_insertInOrder(List *list, const void *pElem) {
    DynamicNode *node, *aux;

    if (!list || !pElem)
        return NULL;

    node = dynamicNode_ini();

    dynamicNode_setData(node, list->copy_element_function(pElem));

    if (list_isEmpty(list)) {
        list->node = node;
        return list;
    }

    aux = list->node;
    while ((dynamicNode_getNext(aux) != NULL) && (list->cmp_element_function(
            dynamicNode_getData(
            dynamicNode_getNext(aux)
            ),
            pElem) <= 0)) {
        aux = dynamicNode_getNext(aux);
    }

    if (aux != list->node) {
        dynamicNode_setNext(node, dynamicNode_getNext(aux));
        dynamicNode_setNext(aux, node);
    } else {
        if (list->cmp_element_function(dynamicNode_getData(aux), pElem) <= 0) {
            dynamicNode_setNext(node, dynamicNode_getNext(aux));
            dynamicNode_setNext(aux, node);
        } else {
            dynamicNode_setNext(node, list->node);
            list->node = node;
        }
    }

    return list;
}

void* list_extractFirst(List* list) {
    DynamicNode *aux;
    void *pElem;

    if (!list || list_isEmpty(list))
        return NULL;

    aux = list->node;


    pElem = list->copy_element_function(dynamicNode_getData(aux));

    list->node = dynamicNode_getNext(aux);
    dynamicNode_destroy(aux, list->destroy_element_function);

    return pElem;
}

void* list_extractLast(List* list) {
    int i;
    DynamicNode *prev, *aux;
    void *pElem;

    if (!list || list_isEmpty(list))
        return NULL;

    prev = NULL;
    aux = list->node;
    i = 0;
    while (dynamicNode_getNext(aux) != NULL) {
        prev = aux;
        aux = dynamicNode_getNext(aux);
        i++;
    }

    pElem = list->copy_element_function(dynamicNode_getData(aux));

    if (prev != NULL)
        dynamicNode_setNext(prev, dynamicNode_getNext(aux));
    else list->node = NULL;


    dynamicNode_destroy(aux, list->destroy_element_function);

    return pElem;
}

Bool list_isEmpty(const List* list) {
    if (list->node == NULL)
        return TRUE;
    return FALSE;
}

int list_size(const List* list) {
    DynamicNode *aux = list->node;
    int i = 0;

    while (aux != NULL) {
        aux = dynamicNode_getNext(aux);
        i++;
    }

    return i;
}

int list_print(FILE *fd, const List* list) {
    DynamicNode *aux;
    int count = 0;

    if (!list || list_isEmpty(list))
        return 0;

    count += fprintf(fd, "{ ");

    aux = list->node;
    while (aux != NULL) {
        count += dynamicNode_print(fd, aux, list->print_element_function);
        count += fprintf(fd, " ");
        aux = dynamicNode_getNext(aux);
    }
    count += fprintf(fd, "}\n");

    return count;
}

int list_belongs(const List * list, void * pElem) {

    DynamicNode *aux;

    /*
        fprintf(stdout,"LIST BELONGS: start ");list->print_element_function(stdout,pElem);
     */
    if (!list || !pElem) return 0;

    if (list_isEmpty(list)) {
        return 0;
    }

    aux = list->node;
    while ((aux != NULL)
            &&
            (list->cmp_element_function(dynamicNode_getData(aux), pElem) != 0)
            ) {
        /*
            fprintf(stdout,"ITERACION i\n");
            list->print_element_function(stdout,pElem);
            list->print_element_function(stdout,dynamicNode_getData( dynamicNode_getNext( aux )));
         */
        aux = dynamicNode_getNext(aux);
        /*
            fprintf(stdout,"ITERACION i: end\n");
         */
    }

    /*
        fprintf(stdout,"LIST BELONGS: end\n");
     */
    if (aux == NULL) /* SE HA ALCANZADO AL FINAL DE LA LISTA SIN ENCONTRAR EL ELEMENTO */
        return 0;
    else return 1;
}

int list_element_index(const List* list, void* pElem) {
    DynamicNode *aux = list->node;
    int i = 0;

    if (list == NULL || pElem == NULL)
        return -1;

    while (aux != NULL) {
        if (list->cmp_element_function(dynamicNode_getData(aux), pElem) == 0)
            return i;
        aux = dynamicNode_getNext(aux);
        i++;
    }
    return -1;
}

/*codigo nuestro*/
void* list_get(const List* list, int i) {
    DynamicNode *aux = list->node;
    int j;
    if (list == NULL || i < 0)
        return NULL;

    for (j = 0; j < i && aux != NULL; j++) {
        aux = dynamicNode_getNext(aux);
    }
    return dynamicNode_getData(aux);
}