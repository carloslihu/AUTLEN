#include <stdio.h>
#include "palabra.h"
#include "ap.h"

int main(int argc, char ** argv) {
    AP * ap;

    Palabra * accion;

    /* CREACIÓN DEL AUTÓMATA */

    /*ESTADOS ENTRADA PILA */
    ap = APNuevo("enunciado", 3, 2, 2);

    /* SE INSERTAN ALFABETOS DE ENTRADA, PILA Y ESTADOS */

    APInsertaSimboloAlfabetoEntrada(ap, "a");
    APInsertaSimboloAlfabetoEntrada(ap, "b");
    APInsertaSimboloAlfabetoPila(ap, "a");
    APInsertaSimboloAlfabetoPila(ap, SIMBOLO_INICIO_PILA);
    APInsertaEstado(ap, "q0", INICIAL);
    APInsertaEstado(ap, "q1", NORMAL);
    APInsertaEstado(ap, "q2", FINAL);




    /* SE INSERTAN TRANSICIONES QUE MODIFICAN ENTRADA O PILA*/

    /* cima pila:Z estadoi: q0 estadof: q0 entrada: a pila: aZ */
    accion = palabraNueva();
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, SIMBOLO_INICIO_PILA);
    APInsertaTransicion(ap, SIMBOLO_INICIO_PILA, "q0", "q0", "a", accion);
    palabraElimina(accion);


    /* cima pila:Z estadoi: q0 estadof: q0 entrada: a pila: aaZ */
    accion = palabraNueva();
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, SIMBOLO_INICIO_PILA);
    APInsertaTransicion(ap, SIMBOLO_INICIO_PILA, "q0", "q0", "a", accion);
    palabraElimina(accion);


    /* cima pila:Z estadoi: q0 estadof: q0 entrada: a pila: aaaZ */
    accion = palabraNueva();
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, SIMBOLO_INICIO_PILA);
    APInsertaTransicion(ap, SIMBOLO_INICIO_PILA, "q0", "q0", "a", accion);
    palabraElimina(accion);


    /* cima pila:a estadoi: q0 estadof: q0 entrada: a pila: aZ */
    accion = palabraNueva();
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    APInsertaTransicion(ap, "a", "q0", "q0", "a", accion);
    palabraElimina(accion);


    /* cima pila:a estadoi: q0 estadof: q0 entrada: a pila: aaZ */
    accion = palabraNueva();
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    APInsertaTransicion(ap, "a", "q0", "q0", "a", accion);
    palabraElimina(accion);


    /* cima pila:a estadoi: q0 estadof: q0 entrada: a pila: aaaZ */
    accion = palabraNueva();
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    palabraInsertaLetra(accion, "a");
    APInsertaTransicion(ap, "a", "q0", "q0", "a", accion);
    palabraElimina(accion);


    /* cima pila:a estadoi: q0 estadof: q1 entrada: b  pila: lambda (como NULL) */
    APInsertaTransicion(ap, "a", "q0", "q1", "b", NULL);


    /* cima pila:a estadoi: q1 estadof: q1 entrada: b  pila: lambda (como NULL) */
    APInsertaTransicion(ap, "a", "q1", "q1", "b", NULL);


    /* cima pila:lambda Z  estadoi: q1 estadof: q2 entrada: lmabda (como NULL)  pila: lambda (como NULL) */
    APInsertaTransicion(ap, "Z", "q1", "q2", NULL, NULL);



    /* SE INSERTAN TRANSICIONES LAMBDA PURAS */



    /* HAY QUE CERRAR LAS TRANSICIONES LAMBDA (NO HAY PERO HAY QUE HACERLO EN GENERAL) */
    APCierraLTransicion(ap);


    /* PROCESO DE LA PRIMERA PALABRA aaabbbbb: RECONOCIDA */


    /* SE INSETA LA PALABRA */

    APInsertaLetra(ap, "a");
    APInsertaLetra(ap, "a");
    APInsertaLetra(ap, "a");
    APInsertaLetra(ap, "b");
    APInsertaLetra(ap, "b");
    APInsertaLetra(ap, "b");
    APInsertaLetra(ap, "b");
    APInsertaLetra(ap, "b");

    /* HAY QUE INICIALIZAR EL ESTADO DEL AUTÓMATA PARA EMPEZAR A PROCESAR */

    APInicializaEstado(ap);


    /* SE MUESTRA EL AUTOMATA */

    fprintf(stdout, "\n\n********************************** AUTÓMATA A PILA *****************************************\n\n");
    APImprime(stdout, ap);


    fprintf(stdout, "\n\n********************************** PROCESA CADENA  *****************************************\n\n");
    APProcesaEntrada(stdout, ap);


    /* PROCESO DE LA SEGUNDA PALABRA abb: RECONOCIDA */


    /* PARA PROCESAR OTRA CADENA HAY QUE INICIALIZARLA */

    APInicializaCadena(ap);

    /* Y LUEGO INSERTARLA */

    APInsertaLetra(ap, "a");
    APInsertaLetra(ap, "b");
    APInsertaLetra(ap, "b");


    APInicializaEstado(ap);

    fprintf(stdout, "\n\n********************************** PROCESA CADENA  *****************************************\n\n");
    APProcesaEntrada(stdout, ap);


    /* PROCESO DE LA TERCERA PALABRA abbbb: RECHAZADA */


    /* PARA PROCESAR OTRA CADENA HAY QUE INICIALIZARLA */

    APInicializaCadena(ap);

    /* Y LUEGO INSERTARLA */

    APInsertaLetra(ap, "a");
    APInsertaLetra(ap, "b");
    APInsertaLetra(ap, "b");
    APInsertaLetra(ap, "b");
    APInsertaLetra(ap, "b");


    APInicializaEstado(ap);

    fprintf(stdout, "\n\n********************************** PROCESA CADENA  *****************************************\n\n");
    APProcesaEntrada(stdout, ap);

    /* SE LIBERAN RECURSOS */



    APElimina(ap);
    return 0;
}
