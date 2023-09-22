#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cantor {
    char nome[40];
    char estiloMusical[40];
    int idade;
} Cantor;

typedef struct _evento {
    char nome[40];
    char categoria[40];
    char local[40];
    int dia, numCantores;
    Cantor cantores[100];
} Evento;

Evento criarEvento(Evento eventoMusic[], int numEventos) {
    
    Evento novoEvento;
    char sair = 'n';
    
    if (numEventos == 0) {
        printf("\nCRIAR NOVO EVENTO\n");
        printf("\nEscreva o nome do Evento:");
        scanf(" %[^\n]s", novoEvento.nome);
        printf("\nEscreva a categoria do Evento:");
        scanf(" %[^\n]s", novoEvento.categoria);
        printf("\nEscreva o local do Evento:");
        scanf(" %[^\n]s", novoEvento.local);
        printf("\nEscreva o dia do Evento:");
        scanf("%d", &novoEvento.dia);
        printf("\n");
    } else {
        do {
            printf("\nEscreva o nome do Evento:");
            scanf(" %[^\n]s", novoEvento.nome);

            int i, nomeExistente = 0;

            for (i = 0; i < numEventos; i++) {
                if (strcasecmp(novoEvento.nome, eventoMusic[i].nome) == 0) {
                    printf("\nEsse Evento ja existe!\n");
                    nomeExistente = 1; 
                    break;             
                }
            }
            if (!nomeExistente) {
                sair = 'n'; 
            }
            else {
                sair = 's';
            }

        } while (sair == 's');

        printf("\nEscreva a categoria do Evento:");
        scanf(" %[^\n]s", novoEvento.categoria);
        printf("\nEscreva o local do Evento:");
        scanf(" %[^\n]s", novoEvento.local);
        printf("\nEscreva o dia do Evento:");
        scanf("%d", &novoEvento.dia);
        printf("\n");
    }
    return novoEvento;
}

void listarEventos(Evento eventoMusic[], int numEventos, int opcao) {
    
    if (numEventos == 0 && opcao == 2) {
        printf("\nNenhum Evento foi cadastrado\n\n");
    }
    else {
        int i;
        for (i = 0; i < numEventos; i++) {
            printf("\nNome do Evento (%d) - %s\n", i + 1, eventoMusic[i].nome);
        }
    }
}

void editarEvento(Evento eventoMusic[], int numEventos) {
    if (numEventos == 0) {
        printf("\nNenhum Evento cadastrado\n\n");
    }
    else {
        char nomeEventos[50];
        int i, opcao;

        printf("\nEscreva o nome do Evento que deseja editar: ");
        scanf(" %[^\n]s", nomeEventos);

        for (i = 0; i < numEventos; i++) {
            if (strcasecmp(nomeEventos, eventoMusic[i].nome) == 0) {
                printf("\n(1) - Para editar o nome do Evento ");
                printf("\n(2) - Para editar a categoria do Evento ");
                printf("\n(3) - Para editar o local do Evento ");
                printf("\n(4) - Para editar o dia do Evento ");
                printf("\n\nSelecione uma opcao :");
                scanf("%d", &opcao);

                switch (opcao) {
                case 1:
                    printf("\n\nEscreva o novo nome: ");
                    scanf(" %[^\n]s", eventoMusic[i].nome);
                    break;
                case 2:
                    printf("Escreva a nova categoria: ");
                    scanf(" %[^\n]s", eventoMusic[i].categoria);
                    break;
                case 3:
                    printf("Escreva o novo local: ");
                    scanf(" %[^\n]s", eventoMusic[i].local);
                    break;
                case 4:
                    printf("Escreva o novo dia: ");
                    scanf("%d", &eventoMusic[i].dia);
                    break;
                default:
                    printf("\nOpcao Invalida!\n\n");
                    return;
                }
                printf("\nOperacao realizada com sucesso!\n\n");
                return;
            }
        }
        printf("\nEvento nao encontrado!\n\n");
    }
}

void removerEvento(Evento eventoMusic[], int numEventos) {
    
    if (numEventos == 0) {
        printf("\nNenhum Evento cadastrado\n\n");
    }
    else {
        char nomeEventos[50];
        int i, encontrei = 0;

        printf("\nEscreva o nome do Evento que deseja remover: ");
        scanf(" %[^\n]s", nomeEventos);

        for (i = 0; i < numEventos; i++) {
            if (strcasecmp(nomeEventos, eventoMusic[i].nome) == 0) {
                encontrei = 1;
            }
            if (encontrei) {
                if (i < numEventos - 1) 
                    eventoMusic[i] = eventoMusic[i + 1];
            }
        }
        if (encontrei) {
            printf("\nOperacao realizada com sucesso!\n\n");
        }
        else {
            printf("\nEvento nao encontrado!\n\n");
        }
    }
}

Cantor cadastrarCantor(Cantor cantores[], int numCantores) {
    
    Cantor novoCantor;
    
        printf("\nCADASTRAR NOVO CANTOR\n");
        printf("\nEscreva o nome do Cantor:");
        scanf(" %[^\n]s", novoCantor.nome);
        printf("\nEscreva o estilo de musica do Cantor:");
        scanf(" %[^\n]s", novoCantor.estiloMusical);
        printf("Escreva a idade do Cantor:");
        scanf("%d", &novoCantor.idade);
        
    return novoCantor;
}

void listarCantores(Cantor cantores[], int numCantores, int opcaoCantor) {
    
    if (numCantores == 0 && opcaoCantor == 2) {
        printf("\nNenhum Cantor cadastrado\n\n");
    }
    else {
        int i;
        for (i = 0; i < numCantores; i++) {
            printf("\nNome do Cantor (%d) - %s\n", i + 1, cantores[i].nome);
        }
    }
}

void editarCantores(Cantor cantores[], int numCantores) {
    if (numCantores == 0) {
        printf("\nNenhum Cantor cadastrado\n\n");
    }
    else {
        char nomeCantor[50];
        int i, opcao;

        printf("\nEscreva o nome do Cantor que deseja editar: ");
        scanf(" %[^\n]s", nomeCantor);

        for (i = 0; i < numCantores; i++) {
            if (strcasecmp(nomeCantor, cantores[i].nome) == 0) {
                printf("\n(1) - Para editar o nome do Cantor");
                printf("\n(2) - Para editar o estilo musical");
                printf("\n(3) - Para editar a idade do Cantor");
                printf("\nSelecione uma opcao:");
                scanf("%d", &opcao);

                switch (opcao) {
                case 1:
                    printf("\nEscreva o novo nome: ");
                    scanf(" %[^\n]s", cantores[i].nome);
                    break;
                case 2:
                    printf("Escreva a nova categoria: ");
                    scanf(" %[^\n]s", cantores[i].estiloMusical);
                    break;
                case 3:
                    printf("Escreva a nova idade: ");
                    scanf("%d", &cantores[i].idade);
                    break;
                default:
                    printf("\nOpcao Invalida!\n\n");
                    return;
                }
                printf("\nOperacao realizada com sucesso!\n\n");
                return;
            }
        }
        printf("\nCantor nao encontrado!\n\n");
    }
    
}

void removerCantores(Cantor cantores[], int numCantores) {
    
    if (numCantores == 0) {
        printf("\nNenhum cantor cadastrado \n\n");
    }
    else {
        char nomeCantores[50];
        int i, achei = 0;

        printf("\nEscreva o nome do cantor que deseja remover: ");
        scanf(" %[^\n]s", nomeCantores);

        for (i = 0; i < numCantores; i++) {
            if (strcasecmp(nomeCantores, cantores[i].nome) == 0) {
                achei = 1;
            }
            if (achei) {
                if (i < numCantores - 1) 
                    cantores[i] = cantores[i + 1];
            }
        }
        if (achei) {
            printf("\nOperacao realizada com sucesso!\n\n");
        }
        else {
            printf("\nCantor nao encontrado!\n\n");
        }
    }
}

int main () {
    
    Evento eventoMusic[100];
    int numEventos = 0;
    int opcao, opcaoCantor, selecionarCantor;
    char reiniciar, sair;
    
    while(1) {
        printf("\n\n\tMENU PRINCIPAL\n");
        printf("\n(1) - Criar um novo Evento");
        printf("\n(2) - Listar todos os Eventos");
        printf("\n(3) - Editar um dado de Evento");
        printf("\n(4) - Remover um Evento");
        printf("\n(5) - Criar, editar ou remover um Cantor do Evento");
        printf("\n(6) - Sair do programa");
        printf("\n\nSelecione uma opcao: ");
        scanf("%d", &opcao);
        printf("\n\n");
        
        switch (opcao) {
        case 1:
            eventoMusic[numEventos] = criarEvento(eventoMusic, numEventos);
            numEventos++;
            break;
        case 2:
            listarEventos(eventoMusic, numEventos, opcao);
            break;
        case 3:
            listarEventos(eventoMusic, numEventos, opcao);
            editarEvento(eventoMusic, numEventos);
            break;
        case 4:
            listarEventos(eventoMusic, numEventos, opcao);
            removerEvento(eventoMusic, numEventos);
            numEventos--;
            break;
        case 5:
            if (numEventos > 0) {
                listarEventos(eventoMusic, numEventos, opcao);
                printf("\n\n");
                printf("Escolha um Evento para adicionar, editar ou remover Cantores\nSelecione:");
                scanf("%d", &selecionarCantor);
                if (selecionarCantor > 0 && selecionarCantor <= numEventos) {
                    do {
                        printf("\n\n\tMENU\n");
                        printf("\n(1) - Cadastrar um novo Cantor");
                        printf("\n(2) - Listar todos os Cantores");
                        printf("\n(3) - Editar os dados de um Cantor");
                        printf("\n(4) - Remover um Cantor");
                        printf("\n(5) - Voltar ao menu principal");
                        printf("\n\nSelecione uma opcao: ");
                        scanf(" %d", &opcaoCantor);
                        printf("\n\n");
                        
                        switch(opcaoCantor) {
                        case 1:
                            eventoMusic[selecionarCantor - 1].cantores[eventoMusic[selecionarCantor - 1].numCantores] = cadastrarCantor(eventoMusic[selecionarCantor - 1].cantores, eventoMusic[selecionarCantor - 1].numCantores);
                            eventoMusic[selecionarCantor - 1].numCantores++;
                            break;
                        case 2:
                            listarCantores(eventoMusic[selecionarCantor-1].cantores, eventoMusic[selecionarCantor-1].numCantores, opcaoCantor);
                            break;
                        case 3:
                            listarCantores(eventoMusic[selecionarCantor-1].cantores, eventoMusic[selecionarCantor-1].numCantores, opcaoCantor);
                            editarCantores(eventoMusic[selecionarCantor-1].cantores, eventoMusic[selecionarCantor-1].numCantores);
                            break;
                        case 4:
                            listarCantores(eventoMusic[selecionarCantor-1].cantores, eventoMusic[selecionarCantor-1].numCantores, opcaoCantor);
                            removerCantores(eventoMusic[selecionarCantor-1].cantores, eventoMusic[selecionarCantor-1].numCantores);
                            eventoMusic[selecionarCantor-1].numCantores--;
                            break;
                        case 5:
                            printf("Deseja voltar ao menu principal? (S/N): ");
                            scanf(" %c", &reiniciar);
                            break;
                        default:
                            printf("\nOpcao inexistente!\n\n");
                        }

                        if (opcaoCantor != 5) {
                            reiniciar = 'n';
                        }

                    } while (reiniciar == 'N' || reiniciar == 'n');
                    break;
                }
                else {
                    printf("\nOpcao inexistente!\n\n");
                }
            }
            else {
                printf("Primeiro crie um Evento\n\n");
            }
            break;
        case 6:
            printf("Deseja sair? (S/N): ");
            scanf(" %c", &sair);
            break;
        default:
            printf("\nOpcao Invalida!\n\n");
        }

        if (opcao != 6) {
            sair = 'n';
        }

    } while (sair == 'N' || sair == 'n');

    return 0;
}
