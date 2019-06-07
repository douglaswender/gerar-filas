typedef struct senha Senha;

typedef struct fila Fila;

Fila* criaFila();
void liberaFila(Fila* fi);
int insereFila(Fila* fi, struct senha s);
int removeFila(Fila* fi);
void imprimeFila(Fila* fi);
