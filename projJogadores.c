#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _jogador {
    char nome[40];
    float altura;
    int numCamisa, idade, titulosCarreira;
} Jogador;

typedef struct _timeBasquete {
    char nome[40];
    char tecnico[40];
    char conferencia[40];
    int numTitulos, anoFundacao, numJogadores;
    Jogador jogadores[100];
} TimeBasquete;

TimeBasquete cadastrarTime() {
    
    TimeBasquete novoTime;
    printf("Escreva o nome do Time:");
    scanf(" %[^\n]s", novoTime.nome);
    printf("Escreva o nome do Tecnico do Time:");
    scanf(" %[^\n]s", novoTime.tecnico);
    printf("Escreva a qual conferencia esse time pertence:");
    scanf(" %[^\n]s", novoTime.conferencia);
    printf("Escreva quantos titulos esse time possui:");
    scanf(" %d", &novoTime.numTitulos);
    printf("Escreva o ano de Fundacao do Time:");
    scanf(" %d", &novoTime.anoFundacao);
    printf("\n");
    novoTime.numJogadores = 0;

    return novoTime;
}


void listarTimes(TimeBasquete basquete[], int numTimes) {
    int i;
    for(i=0;i<numTimes;i++) {
        printf("Nome do Time - %d: - %s\n",i+1,basquete[i].nome);
        printf("\n");
    }
}

void editarTime(TimeBasquete basquete[], int numTimes) {
    char nomeTimes[50];
    int i, opcao;

    printf("Escreva o nome do Time que deseja editar: \n");
    scanf(" %[^\n]s",nomeTimes);
    
    for(i=0; i<numTimes; i++) {
        if(strcmp(nomeTimes, basquete[i].nome) == 0) {
            //compara duas strings 
            printf("Digite:\n ");
            printf("\n1 - Para editar o nome do Time: ");
            scanf(" %d", &opcao);
            printf("\n1 - Para editar o tecnico do Time: ");
            scanf(" %d", &opcao);
            printf("\n1 - Para editar a conferencia do Time: ");
            scanf(" %d", &opcao);
            printf("\n1 - Para editar o numero de Titulos: ");
            scanf(" %d", &opcao);
            printf("\n1 - Para editar o ano de Fundacao do Time:\n ");
            scanf(" %d", &opcao);
    
            
            scanf(" %d", &opcao);
            switch(opcao) {
                case 1:
                    printf("Digite o novo nome do Time: ");
                    scanf(" %[^\n]s", basquete[i].nome);
                break;
                case 2:
                    printf("Digite o novo tecnico do Time: ");
                    scanf(" %[^\n]s", basquete[i].tecnico);
                break;
                case 3:
                    printf("Digite a nova conferencia do Time: ");
                    scanf(" %[^\n]s", basquete[i].conferencia);
                break;
                case 4:
                    printf("Digite o novo numero de titulos do Time: ");
                    scanf(" %d", &basquete[i].numTitulos);
                break;
                case 5:
                    printf("Digite o novo ano de Fundacao do Time: ");
                    scanf(" %d", &basquete[i].anoFundacao);
                break;
                default:
                    printf("Opcao Invalida!\n\n");
                    return;
            }
            printf("Operacao realizada com sucesso!\n\n");
            return;
        }
    }
    printf("Time nao encontrado!\n\n");
}

void removerTime(TimeBasquete basquete[], int numTimes) {

    char nomeTime[50];
    int i, encontrei = 0;

    printf("Escreva o nome do Time que deseja remover: \n");
    scanf(" %[^\n]s", nomeTime);

    for(i=0;i<numTimes;i++) {
        if(strcmp(nomeTime, basquete[i].nome) == 0) {
                encontrei = 1;
            }
        if(encontrei) {
            if(i<numTimes-1) //verifica se existe algo na proxima posicao do vetor 
                basquete[i] = basquete[i+1];
        }
    }
    if(encontrei)  {
        printf("Operacao realizada com sucesso!\n\n");
    } else {
        printf("Time nao encontrado!\n\n");
    }
}

Jogador cadastrarJogador() {
    Jogador novoJodador;
    printf("Escreva o nome do Jogador:");
    scanf(" %[^\n]s", novoJodador.nome);
    printf("Escreva a altura do Jogador:");
    scanf(" %f", &novoJodador.altura);
    printf("Escreva o numero da camisa do Jogador:");
    scanf(" %d", &novoJodador.numCamisa);
    printf("Escreva a idade do Jogador:");
    scanf(" %d", &novoJodador.idade);
    printf("Escreva o numero de Titulos da carreira do Jogador:");
    scanf(" %d", &novoJodador.titulosCarreira);

    return novoJodador;
}

void listarJogador(Jogador jogadores[], int numJogadores) {
    int i;
    for(i=0;i<numJogadores;i++) {
        printf("Nome do Jogador - %d: - %s\n",i+1,jogadores[i].nome);
        printf("\n");
    }
}

void editarJogador(Jogador jogadores[], int numJogadores) {
    char nomeJogadores[50];
    int i, opcao;

    printf("Escreva o nome do Jogador que deseja editar: \n");
    scanf(" %[^\n]s",nomeJogadores);
    
    for(i=0; i<numJogadores; i++) {
        if(strcmp(nomeJogadores, jogadores[i].nome) == 0) {
            //compara duas strings 
            printf("Digite:\n ");
            printf("\n1 - Para editar o nome do Jogador: ");
            scanf(" %d", &opcao);
            printf("\n1 - Para editar a altura do Jogador: ");
            scanf(" %f", &opcao);
            printf("\n1 - Para editar o numero da camisa do Jogador: ");
            scanf(" %d", &opcao);
            printf("\n1 - Para editar a idade do Jogador: ");
            scanf(" %d", &opcao);
            printf("\n1 - Para editar o numero de Titulos da carreira do Jogador:\n ");
            scanf(" %d", &opcao);
    
            
            scanf(" %d", &opcao);
            switch(opcao) {
                case 1:
                    printf("Digite o novo nome do Time: ");
                    scanf(" %[^\n]s", jogadores[i].nome);
                break;
                case 2:
                    printf("Digite o novo tecnico do Time: ");
                    scanf(" %f", &jogadores[i].altura);
                break;
                case 3:
                    printf("Digite a nova conferencia do Time: ");
                    scanf(" %d", &jogadores[i].numCamisa);
                break;
                case 4:
                    printf("Digite o novo numero de titulos do Time: ");
                    scanf(" %d", &jogadores[i].idade);
                break;
                case 5:
                    printf("Digite o novo ano de Fundacao do Time: ");
                    scanf(" %d", &jogadores[i].titulosCarreira);
                break;
                default:
                    printf("Opcao Invalida!\n\n");
                    return;
            }
            printf("Operacao realizada com sucesso!\n\n");
            return;
        }
    }
    printf("Time nao encontrado!\n\n");
}

int main()
{
    TimeBasquete basquete[100];
    int numTimes = 0;
    int opcao,selecionarTime, opcaoJogador;

    while(1) {
        printf("Digite:\n");
        printf("\n1 - Cadastrar um novo time de Basquete:");
        printf("\n2 - Listar todos os times de Basquete:");
        printf("\n3 - Editar um elemento do time de Basquete:");
        printf("\n4 - Remover um elemento do time de Basquete:");
        printf("\n5 - Criar, editar ou remover um Jogador do time de Basquete:");
        printf("\n6 - Sair do programa:\n");
        scanf("%d", &opcao);
        printf("\n\n");

        switch (opcao)
        {
        case 1:
            basquete[numTimes] = cadastrarTime();
            numTimes++;
            break;
        case 2:
            listarTimes(basquete, numTimes);
            break;
        case 3:
            editarTime(basquete, numTimes);
            break;
        case 4:
            removerTime(basquete, numTimes);
            numTimes--;
            break;
        case 5:
            listarTimes(basquete, numTimes);
            printf("\n\n");
            printf("Selecione o time no qual deseja editar os jogadores:\n");
            scanf(" %d", &selecionarTime);
            if(selecionarTime>0 && selecionarTime<=numTimes) {
                printf("Digite:\n");
                printf("\n1 - Cadastrar um novo Jogador:");
                printf("\n2 - Listar todos os Jogadores:");
                printf("\n3 - Editar os dados de um Jogador:");
                printf("\n4 - Remover um Jogador:");
                printf("\n5 - Sair do programa:\n");
                scanf(" %d", &opcaoJogador);
                printf("\n\n");

                switch (opcaoJogador)
                {
                case 1:
                    basquete[selecionarTime-1].jogadores[basquete[selecionarTime-1].numJogadores] = cadastrarJogador();
                    basquete[selecionarTime-1].numJogadores++;
                    break;
                case 2:
                    listarJogadores(basquete[selecionarTime-1].jogadores, basquete[selecionarTime-1].numJogadores);
                    break;
                case 3:
                    editarJogadores(basquete[selecionarTime-1].jogadores, basquete[selecionarTime-1].numJogadores);
                    break;
                case 4:
                    removerJogadores(basquete[selecionarTime-1].jogadores, basquete[selecionarTime-1].numJogadores);
                    basquete[selecionarTime-1].numJogadores--;
                    break;
                default:
                }
            } else {
                printf("Opcao inexistente!\n\n");
            }
            
            break;
        case 6:
            break;
        default:
            printf("Opcao Invalida!\n\n");
        }
    
    }
    
}
