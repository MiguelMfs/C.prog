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
    Lutador** lutadores; // Array of pointers to Lutadores
    struct _torneio* prox;
} Torneio;

typedef struct _no {
    void* elemento;
    struct _no* prox;
} No;

typedef struct _lista {
    No* primeiro;
    No* ultimo;
    int tamanho;
} Lista;

Lista* criarLista() {
    Lista* novaLista = malloc(sizeof(Lista));
    novaLista->primeiro = NULL;
    novaLista->ultimo = NULL;
    novaLista->tamanho = 0;
    return novaLista;
}

void inserirElemento(Lista* lista, void* novoElemento) {
    No* novoNo = malloc(sizeof(No));
    novoNo->elemento = novoElemento;
    novoNo->prox = NULL;

    if (lista->tamanho == 0) {
        lista->primeiro = novoNo;
        lista->ultimo = novoNo;
        lista->tamanho++;
    } else {
        lista->ultimo->prox = novoNo;
        lista->ultimo = novoNo;
        lista->tamanho++;
    }
}

void* buscar(Lista* lista, int indice) {
    No* aux = lista->primeiro;
    int i;
    for (i = 0; i < indice; i++) {
        aux = aux->prox;
    }
    return aux->elemento;
}

void remover(Lista* lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Indice invalido, impossivel remover elemento!\n");
        return;
    }

    No* aux = lista->primeiro;
    No* elemento;

    if (indice == 0) {
        elemento = lista->primeiro;
        lista->primeiro = lista->primeiro->prox;
        lista->tamanho--;
        if (lista->tamanho == 0)
            lista->ultimo = NULL;
    } else {
        int i;
        for (i = 0; i < indice - 1; i++) {
            aux = aux->prox;
        }
        elemento = aux->prox;
        aux->prox = aux->prox->prox;
        if (indice == lista->tamanho - 1) {
            lista->ultimo = aux;
        }
        lista->tamanho--;
    }

    free(elemento->elemento);
    free(elemento);
}

void listarLutadores(Lista* lista) {
    No* aux = lista->primeiro;
    int indice = 0;
    while (aux != NULL) {
        Lutador* lutador = (Lutador*)aux->elemento;
        printf("Indice: %d - Nome: %s - Altura: %.2f - Peso: %.2f - Idade: %d\n",
               indice, lutador->nome, lutador->altura, lutador->peso, lutador->idade);
        aux = aux->prox;
        indice++;
    }
    printf("\n\n");
}

void listarTorneios(Lista* lista) {
    No* aux = lista->primeiro;
    int indice = 0;
    while (aux != NULL) {
        Torneio* torneio = (Torneio*)aux->elemento;
        printf("Nome do Torneio: %s - Num Lutadores: %d\n", torneio->nome, torneio->numLutadores);
        aux = aux->prox;
        indice++;
    }
    printf("\n\n");
}

void editarCaracteristicaLutador(Lista *listaLutadores) {
    if (listaLutadores->tamanho == 0) {
        printf("Nenhum lutador cadastrado. Cadastre um lutador antes de editar caracteristicas.\n");
        return;
    }

    printf("Digite o indice do lutador que deseja editar:\n");
    listarLutadores(listaLutadores);

    int indiceLutador;
    scanf("%d", &indiceLutador);

    if (indiceLutador >= 0 && indiceLutador < listaLutadores->tamanho) {
        Lutador* lutador = (Lutador*)buscar(listaLutadores, indiceLutador);

        printf("Escolha a caracteristica a ser editada:\n");
        printf("1 - Nome\n");
        printf("2 - Altura\n");
        printf("3 - Peso\n");
        printf("4 - Idade\n");

        int opcaoCaracteristica;
        scanf("%d", &opcaoCaracteristica);

        switch (opcaoCaracteristica) {
            case 1:
                printf("Digite o novo nome: ");
                scanf("%s", lutador->nome);
                break;
            case 2:
                printf("Digite a nova altura: ");
                scanf("%f", &lutador->altura);
                break;
            case 3:
                printf("Digite o novo peso: ");
                scanf("%f", &lutador->peso);
                break;
            case 4:
                printf("Digite a nova idade: ");
                scanf("%d", &lutador->idade);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } else {
        printf("Indice de lutador invalido! Tente novamente.\n");
    }
}

Lutador* obterInfoLutador() {
    Lutador* novoLutador = malloc(sizeof(Lutador));

    printf("Digite o nome do lutador: ");
    scanf("%s", novoLutador->nome);

    printf("Digite a altura do lutador: ");
    scanf("%f", &novoLutador->altura);

    printf("Digite o peso do lutador: ");
    scanf("%f", &novoLutador->peso);

    printf("Digite a idade do lutador: ");
    scanf("%d", &novoLutador->idade);

    novoLutador->prox = NULL;

    return novoLutador;
}

Torneio* obterInfoTorneio(Lista* listaLutadores) {
    Torneio* novoTorneio = malloc(sizeof(Torneio));

    printf("Digite o nome do torneio: ");
    scanf("%s", novoTorneio->nome);

    printf("Digite o local do torneio: ");
    scanf("%s", novoTorneio->local);

    printf("Digite a categoria do torneio: ");
    scanf("%s", novoTorneio->categoria);

    printf("Digite o numero de lutadores no torneio: ");
    scanf("%d", &novoTorneio->numLutadores);

    if (novoTorneio->numLutadores > listaLutadores->tamanho) {
        printf("\nNao ha lutadores suficientes cadastrados! Cadastre mais lutadores antes de prosseguir\n");
        free(novoTorneio);
        return NULL; // Return NULL to indicate failure
    }

    novoTorneio->lutadores = malloc(sizeof(Lutador*) * novoTorneio->numLutadores);

    for (int i = 0; i < novoTorneio->numLutadores; i++) {
        int indiceLutador;
        printf("Digite o indice do lutador para adicionar ao torneio:\n");
        listarLutadores(listaLutadores);
        scanf("%d", &indiceLutador);

        if (indiceLutador >= 0 && indiceLutador < listaLutadores->tamanho) {
            novoTorneio->lutadores[i] = (Lutador*)buscar(listaLutadores, indiceLutador);
        } else {
            printf("Indice de lutador invalido! Tente novamente.\n");
            i--; 
        }
    }

    novoTorneio->prox = NULL;

    return novoTorneio;
}

int exibirMenu() {
    int opcao;
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
    return opcao;
}

int main() {
    Lista* listaLutadores = criarLista();
    Lista* listaTorneios = criarLista();
    int opcao;

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1: {
                Lutador* novoLutador = obterInfoLutador();
                inserirElemento(listaLutadores, novoLutador);
                break;
            }
            case 2: {
                editarCaracteristicaLutador(listaLutadores);
                break;
            }
            case 3: {
                listarLutadores(listaLutadores);
                break;
            }
            case 4: {
                Torneio* novoTorneio = obterInfoTorneio(listaLutadores);
                inserirElemento(listaTorneios, novoTorneio);
                break;
            }
            case 5: {
                listarTorneios(listaTorneios);                
            break;
            }
            case 6: {
                // Editar nome, adicionar ou remover Lutadores do Torneio
                //EditarTorneio(listaTorneios);
                break;
            }
            case 7: {
                // Deletar Torneio
                // DeletarTorneio(listaTorneios);
                break;
            }
            case 8: {
                No* aux = listaLutadores->primeiro;
                while (aux != NULL) {
                    No* prox = aux->prox;
                    free(aux->elemento);
                    free(aux);
                    aux = prox;
                }

                aux = listaTorneios->primeiro;
                while (aux != NULL) {
                    No* prox = aux->prox;
                    free(((Torneio*)aux->elemento)->lutadores);
                    free(aux->elemento);
                    free(aux);
                    aux = prox;
                }

                free(listaLutadores);
                free(listaTorneios);

                return 0;
            }
            default: {
                printf("Opcao invalida! Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 8);

    return 0;
}
