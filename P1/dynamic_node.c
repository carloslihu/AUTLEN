#include <stdlib.h>


#include "dynamic_node.h"


struct _DynamicNode {
	void* data;
	struct _DynamicNode *next;
};


DynamicNode * dynamicNode_ini()
{
	DynamicNode * aux_return;

	aux_return = (DynamicNode *) malloc (sizeof(DynamicNode));
	aux_return->data = NULL;
	aux_return->next = NULL;
	return aux_return;
}

void dynamicNode_destroy( DynamicNode * pn, destroy_element_function_type f_d)
{
	if ( pn != NULL)
	{
		f_d (pn->data);
		free ( pn);
	}


}

DynamicNode * dynamicNode_getNext(const DynamicNode * pn)
{
	if ( pn != NULL )
	{
		return pn->next;
	}
	return NULL;
}


DynamicNode * dynamicNode_setNext(DynamicNode * pn, const DynamicNode * next)
{
	if ( pn != NULL )
	{
		pn->next = (DynamicNode*)next;
		return pn;
	}
	return pn;


}

void * dynamicNode_getData(const DynamicNode * pn)
{
	if ( pn != NULL )
	{
		return pn->data;
	}
	return NULL;
}


DynamicNode * dynamicNode_setData(DynamicNode * pn, const void * data)
{
	if ( pn != NULL)
		pn->data = (void *)data;
	return pn;

}

int dynamicNode_print( FILE * fd, const DynamicNode * pn, print_element_function_type f_p)
{
	if ( pn != NULL )
	{
		return f_p(fd, pn->data);

	}
	else
		return 0;
}
