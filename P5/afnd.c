#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "afnd.h"

/*typedef void(*destroy_element_function_type)(void*);
typedef void(*(*
        copy_element_function_type)(const void*));
typedef int(*
        print_element_function_type)(FILE*, const void*);
typedef int(*
        cmp_element_function_type)(const void*, const void*);

typedef enum {
    ERROR = 0, OK = 1
}
Status;

typedef enum {
    FALSE = 0, TRUE = 1
} Bool;
typedef struct _List List;
List*
list_ini(destroy_element_function_type f1, copy_element_function_type f2,
        print_element_function_type f3, cmp_element_function_type f4);
void list_destroy
(List*list);
List*list_insertFirst(List*list, const void*elem);
List*
list_insertLast(List*list, const void*elem);
List*list_insertInOrder(List*list,
        const void*pElem);
void*list_extractFirst(List*list);
void*list_extractLast(List
        *list);
Bool list_isEmpty(const List*list);
const void*list_get(const List*list,
        int i);
int list_size(const List*list);
int list_print(FILE*fd, const List*list);
int list_belongs(const List*list, void*p_elem);*/

int print_p_string(FILE*fd, const
        void*p_c);
void*copy_p_string(const void*p_c);
void destroy_p_string(void*p_c);
int cmp_p_string(const void*p_c1, const void*p_c2);

typedef struct _Relacion
Relacion;
Relacion*relacionNueva(char*nombre, int num_elementos);
void
relacionImprime(FILE*fd, Relacion*p_r);
void relacionElimina(Relacion*p_r);
Relacion*relacionCopia(Relacion*p_r1);
Relacion*relacionInserta(Relacion*p_r,
        int i, int j);
int relacionUnPasoMas(Relacion*p_r);
int relacionTamano(Relacion*
        p_r);
Relacion*relacionCierreReflexivo(Relacion*p_r);
Relacion*
relacionCierreTransitivo(Relacion*p_r);
int relacionIJ(Relacion*p_r, int i, int j
        );
int relacionCierreIJ(Relacion*p_r, int i, int j);
typedef struct _Palabra
Palabra;
Palabra*palabraNueva();
void palabraElimina(Palabra*p_p);
void
palabraImprime(FILE*fd, Palabra*p_p);
Palabra*palabraInsertaLetra(Palabra*p_p,
        char*letra);
char*palabraQuitaInicio(Palabra*p_p);
int palabraTamano(Palabra*p_p
        );
/*typedef struct _Estado Estado;*/
Estado*estadoNuevo(char*nombre, int tipo);
void
estadoElimina(Estado*p_s);
void estadoImprime(FILE*fd, Estado*p_s);
int estadoEs(
        Estado*p_s, char*nombre);
char*estadoNombre(Estado*p_s);
int estadoTipo(Estado*
        p_s);
Estado*estado_copy(Estado*p_s);
int estadoCompara(Estado*p_s1, Estado*p_s2)
;
void estadoADot(FILE*fd, Estado*p_s);
typedef struct _Alfabeto Alfabeto;
Alfabeto*alfabetoNuevo(char*nombre, int tamano);
void alfabetoElimina(Alfabeto*
        p_alfabeto);
Alfabeto*alfabetoInsertaSimbolo(Alfabeto*p_alfabeto, char*simbolo);
void alfabetoImprime(FILE*fd, Alfabeto*p_alf);
char*alfabetoSimboloEn(Alfabeto*
        p_alf, int i);
int alfabetoIndiceDeSimbolo(Alfabeto*p_alf, char*simbolo);
int
alfabetoTamano(Alfabeto*p_alf);
Alfabeto*alfabetoUne(Alfabeto*p_a1, Alfabeto*
        p_a2);
typedef int*VectorIndices;
void VectorIndicesImprime(FILE*fd,
        VectorIndices vi, int tamano);
int VectorIndicesVacio(VectorIndices vi, int
        tamano);
VectorIndices AFNDTransicion(AFND*p_afnd, char*nombre_estado, char*
        nombre_simbolo);
VectorIndices AFNDTransicionDesdeIndices(AFND*p_afnd, int
        indice_estado, int indice_simbolo);
AFND*AFNDAAFND1O(AFND*p_afnd);
AFND*AFNDCopia
(AFND*p_afnd);
Estado*AFNDEstadoEn(AFND*p_afnd, int pos);
Estado*
AFNDEstadoDeNombre(AFND*p_afnd, char*nombre);
int AFNDIndicePrimerEstadoFinal(
        AFND*p_afnd);
AFND*AFND1OInsertaEstadosTransicionesAFND(AFND*p_afnd_destino,
        AFND*p_afnd_origen, char*prefijo_estados, int offset_estados);
AFND*
AFND1OInsertaSimbolosAFND(AFND*p_afnd_destino, AFND*p_afnd_origen);
AFND*
AFND1OUneLTransicion(AFND*p_afnd_destino, AFND*p_afnd_origen, char*
        nombre_nuevo_estado_inicial, char*nombre_nuevo_estado_final, int offset_estados)
;
AFND*AFND1OUne(AFND*p_afnd1O_1, AFND*p_afnd1O_2);
AFND*AFND1OConcatena(AFND*
        p_afnd_origen1, AFND*p_afnd_origen2);
AFND*AFND1OEstrella(AFND*p_afnd_origen);
AFND*AFND1ODeSimbolo(char*simbolo);
AFND*AFND1ODeLambda();
AFND*AFND1ODeVacio();

struct _Transicion {
    char*estado_inicio;
    char*simbolo;
    char*estado_fin;
};
/*typedef
struct _Transicion Transicion;*/

Transicion*transicionNueva(char*estado_inicio,
        char*simbolo, char*estado_fin) {
    Transicion*aux_return;
    aux_return = (Transicion*)
            malloc(sizeof (Transicion));
    aux_return->estado_inicio = copy_p_string(
            estado_inicio);
    aux_return->simbolo = copy_p_string(simbolo);
    aux_return->
            estado_fin = copy_p_string(estado_fin);
    return aux_return;
}

char*transicionInicio(
        Transicion*p_s) {
    {
        if (!(p_s == NULL))goto l_1;
        return NULL;
l_1:
        ;
    }
    return p_s->
            estado_inicio;
}

char*transicionSimbolo(Transicion*p_s) {
    {
        if (!(p_s == NULL))goto
            l_2;
        return NULL;
l_2:
        ;
    }
    return p_s->simbolo;
}

char*transicionFin(Transicion*p_s) {
    {
        if (!(p_s == NULL))goto l_3;
        return NULL;
l_3:
        ;
    }
    return p_s->estado_fin;
}

void
transicionElimina(Transicion*p_s) {
    {
        if (!(p_s != NULL))goto l_4;
        {
            {
                if (!(p_s->
                        estado_inicio != NULL))goto l_5;
                {
                    free(p_s->estado_inicio);
                    p_s->estado_inicio =
                            NULL;
                }
l_5:
                ;
            }
            {
                if (!(p_s->simbolo != NULL))goto l_6;
                {
                    free(p_s->simbolo);
                    p_s->
                            simbolo = NULL;
                }
l_6:
                ;
            }
            {
                if (!(p_s->estado_fin != NULL))goto l_7;
                {
                    free(p_s->
                            estado_fin);
                    p_s->estado_fin = NULL;
                }
l_7:
                ;
            }
            free(p_s);
        }
l_4:
        ;
    }
}

Transicion*
transicionCopia(Transicion*p_s) {
    Transicion*aux_return;
    aux_return =
            transicionNueva(transicionInicio(p_s), transicionSimbolo(p_s), transicionFin(p_s
            ));
    return aux_return;
}

void transicionImprime(FILE*fd, Transicion*p_s) {
    fprintf(
            fd, "Estado Inicial: %s\n", p_s->estado_inicio);
    fprintf(fd, "Simbolo: %s\n", p_s->
            simbolo);
    fprintf(fd, "Estado final: %s\n", p_s->estado_fin);
    return;
}

int
transicionCompara(Transicion*t1, Transicion*t2) {
    int igual_estado_ini,
            igual_simbolo, igual_estado_fin;
    igual_estado_ini = strcmp(t1->estado_inicio, t2->
            estado_inicio);
    igual_simbolo = strcmp(t1->simbolo, t2->simbolo);
    igual_estado_fin =
            strcmp(t1->estado_fin, t2->estado_fin);
    {
        if (!(igual_estado_ini == 0))goto l_8;
        {
            {
                if
                    (!(igual_simbolo == 0))goto l_9;
                {
                    return igual_estado_fin;
                }
                goto l_10;
l_9:
                ;
                return
                igual_simbolo;
l_10:
                ;
            }
        }
        goto l_11;
l_8:
        ;
        return igual_estado_ini;
l_11:
        ;
    }
}

VectorIndices VectorIndicesNuevo(int tamano) {
    VectorIndices vi;
    int i;
    vi = (int*)
            malloc(sizeof (int) * tamano);
    {
        i = 0;
l_12:
        if (!(i < tamano))goto l_14;
        goto l_15;
l_13:
        i
                ++;
        goto l_12;
l_15:
        vi[i] = 0;
        goto l_13;
l_14:
        ;
    }
    return vi;
}

VectorIndices
VectorIndicesListaNuevo(int tamano) {
    VectorIndices result = VectorIndicesNuevo(
            tamano + 1);
    result[tamano] = 2;
    return result;
}

VectorIndices VectorIndicesCopia(
        VectorIndices v1) {
    int i;
    VectorIndices copia;
    int tamano;
    tamano = sizeof (v1) /
            sizeof (v1[0]);
    copia = VectorIndicesNuevo(tamano);
    {
        i = 0;
l_16:
        if (!(v1[i] != 0))goto
            l_18;
        goto l_19;
l_17:
        i++;
        goto l_16;
l_19:
        {
            {
                if (!(v1[i] == 1))goto l_20;
                {
                    copia[i] = 1;
                }
l_20:
                ;
            }} goto l_17;
l_18:
        ;
    }
    return copia;
}

int VectorIndicesTamanoLista(
        VectorIndices v) {
    int i;
    int tamano;
    tamano = 0;
    {
        i = 0;
l_21:
        if (!(v[i] < 2))goto l_23;
        goto l_24;
l_22:
        i++;
        goto l_21;
l_24:
        {tamano++;} goto l_22;
l_23:
        ;
    }
    return tamano;
}

void*VectorIndicesCopiaLista(VectorIndices v1) {
    int i;
    int tamano;
    VectorIndices
    copia;
    tamano = VectorIndicesTamanoLista(v1);
    fprintf(stdout,
            "==========> TAMANO %d\n", tamano);
    copia = VectorIndicesListaNuevo(tamano);
    {
        i = 0;
l_25:
        if (!(v1[i] < 2))goto l_27;
        goto l_28;
l_26:
        i++;
        goto l_25;
l_28:
        {
            copia[i] = v1[i]
            ;} goto l_26;
l_27:
        ;
    }
    return copia;
}

int VectorIndicesListaCompara(const int*v1,
        const int*v2) {
    int i;
    {
        i = 0;
l_29:
        if (!(v1[i] < 2 || v2[i] < 2))goto l_31;
        goto l_32;
l_30:
        i++;
        goto l_29;
l_32:
        {
            {if (!(v1[i] != v2[i]))goto l_33;
                {return 1;}
l_33:
                ;}} goto l_30
                ;
l_31:
        ;
    }
    return 0;
}

void VectorIndicesElimina(VectorIndices vi) {
    {
        if (!(vi == NULL))
            goto l_34;
        return;
l_34:
        ;
    }
    free(vi);
}

int VectorIndicesImprimeLista(FILE*fd,
        VectorIndices v1) {
    int i;
    {
        i = 0;
l_35:
        if (!(v1[i] < 2))goto l_37;
        goto l_38;
l_36:
        i++;
        goto l_35;
l_38:
        {fprintf(fd, "%d\n", v1[i]);} goto l_36;
l_37:
        ;
    }
    return 0;
}

void
VectorIndicesImprime(FILE*fd, VectorIndices vi, int tamano) {
    int i;
    {
        i = 0;
l_39:
        if (!
                (i < tamano))goto l_41;
        goto l_42;
l_40:
        i++;
        goto l_39;
l_42:
        {
            fprintf(fd, "%d", vi[i])
            ;} goto l_40;
l_41:
        ;
    }
    fprintf(fd, "\n");
}

int VectorIndicesVacio(VectorIndices vi,
        int tamano) {
    int i;
    {
        i = 0;
l_43:
        if (!(i < tamano))goto l_45;
        goto l_46;
l_44:
        i++;
        goto
        l_43;
l_46:
        {
            {if (!(vi[i] != 0))goto l_47;
                goto l_45;
l_47:
                ;}} goto l_44;
l_45:
        ;
    }
    return
    (i == tamano);
}

struct _AFND {
    char*nombre;
    Alfabeto*alfabeto;
    int num_estados;
    int
    num_simbolos;
    Estado**estados;
    int**transicion_lambda;
    Relacion*ltransicion;
    VectorIndices**ftransicion;
    Palabra*cadena_actual;
    Palabra*cadena_procesada;
    VectorIndices conjunto_estados_actual;
    VectorIndices*traza;
};

AFND*AFNDNuevo(
        char*nombre, int num_estados, int num_simbolos) {
    AFND*p_afnd;
    int i;
    int j;
    p_afnd = (
            AFND*) malloc(sizeof (AFND));
    p_afnd->nombre = (char*) malloc(strlen(nombre) + 1);
    strcpy(p_afnd->nombre, nombre);
    p_afnd->alfabeto = alfabetoNuevo("A", num_simbolos)
            ;
    p_afnd->num_estados = num_estados;
    p_afnd->num_simbolos = num_simbolos;
    p_afnd->
            estados = (Estado**) malloc(sizeof (Estado*) * num_estados);
    {
        i = 0;
l_48:
        if (!(i <
                num_estados))goto l_50;
        goto l_51;
l_49:
        i++;
        goto l_48;
l_51:
        {
            p_afnd->estados[i] =
            NULL;} goto l_49;
l_50:
        ;
    }
    p_afnd->transicion_lambda = (int**) malloc(num_estados *
            sizeof (int*));
    {
        i = 0;
l_52:
        if (!(i < num_estados))goto l_54;
        goto l_55;
l_53:
        i++;
        goto
        l_52;
l_55:
        {
            p_afnd->transicion_lambda[i] = (int*) malloc(num_estados * sizeof (int));} goto l_53;
l_54:
        ;
    }
    {
        i = 0;
l_56:
        if (!(i < num_estados))goto l_58;
        goto l_59;
l_57:
        i++;
        goto l_56;
l_59:
        {
            {
                j = 0;
l_60:
                if (!(j < num_estados))goto l_62;
                goto l_63;
l_61:
                j++;
                goto l_60;
l_63:
                {p_afnd->transicion_lambda[i][j] = 0;} goto l_61;
l_62:
                ;
            }} goto l_57
                ;
l_58:
        ;
    }
    p_afnd->ltransicion = relacionNueva("RL", num_estados);
    p_afnd->
            ftransicion = (VectorIndices**) malloc(num_estados * sizeof (VectorIndices*));
    {
        i = 0;
l_64:
        if (!(i < num_estados))goto l_66;
        goto l_67;
l_65:
        i++;
        goto l_64;
l_67:
        {
            p_afnd->
            ftransicion[i] = (VectorIndices*) malloc(num_simbolos * sizeof (VectorIndices));}
        goto l_65;
l_66:
        ;
    }
    {
        i = 0;
l_68:
        if (!(i < num_estados))goto l_70;
        goto l_71;
l_69:
        i++;
        goto l_68;
l_71:
        {
            {
                j = 0;
l_72:
                if (!(j < num_simbolos))goto l_74;
                goto l_75;
l_73:
                j++;
                goto l_72;
l_75:
                {p_afnd->ftransicion[i][j] = VectorIndicesNuevo(num_estados);}
                goto l_73;
l_74:
                ;
            }} goto l_69;
l_70:
        ;
    }
    p_afnd->cadena_actual = palabraNueva();
    p_afnd
            ->cadena_procesada = NULL;
    p_afnd->conjunto_estados_actual = VectorIndicesNuevo(
            num_estados);
    p_afnd->traza = NULL;
    return p_afnd;
}

void AFNDImprime(FILE*fd, AFND*
        p_afnd) {
    int i, j, k;
    {
        if (!(p_afnd == NULL))goto l_76;
        return;
l_76:
        ;
    }
    {
        if (!(p_afnd->
                nombre != NULL))goto l_77;
        {
            fprintf(fd, "%s=", p_afnd->nombre);
        }
l_77:
        ;
    }
    fprintf(fd,
            "{");
    fprintf(fd, "\n\tnum_simbolos = %d\n", p_afnd->num_simbolos);
    {
        if (!(p_afnd->
                alfabeto != NULL))goto l_78;
        {
            fprintf(fd, "\n\t");
            alfabetoImprime(fd, p_afnd->
                    alfabeto);
        }
l_78:
        ;
    }
    fprintf(fd, "\n\tnum_estados = %d\n", p_afnd->num_estados);
    {
        if
            (!(p_afnd->estados != NULL))goto l_79;
        {
            fprintf(fd, "\n\tQ={");
            {
                i = 0;
l_80:
                if (!(i <
                        p_afnd->num_estados))goto l_82;
                goto l_83;
l_81:
                i++;
                goto l_80;
l_83:
                {
                    {
                        if (!(p_afnd
                                ->estados[i] != NULL))goto l_84;
                        estadoImprime(fd, p_afnd->estados[i]);
l_84:
                        ;
                    }
                    fprintf(fd, " ");} goto l_81;
l_82:
                ;
            }
            fprintf(fd, "}\n");
        }
l_79:
        ;
    }
    fprintf(fd, "\n\t")
            ;
    relacionImprime(fd, p_afnd->ltransicion);
    {
        if (!(p_afnd->ftransicion != NULL))goto
            l_85;
        {
            fprintf(fd, "\n");
            fprintf(fd, "\tFuncion de Transición = {\n");
            {
                i = 0;
l_86
                        :
                if (!(i < p_afnd->num_estados))goto l_88;
                goto l_89;
l_87:
                i++;
                goto l_86;
l_89:
                {
                    {
                        j = 0
                        ;
l_90:
                        if (!(j < p_afnd->num_simbolos))goto l_92;
                        goto l_93;
l_91:
                        j++;
                        goto l_90;
l_93
                        :
                        {
                            fprintf(fd, "\t\tf(%s,%s)={ ", AFNDNombreEstadoEn(p_afnd, i), AFNDSimboloEn(
                            p_afnd, j));
                            {
                                k = 0;
l_94:
                                if (!(k < p_afnd->num_estados))goto l_96;
                                goto l_97;
l_95:
                                k++;
                                goto l_94;
l_97:
                                {
                                    {
                                        if (!((p_afnd->ftransicion[i][j])[k] == 1))goto l_98;
                                        fprintf(fd,
                                        "%s ", AFNDNombreEstadoEn(p_afnd, k));
l_98:
                                        ;
                                    }} goto l_95;
l_96:
                                ;
                            }
                            fprintf(fd, "}\n")
                            ;} goto l_91;
l_92:
                        ;
                    }} goto l_87;
l_88:
                ;
            }
            fprintf(fd, "\t}\n");
        }
l_85:
        ;
    }
    fprintf(fd,
            "}\n");
}

int AFNDExisteEstado(AFND*p_afnd, char*nombre) {
    int i;
    {
        i = 0;
l_99:
        if (!(i <
                p_afnd->num_estados))goto l_101;
        goto l_102;
l_100:
        i++;
        goto l_99;
l_102:
        {
            {
                if (!(
                        p_afnd->estados[i] != NULL))goto l_103;
                {
                    {
                        if (!(strcmp(estadoNombre(p_afnd->
                                estados[i]), nombre) == 0))goto l_104;
                        {return 1;}
l_104:
                        ;
                    }
                }
l_103:
                ;
            }} goto l_100;
l_101:
        ;
    }
    return 0;
}

char*AFNDNombreEstadoEn(AFND*p_afnd, int pos) {
    {
        if (!(pos <
                p_afnd->num_estados))goto l_105;
        return estadoNombre(p_afnd->estados[pos]);
        goto
        l_106;
l_105:
        ;
        return NULL;
l_106:
        ;
    }
}

char*AFNDSimboloEn(AFND*p_afnd, int pos) {
    {
        if
            (!(pos < p_afnd->num_simbolos))goto l_107;
        return alfabetoSimboloEn(p_afnd->
                alfabeto, pos);
        goto l_108;
l_107:
        ;
        return NULL;
l_108:
        ;
    }
}

void AFNDElimina(AFND*
        p_afnd) {
    int i, j;
    {
        if (!(p_afnd == NULL))goto l_109;
        return;
l_109:
        ;
    }
    {
        if (!(p_afnd->
                nombre != NULL))goto l_110;
        {
            free(p_afnd->nombre);
            p_afnd->nombre = NULL;
        }
l_110:
        ;
    }
    {
        if (!(p_afnd->alfabeto != NULL))goto l_111;
        {
            alfabetoElimina(p_afnd->alfabeto);
            p_afnd->alfabeto = NULL;
        }
l_111:
        ;
    }
    {
        if (!(p_afnd->estados != NULL))goto l_112;
        {
            {
                i = 0;
l_113:
                if (!(i < p_afnd->num_estados))goto l_115;
                goto l_116;
l_114:
                i++;
                goto l_113;
l_116:
                {estadoElimina(p_afnd->estados[i]);} goto l_114;
l_115:
                ;
            }
            free(p_afnd->
                    estados);
            p_afnd->estados = NULL;
        }
l_112:
        ;
    }
    {
        if (!(p_afnd->transicion_lambda != NULL))
            goto l_117;
        {
            {
                i = 0;
l_118:
                if (!(i < p_afnd->num_estados))goto l_120;
                goto l_121;
l_119
                        :
                i++;
                goto l_118;
l_121:
                {free(p_afnd->transicion_lambda[i]);} goto l_119;
l_120:
                ;
            }
        }
l_117:
        ;
    }
    free(p_afnd->transicion_lambda);
    {
        if (!(p_afnd->ltransicion != NULL))goto
            l_122;
        relacionElimina(p_afnd->ltransicion);
l_122:
        ;
    }
    {
        if (!(p_afnd->ftransicion
                != NULL))goto l_123;
        {
            {
                i = 0;
l_124:
                if (!(i < p_afnd->num_estados))goto l_126;
                goto
                l_127;
l_125:
                i++;
                goto l_124;
l_127:
                {
                    {
                        j = 0;
l_128:
                        if (!(j < p_afnd->num_simbolos))goto
                            l_130;
                        goto l_131;
l_129:
                        j++;
                        goto l_128;
l_131:
                        {
                            VectorIndicesElimina(p_afnd->
                            ftransicion[i][j]);} goto l_129;
l_130:
                        ;
                    }
                    free(p_afnd->ftransicion[i]);} goto
                l_125;
l_126:
                ;
            }
        }
l_123:
        ;
    }
    free(p_afnd->ftransicion);
    {
        if (!(p_afnd->cadena_actual !=
                NULL))goto l_132;
        {
            palabraElimina(p_afnd->cadena_actual);
        }
l_132:
        ;
    }
    {
        if (!(p_afnd
                ->conjunto_estados_actual != NULL))goto l_133;
        {
            VectorIndicesElimina(p_afnd->
                    conjunto_estados_actual);
        }
l_133:
        ;
    }
    free(p_afnd);
}

int AFNDIndiceDeSimbolo(AFND*
        p_afnd, char*nombre) {
    return alfabetoIndiceDeSimbolo(p_afnd->alfabeto, nombre);
}

int AFNDIndiceDeEstado(AFND*p_afnd, char*nombre) {
    int i;
    {
        i = 0;
l_134:
        if (!(i < p_afnd
                ->num_estados))goto l_136;
        goto l_137;
l_135:
        i++;
        goto l_134;
l_137:
        {
            {
                if (!(
                        estadoEs(p_afnd->estados[i], nombre)))goto l_138;
                return i;
l_138:
                ;
            }} goto l_135;
l_136:
        ;
    }
    return -1;
}

VectorIndices AFNDTransicion(AFND*p_afnd, char*nombre_estado,
        char*nombre_simbolo) {
    return p_afnd->ftransicion[AFNDIndiceDeEstado(p_afnd,
            nombre_estado)][AFNDIndiceDeSimbolo(p_afnd, nombre_simbolo)];
}

VectorIndices
AFNDTransicionDesdeIndices(AFND*p_afnd, int indice_estado, int indice_simbolo) {
    return p_afnd->ftransicion[indice_estado][indice_simbolo];
}

AFND*
AFNDInsertaSimbolo(AFND*p_afnd, char*simbolo) {
    alfabetoInsertaSimbolo(p_afnd->
            alfabeto, simbolo);
    return p_afnd;
}

AFND*AFNDInsertaEstado(AFND*p_afnd, char*
        nombre, int tipo) {
    int i;
    {
        i = 0;
l_139:
        if (!(i < p_afnd->num_estados))goto l_141;
        goto
        l_142;
l_140:
        i++;
        goto l_139;
l_142:
        {
            {
                if (!(p_afnd->estados[i] == NULL))goto l_143;
                {
                    p_afnd->estados[i] = estadoNuevo(nombre, tipo);
                    goto l_141;
                }
l_143:
                ;
            }} goto l_140;
l_141:
        ;
    }
    {
        if (!((tipo == INICIAL) || (tipo == INICIAL_Y_FINAL)))goto l_144;
        {
            p_afnd->
                    conjunto_estados_actual[i] = 1;
        }
l_144:
        ;
    }
    return p_afnd;
}

AFND*
AFNDInsertaLTransicion(AFND*p_afnd, char*nombre_estado_i, char*nombre_estado_f) {
    int pos_qi, pos_qf;
    pos_qi = AFNDIndiceDeEstado(p_afnd, nombre_estado_i);
    pos_qf =
            AFNDIndiceDeEstado(p_afnd, nombre_estado_f);
    relacionInserta(p_afnd->ltransicion
            , pos_qi, pos_qf);
    return p_afnd;
}

AFND*AFNDInsertaTransicion(AFND*p_afnd, char*
        nombre_estado_i, char*nombre_simbolo_entrada, char*nombre_estado_f) {
    int pos_qi,
            pos_qf, pos_simbolo;
    pos_qi = AFNDIndiceDeEstado(p_afnd, nombre_estado_i);
    pos_qf =
            AFNDIndiceDeEstado(p_afnd, nombre_estado_f);
    pos_simbolo = AFNDIndiceDeSimbolo(
            p_afnd, nombre_simbolo_entrada);
    (p_afnd->ftransicion[pos_qi][pos_simbolo])[
            pos_qf] = 1;
    return p_afnd;
}

AFND*AFNDInsertaLetra(AFND*p_afnd, char*letra) {
    palabraInsertaLetra(p_afnd->cadena_actual, letra);
    return p_afnd;
}

void
AFNDImprimeConjuntoEstadosActual(FILE*fd, AFND*p_afnd) {
    int i;
    {
        if (!(p_afnd->
                conjunto_estados_actual != NULL))goto l_145;
        {
            fprintf(fd, "\nACTUALMENTE EN {");
            {
                i
                        = 0;
l_146:
                if (!(i < p_afnd->num_estados))goto l_148;
                goto l_149;
l_147:
                i++;
                goto
                l_146;
l_149:
                {
                    {
                        if (!(p_afnd->conjunto_estados_actual[i] == 1))goto l_150;
                        {
                            estadoImprime(fd, p_afnd->estados[i]);
                        }
l_150:
                        ;
                    }} goto l_147;
l_148:
                ;
            }
            fprintf(fd,
                    "}\n");
        }
l_145:
        ;
    }
}

void AFNDImprimeCadenaActual(FILE*fd, AFND*p_afnd) {
    palabraImprime(fd, p_afnd->cadena_actual);
}

void AFNDTransita(AFND*p_afnd) {
    char*
    letra_actual;
    int pos_letra_actual;
    int i;
    int j;
    int k;
    VectorIndices
    conjunto_estados_transicion;
    VectorIndices conjunto_estados_siguiente;
    {
        if (!(
                p_afnd == NULL))goto l_151;
        return;
l_151:
        ;
    }
    {
        if (!(palabraTamano(p_afnd->
                cadena_actual) == 0))goto l_152;
        return;
l_152:
        ;
    }
    conjunto_estados_siguiente =
            VectorIndicesNuevo(p_afnd->num_estados);
    letra_actual = palabraQuitaInicio(p_afnd
            ->cadena_actual);
    pos_letra_actual = AFNDIndiceDeSimbolo(p_afnd, letra_actual);
    {
        i =
                0;
l_153:
        if (!(i < p_afnd->num_estados))goto l_155;
        goto l_156;
l_154:
        i++;
        goto l_153
                ;
l_156:
        {
            {
                if (!(p_afnd->conjunto_estados_actual[i] == 1))goto l_157;
                {
                    conjunto_estados_transicion = AFNDTransicionDesdeIndices(p_afnd, i,
                    pos_letra_actual);
                    {
                        j = 0;
l_158:
                        if (!(j < p_afnd->num_estados))goto l_160;
                        goto l_161
                        ;
l_159:
                        j++;
                        goto l_158;
l_161:
                        {
                            {
                                if (!(conjunto_estados_transicion[j] == 1))goto
                                    l_162;
                                {
                                    conjunto_estados_siguiente[j] = 1;
                                    {
                                        k = 0;
l_163:
                                        if (!(k < p_afnd->num_estados))
                                            goto l_165;
                                        goto l_166;
l_164:
                                        k++;
                                        goto l_163;
l_166:
                                        {
                                            {
                                                if (!(
                                                        AFNDCierreLTransicionIJ(p_afnd, j, k)))goto l_167;
                                                {
                                                    conjunto_estados_siguiente[k]
                                                    = 1;
                                                }
l_167:
                                                ;
                                            }} goto l_164;
l_165:
                                        ;
                                    }
                                }
l_162:
                                ;
                            }} goto l_159;
l_160:
                        ;
                    }
                }
l_157:
                ;
            }} goto
        l_154;
l_155:
        ;
    }
    {
        i = 0;
l_168:
        if (!(i < p_afnd->num_estados))goto l_170;
        goto l_171;
l_169:
        i++;
        goto l_168;
l_171:
        {} goto l_169;
l_170:
        ;
    }
    VectorIndicesElimina(p_afnd->
            conjunto_estados_actual);
    p_afnd->conjunto_estados_actual =
            conjunto_estados_siguiente;
    free(letra_actual);
}

int cmp_estado(const char*p_c1,
        const char*p_c2) {
    fprintf(stdout, "ESTADO 1: %s\n", (char*) p_c1);
    fprintf(stdout,
            "ESTADO 2: %s\n", p_c2);
    return strcmp((char*) p_c1, (char*) p_c2);
}

void
doublePointer_destroy(char**p_s, int size) {
    int i;
    {
        if (!(p_s == NULL))goto l_172;
        return;
        goto l_173;
l_172:
        ;
        {
            {
                i = 0;
l_174:
                if (!(i < size))goto l_176;
                goto l_177;
l_175:
                i++;
                goto l_174;
l_177:
                {free(p_s[i]);} goto l_175;
l_176:
                ;
            }
        }
l_173:
        ;
    }
    free(p_s);
    return;
}

void AFNDProcesaEntrada(FILE*fd, AFND*p_afnd) {
    AFNDImprimeConjuntoEstadosActual(fd, p_afnd);
    AFNDImprimeCadenaActual(fd, p_afnd)
            ;
    {
l_178:
        if (!((palabraTamano(p_afnd->cadena_actual) > 0) && !VectorIndicesVacio(
                p_afnd->conjunto_estados_actual, p_afnd->num_estados)))goto l_179;
        {
            AFNDTransita
                    (p_afnd);
            AFNDImprimeConjuntoEstadosActual(fd, p_afnd);
            AFNDImprimeCadenaActual(
                    fd, p_afnd);
        }
        goto l_178;
l_179:
        ;
    }
}

int AFNDIndiceEstadoInicial(AFND*p_afnd) {
    int i
            ;
    {
        i = 0;
l_180:
        if (!(i < p_afnd->num_estados))goto l_182;
        goto l_183;
l_181:
        i++;
        goto
        l_180;
l_183:
        {
            {
                if (!((estadoTipo(p_afnd->estados[i]) == INICIAL) || (estadoTipo(
                        p_afnd->estados[i]) == INICIAL_Y_FINAL)))goto l_184;
                return i;
l_184:
                ;
            }} goto l_181
                ;
l_182:
        ;
    }
    return -1;
}

AFND*AFNDInicializaCadenaActual(AFND*p_afnd) {
    {
        if (!(p_afnd !=
                NULL))goto l_185;
        {
            palabraElimina(p_afnd->cadena_actual);
            p_afnd->cadena_actual =
                    palabraNueva();
        }
l_185:
        ;
    }
    return p_afnd;
}

AFND*AFNDInicializaEstado(AFND*p_afnd) {
    int ind_ei;
    int i;
    ind_ei = AFNDIndiceEstadoInicial(p_afnd);
    {
        i = 0;
l_186:
        if (!(i <
                p_afnd->num_estados))goto l_188;
        goto l_189;
l_187:
        i++;
        goto l_186;
l_189:
        {
            {
                if (!(i
                        == ind_ei))goto l_190;
                p_afnd->conjunto_estados_actual[i] = 1;
                goto l_191;
l_190:
                ;
                p_afnd->conjunto_estados_actual[i] = 0;
l_191:
                ;
            }} goto l_187;
l_188:
        ;
    }
    {
        i = 0;
l_192:
        if
            (!(i < p_afnd->num_estados))goto l_194;
        goto l_195;
l_193:
        i++;
        goto l_192;
l_195:
        {
            {
                if (!(AFNDCierreLTransicionIJ(p_afnd, ind_ei, i)))goto l_196;
                p_afnd->
                conjunto_estados_actual[i] = 1;
l_196:
                ;
            }} goto l_193;
l_194:
        ;
    }
    return p_afnd;
}

AFND*
AFNDCierraLTransicion(AFND*p_afnd) {
    {
        if (!(p_afnd != NULL))goto l_197;
        {
            relacionCierreReflexivo(relacionCierreTransitivo(p_afnd->ltransicion));
        }
l_197:
        ;
    }
    return p_afnd;
}

int AFNDLTransicionIJ(AFND*p_afnd, int i, int j) {
    return
    relacionIJ(p_afnd->ltransicion, i, j);
}

int AFNDIndicePrimerEstadoFinal(AFND*
        p_afnd) {
    int i = 0;
    {
        i = 0;
l_198:
        if (!(i < p_afnd->num_estados))goto l_200;
        goto l_201;
l_199:
        i++;
        goto l_198;
l_201:
        {
            {
                if (!((estadoTipo(AFNDEstadoEn(p_afnd, i)) == FINAL)
                        || (estadoTipo(AFNDEstadoEn(p_afnd, i)) == INICIAL_Y_FINAL)))goto l_202;
                goto l_200
                ;
l_202:
                ;
            }} goto l_199;
l_200:
        ;
    }
    return i;
}

AFND*
AFND1OInsertaEstadosTransicionesAFND(AFND*p_afnd_destino, AFND*p_afnd_origen,
        char*prefijo_estados, int offset_estados) {
    int i, j, k;
    Estado*p_e;
    int tipo;
    char*
    aux_str;
    {
        i = 0;
l_203:
        if (!(i < p_afnd_origen->num_estados))goto l_205;
        goto l_206;
l_204:
        i++;
        goto l_203;
l_206:
        {
            p_e = AFNDEstadoEn(p_afnd_origen, i);
            {
                if (!(estadoTipo
                        (p_e) == FINAL))goto l_207;
                tipo = NORMAL;
                goto l_208;
l_207:
                ;
                {
                    if (!(estadoTipo(p_e) ==
                            INICIAL_Y_FINAL))goto l_209;
                    tipo = NORMAL;
                    goto l_210;
l_209:
                    ;
                    {
                        if (!(estadoTipo(p_e
                                ) == INICIAL))goto l_211;
                        tipo = NORMAL;
                        goto l_212;
l_211:
                        ;
                        tipo = estadoTipo(p_e);
l_212:
                        ;
                    }
l_210:
                    ;
                }
l_208:
                ;
            }
            aux_str = (char*) malloc(sizeof (char) * (strlen(
            prefijo_estados) + strlen(estadoNombre(p_e)) + 1));
            strcpy(aux_str, prefijo_estados)
            ;
            strcat(aux_str, estadoNombre(p_e));
            AFNDInsertaEstado(p_afnd_destino, aux_str,
            tipo);
            free(aux_str);} goto l_204;
l_205:
        ;
    }
    {
        i = 0;
l_213:
        if (!(i < p_afnd_origen->
                num_estados))goto l_215;
        goto l_216;
l_214:
        i++;
        goto l_213;
l_216:
        {
            j = 0;
l_217:
            if (!(
                    j < p_afnd_origen->num_simbolos))goto l_219;
            goto l_220;
l_218:
            j++;
            goto l_217;
l_220:
            {
                k = 0;
l_221:
                if (!(k < p_afnd_origen->num_estados))goto l_223;
                goto l_224;
l_222:
                k++;
                goto l_221;
l_224:
                {
                    {
                        if (!(AFNDTransicionIndicesEstadoiSimboloEstadof(
                                p_afnd_origen, i, j, k) == 1))goto l_225;
                        {
                            AFNDInsertaTransicion(p_afnd_destino,
                            AFNDNombreEstadoEn(p_afnd_destino, i + offset_estados), AFNDSimboloEn(
                            p_afnd_origen, j), AFNDNombreEstadoEn(p_afnd_destino, k + offset_estados));
                        }
l_225:
                        ;
                    }} goto l_222;
l_223:
                ;} goto l_218;
l_219:
            ;} goto l_214;
l_215:
        ;
    }
    {
        i = 0;
l_226:
        if (!(i <
                p_afnd_origen->num_estados))goto l_228;
        goto l_229;
l_227:
        i++;
        goto l_226;
l_229:
        {
            j = 0;
l_230:
            if (!(j < p_afnd_origen->num_estados))goto l_232;
            goto l_233;
l_231:
            j++;
            goto l_230;
l_233:
            {
                {
                    if (!(AFNDLTransicionIJ(p_afnd_origen, i, j) == 1))goto l_234;
                    {
                        AFNDInsertaLTransicion(p_afnd_destino, AFNDNombreEstadoEn(p_afnd_destino, i +
                        offset_estados), AFNDNombreEstadoEn(p_afnd_destino, j + offset_estados));
                    }
l_234:
                    ;
                }} goto l_231;
l_232:
            ;} goto l_227;
l_228:
        ;
    }
    return p_afnd_destino;
}

AFND*
AFND1OInsertaSimbolosAFND(AFND*p_afnd_destino, AFND*p_afnd_origen) {
    int i;
    {
        i = 0;
l_235:
        if (!(i < p_afnd_origen->num_simbolos))goto l_237;
        goto l_238;
l_236:
        i++;
        goto
        l_235;
l_238:
        {
            AFNDInsertaSimbolo(p_afnd_destino, AFNDSimboloEn(p_afnd_origen, i)
            );} goto l_236;
l_237:
        ;
    }
    return p_afnd_destino;
}

AFND*AFND1OUneLTransicion(AFND*
        p_afnd_destino, AFND*p_afnd_origen, char*nombre_nuevo_estado_inicial, char*
        nombre_nuevo_estado_final, int offset_estados) {
    int j;
    {
        j = 0;
l_239:
        if (!(j <
                p_afnd_origen->num_estados))goto l_241;
        goto l_242;
l_240:
        j++;
        goto l_239;
l_242:
        {
            { if (!((estadoTipo(AFNDEstadoEn(p_afnd_origen, j)) == INICIAL) || (estadoTipo(
                        AFNDEstadoEn(p_afnd_origen, j)) == INICIAL_Y_FINAL)))goto l_243;
                {
                    AFNDInsertaLTransicion(p_afnd_destino, nombre_nuevo_estado_inicial,
                    AFNDNombreEstadoEn(p_afnd_destino, j + offset_estados));
                }
l_243:
                ;}
            {
                if (!((
                        estadoTipo(AFNDEstadoEn(p_afnd_origen, j)) == FINAL) || (estadoTipo(AFNDEstadoEn(
                        p_afnd_origen, j)) == INICIAL_Y_FINAL)))goto l_244;
                {
                    AFNDInsertaLTransicion(
                    p_afnd_destino, AFNDNombreEstadoEn(p_afnd_destino, j + offset_estados),
                    nombre_nuevo_estado_final);
                }
l_244:
                ;
            }} goto l_240;
l_241:
        ;
    }
    return p_afnd_destino;
}

AFND*AFNDCopia(AFND*pr_afnd) {
    AFND*aux_afnd;
    aux_afnd = AFNDNuevo(strcat(pr_afnd
            ->nombre, "'"), pr_afnd->num_estados, pr_afnd->num_simbolos);
    return aux_afnd;
}

Estado*AFNDEstadoEn(AFND*p_afnd, int pos) {
    return p_afnd->estados[pos];
}

Estado*
AFNDEstadoDeNombre(AFND*p_afnd, char*nombre) {
    int pos;
    pos = AFNDIndiceDeEstado(
            p_afnd, nombre);
    return p_afnd->estados[pos];
}

int
AFNDTransicionIndicesEstadoiSimboloEstadof(AFND*p_afnd, int i_e1, int i_s, int
        i_e2) {
    return p_afnd->ftransicion[i_e1][i_s][i_e2];
}

int AFNDCierreLTransicionIJ
(AFND*p_afnd, int i, int j) {
    return relacionCierreIJ(p_afnd->ltransicion, i, j);
}

void AFNDADot(AFND*p_afnd) {
    int i, j, k;
    FILE*fd_dot;
    char*nombre_fichero;
    fprintf(
            stdout, "ENTRA");
    nombre_fichero = (char*) malloc(sizeof (char) * (strlen(p_afnd->
            nombre) + 1 + strlen(".dot")));
    strcpy(nombre_fichero, p_afnd->nombre);
    strcat(
            nombre_fichero, ".dot");
    fd_dot = fopen(nombre_fichero, "w");
    free(nombre_fichero);
    printf("CREA Nombre fichero");
    fprintf(fd_dot, "digraph %s  { rankdir=LR;\n",
            p_afnd->nombre);
    fprintf(fd_dot, "\t_invisible [style=\"invis\"];\n");
    {
        i = 0;
l_245
                :
        if (!(i < p_afnd->num_estados))goto l_247;
        goto l_248;
l_246:
        i++;
        goto l_245;
l_248:
        {printf("ESTADO A DOT");
            estadoADot(fd_dot, p_afnd->estados[i]);} goto l_246;
l_247:
        ;
    }
    fprintf(fd_dot, "\t_invisible -> %s ;\n", AFNDNombreEstadoEn(p_afnd,
            AFNDIndiceEstadoInicial(p_afnd)));
    {
        i = 0;
l_249:
        if (!(i < p_afnd->num_estados))goto
            l_251;
        goto l_252;
l_250:
        i++;
        goto l_249;
l_252:
        {
            j = 0;
l_253:
            if (!(j < p_afnd->
                    num_simbolos))goto l_255;
            goto l_256;
l_254:
            j++;
            goto l_253;
l_256:
            {
                k = 0;
l_257:
                if (!
                        (k < p_afnd->num_estados))goto l_259;
                goto l_260;
l_258:
                k++;
                goto l_257;
l_260:
                {
                    {
                        if (
                                !(1 == AFNDTransicionIndicesEstadoiSimboloEstadof(p_afnd, i, j, k)))goto l_261;
                        fprintf(fd_dot, "\t%s -> %s [label=\"%s\"];\n", AFNDNombreEstadoEn(p_afnd, i),
                        AFNDNombreEstadoEn(p_afnd, k), AFNDSimboloEn(p_afnd, j));
l_261:
                        ;
                    }} goto l_258;
l_259:
                ;} goto l_254;
l_255:
            ;} goto l_250;
l_251:
        ;
    }
    {
        i = 0;
l_262:
        if (!(i < p_afnd->
                num_estados))goto l_264;
        goto l_265;
l_263:
        i++;
        goto l_262;
l_265:
        {
            j = 0;
l_266:
            if (!(
                    j < p_afnd->num_estados))goto l_268;
            goto l_269;
l_267:
            j++;
            goto l_266;
l_269:
            {
                {
                    if (!
                            (AFNDLTransicionIJ(p_afnd, i, j) == 1))goto l_270;
                    fprintf(fd_dot,
                    "\t%s -> %s [label=\"&lambda;\"];\n", AFNDNombreEstadoEn(p_afnd, i),
                    AFNDNombreEstadoEn(p_afnd, j));
l_270:
                    ;
                }} goto l_267;
l_268:
            ;} goto l_263;
l_264:
        ;
    }
    fprintf(fd_dot, "}");
    fclose(fd_dot);
    return;
}

int AFNDNumSimbolos(AFND*p_afnd) {
    return p_afnd->num_simbolos;
}

int AFNDNumEstados(AFND*p_afnd) {
    return p_afnd->
            num_estados;
}

int AFNDTipoEstadoEn(AFND*p_afnd, int pos) {
    return estadoTipo(
            p_afnd->estados[pos]);
}

struct _Alfabeto {
    char*nombre;
    int tamano;
    char**simbolos;
};

Alfabeto*alfabetoNuevo(char*nombre, int tamano) {
    Alfabeto*p_alfabeto;
    int i;
    p_alfabeto = (Alfabeto*) malloc(sizeof (Alfabeto));
    p_alfabeto->nombre = (char*)
            malloc(strlen(nombre) + 1);
    strcpy(p_alfabeto->nombre, nombre);
    p_alfabeto->tamano =
            tamano;
    p_alfabeto->simbolos = (char**) malloc(sizeof (char*)*tamano);
    {
        i = 0;
l_271:
        if
            (!(i < tamano))goto l_273;
        goto l_274;
l_272:
        i++;
        goto l_271;
l_274:
        {
            p_alfabeto->
            simbolos[i] = NULL;} goto l_272;
l_273:
        ;
    }
    return p_alfabeto;
}

void alfabetoElimina(
        Alfabeto*p_alfabeto) {
    int i;
    {
        if (!(p_alfabeto == NULL))goto l_275;
        return;
l_275:
        ;
    }
    {
        if (!(p_alfabeto->nombre != NULL))goto l_276;
        {
            free(p_alfabeto->nombre);
            p_alfabeto
                    ->nombre = NULL;
        }
l_276:
        ;
    }
    {
        i = 0;
l_277:
        if (!(i < p_alfabeto->tamano))goto l_279;
        goto
        l_280;
l_278:
        i++;
        goto l_277;
l_280:
        {
            {
                if (!(p_alfabeto->simbolos[i] != NULL))goto
                    l_281;
                {free(p_alfabeto->simbolos[i]);}
l_281:
                ;
            }} goto l_278;
l_279:
        ;
    }
    {
        if (!(
                p_alfabeto->simbolos != NULL))goto l_282;
        free(p_alfabeto->simbolos);
l_282:
        ;
    }
    free
            (p_alfabeto);
}

Alfabeto*alfabetoInsertaSimbolo(Alfabeto*p_alfabeto, char*simbolo
        ) {
    int i;
    i = 0;
    {
        i = 0;
l_283:
        if (!(i < p_alfabeto->tamano))goto l_285;
        goto l_286;
l_284:
        i++;
        goto l_283;
l_286:
        {
            {
                if (!(p_alfabeto->simbolos[i] == NULL))goto l_287;
                {
                    p_alfabeto->simbolos[i] = (char*) malloc(strlen(simbolo) + 1);
                    strcpy(p_alfabeto->
                    simbolos[i], simbolo);
                    goto l_285;
                }
l_287:
                ;
            }} goto l_284;
l_285:
        ;
    }
    return p_alfabeto
            ;
}

void alfabetoImprime(FILE*fd, Alfabeto*p_alf) {
    int i;
    {
        if (!(p_alf->nombre != NULL
                ))goto l_288;
        fprintf(fd, "%s=", p_alf->nombre);
l_288:
        ;
    }
    fprintf(fd, "{ ");
    {
        i = 0;
l_289:
        if (!(i < p_alf->tamano))goto l_291;
        goto l_292;
l_290:
        i++;
        goto l_289;
l_292:
        {
            { if (!(p_alf->simbolos[i] == NULL))goto l_293;
                goto l_291;
                goto l_294;
l_293:
                ;
                fprintf(fd, "%s ", p_alf->simbolos[i]);
l_294:
                ;}} goto l_290;
l_291:
        ;
    }
    fprintf(fd,
            "}\n");
}

char*alfabetoSimboloEn(Alfabeto*p_alf, int i) {
    {
        if (!(i < p_alf->tamano))
            goto l_295;
        return p_alf->simbolos[i];
l_295:
        ;
    }
    return NULL;
}

int
alfabetoIndiceDeSimbolo(Alfabeto*p_alf, char*simbolo) {
    int j;
    {
        if (!(p_alf->tamano
                == 0))goto l_296;
        return -1;
l_296:
        ;
    }
    {
        j = 0;
l_297:
        if (!(j < p_alf->tamano))goto l_299;
        goto l_300;
l_298:
        j++;
        goto l_297;
l_300:
        {
            {
                if (!(strcmp(simbolo, p_alf->simbolos[j]
                        ) == 0))goto l_301;
                {return j;
                    goto l_299;}
l_301:
                ;
            }} goto l_298;
l_299:
        ;
    }
    return -1;
}

int alfabetoTamano(Alfabeto*p_alf) {
    {
        if (!(p_alf == NULL))goto l_302;
        return -1;
l_302:
        ;
    }
    return p_alf->tamano;
}

int alfabetoSimboloEsta(Alfabeto*p_alf, char*
        simbolo) {
    return (alfabetoIndiceDeSimbolo(p_alf, simbolo) != -1);
}

Alfabeto*
alfabetoUne(Alfabeto*p_a1, Alfabeto*p_a2) {
    char*aux_str;
    Alfabeto*aux_return;
    int
    aux_tamano = 0;
    int i;
    aux_str = (char*) malloc(sizeof (char*) * (strlen(p_a1->nombre) +
            strlen(p_a2->nombre) + strlen("_U_") + 1));
    aux_str = strcpy(aux_str, p_a1->nombre);
    aux_str = strcat(aux_str, "_U_");
    aux_str = strcat(aux_str, p_a2->nombre);
    aux_tamano =
            alfabetoTamano(p_a1);
    {
        i = 0;
l_303:
        if (!(i < alfabetoTamano(p_a2)))goto l_305;
        goto
        l_306;
l_304:
        i++;
        goto l_303;
l_306:
        {
            {
                if (!(alfabetoSimboloEsta(p_a1,
                        alfabetoSimboloEn(p_a2, i)) != 1))goto l_307;
                {aux_tamano++;}
l_307:
                ;
            }} goto l_304;
l_305:
        ;
    }
    aux_return = alfabetoNuevo(aux_str, aux_tamano);
    free(aux_str);
    {
        i = 0;
l_308:
        if (!(i < alfabetoTamano(p_a1)))goto l_310;
        goto l_311;
l_309:
        i++;
        goto l_308;
l_311:
        {alfabetoInsertaSimbolo(aux_return, alfabetoSimboloEn(p_a1, i));} goto l_309;
l_310:
        ;
    }
    {
        i = 0;
l_312:
        if (!(i < alfabetoTamano(p_a2)))goto l_314;
        goto l_315;
l_313:
        i
                ++;
        goto l_312;
l_315:
        {
            {
                if (!(alfabetoSimboloEsta(p_a1, alfabetoSimboloEn(p_a2, i))
                        != 1))goto l_316;
                {
                    alfabetoInsertaSimbolo(aux_return, alfabetoSimboloEn(p_a2, i));
                }
l_316:
                ;
            }} goto l_313;
l_314:
        ;
    }
    return aux_return;
}

struct _Estado {
    char*nombre;
    int
    tipo;
};

Estado*estadoNuevo(char*nombre, int tipo) {
    Estado*p_s;
    p_s = (Estado*)
            malloc(sizeof (Estado));
    p_s->nombre = (char*) malloc(strlen(nombre) + 1);
    strcpy(p_s
            ->nombre, nombre);
    p_s->tipo = tipo;
    return p_s;
}

void estadoElimina(Estado*p_s) {
    {
        if
            (!(p_s != NULL))goto l_317;
        {
            {
                if (!(p_s->nombre != NULL))goto l_318;
                {
                    free(p_s->
                            nombre);
                    p_s->nombre = NULL;
                }
l_318:
                ;
            }
            free(p_s);
        }
l_317:
        ;
    }
}

void estadoImprime(FILE*
        fd, Estado*p_s) {
    {
        if (!((p_s->tipo == INICIAL) || (p_s->tipo == INICIAL_Y_FINAL)))goto
            l_319;
        fprintf(fd, "->");
l_319:
        ;
    }
    fprintf(fd, "%s", p_s->nombre);
    {
        if (!((p_s->tipo ==
                FINAL) || (p_s->tipo == INICIAL_Y_FINAL)))goto l_320;
        fprintf(fd, "*");
l_320:
        ;
    }
    fprintf(fd, " ");
    return;
}

int estadoEs(Estado*p_s, char*nombre) {
    {
        if (!(strcmp(p_s
                ->nombre, nombre) == 0))goto l_321;
        return 1;
        goto l_322;
l_321:
        ;
        return 0;
l_322:
        ;
    }
}

Estado*estado_copy(Estado*p_s) {
    Estado*aux_return;
    aux_return = estadoNuevo(
            estadoNombre(p_s), estadoTipo(p_s));
    return aux_return;
}

char*estadoNombre(Estado
        *p_s) {
    {
        if (!(p_s == NULL))goto l_323;
        return NULL;
l_323:
        ;
    }
    return p_s->nombre;
}

int
estadoTipo(Estado*p_s) {
    {
        if (!(p_s == NULL))goto l_324;
        return -1;
l_324:
        ;
    }
    return p_s
            ->tipo;
}

void estadoADot(FILE*fd, Estado*p_s) {
    {
        if (!((estadoTipo(p_s) == FINAL) || (
                estadoTipo(p_s) == INICIAL_Y_FINAL)))goto l_325;
        {
            fprintf(fd,
                    "\t%s [penwidth=\"2\"];\n", p_s->nombre);
        }
        goto l_326;
l_325:
        ;
        {
            fprintf(fd,
                    "\t%s;\n", p_s->nombre);
        }
l_326:
        ;
    }
}

int estadoCompara(Estado*p_s1, Estado*p_s2) {
    return strcmp(p_s1->nombre, p_s2->nombre);
}

struct _Relacion {
    char*nombre;
    int**
    relacion_i;
    int**relacion;
    int**cierre_relacion;
    int num_elementos;
};

int**
matrizIntNxNNueva(int n) {
    int i;
    int j;
    int**matriz;
    matriz = (int**) malloc(n * sizeof
            (int*));
    {
        i = 0;
l_327:
        if (!(i < n))goto l_329;
        goto l_330;
l_328:
        i++;
        goto l_327;
l_330:
        {matriz[i] = (int*) malloc(n * sizeof (int));} goto l_328;
l_329:
        ;
    }
    {
        i = 0;
l_331:
        if (!(i < n
                ))goto l_333;
        goto l_334;
l_332:
        i++;
        goto l_331;
l_334:
        {
            {
                j = 0;
l_335:
                if (!(j < n))goto
                    l_337;
                goto l_338;
l_336:
                j++;
                goto l_335;
l_338:
                {matriz[i][j] = 0;} goto l_336;
l_337:
                ;
            }} goto l_332;
l_333:
        ;
    }
    return matriz;
}

void matrizIntNxNElimina(int**matriz, int
        n) {
    int i;
    {
        if (!(matriz != NULL))goto l_339;
        {
            {
                i = 0;
l_340:
                if (!(i < n))goto l_342;
                goto
                l_343;
l_341:
                i++;
                goto l_340;
l_343:
                {free(matriz[i]);} goto l_341;
l_342:
                ;
            }
        }
l_339:
        ;
    }
    free(matriz);
}

int**matrizIntNxNCopia(int**matriz, int n) {
    int**aux_copia;
    int i,
            j;
    aux_copia = matrizIntNxNNueva(n);
    {
        i = 0;
l_344:
        if (!(i < n))goto l_346;
        goto l_347;
l_345:
        i++;
        goto l_344;
l_347:
        {
            j = 0;
l_348:
            if (!(j < n))goto l_350;
            goto l_351;
l_349:
            j
            ++;
            goto l_348;
l_351:
            {aux_copia[i][j] = matriz[i][j];} goto l_349;
l_350:
            ;} goto
        l_345;
l_346:
        ;
    }
    return aux_copia;
}

void matrizIntNxNImprime(FILE*fd, int**matriz,
        int n) {
    int i, j;
    {
        i = 0;
l_352:
        if (!(i < n))goto l_354;
        goto l_355;
l_353:
        i++;
        goto l_352
                ;
l_355:
        {
            fprintf(fd, "\n\t");
            {
                j = 0;
l_356:
                if (!(j < n))goto l_358;
                goto l_359;
l_357:
                j
                ++;
                goto l_356;
l_359:
                {fprintf(fd, "%d\t", matriz[i][j]);} goto l_357;
l_358:
                ;
            }} goto
        l_353;
l_354:
        ;
    }
    return;
}

Relacion*relacionNueva(char*nombre, int num_elementos) {
    Relacion*p_r;
    int i, j;
    p_r = (Relacion*) malloc(sizeof (Relacion));
    {
        if (!(nombre !=
                NULL))goto l_360;
        {
            p_r->nombre = (char*) malloc(sizeof (char) * (strlen(nombre) + 1));
            strcpy(p_r->nombre, nombre);
        }
l_360:
        ;
    }
    p_r->num_elementos = num_elementos;
    p_r->
            relacion = (int**) malloc(num_elementos * sizeof (int*));
    {
        i = 0;
l_361:
        if (!(i <
                num_elementos))goto l_363;
        goto l_364;
l_362:
        i++;
        goto l_361;
l_364:
        {
            p_r->relacion
            [i] = (int*) malloc(num_elementos * sizeof (int));} goto l_362;
l_363:
        ;
    }
    {
        i = 0;
l_365:
        if (
                !(i < num_elementos))goto l_367;
        goto l_368;
l_366:
        i++;
        goto l_365;
l_368:
        {
            {
                j = 0;
l_369:
                if (!(j < num_elementos))goto l_371;
                goto l_372;
l_370:
                j++;
                goto l_369;
l_372:
                {
                    p_r->relacion[i][j] = 0;} goto l_370;
l_371:
                ;
            }} goto l_366;
l_367:
        ;
    }
    p_r->relacion_i =
            (int**) malloc(num_elementos * sizeof (int*));
    {
        i = 0;
l_373:
        if (!(i < num_elementos))
            goto l_375;
        goto l_376;
l_374:
        i++;
        goto l_373;
l_376:
        {
            p_r->relacion_i[i] = (int*)
            malloc(num_elementos * sizeof (int));} goto l_374;
l_375:
        ;
    }
    {
        i = 0;
l_377:
        if (!(i <
                num_elementos))goto l_379;
        goto l_380;
l_378:
        i++;
        goto l_377;
l_380:
        {
            {
                j = 0;
l_381:
                if
                    (!(j < num_elementos))goto l_383;
                goto l_384;
l_382:
                j++;
                goto l_381;
l_384:
                {
                    p_r->
                    relacion_i[i][j] = 0;} goto l_382;
l_383:
                ;
            }} goto l_378;
l_379:
        ;
    }
    p_r->
            cierre_relacion = (int**) malloc(num_elementos * sizeof (int*));
    {
        i = 0;
l_385:
        if (!(i <
                num_elementos))goto l_387;
        goto l_388;
l_386:
        i++;
        goto l_385;
l_388:
        {
            p_r->
            cierre_relacion[i] = (int*) malloc(num_elementos * sizeof (int));} goto l_386;
l_387:
        ;
    }
    {
        i = 0;
l_389:
        if (!(i < num_elementos))goto l_391;
        goto l_392;
l_390:
        i++;
        goto l_389;
l_392:
        {
            {
                j = 0;
l_393:
                if (!(j < num_elementos))goto l_395;
                goto l_396;
l_394:
                j++;
                goto
                l_393;
l_396:
                {p_r->cierre_relacion[i][j] = 0;} goto l_394;
l_395:
                ;
            }} goto l_390;
l_391:
        ;
    }
    return p_r;
}

void relacionImprime(FILE*fd, Relacion*p_r) {
    int i, j;
    {
        if (!(
                p_r->nombre != NULL))goto l_397;
        fprintf(fd, "%s={\n\t", p_r->nombre);
l_397:
        ;
    }
    {
        j = 0;
l_398:
        if (!(j < p_r->num_elementos))goto l_400;
        goto l_401;
l_399:
        j++;
        goto l_398;
l_401:
        fprintf(fd, "\t[%d]", j);
        goto l_399;
l_400:
        ;
    }
    fprintf(fd, "\n");
    fprintf(fd,
            "\t\tCIERRE\n");
    {
        i = 0;
l_402:
        if (!(i < p_r->num_elementos))goto l_404;
        goto l_405;
l_403:
        i++;
        goto l_402;
l_405:
        {
            fprintf(fd, "\t[%d]", i);
            {
                j = 0;
l_406:
                if (!(j < p_r->
                        num_elementos))goto l_408;
                goto l_409;
l_407:
                j++;
                goto l_406;
l_409:
                {
                    fprintf(fd,
                    "\t%d", p_r->cierre_relacion[i][j]);} goto l_407;
l_408:
                ;
            }
            fprintf(fd, "\n");} goto
        l_403;
l_404:
        ;
    }
    fprintf(fd, "\n");
    fprintf(fd, "\t\tPOTENCIA i\n");
    {
        i = 0;
l_410:
        if (!(
                i < p_r->num_elementos))goto l_412;
        goto l_413;
l_411:
        i++;
        goto l_410;
l_413:
        {
            fprintf(fd, "\t[%d]", i);
            {
                j = 0;
l_414:
                if (!(j < p_r->num_elementos))goto l_416;
                goto
                l_417;
l_415:
                j++;
                goto l_414;
l_417:
                {fprintf(fd, "\t%d", p_r->relacion_i[i][j]);}
                goto l_415;
l_416:
                ;
            }
            fprintf(fd, "\n");} goto l_411;
l_412:
        ;
    }
    fprintf(fd, "\n");
    fprintf(fd, "\t\tRELACION INICIAL i\n");
    {
        i = 0;
l_418:
        if (!(i < p_r->num_elementos))
            goto l_420;
        goto l_421;
l_419:
        i++;
        goto l_418;
l_421:
        {
            fprintf(fd, "\t[%d]", i);
            {
                j = 0;
l_422:
                if (!(j < p_r->num_elementos))goto l_424;
                goto l_425;
l_423:
                j++;
                goto l_422;
l_425:
                {fprintf(fd, "\t%d", p_r->relacion[i][j]);} goto l_423;
l_424:
                ;
            }
            fprintf(fd,
            "\n");} goto l_419;
l_420:
        ;
    }
    fprintf(fd, "}\n");
    return;
}

void relacionElimina(
        Relacion*p_r) {
    int i;
    {
        if (!(p_r->nombre != NULL))goto l_426;
        free(p_r->nombre);
l_426:
        ;
    }
    {
        if (!(p_r->relacion != NULL))goto l_427;
        {
            {
                i = 0;
l_428:
                if (!(i < p_r->
                        num_elementos))goto l_430;
                goto l_431;
l_429:
                i++;
                goto l_428;
l_431:
                {
                    free(p_r->
                    relacion[i]);} goto l_429;
l_430:
                ;
            }
        }
l_427:
        ;
    }
    free(p_r->relacion);
    {
        if (!(p_r->
                relacion_i != NULL))goto l_432;
        {
            {
                i = 0;
l_433:
                if (!(i < p_r->num_elementos))goto l_435
                        ;
                goto l_436;
l_434:
                i++;
                goto l_433;
l_436:
                {free(p_r->relacion_i[i]);} goto l_434;
l_435:
                ;
            }
        }
l_432:
        ;
    }
    free(p_r->relacion_i);
    {
        if (!(p_r->cierre_relacion != NULL))goto
            l_437;
        {
            {
                i = 0;
l_438:
                if (!(i < p_r->num_elementos))goto l_440;
                goto l_441;
l_439:
                i++;
                goto l_438;
l_441:
                {free(p_r->cierre_relacion[i]);} goto l_439;
l_440:
                ;
            }
        }
l_437:
        ;
    }
    free(p_r->cierre_relacion);
    free(p_r);
    return;
}

Relacion*relacionInserta(Relacion
        *p_r, int i, int j) {
    {
        if (!(p_r == NULL))goto l_442;
        return p_r;
l_442:
        ;
    }
    {
        if (!((p_r->
                num_elementos <= i) || (p_r->num_elementos <= j)))goto l_443;
        {
            fprintf(stdout,
                    "Fuera de rango %d %d \n", i, j);
            return p_r;
        }
l_443:
        ;
    }
    p_r->relacion[i][j] = 1;
    p_r->
            relacion_i[i][j] = 1;
    p_r->cierre_relacion[i][j] = 1;
    return p_r;
}

Relacion*
relacionCopia(Relacion*p_r) {
    Relacion*p_r2;
    int i, j;
    char*nombre;
    {
        if (!(p_r == NULL)
                )goto l_444;
        return NULL;
l_444:
        ;
    }
    nombre = (char*) malloc((strlen(p_r->nombre) + 2) *
            sizeof (char));
    strcpy(nombre, p_r->nombre);
    strcat(nombre, "'");
    p_r2 = relacionNueva
            (nombre, p_r->num_elementos);
    free(nombre);
    p_r2->num_elementos = p_r->
            num_elementos;
    {
        i = 0;
l_445:
        if (!(i < p_r->num_elementos))goto l_447;
        goto l_448;
l_446:
        i++;
        goto l_445;
l_448:
        {
            {
                j = 0;
l_449:
                if (!(j < p_r->num_elementos))goto l_451;
                goto l_452;
l_450:
                j++;
                goto l_449;
l_452:
                {
                    p_r2->relacion[i][j] = p_r->relacion[i][j
                    ];
                    p_r2->relacion_i[i][j] = p_r->relacion_i[i][j];
                    p_r2->cierre_relacion[i][j] = p_r
                    ->cierre_relacion[i][j];} goto l_450;
l_451:
                ;
            }} goto l_446;
l_447:
        ;
    }
    return p_r2;
}

int relacionTamano(Relacion*p_r) {
    {
        if (!(p_r != NULL))goto l_453;
        return p_r->
                num_elementos;
        goto l_454;
l_453:
        ;
        return -1;
l_454:
        ;
    }
}

int relacionUnPasoMas(
        Relacion*p_r) {
    int i, j, k;
    int num_cambios = 0;
    int**matriz_i_tmp;
    matriz_i_tmp =
            matrizIntNxNNueva(p_r->num_elementos);
    p_r->nombre = (char*) realloc(p_r->nombre, (
            strlen(p_r->nombre) + 2) * sizeof (char));
    strcat(p_r->nombre, "+");
    {
        i = 0;
l_455:
        if (!(i
                < p_r->num_elementos))goto l_457;
        goto l_458;
l_456:
        i++;
        goto l_455;
l_458:
        {
            {
                j = 0;
l_459:
                if (!(j < p_r->num_elementos))goto l_461;
                goto l_462;
l_460:
                j++;
                goto l_459;
l_462:
                {
                    {
                        k = 0;
l_463:
                        if (!(k < p_r->num_elementos))goto l_465;
                        goto l_466;
l_464:
                        k++;
                        goto l_463;
l_466:
                        {
                            {
                                if (!((p_r->relacion_i[i][k] == p_r->relacion[k][j]) && (p_r->
                                        relacion_i[i][k] == 1)))goto l_467;
                                {
                                    matriz_i_tmp[i][j] = 1;
                                    {
                                        if (!(p_r->
                                                cierre_relacion[i][j] == 0))goto l_468;
                                        {
                                            p_r->cierre_relacion[i][j] = 1;
                                            num_cambios
                                            ++;
                                        }
l_468:
                                        ;
                                    }
                                    goto l_465;
                                }
l_467:
                                ;
                            }} goto l_464;
l_465:
                        ;
                    }} goto l_460;
l_461:
                ;
            }} goto
        l_456;
l_457:
        ;
    }
    matrizIntNxNElimina(p_r->relacion_i, p_r->num_elementos);
    p_r->
            relacion_i = matriz_i_tmp;
    return num_cambios;
}

Relacion*relacionCierreReflexivo(
        Relacion*p_r) {
    int i;
    {
        if (!(p_r == NULL))goto l_469;
        return NULL;
        goto l_470;
l_469:
        ;
        {
            p_r->nombre = (char*) realloc(p_r->nombre, (strlen(p_r->nombre) + 2) * sizeof (char));
            strcat(p_r->nombre, "*");
            {
                i = 0;
l_471:
                if (!(i < p_r->num_elementos))goto l_473;
                goto
                l_474;
l_472:
                i++;
                goto l_471;
l_474:
                {p_r->cierre_relacion[i][i] = 1;} goto l_472;
l_473:
                ;
            }
        }
l_470:
        ;
    }
    return p_r;
}

Relacion*relacionCierreTransitivo(Relacion*p_r) {
    int num_cambios = -1;
    {
l_475:
        if (!(num_cambios != 0))goto l_476;
        {
            num_cambios =
                    relacionUnPasoMas(p_r);
        }
        goto l_475;
l_476:
        ;
    }
    return p_r;
}

int relacionIJ(Relacion
        *p_r, int i, int j) {
    {
        if (!((i >= p_r->num_elementos) || (j >= p_r->num_elementos)))goto
            l_477;
        {
            return -1;
        }
l_477:
        ;
    }
    return (p_r->relacion[i][j] == 1);
}

int relacionCierreIJ
(Relacion*p_r, int i, int j) {
    {
        if (!((i >= p_r->num_elementos) || (j >= p_r->
                num_elementos)))goto l_478;
        {
            return -1;
        }
l_478:
        ;
    }
    return (p_r->cierre_relacion[i][j
            ] == 1);
}

struct _Palabra {
    char**letras;
    int tamano;
};

Palabra*palabraNueva() {
    Palabra*aux_palabra;
    aux_palabra = (Palabra*) malloc(sizeof (Palabra));
    aux_palabra
            ->letras = NULL;
    aux_palabra->tamano = 0;
    return aux_palabra;
}

Palabra*
palabraInsertaLetra(Palabra*p_p, char*letra) {
    p_p->letras = (char**) realloc(p_p->
            letras, (p_p->tamano + 1) * sizeof (char*));
    p_p->letras[p_p->tamano] = (char*) malloc((
            strlen(letra) + 1) * sizeof (char));
    strcpy(p_p->letras[p_p->tamano], letra);
    (p_p->
            tamano)++;
    return p_p;
}

char*palabraQuitaInicio(Palabra*p_p) {
    int i;
    char*inicio;
    {
        if (!(p_p == NULL))goto l_479;
        return NULL;
l_479:
        ;
    }
    {
        if (!(p_p->tamano == 0))goto
            l_480;
        return NULL;
l_480:
        ;
    }
    inicio = p_p->letras[0];
    {
        i = 1;
l_481:
        if (!(i < p_p->tamano)
                )goto l_483;
        goto l_484;
l_482:
        i++;
        goto l_481;
l_484:
        {
            p_p->letras[i - 1] = p_p->
            letras[i];} goto l_482;
l_483:
        ;
    }
    (p_p->tamano)--;
    p_p->letras = (char**) realloc(p_p
            ->letras, p_p->tamano * sizeof (char*));
    return inicio;
}

void palabraElimina(Palabra
        *aux_p) {
    int i;
    {
        if (!(aux_p == NULL))goto l_485;
        return;
l_485:
        ;
    }
    {
        if (!(aux_p->letras
                != NULL))goto l_486;
        {
            {
                i = 0;
l_487:
                if (!(i < aux_p->tamano))goto l_489;
                goto l_490;
l_488:
                i++;
                goto l_487;
l_490:
                {free(aux_p->letras[i]);} goto l_488;
l_489:
                ;
            }
        }
l_486:
        ;
    }
    free(aux_p->letras);
    free(aux_p);
}

void palabraImprime(FILE*fd, Palabra*aux_p) {
    int i;
    {
        if (!(aux_p == NULL))goto l_491;
        return;
l_491:
        ;
    }
    fprintf(fd, "[(%d)", aux_p->
            tamano);
    {
        i = 0;
l_492:
        if (!(i < aux_p->tamano))goto l_494;
        goto l_495;
l_493:
        i++;
        goto
        l_492;
l_495:
        {fprintf(fd, " %s", aux_p->letras[i]);} goto l_493;
l_494:
        ;
    }
    fprintf(fd
            , "]\n");
    return;
}

int palabraTamano(Palabra*p_p) {
    {
        if (!(p_p == NULL))goto l_496;
        return -1;
l_496:
        ;
    }
    return p_p->tamano;
}

int print_p_string(FILE*fd, const void*p_c
        ) {
    return fprintf(fd, "%s", (char*) p_c);
}

void*copy_p_string(const void*p_c) {
    char*
    aux_return;
    aux_return = (char*) malloc(strlen((char*) p_c) + 1);
    strcpy(aux_return, (
            char*) p_c);
    return (void*) aux_return;
}

void destroy_p_string(void*p_c) {
    {
        if (!(p_c
                != NULL))goto l_497;
        {
            free(p_c);
        }
l_497:
        ;
    }
}

int cmp_p_string(const void*p_c1, const
        void*p_c2) {
    return strcmp((char*) p_c1, (char*) p_c2);
}
