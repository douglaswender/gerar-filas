//Fun��es para Carregar em fila din�mica
typedef struct senha Senha;
typedef struct fila Fila;
Fila* criaFila();
void liberaFila(Fila* fi);
int insereFila(Fila* fi, struct senha s);
int removeFila(Fila* fi);//nessa fun��o ele tem que reescrever o arquivo.
void imprimeFilaNormal(Fila* fi);
