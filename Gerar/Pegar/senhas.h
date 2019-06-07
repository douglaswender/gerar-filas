//Funções para Carregar em fila dinâmica
typedef struct senha Senha;
typedef struct fila Fila;
Fila* criaFila();
void liberaFila(Fila* fi);
int insereFila(Fila* fi, struct senha s);
int removeFila(Fila* fi);//nessa função ele tem que reescrever o arquivo.
void imprimeFilaNormal(Fila* fi);
