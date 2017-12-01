#include "transicion_ap.h"

struct _TransicionAP {
    char* nombre;
    int num_simbolos_pila;
    int num_estados;
    int num_simbolos_entrada;
    List * nombres_pila;
    List * nombres_entrada;
    List * nombres_estados;
    Relacion* transicionesL;
    List * **** acciones;
};

TransicionAP * transicionAPNueva(char * nombre, int num_simbolos_pila, int num_estados, int num_simbolos_entrada, List * nombres_pila, List * nombres_estados, List * nombres_entrada) {
    int i, j, k, l;
    TransicionAP * aux_return;

    if (nombre == NULL || nombres_pila == NULL || nombres_estados == NULL || nombres_entrada == NULL ||
            num_simbolos_pila != list_size(nombres_pila) || num_estados != list_size(nombres_estados) || num_simbolos_entrada != list_size(nombres_entrada))
        return NULL;

    aux_return = (TransicionAP *) calloc(1, sizeof (TransicionAP));

    aux_return->nombre = (char*) calloc(strlen(nombre) + 1, sizeof (char));
    strcpy(aux_return->nombre, nombre);

    aux_return->num_simbolos_pila = num_simbolos_pila;
    aux_return->num_estados = num_estados;
    aux_return->num_simbolos_entrada = num_simbolos_entrada + 1;

    aux_return->nombres_pila = nombres_pila;
    aux_return->nombres_entrada = nombres_entrada;
    aux_return->nombres_estados = nombres_estados;

    aux_return->transicionesL = relacionNueva(nombre, num_estados);

    aux_return->acciones = (List * ****) calloc(num_simbolos_pila, sizeof (List * ***));
    for (i = 0; i < num_simbolos_pila; i++) {
        aux_return->acciones[i] = (List * ***) calloc(num_estados, sizeof (List * **));
        for (j = 0; j < num_estados; j++) {
            aux_return->acciones[i][j] = (List * **) calloc(num_estados, sizeof (List * *));
            for (k = 0; k < num_estados; k++) {
                aux_return->acciones[i][j][k] = (List * *) calloc(aux_return->num_simbolos_entrada, sizeof (List *));
                for (l = 0; l < aux_return->num_simbolos_entrada; l++) {
                    aux_return->acciones[i][j][k][l] = list_ini((destroy_element_function_type) palabraElimina,
                            (copy_element_function_type) palabraCopia,
                            (print_element_function_type) palabraImprime,
                            (cmp_element_function_type) palabraCompara
                            );
                }
            }
        }
    }

    return aux_return;
}

void transicionAPElimina(TransicionAP * p_t) {
    int i, j, k, l;

    if (p_t == NULL)
        return;

    if (p_t->acciones != NULL) {
        for (i = 0; i < p_t->num_simbolos_pila; i++) {
            for (j = 0; j < p_t->num_estados; j++) {
                for (k = 0; k < p_t->num_estados; k++) {
                    for (l = 0; l < p_t->num_simbolos_entrada; l++) {
                        if (p_t->acciones[i][j][k][l] != NULL) list_destroy(p_t->acciones[i][j][k][l]);
                    }
                }
            }
        }

    }


    for (i = 0; i < p_t->num_simbolos_pila; i++) {
        for (j = 0; j < p_t->num_estados; j++) {
            for (k = 0; k < p_t->num_estados; k++) {
                free(p_t->acciones[i][j][k]);
            }
        }

    }

    for (i = 0; i < p_t->num_simbolos_pila; i++) {
        for (j = 0; j < p_t->num_estados; j++) {
            free(p_t->acciones[i][j]);
        }

    }
    for (i = 0; i < p_t->num_simbolos_pila; i++) {
        free(p_t->acciones[i]);

    }

    list_destroy(p_t->nombres_pila);
    list_destroy(p_t->nombres_estados);
    list_destroy(p_t->nombres_entrada);
    relacionElimina(p_t->transicionesL);
    free(p_t->acciones);
    free(p_t);
}

TransicionAP* transicionAPInserta(TransicionAP * p_t,
        char * nombre_simbolo_pila,
        char * nombre_estado_i,
        char * nombre_estado_f,
        char * nombre_simbolo_entrada,
        Palabra * accion) {

    int i, j, k, l;
    Palabra*lambda;

    i = list_element_index(p_t->nombres_pila, nombre_simbolo_pila);
    j = list_element_index(p_t->nombres_estados, nombre_estado_i);
    k = list_element_index(p_t->nombres_estados, nombre_estado_f);

    if (nombre_simbolo_entrada == NULL) {
        l = p_t->num_simbolos_entrada;
    } else {
        l = list_element_index(p_t->nombres_entrada, nombre_simbolo_entrada);
    }
    if (accion) {
        list_insertFirst(p_t->acciones[i][j][k][l], accion);
    } else {
        lambda = palabraNueva();
        ;
        palabraInsertaLetra(lambda, "lambda");
        list_insertFirst(p_t->acciones[i][j][k][l], lambda);
        palabraElimina(lambda);
    }
    return p_t;
}

TransicionAP* transicionAPInsertaSimboloAlfabetoEntrada(
        TransicionAP * p_t,
        char * simbolo) {
    list_insertFirst(p_t->nombres_entrada, simbolo);
    return p_t;
}

TransicionAP* transicionAPInsertaSimboloAlfabetoPila(
        TransicionAP * p_t,
        char * simbolo) {
    list_insertFirst(p_t->nombres_pila, simbolo);
    return p_t;
}

TransicionAP* transicionAPInsertaSimboloAlfabetoEstado(
        TransicionAP * p_t,
        char * nombre) {
    list_insertFirst(p_t->nombres_estados, nombre);
    return p_t;
}

TransicionAP* transicionLAPInserta(TransicionAP * p_t,
        char * nombre_estado_i,
        char * nombre_estado_f) {
    int i, f;
    i = list_element_index(p_t->nombres_estados, nombre_estado_i);
    f = list_element_index(p_t->nombres_estados, nombre_estado_f);

    relacionInserta(p_t->transicionesL, i, f);
    return p_t;
}

TransicionAP* transicioncierreLambda(TransicionAP* p_ap) {
    if (relacionCierreTransitivo(p_ap->transicionesL))
        return p_ap;
    return NULL;
}

int* transicionLAPpos_estado_f(TransicionAP * p_t, char* nombre_estado_i, int* tam) {
    int i, f;
    int* pos_estado_f;
    *tam = 0;
    pos_estado_f = (int*) calloc(p_t->num_estados, sizeof (int));
    i = list_element_index(p_t->nombres_estados, nombre_estado_i);
    for (f = 0; f < p_t->num_estados; f++) {
        if (relacionCierreIJ(p_t->transicionesL, i, f) == 1) {
            pos_estado_f[*tam] = f;
            *tam++;
        }
    }
    return pos_estado_f;
}