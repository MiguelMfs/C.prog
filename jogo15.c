#include <stdio.h>
#include <stdlib.h> // alocação de memória, gerar num aleatórios 
#include <time.h> // temporizador 

#define SIZE 4  // define que a matriz será 4x4 
#define EMPTY_TILE 0  // um dos espaços será em branco 


void printQuad(int quad[][SIZE]) { //imprimir o quadro ao usuario 
    for (int i = 0; i < SIZE; i++) { //percorrer as linhas 'i' do quadro 
        for (int j = 0; j < SIZE; j++) { //percorrer as colunas 'j' do quadro 
            if (quad[i][j] == EMPTY_TILE) { //deixar um espaço em branco
                printf("   ");
            } else {
                printf("%2d ", quad[i][j]);
            }
        }
        printf("\n");
    }
}

void shuffleQuad(int quad[][SIZE]) { // embaralhar o quadro
    srand(time(NULL));
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = SIZE - 1; j > 0; j--) {
            int randLin = rand() % (i + 1); // a função rand é usada para gerar valores aleatórios na linha 
            int randCol = rand() % (j + 1); // a função rand é usada para gerar valores aleatórios na coluna 
            swapBloc(quad, i, j, randLin, randCol); // a função swap é usada para trocar valores, nesse caso embaralhando os blocos do quadro 
        }
    }
}

void swapBloc(int quad[][SIZE], int Lin1, int Col1, int Lin2, int Col2) { //função para trocar dois blocos de lugar 
    int temp1 = quad[Lin1][Col1], temp2 = quad[Lin2][Col2]; //temp vai armazenar temporariamente as variaveis 
    quad[Lin1][Col1] = temp2; //trocar as peças da linha 1 e coluna 1
    quad[Lin2][Col2] = temp1; // trocar as peças com a linha 2 e coluna 2

}

int Resolvido(int quad[][SIZE]) { // função para verificar se o quadro está resolvido
    int contar = 1; //começa em 1, pois 1 é o primeiro valor do quadro
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (quad[i][j] != contar && (i != SIZE - 1 || j != SIZE - 1)) { //verifica se o bloco está fora do lugar, 
                //se a função for verdadeira o quadro não está resolvido e o loop continua
                return 0; // O quadro não está resolvido
            }
            contar++; //soma 1 a cada valor, uma vez que o quadro está em ordem crescente de 1 em 1
        }
    }
    return 1; // O quadro está resolvido
}

int main() {
    int quad[SIZE][SIZE] = { //esse seria o quadro padrão inicial
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, EMPTY_TILE}
    };
    
    shuffleQuad(quad); //chamando a função para embaralhar o quadro 
    
    printf("Quadro inicial:\n");
    printQuad(quad);
    printf("\n");
    
    time_t startTime = time(NULL); //iniciar o temporizador 
    
while (!Resolvido(quad)) { //enquanto o tabuleiro não estiver resolvido, o while irá se repetir 
        int bloco;
        printf("Digite o número da pastilha que deseja mover (1-15): ");
        scanf("%d", &bloco);

        int blocoLin, blocoCol, emptyLin, emptyCol;
        
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (quad[i][j] == bloco) { //o for irá percorrer o quadro para achar o bloco desejado
                blocoLin = i; //a variável será atualizada com o valor do bloco encontrado 
                blocoCol = j;
            }
            if (quad[i][j] == EMPTY_TILE) {
                emptyLin = i; //os espaços vazios serão atualizados com o valor do bloco encontrado 
                emptyCol = j;
                }
            }
        }
        if ((blocoLin == emptyLin && abs(blocoCol - emptyCol) == 1) ||
            (blocoCol == emptyCol && abs(blocoLin - emptyLin) == 1)) { //verifica se o bloco selecionado possui alguma possibilidade de movimentação 
            swapBloc(quad, blocoLin, blocoCol, emptyLin, emptyCol); //se pelo menos uma condição for verdadeira, o bloco será movido para o espaço vazio
            printf("Quadro atual:\n");
            printQuad(quad);
            printf("\n");
        } else {
            printf("Movimento invalido! Tente novamente.\n");
        }
    }
    
    time_t endTime = time(NULL);
    double gameTime = difftime(endTime, startTime); //calcular o tempo total de jogo 

    printf("Parabens! Você resolveu o quebra-cabeca em %.2f segundos.\n", gameTime);
    
 return 0;
}
