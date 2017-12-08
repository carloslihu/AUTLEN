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

#endif
