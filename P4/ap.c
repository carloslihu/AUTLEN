#include "ap.h"

struct _AP {
    char* nombre;
    Estado * estadoInicial; /*estado en el que comienza el automata*/
    Palabra * cadenaEntrada; /*lista de palabras que componen la cadena de entrada*/
    TransicionAP * transiciones;
    ConfiguracionApnd * configuraciones; /*lista de configuraciones actuales del automata*/
    int num_estados;
    List * estados; /*Todos los estados existentes*/
};

/**
 * @brief
 */
AP * APNuevo(char * nombre, int num_estados, int num_simbolos_entrada, int num_simbolos_pila) {/*NO TERMINADO*/
    AP * p_ap;
    List* pila, *entrada, *estados;
    p_ap = (AP*) malloc(sizeof (AP));
    p_ap->nombre = (char*) calloc(strlen(nombre) + 1, sizeof (char));
    strcpy(p_ap->nombre, nombre);

    p_ap->num_estados = num_estados;
    p_ap->estados = list_ini((destroy_element_function_type) estadoElimina,
            (copy_element_function_type) estado_copy,
            (print_element_function_type) estadoImprime,
            (cmp_element_function_type) estadoCompara);

    pila = list_ini((destroy_element_function_type) destroy_p_string,
            (copy_element_function_type) copy_p_string,
            (print_element_function_type) print_p_string,
            (cmp_element_function_type) strcmp);
    entrada = list_ini((destroy_element_function_type) destroy_p_string,
            (copy_element_function_type) copy_p_string,
            (print_element_function_type) print_p_string,
            (cmp_element_function_type) strcmp);
    estados = list_ini((destroy_element_function_type) destroy_p_string,
            (copy_element_function_type) copy_p_string,
            (print_element_function_type) print_p_string,
            (cmp_element_function_type) strcmp);

    p_ap->cadenaEntrada = palabraNueva();
    p_ap->transiciones = transicionAPNueva(nombre, num_simbolos_pila, num_estados, num_simbolos_entrada,
            pila, estados, entrada);
    p_ap->configuraciones = NULL;

    return p_ap;
}

void APElimina(AP * p_ap) {/*NO TERMINADO*/
    free(p_ap->nombre);
    estadoElimina(p_ap->estadoInicial);
    palabraElimina(p_ap->cadenaEntrada);
    list_destroy(p_ap->estados);
    transicionAPElimina(p_ap->transiciones);
    configuracionApndDestroy(p_ap->configuraciones);
    free(p_ap);
}

void APImprime(FILE * fd, AP* p_ap) {
    if (fd == NULL || p_ap == NULL)
        return;
    fprintf(fd, "AP={\t%s\n\n", p_ap->nombre);
    transicionImprimeAlfabeto(fd, p_ap->transiciones);
    fprintf(fd, "\nQ=");
    list_print(fd, p_ap->estados);
    fprintf(fd, "\n");
    fprintf(fd, "configuracion actual:\n");
    configuracionApndPrint(fd, p_ap->configuraciones);
    fprintf(fd, "Cadena inicial:\n");
    palabraImprime(fd, p_ap->cadenaEntrada);

    fprintf(fd, "\ntransiciones Lambda Puras:\n");
    transicionImprimeRelacion(fd, p_ap->transiciones);
    transicionImprimeTransiciones(fd, p_ap->transiciones);




}

/**
 * @brief inserta un simbolo (que es un string) en el alfabeto de la entrada, que es una lista de PALABRAS
 */
AP * APInsertaSimboloAlfabetoEntrada(AP * p_ap, char * simbolo) {
    transicionAPInsertaSimboloAlfabetoEntrada(p_ap->transiciones, simbolo);
    return p_ap;
}

AP * APInsertaSimboloAlfabetoPila(AP * p_ap, char * simbolo) {
    transicionAPInsertaSimboloAlfabetoPila(p_ap->transiciones, simbolo);
    return p_ap;
}

AP * APInsertaEstado(AP * p_ap, char * nombre, int tipo) {
    Estado* e;
    e = estadoNuevo(nombre, tipo);
    list_insertLast(p_ap->estados, e);
    transicionAPInsertaSimboloAlfabetoEstado(p_ap->transiciones, nombre);
    if (tipo == INICIAL || tipo == INICIAL_Y_FINAL) {
        p_ap->estadoInicial = estado_copy(e);
    }
    estadoElimina(e);
    return p_ap;
}

AP * APInsertaLTransicion(AP * p_ap,
        char * nombre_estado_i,
        char * nombre_estado_f) {
    transicionLAPInserta(p_ap->transiciones,
            nombre_estado_i, nombre_estado_f);
    return p_ap;
}

AP * APInsertaTransicion(AP * p_ap,
        char * nombre_simbolo_pila,
        char * nombre_estado_i,
        char * nombre_estado_f,
        char * nombre_simbolo_entrada,
        Palabra * accion) {

    transicionAPInserta(p_ap->transiciones,
            nombre_simbolo_pila, nombre_estado_i, nombre_estado_f, nombre_simbolo_entrada,
            accion);
    return p_ap;
}

/**
 * @brief insertar una letra en la cadena de entrada. La cadena de entrada es una lista de PALABRAS, donde letra (que es un string) es un simbolo de esta cadena de entrada
 */
AP * APInsertaLetra(AP * p_ap, char * letra) {
    palabraInsertaLetra(p_ap->cadenaEntrada, letra);
    return p_ap;
}

/**
 * @brief calcula las relaciones instantaneas. al iniciar el automata, genera transiciones instantaneas que son composicion de otras transiciones instantaneas
 */
AP * APCierraLTransicion(AP * p_ap) {
    if (transicioncierreLambda(p_ap->transiciones))
        return p_ap;
    return NULL;
}

/**
 * genera la configuracion_apnd que contiene el estado inicial y los estados a los que se puede llegar mediante el inicial a traves de transiciones instantaneas
 */
AP * APInicializaEstado(AP * p_ap) {
    Stack * pila;
    ConfiguracionAp* p_cap;
    int* aux;
    int tam, i;
    Estado*e;
    if (p_ap->configuraciones)
        configuracionApndDestroy(p_ap->configuraciones);

    pila = stack_ini((destroy_element_function_type) destroy_p_string,
            (copy_element_function_type) copy_p_string,
            (print_element_function_type) print_p_string,
            (cmp_element_function_type) strcmp);
    stack_push(pila, SIMBOLO_INICIO_PILA);
    p_ap->configuraciones = configuracionApndIni();
    p_cap = configuracionApNueva(p_ap->estadoInicial, pila, p_ap->cadenaEntrada);
    configuracionApndInsert(p_ap->configuraciones, p_cap);

    configuracionApElimina(p_cap);
    /*inserto configuraciones por transiciones lambda*/
    aux = transicionLAPpos_estado_f(p_ap->transiciones, estadoNombre(p_ap->estadoInicial), &tam);
    for (i = 0; i < tam; i++) {
        e = list_get(p_ap->estados, aux[i]);
        p_cap = configuracionApNueva(e, pila, p_ap->cadenaEntrada);
        configuracionApndInsert(p_ap->configuraciones, p_cap);
        configuracionApElimina(p_cap);
    }

    free(aux);
    /*TODO*/
    stack_destroy(pila);
    return p_ap;
}

/**
 * un paso del procesamiento de la entrada: según una transicion posible de hacer y a partir de una configuracion_ap, una entrada y una pila,
 * genera nuevas configuracion_ap consumiendo simbolo de entrada, modificando la pila y cambiando el estado de la nueva con respecto de la antigua
 * (todas las modificaciones se reflejan en la nueva configuracion y no en la configuracion antigua)
 * a partir de una configuracion A, crea una copia B y en esta B realiza las modificaciones que haría el automata si hiciera esa transicion
 */
int APTransita(AP * p_ap) {
    if (p_ap == NULL) return -1;
    return transicionAPTransita(p_ap->transiciones, p_ap->estados, &p_ap->configuraciones);
}

/**
 * recorre la lista de configuraciones_ap (situaciones) y para cada una de ellas, llama a APTransita. si alcanza un estado final con la entrada vacia, termina.
 * Si consume toda la cadena de entrada y no esta en un estado final, termina con error.
 */
int APProcesaEntrada(FILE *fd, AP * p_ap) {
    int i = 0, j = 0;
    fprintf(fd, "SE VA A PROCESAR LA ENTRADA\t");
    palabraImprime(fd, p_ap->cadenaEntrada);
    fprintf(fd, "\nA PARTIR DE ESTA CONFIGURACIÓN INICIAL:\n");
    configuracionApndPrint(fd, p_ap->configuraciones);

    for (j = 0; i != 1 && !configuracionApndIsEmpty(p_ap->configuraciones); j++) {
        fprintf(fd, "	ITERACION %d\n"
                "TRAS ITERAR LA CONFIGURACIÓN ACTUAL ES \n", j);
        i = APTransita(p_ap);
        configuracionApndPrint(fd, p_ap->configuraciones);
    };

    if (i == 1) {
        fprintf(fd, "\n¡¡¡ RECONOCIDA !!!!\n");
    } else {
        fprintf(fd, "\n¡¡¡ RECHAZADA !!!!\n");
    }
    return i;
}

void APInicializaCadena(AP * p_ap) {
    palabraElimina(p_ap->cadenaEntrada);
    p_ap->cadenaEntrada = palabraNueva();
}