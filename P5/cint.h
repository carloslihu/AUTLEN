#ifndef CINT_H
#define CINT_H
typedef struct _CInt CInt;
#include "basic_types.h"

CInt * CIntNuevo(int tam);
void CIntElimina(CInt* ci);
int CIntCompara(CInt*ci1, CInt*ci2);
void CIntImprime(FILE * fd, CInt * p_s);
CInt* CIntCopia(CInt*ci);
int CIntInserta(CInt*ci, int pos, int bit);
int CIntPosBit(CInt*ci, int pos);
void CIntInicializa(CInt*ci);
Bool CIntVacio(CInt*ci);
#endif 

