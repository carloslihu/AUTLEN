#ifndef GENERIC_COLLECTIONS_TYPES_H
#define GENERIC_COLLECTIONS_TYPES_H

#include <stdio.h>

typedef void (*destroy_element_function_type)(void*);
typedef void (*(*copy_element_function_type)(const void*));
typedef int (*print_element_function_type)(FILE *, const void*);
typedef int (*cmp_element_function_type)(const void*, const void *);


#endif
