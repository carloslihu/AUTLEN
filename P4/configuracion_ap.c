#include "configuracion_ap.h"

struct _ConfiguracionAp {
    Estado * estado;
    Stack * pila;
    Palabra *cadena;
};

/* Se crea una configuración reservando memoria nueva para ella y para copiar
todas las componentes que se proporcionan como argumento */
ConfiguracionAp * configuracionApNueva(Estado * estado, Stack * pila, Palabra *cadena) {
    ConfiguracionAp* p_cap;
    if (!estado || !pila || !cadena)
        return NULL;
    p_cap = (ConfiguracionAp*) malloc(sizeof (ConfiguracionAp));
    if (p_cap == NULL)
        return NULL;
    p_cap->estado = estado_copy(estado);
    p_cap->pila = stack_copy(pila);
    p_cap->cadena = palabraCopia(cadena);
    return p_cap;
}

/* Se libera toda la memoria asociada con la configuracion */
void configuracionApElimina(ConfiguracionAp * p_cap) {
    if (p_cap) {
        estadoElimina(p_cap->estado);
        stack_destroy(p_cap->pila);
        palabraElimina(p_cap->cadena);
        free(p_cap);
    }
}

/* Se muestra por pantalla la configuración */
void configuracionApImprime(FILE * fd, ConfiguracionAp * p_cap) {
    if (fd && p_cap) {
        fprintf(fd, "(");
        estadoImprime(fd, p_cap->estado);
        fprintf(fd, " ");
        stack_print(fd, p_cap->pila);
        fprintf(fd, " ");
        palabraImprime(fd, p_cap->cadena);
        fprintf(fd, ")");
    }
}

/* Se devuelve una copia en memoria nueva de la configuración */
ConfiguracionAp * configuracionApCopia(ConfiguracionAp * p_cap) {
    ConfiguracionAp * p_cap2;
    if (!p_cap)
        return NULL;
    p_cap2 = (ConfiguracionAp*) malloc(sizeof (ConfiguracionAp));
    p_cap2->estado = estado_copy(p_cap->estado);
    p_cap2->pila = stack_copy(p_cap->pila);
    p_cap2->cadena = palabraCopia(p_cap->cadena);
    return p_cap2;
}

/* Se utiliza para comparar dos configuraciones deterministas, devolviendo un
valor negativo, 0 o positivo en función de la comparación de sus componentes en
este orden: estados, pilas, cadenas. En el caso de que no sean iguales, devuelve
el valor que devuelva la comparación de la primera que sea distinta*/
int configuracionCompara(ConfiguracionAp * p_cap1, ConfiguracionAp * p_cap2) {
    int cmp;
    /*en el caso de que alguno sea NULL, tratamos el error asi
            si ambos son NULL son iguales
            y si alguno es distinto de NULL entonces es mayor que el que es NULL*/
    if (p_cap1 == NULL && p_cap2 == NULL)
        return 0;
    else if (p_cap1 != NULL && p_cap2 == NULL)
        return 1;
    else if (p_cap1 == NULL && p_cap2 != NULL)
        return -1;

    if ((cmp = estadoCompara(p_cap1->estado, p_cap2->estado)) != 0)
        return cmp;
    else if ((cmp = stack_compare(p_cap1->pila, p_cap2->pila)) != 0)
        return cmp;
    else
        return palabraCompara(p_cap1->cadena, p_cap2->cadena);

}
/*devuelve el estado del ap*/
Estado*configuracionApEstado(ConfiguracionAp * p_cap) {
    return p_cap->estado;
}
/*devuelve la pila del ap*/
Stack * configuracionApPila(ConfiguracionAp * p_cap) {
    return p_cap->pila;
}
/*devuelve la cadena del ap*/
Palabra*configuracionApCadena(ConfiguracionAp * p_cap) {
    return p_cap->cadena;
}