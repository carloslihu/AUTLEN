#include "transforma.h"

AFND * AFNDTransforma(AFND * afnd) {
    AFND * afd;
    char nombre_estado[50];
    int **ci;
    int num_estados, num_estados2, num_simbolos;
    int tipo;
    int i, j;
    int i_e1, i_s, i_e2;

    if (!afnd)
        return NULL;

    num_estados = pow(2, AFNDNumEstados(afnd));
    num_estados2 = AFNDNumEstados(afnd);
    num_simbolos = AFNDNumSimbolos(afnd);
    afd = AFNDNuevo("determinista", num_estados, num_simbolos);
    for (i_s = 0; i_s < num_simbolos; i_s++)
        AFNDInsertaSimbolo(afd, AFNDSimboloEn(afnd, i_s));

    /*free*/
    ci = (int**) calloc(num_estados, sizeof (int*));
    for (i = 0; i < num_estados; i++)
        ci[i] = (int*) calloc(num_estados2, sizeof (int));

    i_e1 = AFNDIndiceEstadoInicial(afnd);
    tipo = INICIAL;
    strcpy(nombre_estado, "");
    for (i_e2 = 0; i_e2 < num_estados2; i_e2++)
        if (AFNDCierreLTransicionIJ(afnd, i_e1, i_e2) == 1) {
            strcat(nombre_estado, AFNDNombreEstadoEn(afnd, i_e2));
            ci[0][i_e2] = 1;
            if (AFNDTipoEstadoEn(afnd, i_e2) == FINAL ||
                    AFNDTipoEstadoEn(afnd, i_e2) == INICIAL_Y_FINAL)
                tipo = INICIAL_Y_FINAL;
        }

    AFNDInsertaEstado(afd, nombre_estado, tipo);
    strcpy(nombre_estado, "");

    /*
        for (i_s = 0; i_s < num_simbolos; i_s++)
            for (i = 0; i < num_estados; i++)
                for (j = 0; j < num_estados2; j++)
                    if (ci[i][j] == 1) {
                    
                        //if (AFNDTransicionIndicesEstadoiSimboloEstadof(afnd, i_e1, i_s, i_e2) == 1)

                    }
     */
    return afd;

}