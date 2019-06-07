#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "FileManager.h"
#include "Senhas.h"

FILE* AbreArquivoNormal(char modo){

    FILE *file;

    switch(modo){
        case 'w':
            file = fopen("C:\\Users\\dougl\\Documents\\senhasNormal.txt", "wt"); //ATEN��O, RENOMEAR O USU�RIO ALI DE ACORDO COM O SEU NOME DE USU�RIO DO WINDOWS.
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

FILE* AbreArquivoPreferencial(char modo){

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

void CadastraNormal(int senha, char canal){

    FILE *file;

    file = AbreArquivoNormal('a');

    fprintf(file, "%d %c\n", senha, canal);

    FechaArquivo(file);
}

void CadastraPreferencial(int senha, char canal){

    FILE *file;

    file = AbreArquivoPreferencial('a');

    fprintf(file, "%d %c\n", senha, canal);

    FechaArquivo(file);
}

void CadastraCaixa(int senha, char canal){

    FILE *file;

    file = AbreArquivoCaixa('a');

    fprintf(file, "%d %c\n", senha, canal);

    FechaArquivo(file);
}
void ListarNormal(){

    FILE *file;
    int senha;
    char canal;


    file = AbreArquivoNormal('r');

    while(fscanf(file, "%d %c", &senha, &canal)!=EOF){
        printf("%d %c\n", senha, canal);

    }
    FechaArquivo(file);
}

void ListarPreferencial(){

    FILE *file;
    int senha;
    char canal;


    file = AbreArquivoPreferencial('r');

    while(fscanf(file, "%d %c", &senha, &canal)!=EOF){
        printf("%d %c\n", senha, canal);

    }
    FechaArquivo(file);
}

void ListarCaixa(){

    FILE *file;
    int senha;
    char canal;


    file = AbreArquivoCaixa('r');

    while(fscanf(file, "%d %c", &senha, &canal)!=EOF){
        printf("%d %c\n", senha, canal);

    }
    FechaArquivo(file);
}

int PegarSeqNormal(){

    int retorno = 0;
    char canal; //inutil

    FILE* file = AbreArquivoNormal('r');

    while(fscanf(file, "%d %c", &retorno, &canal) !=EOF){
        //printf("%d %c\n", retorno, canal);

    }

    FechaArquivo(file);

    if(retorno == 0){
        return 0;
    }else{
        return retorno;
    }
}

int PegarSeqPreferencial(){

    int retorno = 0;
    char canal; //inutil

    FILE* file = AbreArquivoPreferencial('r');

    while(fscanf(file, "%d %c", &retorno, &canal)!=EOF){
        //printf("%d %c\n", retorno, canal);

    }

    FechaArquivo(file);

    if(retorno == 0){
        return 0;
    }else{
        return retorno;
    }
}

int PegarSeqCaixa(){

    int retorno = 0;
    char canal; //inutil

    FILE* file = AbreArquivoCaixa('r');

    while(fscanf(file, "%d %c\n", &retorno, &canal)!=EOF){
        //printf("%d %c\n", retorno, canal);

    }

    FechaArquivo(file);

    if(retorno == 0){
        return 0;
    }else{
        return retorno;
    }
}

void zerarDados(){
    FILE* file = AbreArquivoCaixa('w');
    FechaArquivo(file);
    file = AbreArquivoPreferencial('w');
    FechaArquivo(file);
    file = AbreArquivoNormal('w');

    FechaArquivo(file);
}
