typedef struct _Palabra Palabra;

Palabra * palabraNueva();
/* Crea una palabra nueva */
void palabraElimina(Palabra * p_p);
/* Libera la memoria asociada con la palabra */
void palabraImprime(FILE * fd, Palabra * p_p);
/* Muestra por el FILE * la palabra */
Palabra * palabraInsertaLetra(Palabra * p_p, char * letra);
/* Inserta una letra (que es un string - char * - ) en la palabra proporcionada
como argumento (modificándola, por tanto) y devuelve la palabra resultante. Para
ello debe hacer una copia en memoria nueva para la nueva letra */
int palabraTamano(Palabra * p_p);
/* Devuelve la longitud de la palabra */
Palabra * palabraCopia (Palabra * p_p);
/* Hace en memoria nueva una copia de la palabra y la devuelve */
int palabraCompara( Palabra * p_p1, Palabra * p_p2);
/* Para comparar dos palabras, devuelve un valor negativo, cero o positivo en
función de que todas las letras de la misma posición y de izquierda a derecha
sean iguales. En el caso de que no lo sean, se devuelve el strcmp de la primera
pareja de letras que no sean iguales */