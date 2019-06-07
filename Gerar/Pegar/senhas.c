#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "senhas.h"
#include "pegar.h"


//Estrutura de fila
struct senha{
    int numero;
    char canal;
};
//Descri��o do tipo Fila. Duplamente encadeada para tentativa de mostrar qual foi o �ltimo
//Camarada a ser chamado, recurso experimental, o correto � usar uma aux.
struct elemento{
    struct elemento *ant;
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

Fila* criaFila(){

    Fila* fi = (Fila*) malloc(sizeof(Fila));

    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void liberaFila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int insereFila(Fila* fi, Senha s){
    if(fi == NULL)
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if(no==NULL)
        return 0;
    //cria um n� alimentando os dados recebidos por par�metro.
    no->dados = s;
    //seta ele como ultimo da lista direcionando o pr�ximo para null.
    no->prox = NULL;
    //verifica se a fila est� vazia, se sim coloca o n� como primeiro:
    if(fi->fim == NULL)
        fi->inicio = no;
    //se n�o ele adiciona como o �ltimo e substitui na fila quem � o �ltimo.
    else
        fi->fim->prox = no;
    fi->fim = no;
    fi->qtd++;

    return 1;

}

int removeFila(Fila* fi){
    //se a fila est� vazia ou n�o existe retorna 0 (faz uma verifica��o no processo principal)
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)
        return 0;
    //copia o elemento a ser retirado pra n�o perder os dados.
    Elem* no = fi->inicio;

    //Define o primeiro como pr�ximo
    fi->inicio = fi->inicio->prox;

    //verifica se a fila ficou vazia
    if(fi->inicio == NULL)
        fi->fim = NULL;
    printf("SENHA: %d %c", no->dados.numero, no->dados.canal);
    free(no);
    fi->qtd--;

    return 1;
}
void imprimeFilaNormal(Fila* fi){

    if(fi==NULL)
        return;

    Elem* no = fi->inicio;
    FILE* file = AbreArquivoNormal('w');

    while(no!=NULL){

        fprintf(file, "%d\t%c\n", no->dados.numero, no->dados.canal);
        printf("\nSenha: %d\n", no->dados.numero);
        printf("\nCanal: %c\n", no->dados.canal);
        printf("---------------------------\n");

        no=no->prox;
    }

}
