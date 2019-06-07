#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "FileManager.h"
#include "Senhas.h"
//ALUNOS:
//  DOUGLAS WENDER LOPES DE OLIVEIRA
//  LUCAS TOMASI
//  NISIO OLIVEIRA

int seqPref, seqNormal, seqCaixa;

typedef struct senha{
    int numero;
    char canal;
} Senha;

int main()
{

    int opc=1, op=0;
    seqCaixa=PegarSeqCaixa()+1;
    seqNormal=PegarSeqNormal()+1;
    seqPref=PegarSeqPreferencial()+1;

    while(opc!=0){

        char canal;
        system("cls");
        printf("\t\t\t\t\t\tGerar Senhas Systems\n\n");
        printf("1 - Criar nova senha\n");
        printf("2 - Listar senhas\n");
        printf("3 - Zerar dados\n");
        printf("0 - Sair\n");
        scanf(" %d", &opc);
        printf(" %d", opc);

        switch(opc){
            case 1:
                system("cls"); //substituir cls por "clear" no linux
                printf("\t\t\t\t\t\tCanais de atendimento:\n\n1 - Caixa\t2 - Atendimento Normal\t3 - Atendimento Preferencial \n\nInforme o canal de atendimento: ");
                //getchar();
                scanf(" %d", &op);
                if(op==1){
                //if((strcmp(canal, "A")==0)||(strcmp(canal, "a")==0)){
                        struct senha s;

                        s.canal = 'A';
                        //testando variáveis
                        //printf("%c", s.canal);
                        //getchar();
                        //getchar();

                        //implementa número vindo do txt
                        s.numero = seqCaixa;

                        //imprimeFila(caixa); //teste de impressão dos dados na lista; VAI SER USADO PARA PASSAR TODAS INFORMAÇÕES PARA O ARQUIVO DE TEXTO.
                        seqCaixa++;

                        //Cadastra no arquivo de texto
                        CadastraCaixa(s.numero, s.canal);

                        //imprime a senha que foi escolhida para o usuário.
                        printf("Sua senha e: %d-%c", s.numero, s.canal);
                        getchar();
                        getchar();
                }
                else if(op==2){
                        /*@override
                        do código do caixa*/
                        struct senha s;

                        s.canal = 'B';

                        //implementa número vindo do txt
                        s.numero = seqNormal;

                        //imprimeFila(caixa); //teste de impressão dos dados na lista; VAI SER USADO PARA PASSAR TODAS INFORMAÇÕES PARA O ARQUIVO DE TEXTO.
                        seqNormal++;

                        //Cadastra no arquivo de texto
                        CadastraNormal(s.numero, s.canal);

                        //imprime a senha que foi escolhida para o usuário.
                        printf("Sua senha e: %d-%c", s.numero, s.canal);
                        getchar();
                        getchar();
                }
                else if(op==3){
                        /*@override
                        do código do caixa*/
                        struct senha s;

                        s.canal = 'C';

                        //implementa número vindo do txt
                        s.numero = seqPref;

                        //imprimeFila(caixa); //teste de impressão dos dados na lista; VAI SER USADO PARA PASSAR TODAS INFORMAÇÕES PARA O ARQUIVO DE TEXTO.
                        seqPref++;

                        //Cadastra no arquivo de texto
                        CadastraPreferencial(s.numero, s.canal);

                        //imprime a senha que foi escolhida para o usuário.
                        printf("Sua senha e: %d-%c", s.numero, s.canal);
                        getchar();
                        getchar();
                }
                else{
                    printf("\t\t\t\t\tOpcao invalida, retornando ao MENU principal!\n");
                    getchar();
                    getchar();
                }

                break;
            case 2:
                system("cls");
                printf("\nInforme qual canal de senhas desenha listar:\n1-Normal\t2-Prefencial\t3-Caixa\n\n");
                scanf("%d", &op);
                switch(op){
                    case 1:
                        system("cls");
                        printf("Senhas da fila Normal:\n");
                        ListarNormal();
                        getchar();
                        getchar();
                        break;
                    case 2:
                        system("cls");
                        printf("Senhas da fila Preferencial:\n");
                        ListarPreferencial();
                        getchar();
                        getchar();
                        break;
                    case 3:
                        system("cls");
                        printf("Senhas do Caixa:\n");
                        ListarCaixa();
                        getchar();
                        getchar();
                        break;
                    default:
                        system("cls");
                        printf("\t\t\t\t\tOpcao invalida, retornando ao MENU principal!\n");
                        getchar();
                        getchar();
                }
                system("cls");//substituir cls por clear no linux
                //printf("Senhas: \n");
                //getchar();
                //getchar();
               break;
            case 3:
                system("cls");
                printf("Espere um momento, dados sendo apagados...\n");
                Sleep(3000);
                zerarDados();
                seqNormal = PegarSeqNormal()+1;
                seqCaixa = PegarSeqCaixa()+1;
                seqPref = PegarSeqPreferencial()+1;
                break;


            case 0:
                system("cls");
                printf("\t\t\t\tPressione qualquer tecla para sair do Gerar Senhas Systems");
                getchar();
                getchar();
                opc = 0;
                break;

        }
    }


    return 0;
}
