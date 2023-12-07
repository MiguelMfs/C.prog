#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int TEMPO_MAXIMO = 90000;

// Função de Bubble Sort
void bubbleSort(int vetor[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                // Troca os elementos se estiverem fora de ordem
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

// Função de Insertion Sort
void insertionSort(int vetor[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        // Move os elementos do vetor[0..i-1] que são maiores que a chave
        // para uma posição à frente de sua posição atual
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

// Função de Selection Sort
void selectionSort(int vetor[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (vetor[j] < vetor[min_index]) {
                // Encontra o menor elemento
                min_index = j;
            }
        }
        // Troca o elemento mínimo com o primeiro não ordenado
        temp = vetor[min_index];
        vetor[min_index] = vetor[i];
        vetor[i] = temp;
    }
}

// Função de Merge Sort
void merge(int vetor[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria vetores temporários
    int L[n1], R[n2];

    // Copia os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[m + 1 + j];

    // Junta os vetores temporários de volta ao vetor[l..r]
    i = 0; // Índice inicial do primeiro subvetor
    j = 0; // Índice inicial do segundo subvetor
    k = l; // Índice inicial do subvetor mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int vetor[], int l, int r) {
    if (l < r) {
        // Encontra o ponto médio
        int m = l + (r - l) / 2;

        // Ordena as duas metades
        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);

        // Junta as duas metades ordenadas
        merge(vetor, l, m, r);
    }
}

// Função de Quick Sort
int partition(int vetor[], int low, int high) {
    int pivot = vetor[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vetor[j] < pivot) {
            i++;
            // Troca vetor[i] e vetor[j]
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    // Troca vetor[i + 1] e vetor[high] (pivô)
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[high];
    vetor[high] = temp;

    return (i + 1);
}
void quickSort(int vetor[], int low, int high) {
    if (low < high) {
        // Encontra o índice de particionamento
        int pi = partition(vetor, low, high);

        // Ordena os elementos à esquerda e à direita do índice de particionamento
        quickSort(vetor, low, pi - 1);
        quickSort(vetor, pi + 1, high);
    }
}

void medirTempoExecucao(int vetor[], int tamanho, char *nomeAlgoritmo, char *ordem) {
    clock_t start_time = clock();

    // Escolha do algoritmo
    if (strcmp(nomeAlgoritmo, "Bubble Sort") == 0) {
        bubbleSort(vetor, tamanho);
    } else if (strcmp(nomeAlgoritmo, "Insertion Sort") == 0) {
        insertionSort(vetor, tamanho);
    } else if (strcmp(nomeAlgoritmo, "Selection Sort") == 0) {
        selectionSort(vetor, tamanho);
    } else if (strcmp(nomeAlgoritmo, "Merge Sort") == 0) {
        mergeSort(vetor, 0, tamanho - 1);
    } else if (strcmp(nomeAlgoritmo, "Quick Sort") == 0) {
        quickSort(vetor, 0, tamanho - 1);
    }

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao para %s com vetor %s: %f segundos\n", nomeAlgoritmo, ordem, time_taken);

    // Verifica se o tempo de execução excede o limite máximo
    if (time_taken > TEMPO_MAXIMO) {
        printf("A execucao demorou mais que %d segundos. Interrompendo o programa.\n", TEMPO_MAXIMO);
        exit(EXIT_FAILURE); // Ou tome outras medidas, como retornar um código de erro, dependendo do seu caso.
    }
}


int main() {
    int TAMANHO_VETOR = 500000;
    srand(time(NULL));

    // Aloca espaço dinamicamente para os vetores
    int *vetorAleatorio = (int *)calloc(TAMANHO_VETOR, sizeof(int));
    int *vetorCrescente = (int *)calloc(TAMANHO_VETOR, sizeof(int));
    int *vetorDecrescente = (int *)calloc(TAMANHO_VETOR, sizeof(int));

    if (vetorAleatorio == NULL || vetorCrescente == NULL || vetorDecrescente == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    // Popula os vetores aleatório, crescente e decrescente
    for (int i = 0; i < TAMANHO_VETOR; ++i) {
        vetorAleatorio[i] = rand();
        vetorCrescente[i] = i;
        vetorDecrescente[i] = TAMANHO_VETOR - i;
    }

    int opcao;
    printf("Escolha o algoritmo de ordenacao:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("Digite o numero correspondente ao algoritmo desejado: ");
    scanf("%d", &opcao);

    char *nomeAlgoritmo;
    switch (opcao) {
        case 1:
            nomeAlgoritmo = "Bubble Sort";
            break;
        case 2:
            nomeAlgoritmo = "Insertion Sort";
            break;
        case 3:
            nomeAlgoritmo = "Selection Sort";
            break;
        case 4:
            nomeAlgoritmo = "Merge Sort";
            break;
        case 5:
            nomeAlgoritmo = "Quick Sort";
            break;
        default:
            printf("Opcao invalida. Saindo do programa.\n");
            free(vetorAleatorio);
            free(vetorCrescente);
            free(vetorDecrescente);
            return 0;
    }

    printf("\nMede o tempo de execucao para o vetor ordenado de forma crescente\n");
    medirTempoExecucao(vetorCrescente, TAMANHO_VETOR, nomeAlgoritmo, "ordenado de forma crescente");

    printf("\nMede o tempo de execucao para o vetor ordenado de forma decrescente\n");
    medirTempoExecucao(vetorDecrescente, TAMANHO_VETOR, nomeAlgoritmo, "ordenado de forma decrescente");

    printf("\nMede o tempo de execucao para o vetor ordenado aleatoriamente\n");
    medirTempoExecucao(vetorAleatorio, TAMANHO_VETOR, nomeAlgoritmo, "ordenado aleatoriamente");

    // Libera a memória alocada para os vetores
    free(vetorAleatorio);
    free(vetorCrescente);
    free(vetorDecrescente);

    return 0;
}
