#include "configuracion_ap.h"
/* Se crea una configuración reservando memoria nueva para ella y para copiar
todas las componentes que se proporcionan como argumento */
ConfiguracionAp * configuracionApNueva( Estado * estado, Stack * pila, Palabra *cadena){
	
}

/* Se libera toda la memoria asociada con la configuracion */
void configuracionApElimina( ConfiguracionAp * p_cap){
	
}

/* Se muestra por pantalla la configuración */
void configuracionApImprime( FILE * fd, ConfiguracionAp * p_cap){
	
}

/* Se devuelve una copia en memoria nueva de la configuración */
ConfiguracionAp * configuracionApCopia( ConfiguracionAp * p_cap){
	
}

/* Se utiliza para comparar dos configuraciones deterministas, devolviendo un
valor negativo, 0 o positivo en función de la comparación de sus componentes en
este orden: estados, pilas, cadenas. En el caso de que no sean iguales, devuelve
el valor que devuelva la comparación de la primera que sea distinta*/
int configuracionCompara( ConfiguracionAp * p_cap1, ConfiguracionAp * p_cap2){
	
}