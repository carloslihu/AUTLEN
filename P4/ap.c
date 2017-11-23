
struct _transicion{
	char * nombre_simbolo_pila;
    char * nombre_estado_i;
    char * nombre_estado_f;
    char * nombre_simbolo_entrada;
    Palabra* accion;
} ;

struct _AP{
	char* nombre;/*nombre del automata*/
	int num_estados;
	int num_simbolos_entrada;
	int num_simbolos_pila;
	List * sigma;/*lista de palabras para el alfabeto de la entrada*/
	List * gamma;/*lista de palabras para el alfabeto de la pila*/
	List * estados;/*lista de los posibles estados del automata*/
	List * transiciones/*lista de transiciones*/
	Estado * estadoInicial;/*estado en el que comienza el automata*/
	Palabra * cadenaEntrada; /*lista de palabras que componen la cadena de entrada*/
	ConfiguracionApnd * situaciones;/*lista de configuraciones actuales del automata*/
	//Transicion * transicion;
	//quiza algo para transicones lambda
};

/**
 * @brief
*/
AP * APNuevo( char * nombre, int num_estados, int num_simbolos_entrada, int num_simbolos_pila ){

}

void APElimina(AP * p_ap){ }
void APImprime(FILE * fd, AP* p_ap){ }
/**
 * @brief inserta un simbolo (que es un string) en el alfabeto de la entrada, que es una lista de PALABRAS
*/
AP * APInsertaSimboloAlfabetoEntrada(AP * p_ap, char * simbolo){ }
AP * APInsertaSimboloAlfabetoPila(AP * p_ap, char * simbolo){ }
AP * APInsertaEstado(AP  * p_ap, char * nombre, int tipo){ }

AP * APInsertaLTransicion(AP * p_ap,
                          char * nombre_estado_i,
                          char * nombre_estado_f ){ }

AP * APInsertaTransicion(AP * p_ap,
                         char * nombre_simbolo_pila,
                         char * nombre_estado_i,
                         char * nombre_estado_f,
                         char * nombre_simbolo_entrada,
                         Palabra * accion){ }

/**
 * @brief insertar una letra en la cadena de entrada. La cadena de entrada es una lista de PALABRAS, donde letra (que es un string) es un simbolo de esta cadena de entrada
 */
AP * APInsertaLetra(AP * p_ap, char * letra){ }
/**
 * @brief calcula las relaciones instantaneas. al iniciar el automata, genera transiciones instantaneas que son composicion de otras transiciones instantaneas
 */
AP * APCierraLTransicion (AP * p_ap){ }
/**
 * genera la configuracion_apnd que contiene el estado inicial y los estados a los que se puede llegar mediante el inicial a traves de transiciones instantaneas
 */
AP * APInicializaEstado (AP * p_ap){ }
/**
 * un paso del procesamiento de la entrada: según una transicion posible de hacer y a partir de una configuracion_ap, una entrada y una pila,
 * genera nuevas configuracion_ap consumiendo simbolo de entrada, modificando la pila y cambiando el estado de la nueva con respecto de la antigua
 * (todas las modificaciones se reflejan en la nueva configuracion y no en la configuracion antigua)
 * a partir de una configuracion A, crea una copia B y en esta B realiza las modificaciones que haría el automata si hiciera esa transicion
 */
int APTransita(AP * p_ap){ }
/**
 * recorre la lista de configuraciones_ap (situaciones) y para cada una de ellas, llama a APTransita. si alcanza un estado final con la entrada vacia, termina.
 * Si consume toda la cadena de entrada y no esta en un estado final, termina con error.
 */
int APProcesaEntrada(FILE *fd, AP * p_ap){ }
