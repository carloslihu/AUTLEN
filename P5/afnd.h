#ifndef AFND_H
#define AFND_H

#include <stdio.h>

#define INICIAL 0
#define FINAL 1
#define INICIAL_Y_FINAL 2
#define NORMAL 3

typedef struct _AFND AFND;

/* FUNCIONES PARA CREAR/DESTRUIR */
AFND * AFNDNuevo(char * nombre, int num_estados, int num_simbolos);
void AFNDElimina(AFND * p_afnd);


/* FUNCIONES PARA INDICE <-> COSA */
int AFNDIndiceDeSimbolo(AFND * p_afnd, char * nombre);
int AFNDIndiceDeEstado(AFND * p_afnd, char * nombre);
char * AFNDNombreEstadoEn(AFND * p_afnd, int pos);
char * AFNDSimboloEn(AFND * p_afnd, int pos);
/* FUNCIONES PARA INDICE */
int AFNDIndiceEstadoInicial(AFND * p_afnd);
int AFNDIndicePrimerEstadoFinal(AFND * p_afnd);


/* FUNCIONES PARA INSERTAR */
AFND * AFNDInsertaSimbolo(AFND * p_afnd, char * simbolo);
AFND * AFNDInsertaEstado(AFND * p_afnd, char * nombre, int tipo);
AFND * AFNDInsertaTransicion(AFND * p_afnd, char * nombre_estado_i, char * nombre_simbolo_entrada, char * nombre_estado_f);
AFND * AFNDInsertaLTransicion(AFND * p_afnd, char * nombre_estado_i, char * nombre_estado_f);
AFND * AFNDInsertaLetra(AFND * p_afnd, char * letra);


/* FUNCIONES PARA PROCESAR CADENAS */
void AFNDTransita(AFND * p_afnd);
void AFNDProcesaEntrada(FILE * fd, AFND * p_afnd);


/* FUNCIONES PARA ANTES DE PROCESAR */
AFND * AFNDInicializaEstado(AFND * p_afnd);
AFND * AFNDInicializaCadenaActual(AFND * p_afnd);
AFND * AFNDCierraLTransicion(AFND * p_afnd);


/* FUNCIONES PARA SABER TRANSICIONES*/
/*Devuelve 1 si hay transición directa 
 * desde el estado de índice i_e1, con el símbolo de índice i_s, al estado de índice i_e2. 
 * Devuelve 0 si tal transición no existe.*/
int AFNDTransicionIndicesEstadoiSimboloEstadof(AFND * p_afnd, int i_e1, int i_s, int i_e2);
/*Devuelve 1 si se puede ir con transiciones lambda,
 *  desde el estado de índice i, hasta el estado de índice j. 
 * Devuelve 0 si tal transición no existe*/
int AFNDCierreLTransicionIJ(AFND * p_afnd, int i, int j);


/* FUNCIONES PARA OBTENER INFORMACIÓN DEL AUTÓMATA */
int AFNDNumSimbolos(AFND * p_afnd);
int AFNDNumEstados(AFND * p_afnd);
int AFNDTipoEstadoEn(AFND * p_afnd, int pos);


/* FUNCIONES PARA IMPRIMIR */
void AFNDImprime(FILE * fd, AFND* p_afnd);
void AFNDImprimeConjuntoEstadosActual(FILE * fd, AFND * p_afnd);
void AFNDImprimeCadenaActual(FILE *fd, AFND * p_afnd);
/* FUNCIONES PARA IMPRIMIR DIAGRAMA */
void AFNDADot(AFND * p_afnd);

/* NO ESTA EN LA DOCUMENTACION
int AFNDLTransicionIJ(AFND * p_afnd, int i, int j);
 */

/* FUNCIONES AÑADIDAS */

typedef struct _Estado Estado;
/* Reserva memoria nueva para el estado y para la cadena de su nombre, crea un
estado con las dos componentes que se le proporcionan como argumento */
Estado * estadoNuevo(char * nombre, int tipo);

/* Libera la memoria asociada con el estado */
void estadoElimina(Estado * p_s);

/* Muestra por el FILE * el estado */
void estadoImprime(FILE * fd, Estado * p_s);

/* Función de comparación de estados por nombre, devuelve 1 si el estado tiene el
nombre proporcionado */
int estadoEs(Estado * p_s, char * nombre);

/* Devuelve (un puntero) al nombre del estado */
char * estadoNombre(Estado * p_s);

/* Devuelve el tipo de estado */
int estadoTipo(Estado * p_s);

/* Se usa para comparar estados por su nombre y devuelve el strcmp de sus nombres
 */
int estadoCompara(Estado * p_s1, Estado * p_s2);

/* Se crea una copia en memoria nueva del estado proporcionado como argumento */
Estado * estado_copy(Estado * p_s);


typedef struct _Transicion Transicion;

Transicion*transicionNueva(char*estado_inicio,
        char*simbolo, char*estado_fin);
void transicionElimina(Transicion*p_s);
Transicion*transicionCopia(Transicion*p_s);
void transicionImprime(FILE*fd, Transicion*p_s);
int transicionCompara(Transicion*t1, Transicion*t2);
char*transicionInicio(Transicion*p_s);
char*transicionSimbolo(Transicion*p_s);
char*transicionFin(Transicion*p_s);

#endif
