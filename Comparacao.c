#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
}


int main() {

    int TAMANHO_VETOR = 5000;
    // Inicializa a semente do gerador de números aleatórios
    srand(time(NULL));

    // Cria e popula o vetor aleatoriamente
    int vetorAleatorio[TAMANHO_VETOR];
    for (int i = 0; i < TAMANHO_VETOR; ++i) {
        vetorAleatorio[i] = rand();
    }

    // Cria cópias do vetor para os casos ordenados
    int vetorCrescente[TAMANHO_VETOR];
    int vetorDecrescente[TAMANHO_VETOR];

    for (int i = 0; i < TAMANHO_VETOR; ++i) {
        vetorCrescente[i] = i;
        vetorDecrescente[i] = TAMANHO_VETOR - i;
    }

    printf("Mede o tempo de execucao para o vetor ordenado de forma crescente\n");
    medirTempoExecucao(vetorCrescente, TAMANHO_VETOR, "Bubble Sort", "ordenado de forma crescente");
    medirTempoExecucao(vetorCrescente, TAMANHO_VETOR, "Insertion Sort", "ordenado de forma crescente");
    medirTempoExecucao(vetorCrescente, TAMANHO_VETOR, "Selection Sort", "ordenado de forma crescente");
    medirTempoExecucao(vetorCrescente, TAMANHO_VETOR, "Merge Sort", "ordenado de forma crescente");
    medirTempoExecucao(vetorCrescente, TAMANHO_VETOR, "Quick Sort", "ordenado de forma crescente");
    printf("\n\n");

    printf("Mede o tempo de execucao para o vetor ordenado de forma decrescente\n");
    medirTempoExecucao(vetorDecrescente, TAMANHO_VETOR, "Bubble Sort", "ordenado de forma decrescente");
    medirTempoExecucao(vetorDecrescente, TAMANHO_VETOR, "Insertion Sort", "ordenado de forma decrescente");
    medirTempoExecucao(vetorDecrescente, TAMANHO_VETOR, "Selection Sort", "ordenado de forma decrescente");
    medirTempoExecucao(vetorDecrescente, TAMANHO_VETOR, "Merge Sort", "ordenado de forma decrescente");
    medirTempoExecucao(vetorDecrescente, TAMANHO_VETOR, "Quick Sort", "ordenado de forma decrescente");
    printf("\n\n");

    printf("Mede o tempo de execucao para o vetor ordenado aleatoriamente\n");
    medirTempoExecucao(vetorAleatorio, TAMANHO_VETOR, "Bubble Sort", "ordenado aleatoriamente");
    medirTempoExecucao(vetorAleatorio, TAMANHO_VETOR, "Insertion Sort", "ordenado aleatoriamente");
    medirTempoExecucao(vetorAleatorio, TAMANHO_VETOR, "Selection Sort", "ordenado aleatoriamente");
    medirTempoExecucao(vetorAleatorio, TAMANHO_VETOR, "Merge Sort", "ordenado aleatoriamente");
    medirTempoExecucao(vetorAleatorio, TAMANHO_VETOR, "Quick Sort", "ordenado aleatoriamente");
    printf("\n\n");
    
    return 0;
}
