#ifndef CINT_H
#define CINT_H
typedef struct _CInt CInt;
#include "basic_types.h"
/* Inicializa la estructura */
CInt * CIntNuevo(int tam);

/* Libera la estructura */
void CIntElimina(CInt* ci);

/* Compara 2 elementos */
int CIntCompara(CInt*ci1, CInt*ci2);

/* Imprime el elemento */
void CIntImprime(FILE * fd, CInt * p_s);

/* Copia el elemento */
CInt* CIntCopia(CInt*ci);

/* Inserta en una posicion el bit deseado */
int CIntInserta(CInt*ci, int pos, int bit);

/* Devuelve de una posicion el bit deseado */
int CIntPosBit(CInt*ci, int pos);

/* Inicializa a 0s todos los bits */
void CIntInicializa(CInt*ci);

/* Si todos los bits estan a 0, se considera vacio */
Bool CIntVacio(CInt*ci);
#endif 

