//senhas

struct senha{
    int numero;
    char canal;
};

typedef struct senha Senha;

struct elemento{
    struct elemento *prox;
    struct senha dados;
};


typedef struct elemento Elem;

struct fila{
    //char nome[30];
    struct elemento* inicio;
    struct elemento* fim;
    int qtd;
};
typedef struct fila Fila;
Fila* criaFila();
void liberaFila(Fila* fi);
int insereFila(Fila* fi, struct senha s);
int removeFila(Fila* fi);//nessa função ele tem que reescrever o arquivo.
void imprimeFilaNormal(Fila* fi);
void imprimeFilaPref(Fila* fi);
void imprimeFilaCaixa(Fila* fi);
void reescreverFilaNormal(Fila* fi);
void reescreverFilaPref(Fila* fi);
void reescreverFilaCaixa(Fila* fi);


//Funções pra escolher os arquivos

FILE* AbreArquivoNormal(char modo);
FILE* AbreArquivoPref(char modo);
FILE* AbreArquivoCaixa(char modo);
void FechaArquivo(FILE* file);
Fila* ListarNormal();
Fila* ListarPreferencial();
Fila* ListarCaixa();
void CadastraNormal(int senha, char canal);
void CadastraPref(int senha, char canal);
void CadastraCaixa(int senha, char canal);



