#ifndef DYNAMIC_NODE_H
#define DYNAMIC_NODE_H

#include <stdio.h>
#include "generic_collections_types.h"


typedef struct _DynamicNode DynamicNode;

DynamicNode * dynamicNode_ini();
void dynamicNode_destroy( DynamicNode * pn, destroy_element_function_type f_d);
DynamicNode * dynamicNode_getNext(const DynamicNode * pn);
DynamicNode * dynamicNode_setNext(DynamicNode * pn, const DynamicNode * next);
void * dynamicNode_getData(const DynamicNode * pn);
DynamicNode * dynamicNode_setData(DynamicNode * pn,const void * data);
int dynamicNode_print( FILE * fd, const DynamicNode * pn, print_element_function_type f_p);





#endif
