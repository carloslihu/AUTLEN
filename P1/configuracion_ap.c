#include "configuracion_ap.h"

struct _ConfiguracionAp {
	Estado * estado;
	Stack * pila;
	Palabra *cadena;
};
/* Se crea una configuración reservando memoria nueva para ella y para copiar
todas las componentes que se proporcionan como argumento */
ConfiguracionAp * configuracionApNueva( Estado * estado, Stack * pila, Palabra *cadena) {
	ConfiguracionAp* p_cap;
	if (!estado || !pila || !cadena)
		return NULL;
	p_cap = (ConfiguracionAp*)malloc(sizeof(ConfiguracionAp));
	p_cap->estado = estado;
	p_cap->pila = pila;
	p_cap->cadena = cadena;
	return p_cap;
}

/* Se libera toda la memoria asociada con la configuracion */
void configuracionApElimina( ConfiguracionAp * p_cap) {
	if (p_cap) {
		estadoElimina(p_cap->estado);
		stack_destroy(p_cap->pila);
		palabraElimina(p_cap->cadena);
		free(p_cap);
	}
}

/* Se muestra por pantalla la configuración */
void configuracionApImprime( FILE * fd, ConfiguracionAp * p_cap) {
	/*TODO ver formatos de impresion*/
	if (fd && p_cap) {

	}
}

/* Se devuelve una copia en memoria nueva de la configuración */
ConfiguracionAp * configuracionApCopia( ConfiguracionAp * p_cap) {
	ConfiguracionAp * p_cap2;
	if (!p_cap)
		return NULL;
	p_cap2 = (ConfiguracionAp*)malloc(sizeof(ConfiguracionAp));
	p_cap2->estado = estado_copy(p_cap->estado);
	/*TODO copiar pila?*/
	p_cap2->pila;
	p_cap2->cadena = palabraCopia (p_cap->cadena);
	return p_cap2;
}

/* Se utiliza para comparar dos configuraciones deterministas, devolviendo un
valor negativo, 0 o positivo en función de la comparación de sus componentes en
este orden: estados, pilas, cadenas. En el caso de que no sean iguales, devuelve
el valor que devuelva la comparación de la primera que sea distinta*/
int configuracionCompara( ConfiguracionAp * p_cap1, ConfiguracionAp * p_cap2) {
	/*TODO aqui no se puede hacer control de errores*/
	int cmp;
	if ((cmp = estadoCompara(p_cap1->estado, p_cap2->estado )) != 0)
		return cmp;
	/*TODO comparar pilas?*/
	/*else if ((cmp = ) != 0)
		return cmp;*/
	else
		return palabraCompara( p_cap1->cadena, p_cap2->cadena);

}