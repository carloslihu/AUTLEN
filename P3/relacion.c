#include "relacion.h"

typedef struct {
    char *nombre;
    int num_elementos;
    int **inicial;
    int **cierre;
} _Relacion;

Relacion * relacionNueva(char * nombre, int num_elementos);

/*
Crea una nueva relación a la que se le da como nombre el proporcionado como argumento para un conjunto con el número de elementos que se prorpociona como argumento.
Debe reservar memoria propia para todas las componentes que decidas utilizar en la relación.
 */
void matrizImprime(FILE * fd, Relacion * p_r, int flag) {
    int i, j;
    for (i = 0; i < p_r->num_elementos; i++) {
        fprintf(fd, "\t\t[%d]\t", &i);
        for (j = 0; j < p_r->num_elementos; j++) {
            if (flag == 0)
                fprintf(fd, "%d\t", &p_r->cierre[i][j]);
            else
                fprintf(fd, "%d\t", &p_r->inicial[i][j]);
        }
    }
}

void relacionImprime(FILE * fd, Relacion * p_r) {
    int i, j;
    fprintf(fd, "%s={\n\t\t", p_r->nombre);
    for (i = 0; i < p_r->num_elementos; i++) {
        fprintf(fd, "[%d]\t", &i);
    }
    //fprintf(fd,"",);
    fprintf(fd, "\n\t\t\tCIERRE\n");
    matrizImprime(fd, p_r, 0);
    fprintf(fd, "\n");
    matrizImprime(fd, p_r, 1);
    fprintf(fd, "\n\t\t\tRELACION INICIAL i\n");
    matrizImprime(fd, p_r, 1);
    fprintf(fd, "\n}");
}



/*
Muestra por el FILE * la relación. Puedes suponer el formato de salida utilizado en los ejemplos.
 */
void relacionElimina(Relacion * p_r);
/*
Libera toda la memoria asociada con la relación.
 */
Relacion * relacionCopia(Relacion * p_r1);
/*
Genera en memoria nueva una copia de la relación proporcionada como argumento y la devuelve.
 */
Relacion * relacionInserta(Relacion * p_r, int i, int j);
/*
Modifica la relación proporcionada como argumento para que tenga constancia de que el elemento i está relacionado con el j. 
Se está suponiendo que los elementos están dispuestos en un orden precondebido y conocido por el usuario de la librería. 
Una vez modificada, la relación es también devuelta.
 */
int relacionTamano(Relacion * p_r);
/*
Devuelve el cardinal del conjunto sobre el que está definida la relación.
 */
Relacion * relacionCierreTransitivo(Relacion * p_r);
/*
Modifica la relación para conservar el ella su cierre transitivo. Devuelve la relación como retorno.
 */
int relacionIJ(Relacion * p_r, int i, int j);
/*
Devuelve 1 si el elemento i está relacionado originalmente con el j y 0 en caso contrario.
 */
int relacionCierreIJ(Relacion * p_r, int i, int j);
/*
Devuelve 1 si el elemento i está relacionado (en el cierre transitivo) con el j y 0 en el caso contrario.
 */
