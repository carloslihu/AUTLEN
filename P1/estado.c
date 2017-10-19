#include "estado.h"

/* Reserva memoria nueva para el estado y para la cadena de su nombre, crea un
estado con las dos componentes que se le proporcionan como argumento */
Estado * estadoNuevo( char * nombre, int tipo){}

/* Libera la memoria asociada con el estado */
void estadoElimina( Estado * p_s){}

/* Muestra por el FILE * el estado */
void estadoImprime( FILE * fd, Estado * p_s){}

/* Función de comparación de estados por nombre, devuelve 1 si el estado tiene el
nombre proporcionado */
int estadoEs(Estado * p_s, char * nombre){}

/* Devuelve (un puntero) al nombre del estado */
char * estadoNombre(Estado * p_s){}

/* Devuelve el tipo de estado */
int estadoTipo(Estado * p_s){}

/* Se usa para comparar estados por su nombre y devuelve el strcmp de sus nombres
*/
int estadoCompara(Estado * p_s1, Estado * p_s2){}

/* Se crea una copia en memoria nueva del estado proporcionado como argumento */
Estado * estado_copy(Estado * p_s){}
