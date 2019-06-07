#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pegar.h"
//ALUNOS:
//  DOUGLAS WENDER LOPES DE OLIVEIRA
//  LUCAS TOMASI
//  NISIO OLIVEIRA
int op;
//A IDEIA AGORA É FAZER UM CARREGAMENTO DOS DADOS POR COMPLETO NAS FILAS E QUANDO
//O USUÁRIO SAIR (APERTAR O 0) SALVA OS DADOS DA FILA NO ARQUIVO DE TEXTO;
int main()
{
    //int r;
    Fila* filaNormal = criaFila();
    Fila* filaPref = criaFila();
    Fila* filaCaixa = criaFila();



    do{
        system("cls");
        printf("Bem vindo(a) o que deseja fazer?\n");
        printf("1 - Chamar o proximo da fila normal\n");
        printf("2 - Chamar o proximo da fila preferencial\n");
        printf("3 - Chamar o proximo da fila do caixa\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            system("cls");

            filaNormal = ListarNormal();
            //printf("%d", filaNormal->inicio->dados.numero);
            imprimeFilaNormal(filaNormal);
            //imprimeFilaNormal(filaNormal);
            //remover o primeiro
            //r = removeFila(filaNormal);
            //printf("%d", r);
            //reescreverFilaNormal(filaNormal);
            //reescrever o arquivo
            //printf("%d");

            break;
        case 2:
            system("cls");

            filaPref = ListarPreferencial();
            //printf("%d", filaNormal->inicio->dados.numero);
            imprimeFilaPref(filaPref);

            break;
        case 3:
            system("cls");

            filaCaixa = ListarCaixa();
            //printf("%d", filaNormal->inicio->dados.numero);
            imprimeFilaCaixa(filaCaixa);

            break;
        case 0:
            system("cls");
            printf("Voce saiu do sistema!\n");
            op = 0;
            break;
        default:
            system("cls");
            printf("Erro 207!");
            Sleep(3000);
            break;
        }

    }while(op!=0);

    liberaFila(filaNormal);
    liberaFila(filaCaixa);
    liberaFila(filaPref);

}
