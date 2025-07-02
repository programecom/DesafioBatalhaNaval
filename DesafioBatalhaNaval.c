#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

#define TAMANHO_TABULEIRO 10 // tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3    // tamanho fixo dos navios (3 posições)
#define AGUA 0             //  água no tabuleiro
#define NAVIO 3            //  uma parte do navio no tabuleiro

// Função para iniciar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // Define todas as posições como água
        }
    }
}

// Função para ver se uma posição está dentro dos limites do tabuleiro
int isPosicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO &&
            coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para posicionar um navio no tabuleiro
// Retorna 1 se o navio foi posicionado com sucesso, 0 caso contrário 
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                    int linhaInicial, int colunaInicial, char orientacao) {
    // Vetor para armazenar temporariamente as coordenadas do navio
    int posicoesNavio[TAMANHO_NAVIO][2];

    // Verifica se o navio cabe no tabuleiro e se há sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linhaAtual = linhaInicial;
        int colunaAtual = colunaInicial;

        if (orientacao == 'H' || orientacao == 'h') { // Horizontal
            colunaAtual += i;
        } else if (orientacao == 'V' || orientacao == 'v') { // Vertical
            linhaAtual += i;
        } else {
            printf("Erro: Orientacao invalida. Use 'H' para horizontal ou 'V' para vertical.\n");
            return 0; // Orientação inválida
        }

        // Valida se a posição está dentro dos limites do tabuleiro
        if (!isPosicaoValida(linhaAtual, colunaAtual)) {
            printf("Erro: Navio fora dos limites do tabuleiro na posicao (%d, %d).\n", linhaAtual, colunaAtual);
            return 0; // Fora dos limites
        }

        // Valida se já existe um navio na posição
        if (tabuleiro[linhaAtual][colunaAtual] == NAVIO) {
            printf("Erro: Sobreposicao de navios na posicao (%d, %d).\n", linhaAtual, colunaAtual);
            return 0; // Sobreposição
        }

        // Armazena as posições temporariamente
        posicoesNavio[i][0] = linhaAtual;
        posicoesNavio[i][1] = colunaAtual;
    }

    // Se todas as validações passaram, posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[posicoesNavio[i][0]][posicoesNavio[i][1]] = NAVIO;
    }

    return 1; // Navio posicionado com sucesso
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  "); // Espaço para alinhar com os índices das colunas
    // Imprime os índices das colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n"); // Nova linha após os índices das colunas

    // Imprime o tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime o índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da célula
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Declara a matriz do tabuleiro

    // 1. Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios (podem ser alteradas para testar diferentes posições)
    int linhaNavio1 = 1;
    int colunaNavio1 = 2;
    char orientacaoNavio1 = 'H'; // Navio 1 horizontal

    int linhaNavio2 = 4;
    int colunaNavio2 = 5;
    char orientacaoNavio2 = 'V'; // Navio 2 vertical

    printf("--- Posicionando Navios no Tabuleiro ---\n\n");

    // 2. Posiciona o primeiro navio (horizontal)
    printf("Tentando posicionar Navio 1 (Horizontal) em (%d, %d)...\n", linhaNavio1, colunaNavio1);
    if (posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, orientacaoNavio1)) {
        printf("Navio 1 posicionado com sucesso!\n");
    } else {
        printf("Nao foi possivel posicionar o Navio 1.\n");
    }
    printf("\n");

    // 3. Posiciona o segundo navio (vertical)
    printf("Tentando posicionar Navio 2 (Vertical) em (%d, %d)...\n", linhaNavio2, colunaNavio2);
    if (posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, orientacaoNavio2)) {
        printf("Navio 2 posicionado com sucesso!\n");
    } else {
        printf("Nao foi possivel posicionar o Navio 2.\n");
    }
    printf("\n");

    // 4. Exibe o tabuleiro com os navios posicionados
    printf("--- Tabuleiro Final ---\n");
    exibirTabuleiro(tabuleiro);

    return 0; // Indica que o programa terminou com sucesso
}