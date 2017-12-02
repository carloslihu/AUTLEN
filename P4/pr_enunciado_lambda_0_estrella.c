#include <stdio.h>
#include "palabra.h"
#include "ap.h"

int main(int argc, char ** argv) {
    AP * ap;
    Palabra * accion;

    /* CREACIÓN DEL AUTÓMATA */

    /*ESTADOS ENTRADA PILA */
    ap = APNuevo("enunciado", 3, 1, 1);

    /* SE INSERTAN ALFABETOS DE ENTRADA, PILA Y ESTADOS */

    APInsertaSimboloAlfabetoEntrada(ap, "0");
    APInsertaSimboloAlfabetoPila(ap, SIMBOLO_INICIO_PILA);
    APInsertaEstado(ap, "q0", INICIAL);
    APInsertaEstado(ap, "q1", NORMAL);
    APInsertaEstado(ap, "q2", FINAL);



    /* INICIO DEL AUTÓMATA QUE RECONOCE 0N1N O 1N0N CON TRANSICIONES LAMBDA PURAS A LOS ESTADOS INICIALES DE LOS OTROS DOS*/

    /* SE INSERTAN TRANSICIONES LAMBDA PURAS */
    APInsertaLTransicion(ap, "q0", "q1");
    APInsertaLTransicion(ap, "q1", "q0");
    APInsertaLTransicion(ap, "q1", "q2");

    /* INICIO DEL AUTÓMATA QUE RECONOCE 0N1N */

    /* SE INSERTAN TRANSICIONES QUE MODIFICAN ENTRADA O PILA*/

    /* cima pila:Z estadoi: q0 estadof: q1 entrada: 0 pila: Z */
    accion = palabraNueva();
    palabraInsertaLetra(accion, SIMBOLO_INICIO_PILA);
    APInsertaTransicion(ap, SIMBOLO_INICIO_PILA, "q0", "q1", "0", accion);
    palabraElimina(accion);

    /* cima pila:Z estadoi: q1 estadof: q2 entrada: lambda pila: lambda */
    APInsertaTransicion(ap, SIMBOLO_INICIO_PILA, "q1", "q2", NULL, NULL);


    APCierraLTransicion(ap);


    /* PROCESO DE LA PRIMERA PALABRA 000: RECONOCIDA */


    /* SE INSETA LA PALABRA */

    APInsertaLetra(ap, "0");
    APInsertaLetra(ap, "0");
    APInsertaLetra(ap, "0");

    /* HAY QUE INICIALIZAR EL ESTADO DEL AUTÓMATA PARA EMPEZAR A PROCESAR */

    APInicializaEstado(ap);


    /* SE MUESTRA EL AUTOMATA */

    fprintf(stdout, "\n\n********************************** AUTÓMATA A PILA *****************************************\n\n");
    APImprime(stdout, ap);


    fprintf(stdout, "\n\n********************************** PROCESO DE CADENA ***************************************\n\n");
    APProcesaEntrada(stdout, ap);


    /* PROCESO DE LA SEGUNDA PALABRA 00: RECONOCIDA */


    /* PARA PROCESAR OTRA CADENA HAY QUE INICIALIZARLA */

    APInicializaCadena(ap);

    /* Y LUEGO INSERTARLA  00 ACEPTADA*/

    APInsertaLetra(ap, "0");
    APInsertaLetra(ap, "0");


    APInicializaEstado(ap);

    fprintf(stdout, "\n\n********************************** PROCESO DE CADENA ***************************************\n\n");
    APProcesaEntrada(stdout, ap);


    /* SE LIBERAN RECURSOS */



    APElimina(ap);
    return 0;
}
