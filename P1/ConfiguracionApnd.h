

ConfiguracionApnd * configuracionApndIni();
/* Inicializa una configuracion no determinista */
ConfiguracionApnd* configuracionApndInsert(ConfiguracionApnd* capnd, const ConfiguracionAp * p_cap);
/* Inserta una configuracion determinista en una no determinista. Se realiza una
copia en memoria propia de la coleccion para el nuevo elemento y se asegura que
no haya duplicados*/
ConfiguracionAp * configuracionApndExtract(ConfiguracionApnd * capnd);
/* Se obtiene una configuracion determinista de la no determinista, que
desaparece de la coleccion.
No se especifica el orden en el que se extrae */
int configuracionApndIsEmpty(const ConfiguracionApnd* capnd);
/* Se devuelve 1 si esta vacia y 0 en caso contrario */
int configuracionApndSize(const ConfiguracionApnd * capnd);
/* Se devuelve el numero de configuraciones deterministas que hay dentro de la no
determinista */
int configuracionApndPrint(FILE *fd, const ConfiguracionApnd* capnd);
/* Se imprime todas las configuraciones deterministas. No se especifica en que
orden */
void configuracionApndDestroy( ConfiguracionApnd* capnd);
/* Se libera toda la memoria asociada con la configuracion no determinista */