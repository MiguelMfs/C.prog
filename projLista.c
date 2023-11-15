#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _lutador {
    char nome[40];
    float altura, peso;
    int idade;
    struct _lutador* prox;
} Lutador;

typedef struct _torneio {
    char nome[40];
    char local[40];
    char categoria[40];
    int numLutadores;
    Lutador* lutadores;
    struct _torneio* prox;
} Torneio;

Lutador* cadastrarLutador() {
    Lutador* novoLutador = malloc(sizeof(Lutador));
    printf("Digite o nome do lutador: ");
    scanf(" %[^\n]s", novoLutador->nome);
    printf("Digite a altura do lutador: ");
    scanf("%f", &novoLutador->altura);
    printf("Digite o peso do lutador: ");
    scanf("%f", &novoLutador->peso);
    printf("Digite a idade do lutador: ");
    scanf("%d", &novoLutador->idade);
    novoLutador->prox = NULL;
    return novoLutador;
}

Torneio* cadastrarTorneio() {
    Torneio* novoTorneio = malloc(sizeof(Torneio));
    novoTorneio->numLutadores = 0;
    novoTorneio->lutadores = NULL;
    printf("Digite o nome do Torneio: ");
    scanf(" %[^\n]s", novoTorneio->nome);
    printf("Digite o local do Torneio: ");
    scanf(" %[^\n]s", novoTorneio->local);
    printf("Digite a categoria de lutas do Torneio: ");
    scanf(" %[^\n]s", novoTorneio->categoria);
    novoTorneio->prox = NULL;
    return novoTorneio;
}

void editarLutador(Lutador* lutador) {
    int opcao;

    printf("\n1 - Para editar o nome do Lutador\n");
    printf("2 - Para editar a altura do Lutador\n");
    printf("3 - Para editar o peso do Lutador\n");
    printf("4 - Para editar a idade do Lutador\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
        printf("Digite o novo nome do Lutador: ");
        scanf(" %[^\n]s", lutador->nome);
        break;
    case 2:
        printf("Digite a nova altura do Lutador: ");
        scanf("%f", &lutador->altura);
        break;
    case 3:
        printf("Digite o novo peso do Lutador: ");
        scanf("%f", &lutador->peso);
        break;
    case 4:
        printf("Digite a nova idade do Lutador: ");
        scanf("%d", &lutador->idade);
        break;
    default:
        printf("Opcao invalida!\n");
    }
}

void listarLutadores(Lutador* lutadores) {
    while (lutadores != NULL) {
        printf(" %s\n", lutadores->nome);
        lutadores = lutadores->prox;
    }
}

void editarTorneio(Torneio* torneio) {
    int opcao;

    printf("\n1 - Para editar o nome do Torneio\n");
    printf("2 - Para editar o local do Torneio\n");
    printf("3 - Para editar a categoria do Torneio\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
        printf("Digite o novo nome do Torneio: ");
        scanf(" %[^\n]s", torneio->nome);
        break;
    case 2:
        printf("Digite o novo local do Torneio: ");
        scanf(" %[^\n]s", torneio->local);
        break;
    case 3:
        printf("Digite a nova categoria de luta do Torneio: ");
        scanf(" %[^\n]s", torneio->categoria);
        break;
    default:
        printf("Opcao invalida!\n");
    }
}

void listarTorneios(Torneio* torneios) {
    while (torneios != NULL) {
        printf("Torneio: %s\n", torneios->nome);
        printf("Lutadores no Torneio:\n");
        listarLutadores(torneios->lutadores);
        printf("\n");
        torneios = torneios->prox;
    }
}

void adicionarLutadorAoTorneio(Torneio* torneio, Lutador* lutador) {
    Lutador* novoLutador = malloc(sizeof(Lutador));
    strcpy(novoLutador->nome, lutador->nome);
    novoLutador->altura = lutador->altura;
    novoLutador->peso = lutador->peso;
    novoLutador->idade = lutador->idade;
    novoLutador->prox = torneio->lutadores;
    torneio->lutadores = novoLutador;
    torneio->numLutadores++;
}

int main() {
    Lutador* lutadores = NULL;
    Torneio* torneios = NULL;
    int opcao, opcaoLutador;
    char sair, reiniciar;

    do {
        printf("\n\n\tMENU\n");
        printf("1 - Cadastrar um novo Lutador\n");
        printf("2 - Editar uma caracteristica do Lutador\n");
        printf("3 - Listar todos os Lutadores\n");
        printf("4 - Cadastrar Torneio\n");
        printf("5 - Listar Torneios\n");
        printf("6 - Editar nome, adicionar ou remover Lutadores do Torneio\n");
        printf("7 - Deletar Torneio\n");
        printf("8 - Sair do programa\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        printf("\n\n");

        switch (opcao) {
        case 1:
            lutadores = cadastrarLutador();
            break;
        case 2:
            listarLutadores(lutadores);
            char nomeLutador[40];
            printf("\nEscreva o nome do Lutador que deseja editar: ");
            scanf(" %[^\n]s", nomeLutador);
            Lutador* current = lutadores;
            while (current != NULL) {
                if (strcmp(nomeLutador, current->nome) == 0) {
                    editarLutador(current);
                    break;
                }
                current = current->prox;
            }
            break;
        case 3:
            listarLutadores(lutadores);
            break;
        case 4:
            torneios = cadastrarTorneio();
            break;
        case 5:
            listarTorneios(torneios);
            break;
        case 6:
            if (torneios == NULL) {
                printf("\nNenhum Torneio foi cadastrado para realizar edicoes.\n");
            } else {
                do {
                    char nomeTorneio[40];
                    printf("1 - Para editar o nome do Torneio\n");
                    printf("2 - Para adicionar um Lutador ao Torneio\n");
                    printf("3 - Para voltar ao menu principal\n");
                    printf("Selecione uma opcao: ");
                    scanf("%d", &opcaoLutador);

                    switch (opcaoLutador) {
                    case 1:
                        listarTorneios(torneios);
                        printf("Escreva o nome do Torneio que deseja editar: ");
                        scanf(" %[^\n]s", nomeTorneio);
                        Torneio* currentTorneio = torneios;
                        while (currentTorneio != NULL) {
                            if (strcmp(nomeTorneio, currentTorneio->nome) == 0) {
                                editarTorneio(currentTorneio);
                                break;
                            }
                            currentTorneio = currentTorneio->prox;
                        }
                        break;
                    case 2:
                        listarTorneios(torneios);
                        char nomeLutador[40];
                        printf("Escreva o nome do Torneio ao qual deseja adicionar um Lutador: ");
                        scanf(" %[^\n]s", nomeTorneio);
                        currentTorneio = torneios;
                        while (currentTorneio != NULL) {
                            if (strcmp(nomeTorneio, currentTorneio->nome) == 0) {
                                listarLutadores(lutadores);
                                printf("Escreva o nome do Lutador que deseja adicionar ao Torneio: ");
                                scanf(" %[^\n]s", nomeLutador);
                                Lutador* currentLutador = lutadores;
                                while (currentLutador != NULL) {
                                    if (strcmp(nomeLutador, currentLutador->nome) == 0) {
                                        adicionarLutadorAoTorneio(currentTorneio, currentLutador);
                                        break;
                                    }
                                    currentLutador = currentLutador->prox;
                                }
                                if (currentLutador == NULL) {
                                    printf("\nLutador nao encontrado.\n");
                                }
                                break;
                            }
                            currentTorneio = currentTorneio->prox;
                        }
                        break;
                    case 3:
                        printf("Deseja voltar ao menu principal? (S/N): ");
                        scanf(" %c", &reiniciar);
                        break;
                    default:
                        printf("\nOpcao inexistente!\n\n");
                    }

                    if (opcaoLutador != 3) {
                        reiniciar = 'n';
                    }
                } while (reiniciar == 'N' || reiniciar == 'n');
            }
            break;
        case 7:
            listarTorneios(torneios);
            char nomeTorneio[40];
            printf("Escreva o nome do Torneio que deseja remover: ");
            scanf(" %[^\n]s", nomeTorneio);
            Torneio* prevTorneio = NULL;
            currentTorneio = torneios;
            while (currentTorneio != NULL) {
                if (strcmp(nomeTorneio, currentTorneio->nome) == 0) {
                    if (prevTorneio == NULL) {
                        torneios = currentTorneio->prox;
                    } else {
                        prevTorneio->prox = currentTorneio->prox;
                    }
                    free(currentTorneio);
                    printf("\nOperacao realizada com sucesso!\n\n");
                    break;
                }
                prevTorneio = currentTorneio;
                currentTorneio = currentTorneio->prox;
            }
            if (currentTorneio == NULL) {
                printf("\nTorneio nao encontrado!\n\n");
            }
            break;
        case 8:
            printf("Deseja sair? (S/N): ");
            scanf(" %c", &sair);
            break;
        default:
            printf("Opcao Invalida!\n");
            break;
        }

        if (opcao != 8) {
            sair = 'n';
        }
    } while (sair == 'N' || sair == 'n');

    // Free allocated memory before exiting
    Lutador* currentLutador = lutadores;
    while (currentLutador != NULL) {
        Lutador* nextLutador = currentLutador->prox;
        free(currentLutador);
        currentLutador = nextLutador;
    }

    Torneio* currentTorneio = torneios;
    while (currentTorneio != NULL) {
        Torneio* nextTorneio = currentTorneio->prox;
        Lutador* currentLutadorInTorneio = currentTorneio->lutadores;
        while (currentLutadorInTorneio != NULL) {
            Lutador* nextLutadorInTorneio = currentLutadorInTorneio->prox;
            free(currentLutadorInTorneio);
            currentLutadorInTorneio = nextLutadorInTorneio;
        }
        free(currentTorneio);
        currentTorneio = nextTorneio;
    }

    return 0;
}
