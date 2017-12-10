#include "transforma.h"

AFND * AFNDTransforma(AFND * afnd) {
    AFND * afd;
    List * cis;
    List* t_inicio, *t_simbolo, *t_fin; /* listas donde guardaré los valores de la transicion
                                         son listas de char* */
    CInt*ci_aux, *ci;
    char nombre_estado[50], e_1[50], e_2[50];
    int num_estados, num_simbolos, num_estados_final;
    int tipo, tipo_aux;
    int flag_i = 0, flag_f = 0;
    int i, j;
    int i_e1, i_s, i_e2;
    char* e_1_aux, * e_2_aux, *s_aux;
    if (!afnd)
        return NULL;

    t_inicio = list_ini((destroy_element_function_type) destroy_p_string,
            (copy_element_function_type) copy_p_string,
            (print_element_function_type) print_p_string,
            (cmp_element_function_type) strcmp);
    t_simbolo = list_ini((destroy_element_function_type) destroy_p_string,
            (copy_element_function_type) copy_p_string,
            (print_element_function_type) print_p_string,
            (cmp_element_function_type) strcmp);
    t_fin = list_ini((destroy_element_function_type) destroy_p_string,
            (copy_element_function_type) copy_p_string,
            (print_element_function_type) print_p_string,
            (cmp_element_function_type) strcmp);

    cis = list_ini((destroy_element_function_type) CIntElimina,
            (copy_element_function_type) CIntCopia,
            (print_element_function_type) CIntImprime,
            (cmp_element_function_type) CIntCompara);
    
    num_estados = AFNDNumEstados(afnd);
    num_simbolos = AFNDNumSimbolos(afnd);


    /* calcular estado inicial */
    i = AFNDIndiceEstadoInicial(afnd);
    tipo = INICIAL;
    ci_aux = CIntNuevo(num_estados);
    CIntInicializa(ci_aux);
    for (j = 0; j < num_estados; j++)
        if (AFNDCierreLTransicionIJ(afnd, i, j) == 1) {
            CIntInserta(ci_aux, j, 1);
        }
    list_insertLast(cis, ci_aux);
    CIntElimina(ci_aux);


    /* calculamos el resto de estados */
    num_estados_final = 1;
    ci = CIntNuevo(num_estados);
    for (i = 0;; i++) {
        ci_aux = list_get(cis, i);
        if (ci_aux == NULL)
            break;

        for (i_s = 0; i_s < num_simbolos; i_s++) {
            /* calculamos fila de ints */
            CIntInicializa(ci);
            for (i_e1 = 0; i_e1 < num_estados; i_e1++) {
                if (CIntPosBit(ci_aux, i_e1) == 1) {
                    for (i_e2 = 0; i_e2 < num_estados; i_e2++) {

                        if (AFNDTransicionIndicesEstadoiSimboloEstadof(afnd, i_e1, i_s, i_e2) == 1) {
                            CIntInserta(ci, i_e2, 1);
                        }
                    }
                }
            }
            /* añadimos transiciones lambda */
            for (i_e1 = 0; i_e1 < num_estados; i_e1++) {
                if (CIntPosBit(ci, i_e1) == 1) {
                    for (i_e2 = 0; i_e2 < num_estados; i_e2++) {
                        if (AFNDCierreLTransicionIJ(afnd, i_e1, i_e2) == 1) {
                            CIntInserta(ci, i_e2, 1);
                        }
                    }
                }
            }
            /* inserto transicion nueva no lambda en la lista de transiciones*/
            strcpy(e_1, "");
            for (j = 0; j < num_estados; j++) {
                if (CIntPosBit(ci_aux, j) == 1)
                    strcat(e_1, AFNDNombreEstadoEn(afnd, j));
            }
            strcpy(e_2, "");
            for (j = 0; j < num_estados; j++) {
                if (CIntPosBit(ci, j) == 1)
                    strcat(e_2, AFNDNombreEstadoEn(afnd, j));
            }
            if (strcmp(e_2, "")) {
                list_insertLast(t_inicio, e_1);
                list_insertLast(t_simbolo, AFNDSimboloEn(afnd, i_s));
                list_insertLast(t_fin, e_2);
            }
            /* estado nuevo por insertar */
            if (list_belongs(cis, ci) == FALSE && CIntVacio(ci) == FALSE) {
                list_insertLast(cis, ci);
                num_estados_final++;
            }
        }
    }
    CIntElimina(ci);

    /* creo automata determinista */
    afd = AFNDNuevo("determinista", num_estados_final, num_simbolos);
    /* inserto simbolos en autómata*/
    for (i_s = 0; i_s < num_simbolos; i_s++)
        AFNDInsertaSimbolo(afd, AFNDSimboloEn(afnd, i_s));

    /* inserto los estados en el autómata a partir del CInt */
    while (list_isEmpty(cis) == FALSE) {
        ci_aux = list_extractFirst(cis);
        strcpy(nombre_estado, "");
        flag_i = 0;
        flag_f = 0;
        for (i_e1 = 0; i_e1 < num_estados; i_e1++) {
            if (CIntPosBit(ci_aux, i_e1) == 1) {
                strcat(nombre_estado, AFNDNombreEstadoEn(afnd, i_e1));
                tipo_aux = AFNDTipoEstadoEn(afnd, i_e1);
                if (tipo_aux == INICIAL)
                    flag_i = 1;
                else if (tipo_aux == FINAL)
                    flag_f = 1;

                else if (tipo_aux == INICIAL_Y_FINAL) {
                    flag_i = 1;
                    flag_f = 1;
                }
            }
        }
        if (flag_i == 1 && flag_f == 1)
            tipo = INICIAL_Y_FINAL;
        else if (flag_i == 1)
            tipo = INICIAL;
        else if (flag_f == 1)
            tipo = FINAL;
        else
            tipo = NORMAL;
        AFNDInsertaEstado(afd, nombre_estado, tipo);
        CIntElimina(ci_aux);
    }
    /* inserto las transiciones en el autómata*/
    while (list_isEmpty(t_inicio) == FALSE) {
        e_1_aux = list_extractFirst(t_inicio);
        s_aux = list_extractFirst(t_simbolo);
        e_2_aux = list_extractFirst(t_fin);
        AFNDInsertaTransicion(afd, e_1_aux, s_aux, e_2_aux);
        free(e_1_aux);
        free(s_aux);
        free(e_2_aux);
    }
    list_destroy(cis);
    list_destroy(t_inicio);
    list_destroy(t_simbolo);
    list_destroy(t_fin);

    return afd;
}