#include "configuracion_apnd.h"

struct _ConfiguracionApnd {
    List*p_caps;
};

/* Inicializa una configuracion no determinista */
ConfiguracionApnd * configuracionApndIni() {
    ConfiguracionApnd * capnd;
    capnd = (ConfiguracionApnd *) malloc(sizeof (ConfiguracionApnd));
    capnd->p_caps = list_ini((destroy_element_function_type) configuracionApElimina,
            (copy_element_function_type) configuracionApCopia,
            (print_element_function_type) configuracionApImprime,
            (cmp_element_function_type) configuracionCompara);
    return capnd;
}

/* Inserta una configuracion determinista en una no determinista. Se realiza una
copia en memoria propia de la coleccion para el nuevo elemento y se asegura que
no haya duplicados*/
ConfiguracionApnd* configuracionApndInsert(ConfiguracionApnd* capnd, const ConfiguracionAp * p_cap) {
    if (!capnd || !p_cap) {
        return NULL;
    }
    if (list_belongs(capnd->p_caps, (void*) p_cap) == FALSE) {
        capnd->p_caps = list_insertFirst(capnd->p_caps, p_cap);
    }
    return capnd;
}

/* Se obtiene una configuracion determinista de la no determinista, que
desaparece de la coleccion.
No se especifica el orden en el que se extrae */
ConfiguracionAp * configuracionApndExtract(ConfiguracionApnd * capnd) {
    if (!capnd)
        return NULL;
    return list_extractFirst(capnd->p_caps);
}

/* Se devuelve 1 si esta vacia y 0 en caso contrario */
int configuracionApndIsEmpty(const ConfiguracionApnd* capnd) {
    if (!capnd)
        return -1;
    return list_isEmpty(capnd->p_caps);
}

/* Se devuelve el numero de configuraciones deterministas que hay dentro de la no
determinista */
int configuracionApndSize(const ConfiguracionApnd * capnd) {
    if (!capnd)
        return -1;
    return list_size(capnd->p_caps);
}

/* Se imprime todas las configuraciones deterministas. No se especifica en que
orden */
int configuracionApndPrint(FILE *fd, const ConfiguracionApnd* capnd) {
    if (!fd || !capnd)
        return -1;
    list_print(fd, capnd->p_caps);
    return 0;

}

/* Se libera toda la memoria asociada con la configuracion no determinista */
void configuracionApndDestroy(ConfiguracionApnd* capnd) {
    if (capnd) {
        if (capnd->p_caps)
            list_destroy(capnd->p_caps);
        free(capnd);
    }
}