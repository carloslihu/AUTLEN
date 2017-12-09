#include "cint.h"

struct _CInt {
    int tam;
    int* bits;
};

CInt * CIntNuevo(int tam) {
    CInt *ci;
    ci = (CInt*) malloc(sizeof (CInt));
    ci->tam = tam;
    ci->bits = (int*) calloc(tam, sizeof (int));
    return ci;
}

void CIntElimina(CInt* ci) {
    free(ci->bits);
    free(ci);
}

int CIntCompara(CInt*ci1, CInt*ci2) {
    int i;
    if (ci1->tam != ci2->tam)
        return -1;
    for (i = 0; i < ci1->tam; i++)
        if (ci1->bits[i] != ci2->bits[i])
            return -1;

    return 0;

}

void CIntImprime(FILE * fd, CInt * ci) {
    int i;
    fprintf(fd, "{ ");
    for (i = 0; i < ci->tam; i++)
        fprintf(fd, "%d ", ci->bits[i]);
    fprintf(fd, "}\n");
}

CInt*CIntCopia(CInt*ci) {
    CInt *ci2;
    int i;
    ci2 = (CInt*) malloc(sizeof (CInt));
    ci2->tam = ci->tam;
    ci2->bits = (int*) calloc(ci->tam, sizeof (int));
    for (i = 0; i < ci->tam; i++) {
        ci2->bits[i] = ci->bits[i];
    }
    return ci2;
}

int CIntInserta(CInt*ci, int pos, int bit) {
    if (pos >= ci->tam)
        return -1;
    ci->bits[pos] = bit;
    return 0;
}

int CIntPosBit(CInt*ci, int pos) {
    return ci->bits[pos];
}

void CIntInicializa(CInt*ci) {
    int i;
    for (i = 0; i < ci->tam; i++)
        ci->bits[i] = 0;
}

Bool CIntVacio(CInt*ci) {
    int i;
    for (i = 0; i < ci->tam; i++)
        if (ci->bits[i] == 1)
            return FALSE;
    return TRUE;
}