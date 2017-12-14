#include "afnd.h"
#include "transforma.h"

int main(int argc, char ** argv) {

    AFND * p_afnd;
    AFND * afd;


    p_afnd = AFNDNuevo("af3", 3, 2);
    AFNDInsertaSimbolo(p_afnd, "0");
    AFNDInsertaSimbolo(p_afnd, "1");

    AFNDInsertaEstado(p_afnd, "q0", INICIAL);
    AFNDInsertaEstado(p_afnd, "q1", NORMAL);
    AFNDInsertaEstado(p_afnd, "q2", FINAL);


    AFNDInsertaTransicion(p_afnd, "q0", "0", "q0");
    AFNDInsertaTransicion(p_afnd, "q0", "1", "q0");

    AFNDInsertaTransicion(p_afnd, "q0", "0", "q1");


    AFNDInsertaTransicion(p_afnd, "q1", "1", "q2");


    /*-----------------------------*/
    AFNDCierraLTransicion(p_afnd);
    AFNDADot(p_afnd);
    afd = AFNDTransforma(p_afnd);
    AFNDImprime(stdout, afd);
    AFNDADot(afd);

    AFNDElimina(afd);

    AFNDElimina(p_afnd);

    return 0;
}
