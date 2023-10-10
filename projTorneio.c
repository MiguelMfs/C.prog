#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _lutador {
    char nome[40];
    float altura, peso;
    int idade;
} Lutador;

typedef struct _torneio {
    char nome[40];
    char local[40];
    char categoria[40];
    int numLutadores;
    Lutador *lutadores[100];
} Torneio;

Lutador *cadastrarLutador(){
    Lutador *novoLutador = malloc(sizeof(Lutador));
    printf ("Digite o nome do lutador: ");
    scanf (" %[^\n]s", novoLutador->nome);
    printf ("Digite a altura do lutador: ");
    scanf("%f", &novoLutador->altura);
    printf ("Digite o peso do lutador: ");
    scanf("%f", &novoLutador->peso);
    printf ("Digite a idade do lutador: ");
    scanf("%d", &novoLutador->idade);
    
    return novoLutador;
}

Torneio *cadastrarTorneio(){
    Torneio *novoTorneio = malloc(sizeof(Torneio));
    printf ("Digite o nome do Torneio: ");
    scanf (" %[^\n]s", novoTorneio->nome);
    printf ("Digite o local do Torneio: ");
    scanf (" %[^\n]s", novoTorneio->local);
    printf ("Digite a categoria de lutas do Torneio: ");
    scanf (" %[^\n]s", novoTorneio->categoria);
 
    return novoTorneio;
}

void editarLutador(Lutador *lutadores[], int numLutadores){
    
    if(numLutadores == 0) {
        printf("\nNenhum Lutador foi cadastrado para realizar edicoes.");
    } else {
        char nomeLutador[50];
        int i, opcao;

        printf("\nEscreva o nome do Lutador que deseja editar: ");
        scanf(" %[^\n]s", nomeLutador);

        for(i=0; i<numLutadores; i++) {
            if (strcasecmp(nomeLutador, lutadores[i]->nome) == 0) {
                printf("\n1 - Para editar o nome do Lutador: ");
                printf("\n2 - Para editar a altura do Lutador: ");
                printf("\n3 - Para editar o peso do Lutador: ");
                printf("\n4 - Para editar a idade do Lutador: ");
                printf("\n\nSelecione uma opcao: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    printf("\nDigite o novo nome do Lutador: ");
                    scanf(" %[^\n]s", lutadores[i]->nome);
                break;
                case 2:
                    printf("\nDigite a nova altura do Lutador: ");
                    scanf("%f", &lutadores[i]->altura);
                break;
                case 3:
                    printf("\nDigite o novo peso do Lutador: ");
                    scanf("%f", &lutadores[i]->peso);
                break;
                case 4:
                    printf("\nDigite a nova idade do Lutador: ");
                    scanf("%d", &lutadores[i]->idade);
                break;
                
                
                default:
                    break;
                }
            }
        }
    
    }
}
void listarLutadores(Lutador *lutadores[], int numLutadores){
    int i;
    for(i=0; i<numLutadores; i++){
        printf(" %s\n", lutadores[i]->nome);
    }
}

void editarTorneio(Torneio *torneios[], int numTorneios) {
    if(numTorneios == 0) {
        printf("\nNenhum Torneio foi cadastrado para realizar edicoes.");
    } else {
        char nomeTorneio[50];
        int i, opcao;

        printf("\nEscreva o nome do Torneio que deseja editar: ");
        scanf(" %[^\n]s", nomeTorneio);

        for(i=0; i<numTorneios; i++) {
            if (strcasecmp(nomeTorneio, torneios[i]->nome) == 0) {
                printf("\n1 - Para editar o nome do Torneio: ");
                printf("\n2 - Para editar o local do Torneio: ");
                printf("\n3 - Para editar a categoria do Torneio: ");
                printf("\n\nSelecione uma opcao: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    printf("\nDigite o novo nome do Torneio: ");
                    scanf(" %[^\n]s", torneios[i]->nome);
                break;
                case 2:
                    printf("\nDigite o novo local do Torneio: ");
                    scanf(" %[^\n]s", torneios[i]->local);
                break;
                case 3:
                    printf("\nDigite a nova categoria de luta do Torneio: ");
                    scanf(" %[^\n]s", torneios[i]->categoria);
                break;
                
                
                default:
                    break;
                }
            }
        }
    
    }
}

void listarTorneios(Torneio *torneios[], int numTorneios) {
    int i;
    for(i=0; i<numTorneios; i++){
        printf(" %s\n", torneios[i]->nome);
    }
}

int main(){
    Lutador *lutadores[100];
    Torneio *torneios[100];
    int opcao; 
    int numTorneios = 0;
    int numLutadores = 0;
    char sair;
    

    do {
        printf("\n\n\tMENU\n");
        printf("\n1 - Cadastrar um novo Lutador:");
        printf("\n2 - Editar uma caracteristica do Lutador:");
        printf("\n3 - Listar todos os Lutadores:");
        printf("\n4 - Cadastrar Torneio:");
        printf("\n5 - Listar Torneios:");
        printf("\n6 - Editar nome, adicionar ou remover Lutadores do Torneio:");
        printf("\n7 - Deletar Torneio:");
        printf("\n8 - Sair do programa");
        printf("\n\nSelecione uma opcao: ");
        scanf("%d", &opcao);
        printf("\n\n");

        switch (opcao){
        case 1: 
        lutadores[numLutadores] = cadastrarLutador();
        numLutadores++;
            break;
        case 2: 
        listarLutadores(lutadores, numLutadores);
        editarLutador(lutadores, numLutadores);
            break;
        case 3: 
        listarLutadores(lutadores, numLutadores);
            break;
        case 4: 
        torneios[numTorneios] = cadastrarTorneio();
        numTorneios++;
            break;
        case 5: 
        listarTorneios(torneios, numTorneios);
            break;
        case 6:
            if(numTorneios == 0) {
                printf("\nNenhum Torneio foi cadastrado para realizar edicoes.");
            } else {
            
                char nomeTorneio[50];
                int i, opcao, opcaoJogador;
        
                listarTorneios(torneios, numTorneios);
        
                printf("\nEscreva o nome do Torneio que deseja editar: ");
                scanf(" %[^\n]s", nomeTorneio);

                for(i=0; i<numTorneios; i++) {
                    if (strcasecmp(nomeTorneio, torneios[i]->nome) == 0) {
                        printf("\n1 - Para editar o nome do Torneio: ");
                        printf("\n2 - Para adicionar um Lutador ao Torneio: ");
                        printf("\n3 - Para remover um lutador do Torneio: ");
                        printf("\n\nSelecione uma opcao: ");
                        scanf("%d", &opcao);

                switch (opcao){
                case 1:
                    printf("\nDigite o novo nome do Torneio: ");
                    scanf(" %[^\n]s", torneios[i]->nome);
                break;
                case 2:
                    if (torneios[i]->numLutadores >= 100) {
                        printf("\nO Torneio ja possui o numero maximo de lutadores.");
                } else {
                    int j;
                    listarLutadores(lutadores, numLutadores);
                    printf("\nEscolha o lutador a ser adicionado: ");

                    if (strcasecmp(nomeTorneio, torneios[i]->nome) == 0) {
                        Lutador *lutadorSelecionado = lutadores[opcao - 1];
                        torneios[i]->lutadores[torneios[i]->numLutadores] = lutadorSelecionado;
                        torneios[i]->numLutadores++;
                         printf("%s adicionado ao Torneio %s.\n", lutadorSelecionado->nome, torneios[i]->nome);
                    } else {
                    printf("\nLutador invalido. Escolha um lutador valido.");
                    }
                }
                break;
                case 3:
                
                break;
                }
            
            }  
        }      
    }    

            break;
        case 7:
            break;
        case 8: 
            printf("Deseja sair? (S/N): ");
            scanf(" %c", &sair);
            break;

        default:    
            puts("Opcao Invalida!");
            break;
        }

        if (opcao != 8) {
            sair = 'n';
        }


    } while (sair == 'N' || sair == 'n');
    
    return 0;
}
