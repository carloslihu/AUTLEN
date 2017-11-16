AP * APNuevo( char * nombre,
              int num_estados,
              int num_simbolos_entrada,
              int num_simbolos_pila ){ }

void APElimina(AP * p_ap){ }
void APImprime(FILE * fd, AP* p_ap){ }
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

AP * APInsertaLetra(AP * p_ap, char * letra){ }
AP * APCierraLTransicion (AP * p_ap){ }
AP * APInicializaEstado (AP * p_ap){ }
int APTransita(AP * p_ap){ }
int APProcesaEntrada(FILE *fd, AP * p_ap){ }
