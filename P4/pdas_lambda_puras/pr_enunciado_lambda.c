#include <stdio.h>
#include "palabra.h"
#include "ap.h"

int main(int argc, char ** argv)
{
	AP * ap;
	int i;
	Palabra * accion;

/* CREACIÓN DEL AUTÓMATA */
	 
	/*ESTADOS ENTRADA PILA */
	ap = APNuevo("enunciado",7,2,3);

	/* SE INSERTAN ALFABETOS DE ENTRADA, PILA Y ESTADOS */
	
	APInsertaSimboloAlfabetoEntrada(ap, "0");
	APInsertaSimboloAlfabetoEntrada(ap, "1");
	APInsertaSimboloAlfabetoPila(ap, "0");
	APInsertaSimboloAlfabetoPila(ap, "1");
	APInsertaSimboloAlfabetoPila(ap, SIMBOLO_INICIO_PILA);
	APInsertaEstado(ap,"q0",INICIAL);
	APInsertaEstado(ap,"q1.1",NORMAL);
	APInsertaEstado(ap,"q1.2",NORMAL);
	APInsertaEstado(ap,"q2.1",NORMAL);
	APInsertaEstado(ap,"q2.2",NORMAL);
	APInsertaEstado(ap,"q1.3",FINAL);
	APInsertaEstado(ap,"q2.3",FINAL);



/* INICIO DEL AUTÓMATA QUE RECONOCE 0N1N O 1N0N CON TRANSICIONES LAMBDA PURAS A LOS ESTADOS INICIALES DE LOS OTROS DOS*/

	/* SE INSERTAN TRANSICIONES LAMBDA PURAS */
	APInsertaLTransicion(ap,"q0","q1.1");
	APInsertaLTransicion(ap,"q0","q2.1");

/* INICIO DEL AUTÓMATA QUE RECONOCE 0N1N */

	/* SE INSERTAN TRANSICIONES QUE MODIFICAN ENTRADA O PILA*/
	
	/* cima pila:Z estadoi: q1.1 estadof: q1.1 entrada: 0 pila: 0Z */ 
	accion= palabraNueva();
	palabraInsertaLetra(accion,"0");
	palabraInsertaLetra(accion,SIMBOLO_INICIO_PILA);
	APInsertaTransicion(ap, SIMBOLO_INICIO_PILA,"q1.1","q1.1","0",accion); 
	palabraElimina(accion);

	
	/* cima pila:0 estadoi: q1.1 estadof: q1.1 entrada: 0 pila: 00 */ 
	accion= palabraNueva();
	palabraInsertaLetra(accion,"0");
	palabraInsertaLetra(accion,"0");
	APInsertaTransicion(ap, "0","q1.1","q1.1","0",accion); 
	palabraElimina(accion);

	
	/* cima pila:0 estadoi: q1.1 estadof: q1.2 entrada: 1 pila: lambda */ 
	APInsertaTransicion(ap, "0","q1.1","q1.2","1",NULL); 

	
	/* cima pila:0 estadoi: q1.2 estadof: q1.2 entrada: 1 pila: lambda */ 
	APInsertaTransicion(ap, "0","q1.2","q1.2","1",NULL); 
	
	/* cima pila:Z estadoi: q1.2 estadof: q1.3 entrada: lambda pila: lambda */ 
	APInsertaTransicion(ap, SIMBOLO_INICIO_PILA,"q1.2","q1.3",NULL,NULL); 


/* INICIO DEL AUTÓMATA QUE RECONOCE 1N0N */

	/* SE INSERTAN TRANSICIONES QUE MODIFICAN ENTRADA O PILA*/
	
	/* cima pila:Z estadoi: q2.1 estadof: q2.1 entrada: 1 pila: 1Z */ 
	accion= palabraNueva();
	palabraInsertaLetra(accion,"1");
	palabraInsertaLetra(accion,SIMBOLO_INICIO_PILA);
	APInsertaTransicion(ap, SIMBOLO_INICIO_PILA,"q2.1","q2.1","1",accion); 
	palabraElimina(accion);

	
	/* cima pila:1 estadoi: q2.1 estadof: q2.1 entrada: 1 pila: 11 */ 
	accion= palabraNueva();
	palabraInsertaLetra(accion,"1");
	palabraInsertaLetra(accion,"1");
	APInsertaTransicion(ap, "1","q2.1","q2.1","1",accion); 
	palabraElimina(accion);

	
	/* cima pila:1 estadoi: q2.1 estadof: q2.2 entrada: 0 pila: lambda */ 
	APInsertaTransicion(ap, "1","q2.1","q2.2","0",NULL); 

	
	/* cima pila:1 estadoi: q2.2 estadof: q2.2 entrada: 0 pila: lambda */ 
	APInsertaTransicion(ap, "1","q2.2","q2.2","0",NULL); 
	
	/* cima pila:Z estadoi: q2.2 estadof: q2.3 entrada: lambda pila: lambda */ 
	APInsertaTransicion(ap, SIMBOLO_INICIO_PILA,"q2.2","q2.3",NULL,NULL); 



/* PROCESO DE LA PRIMERA PALABRA 000111: RECONOCIDA */


	/* SE INSETA LA PALABRA */
	
	APInsertaLetra(ap, "0");
	APInsertaLetra(ap, "0");
	APInsertaLetra(ap, "0");
	APInsertaLetra(ap, "1");
	APInsertaLetra(ap, "1");
	APInsertaLetra(ap, "1");

	/* HAY QUE INICIALIZAR EL ESTADO DEL AUTÓMATA PARA EMPEZAR A PROCESAR */

	APInicializaEstado(ap);


	/* SE MUESTRA EL AUTOMATA */

        fprintf(stdout,"\n\n********************************** AUTÓMATA A PILA *****************************************\n\n");
	APImprime(stdout, ap);


        fprintf(stdout,"\n\n********************************** PROCESA CADENA  *****************************************\n\n");
 	APProcesaEntrada(stdout,ap); 


/* PROCESO DE LA SEGUNDA PALABRA abb: RECONOCIDA */


	/* PARA PROCESAR OTRA CADENA HAY QUE INICIALIZARLA */
	
	APInicializaCadena(ap);

	/* Y LUEGO INSERTARLA  1100 ACEPTADA*/

	APInsertaLetra(ap, "1");
	APInsertaLetra(ap, "1");
	APInsertaLetra(ap, "0");
	APInsertaLetra(ap, "0");


	APInicializaEstado(ap);

        fprintf(stdout,"\n\n********************************** PROCESA CADENA  *****************************************\n\n");
 	APProcesaEntrada(stdout,ap); 


/* PROCESO DE LA TERCERA PALABRA 0110: RECHAZADA */


	/* PARA PROCESAR OTRA CADENA HAY QUE INICIALIZARLA */
	
	APInicializaCadena(ap);

	/* Y LUEGO INSERTARLA */

	APInsertaLetra(ap, "0");
	APInsertaLetra(ap, "1");
	APInsertaLetra(ap, "1");
	APInsertaLetra(ap, "0");


	APInicializaEstado(ap);

        fprintf(stdout,"\n\n********************************** PROCESA CADENA  *****************************************\n\n");
 	APProcesaEntrada(stdout,ap); 

/* SE LIBERAN RECURSOS */



	APElimina( ap);

}
