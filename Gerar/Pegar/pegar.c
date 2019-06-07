#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pegar.h"



//Descrição do tipo Fila. Duplamente encadeada para tentativa de mostrar qual foi o último
//Camarada a ser chamado, recurso experimental, o correto é usar uma aux.


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
    //cria um nó alimentando os dados recebidos por parâmetro.
    no->dados = s;
    //seta ele como ultimo da lista direcionando o próximo para null.
    no->prox = NULL;
    //verifica se a fila está vazia, se sim coloca o nó como primeiro:
    if(fi->fim == NULL)
        fi->inicio = no;
    //se não ele adiciona como o último e substitui na fila quem é o último.
    else
        fi->fim->prox = no;
    fi->fim = no;
    fi->qtd++;

    return 1;

}

int removeFila(Fila* fi){
    //se a fila está vazia ou não existe retorna 0 (faz uma verificação no processo principal)
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)
        return 0;
    //copia o elemento a ser retirado pra não perder os dados.
    Elem* no = fi->inicio;

    //Define o primeiro como próximo
    fi->inicio = fi->inicio->prox;

    //verifica se a fila ficou vazia
    if(fi->inicio == NULL)
        fi->fim = NULL;

    //printf("SENHA: %d %c", no->dados.numero, no->dados.canal);
    free(no);
    fi->qtd--;

    return 1;
}
void imprimeFilaNormal(Fila* fi){

    if(fi==NULL)
        return;

    Elem* no = fi->inicio;

    removeFila(fi);

    if(fi->fim != NULL){

        printf("IMPRIME FILA: %d %c\n", no->dados.numero, no->dados.canal);
        reescreverFilaNormal(fi);
        getchar();
        getchar();
        //no=no->prox;

    }else{
        printf("Nao existem senhas a serem chamadas nesse canal.");
        getchar();
        getchar();
    }

}

void imprimeFilaPref(Fila* fi){

    if(fi==NULL)
        return;

    Elem* no = fi->inicio;

    removeFila(fi);

    if(fi->fim != NULL){

        printf("IMPRIME FILA: %d %c\n", no->dados.numero, no->dados.canal);
        reescreverFilaPref(fi);
        getchar();
        getchar();
        //no=no->prox;

    }else{
        printf("Nao existem senhas a serem chamadas nesse canal.");
        getchar();
        getchar();
    }

}

void imprimeFilaCaixa(Fila* fi){

    if(fi==NULL)
        return;

    Elem* no = fi->inicio;

    removeFila(fi);

    if(fi->fim != NULL){

        printf("IMPRIME FILA: %d %c\n", no->dados.numero, no->dados.canal);
        reescreverFilaCaixa(fi);
        getchar();
        getchar();
        //no=no->prox;

    }else{
        printf("Nao existem senhas a serem chamadas nesse canal.");
        getchar();
        getchar();
    }

}

void reescreverFilaNormal(Fila* fi){

    if(fi==NULL){
        return;
    }
    FILE* file = AbreArquivoNormal('w');
    FechaArquivo(file);
    Elem* no = fi->inicio;

    while(no->prox != NULL){

        CadastraNormal(no->dados.numero, no->dados.canal);

        //printf("\nSenha: %d\n", no->dados.numero);
        //printf("\nCanal: %c\n", no->dados.canal);
        //printf("---------------------------\n");

        no=no->prox;
        //i++;
    }
}

void reescreverFilaPref(Fila* fi){

    if(fi==NULL){
        return;
    }
    FILE* file = AbreArquivoPref('w');
    FechaArquivo(file);
    Elem* no = fi->inicio;

    while(no->prox != NULL){
        CadastraPref(no->dados.numero, no->dados.canal);
        //printf("\nSenha: %d\n", no->dados.numero);
        //printf("\nCanal: %c\n", no->dados.canal);
        //printf("---------------------------\n");

        no=no->prox;
        //i++;
    }
}

void reescreverFilaCaixa(Fila* fi){

    if(fi==NULL){
        return;
    }
    FILE* file = AbreArquivoCaixa('w');
    FechaArquivo(file);
    Elem* no = fi->inicio;

    while(no->prox != NULL){
        CadastraCaixa(no->dados.numero, no->dados.canal);
        //printf("\nSenha: %d\n", no->dados.numero);
        //printf("\nCanal: %c\n", no->dados.canal);
        //printf("---------------------------\n");

        no=no->prox;
        //i++;
    }
}

FILE* AbreArquivoNormal(char modo){

    FILE *file;

    switch(modo){
        case 'w':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasNormal.txt", "wt"); //ATENÇÃO, RENOMEAR O USUÁRIO ALI DE ACORDO COM O SEU NOME DE USUÁRIO DO WINDOWS.
            break;
        case 'r':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasNormal.txt", "rt");
            break;
        case 'a':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasNormal.txt", "a");
            break;
    }
    if(file == NULL){
        printf("Nao foi possivel encontrar o arquivo de dados Normal!");

    }
    return file;
}

FILE* AbreArquivoPref(char modo){

    FILE *file;

    switch(modo){
        case 'w':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasPreferencial.txt", "wt");
            break;
        case 'r':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasPreferencial.txt", "rt");
            break;
        case 'a':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasPreferencial.txt", "a");
            break;
    }
    if(file == NULL){
        printf("Nao foi possivel encontrar o arquivo de dados Preferencial!");
        //Verificar o comando exit;
        exit(0);
    }
    return file;
}

FILE* AbreArquivoCaixa(char modo){

    FILE *file;

    switch(modo){
        case 'w':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasCaixa.txt", "wt");
            break;
        case 'r':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasCaixa.txt", "rt");
            break;
        case 'a':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasCaixa.txt", "a");
            break;
    }
    if(file == NULL){
        printf("Nao foi possivel encontrar o arquivo de dados Caixa!");
        //Verificar o comando exit;
        exit(0);
    }
    return file;
}

void FechaArquivo(FILE *file){
    fclose(file);
}

Fila* ListarNormal(){

    Fila* fi = criaFila();
    FILE* file = AbreArquivoNormal('r');
    int senha;
    char canal;
    struct senha dados;

    while(!feof(file)){
            //printf("Entrou no while do f() listar normal\n");
            fscanf(file, "%d %c", &senha, &canal);
            //printf("%d %c\n", senha, canal);
            dados.canal = canal;
            dados.numero = senha;

            //Em vez de printar ele tem que carregar um por um na fila
            insereFila(fi, dados);


    }
    FechaArquivo(file);
    return fi;
}

Fila* ListarPreferencial(){

    Fila* fi = criaFila();
    FILE* file = AbreArquivoPref('r');
    int senha;
    char canal;
    struct senha dados;

    while(!feof(file)){
            //printf("Entrou no while do f() listar normal\n");
            fscanf(file, "%d %c", &senha, &canal);
            //printf("%d %c\n", senha, canal);
            dados.canal = canal;
            dados.numero = senha;

            //Em vez de printar ele tem que carregar um por um na fila
            insereFila(fi, dados);


    }
    FechaArquivo(file);
    return fi;
}

Fila* ListarCaixa(){

    Fila* fi = criaFila();
    FILE* file = AbreArquivoCaixa('r');
    int senha;
    char canal;
    struct senha dados;

    while(!feof(file)){
            //printf("Entrou no while do f() listar normal\n");
            fscanf(file, "%d %c", &senha, &canal);
            //printf("%d %c\n", senha, canal);
            dados.canal = canal;
            dados.numero = senha;

            //Em vez de printar ele tem que carregar um por um na fila
            insereFila(fi, dados);


    }
    FechaArquivo(file);
    return fi;
}

void CadastraNormal(int senha, char canal){

    FILE *file;

    file = AbreArquivoNormal('a');

    fprintf(file, "%d %c\n", senha, canal);

    FechaArquivo(file);
}

void CadastraCaixa(int senha, char canal){

    FILE *file;

    file = AbreArquivoCaixa('a');

    fprintf(file, "%d %c\n", senha, canal);

    FechaArquivo(file);
}

void CadastraPref(int senha, char canal){

    FILE *file;

    file = AbreArquivoPref('a');

    fprintf(file, "%d %c\n", senha, canal);

    FechaArquivo(file);
}


