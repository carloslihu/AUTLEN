#ifndef TRANSICION_AP_H
#define TRANSICION_AP_H


#include "generic_collections_types.h"
#include "generic_string.h"
#include "list.h"
#include "configuracion_apnd.h"
#include "relacion.h"
typedef struct _TransicionAP TransicionAP;

TransicionAP * transicionAPNueva(char * nombre, int num_simbolos_pila, int num_estados, int num_simbolos_entrada,
        List * nombres_pila, List * nombres_estados, List * nombres_entrada);
TransicionAP* transicionAPInserta(TransicionAP * p_t,
        char * nombre_simbolo_pila,
        char * nombre_estado_i,
        char * nombre_estado_f,
        char * nombre_simbolo_entrada,
        Palabra * accion);
void transicionAPElimina(TransicionAP * p_t);

#endif