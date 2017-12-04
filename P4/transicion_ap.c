#include "transicion_ap.h"

struct _TransicionAP {
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

    if (nombres_pila == NULL || nombres_estados == NULL || nombres_entrada == NULL)
        return NULL;

    aux_return = (TransicionAP *) calloc(1, sizeof (TransicionAP));

    /*aux_return->nombre = (char*) calloc(strlen(nombre) + 1, sizeof (char));
    strcpy(aux_return->nombre, nombre);*/

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
        l = p_t->num_simbolos_entrada - 1;
    } else {
        l = list_element_index(p_t->nombres_entrada, nombre_simbolo_entrada);
    }
    if (accion) {
        list_insertLast(p_t->acciones[i][j][k][l], accion);
    } else {
        lambda = palabraNueva();
        palabraInsertaLetra(lambda, "lambda");
        list_insertLast(p_t->acciones[i][j][k][l], lambda);
        palabraElimina(lambda);
    }
    return p_t;
}

TransicionAP* transicionAPInsertaSimboloAlfabetoEntrada(
        TransicionAP * p_t,
        char * simbolo) {
    list_insertLast(p_t->nombres_entrada, simbolo);
    return p_t;
}

TransicionAP* transicionAPInsertaSimboloAlfabetoPila(
        TransicionAP * p_t,
        char * simbolo) {
    list_insertLast(p_t->nombres_pila, simbolo);
    return p_t;
}

TransicionAP* transicionAPInsertaSimboloAlfabetoEstado(
        TransicionAP * p_t,
        char * nombre) {
    list_insertLast(p_t->nombres_estados, nombre);
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

/*Devuelve un array con las posiciones finales, dado un estado inicial*/
int* transicionLAPpos_estado_f(TransicionAP * p_t, char* nombre_estado_i, int* tam) {
    int i, f, size;
    int* pos_estado_f;
    size = 0;
    pos_estado_f = (int*) calloc(p_t->num_estados, sizeof (int));
    i = list_element_index(p_t->nombres_estados, nombre_estado_i);
    for (f = 0; f < p_t->num_estados; f++) {
        if (relacionCierreIJ(p_t->transicionesL, i, f) == 1) {
            pos_estado_f[size] = f;
            size++;
        }
    }
    *tam = size;
    return pos_estado_f;
}

void transicionImprimeAlfabeto(FILE * fd, TransicionAP * p_t) {
    fprintf(fd, "Sigma=");
    list_print(fd, p_t->nombres_entrada);
    fprintf(fd, "\nGamma=");
    list_print(fd, p_t->nombres_pila);
}

void transicionImprimeRelacion(FILE * fd, TransicionAP * p_t) {
    relacionImprime(fd, p_t->transicionesL);
}

void transicionImprimeTransiciones(FILE * fd, TransicionAP * p_t) {
    int i, j, k, l;
    fprintf(fd, "\n	Transiciones que modifican entrada o pila: "
            "[ <cima pila> <estado inicial> <estado final> <simbolo entrada> ==> ]"
            " <accion en la pila>\n");
    for (i = 0; i < p_t->num_simbolos_pila; i++) {
        for (j = 0; j < p_t->num_estados; j++) {
            for (k = 0; k < p_t->num_estados; k++) {
                for (l = 0; l < p_t->num_simbolos_entrada; l++) {
                    if (!list_isEmpty(p_t->acciones[i][j][k][l])) {
                        fprintf(fd, "[ %s ", (char*) list_get(p_t->nombres_pila, i));
                        fprintf(fd, "%s ", (char*) list_get(p_t->nombres_estados, j));
                        fprintf(fd, "%s ", (char*) list_get(p_t->nombres_estados, k));
                        if (l == p_t->num_simbolos_entrada - 1) {
                            fprintf(fd, "lambda ] ==> ");
                        } else
                            fprintf(fd, "%s ] ==> ", (char*) list_get(p_t->nombres_entrada, l));
                        list_print(fd, p_t->acciones[i][j][k][l]);

                    }

                }
            }
        }
    }
}

/*FALTA añadir transiciones lambda puras*/
int transicionAPTransita(TransicionAP* p_t, List*estados, ConfiguracionApnd** p_capnd) {
    ConfiguracionApnd* res, *capnd;
    ConfiguracionAp*cap, *cap_aux;
    char* tope_pila, *tope_entrada, *nombre_estado_i, *tope_accion;
    int i, j, k, l[2], m, tope_entrada_index, n, o, tam;
    int flag_reconocido = 0;
    int*aux;
    Stack*pila, *pila_aux;
    Palabra*accion, *lambda, *cadena_aux, *accion_aux, *cadenaEntrada;
    Estado*estado, *e;

    capnd = *p_capnd;
    lambda = palabraNueva();
    palabraInsertaLetra(lambda, "lambda");
    res = configuracionApndIni();

    while(!configuracionApndIsEmpty(capnd)){
        cap = configuracionApndExtract(capnd);

        /*calcular indice de primer elemento de pila (i)*/
        pila = configuracionApPila(cap);
        tope_pila = stack_pop(pila);
        /*mirar si pila a null*/
        if (tope_pila) {
            i = list_element_index(p_t->nombres_pila, tope_pila);

            /*calcular indice de estado inicial (j)*/
            nombre_estado_i = estadoNombre(configuracionApEstado(cap));
            j = list_element_index(p_t->nombres_estados, nombre_estado_i);

            /*calcular primer elemento de la entrada (l)*/
            cadenaEntrada = configuracionApCadena(cap);
            tope_entrada = palabraPrimer(cadenaEntrada);
            tope_entrada_index = list_element_index(p_t->nombres_entrada, tope_entrada);

            l[0] = tope_entrada_index;
            l[1] = p_t->num_simbolos_entrada - 1;
            /*para cada estado final*/
            for (k = 0; k < p_t->num_estados; k++) {
                if (tope_entrada == NULL)
                    n = 1;
                else
                    n = 0;
                /*para simbolo entrada y lambda*/
                for (; n < 2 ; n++) {

                    if (l[n]!=-1 && !list_isEmpty(p_t->acciones[i][j][k][l[n]])) {

                        estado = list_get(estados, k);
                        /*para cada una de las acciones de la lista*/
                        for (m = 0; m < list_size(p_t->acciones[i][j][k][l[n]]); m++) {
                            accion = list_get(p_t->acciones[i][j][k][l[n]], m);
                            accion_aux = palabraCopia(accion);
                            pila_aux = stack_copy(pila);
                            /*metemos acciones en pila*/
                            if (palabraCompara(accion_aux, lambda) != 0) {
                                while (palabraVacia(accion_aux) == FALSE) {
                                    tope_accion = palabraPop(accion_aux);
                                    stack_push(pila_aux, tope_accion);
                                    free(tope_accion);
                                }
                            palabraElimina(accion_aux);
                            accion_aux = NULL;
                            }

                            /*cadena entrada nueva*/
                            if (n == 1) {/*caso lambda*/
                                cadena_aux = palabraCopia(cadenaEntrada);
                            } else {/*otro caso*/
                                cadena_aux = palabraExtraePrimer(cadenaEntrada);
                            }
                            if (palabraVacia(cadena_aux) &&
                                    ((estadoTipo(estado) == FINAL) || (estadoTipo(estado) == INICIAL_Y_FINAL) || stack_isEmpty(pila_aux))) {
                                flag_reconocido = 1;
                            }
                            cap_aux = configuracionApNueva(estado, pila_aux, cadena_aux);
                            configuracionApndInsert(res, cap_aux);
                            configuracionApElimina(cap_aux);

                            aux = transicionLAPpos_estado_f(p_t, estadoNombre(estado), &tam);
                            for (o = 0; o < tam; o++) {
                                e = list_get(estados, aux[o]);
                                cap_aux = configuracionApNueva(e, pila_aux, cadena_aux);
                                configuracionApndInsert(res, cap_aux);
                                configuracionApElimina(cap_aux);
                            }
                            free(aux);
                            palabraElimina(accion_aux);
                            stack_destroy(pila_aux);
                            palabraElimina(cadena_aux);
                        }


                    }
                }
            }
        }
        free(tope_pila);
        configuracionApElimina(cap);
    }

    palabraElimina(lambda);
    configuracionApndDestroy(*p_capnd);
    *p_capnd = res;
    /*todo return*/

    /*return 1 si entrada vacia y estado final
              si entrada vacia pila vacia*/
    /*else return 0*/
    return flag_reconocido;
}

