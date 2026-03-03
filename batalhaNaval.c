#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro: Tabuleiro Completo e Navios Diagonais

int main() {
    // ====================== CONFIGURAÇÕES INICIAIS ======================
    int TAMANHO = 10;          // Tabuleiro 10x10
    int TAM_NAVIO = 3;         // Todos os navios têm tamanho 3

    // Matriz do tabuleiro: 0 = Água, 3 = Parte de navio
    int tabuleiro[10][10] = {0};

    // ====================== POSICIONAMENTO DOS NAVIOS ======================

    // 1. Navio Horizontal (linha 1, colunas 2-4)
    int lin_h = 1;
    int col_h = 2;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[lin_h][col_h + i] = 3;
    }

    // 2. Navio Vertical (coluna 8, linhas 6-8)
    int col_v = 8;
    int lin_v = 6;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[lin_v + i][col_v] = 3;
    }

    // 3. Navio Diagonal Principal ( / ) → (0,0), (1,1), (2,2)
    int lin_d1 = 0;
    int col_d1 = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[lin_d1 + i][col_d1 + i] = 3;
    }

    // 4. Navio Diagonal Secundária ( \ ) → (2,9), (3,8), (4,7)
    int lin_d2 = 2;
    int col_d2 = 9;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[lin_d2 + i][col_d2 - i] = 3;
    }

    // ====================== VALIDAÇÃO SIMPLES DE SOBREPOSIÇÃO ======================
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 3) {
                // Conta quantas vezes o número 3 aparece (deveria ser 12 no total)
                sobreposicao++;
            }
        }
    }
    if (sobreposicao != 12) {
        printf("ERRO: Houve sobreposição de navios!\n");
        return 1;
    }

    // ====================== EXIBIÇÃO DO TABULEIRO ======================
    printf("\n=== Tabuleiro de Batalha Naval 10x10 ===\n");
    printf("   ");                     // Espaço para alinhar colunas

    // Cabeçalho das colunas
    for (int c = 0; c < TAMANHO; c++) {
        printf("%2d ", c);
    }
    printf("\n");

    // Imprime o tabuleiro completo
    for (int linha = 0; linha < TAMANHO; linha++) {
        printf("%2d ", linha);         // Número da linha

        for (int coluna = 0; coluna < TAMANHO; coluna++) {
            printf("%2d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    // ====================== INFORMAÇÕES DOS NAVIOS ======================
    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Parte de navio\n\n");

    printf("Navio 1 - Horizontal : linha %d, colunas %d a %d\n", lin_h, col_h, col_h + TAM_NAVIO - 1);
    printf("Navio 2 - Vertical   : coluna %d, linhas %d a %d\n", col_v, lin_v, lin_v + TAM_NAVIO - 1);
    printf("Navio 3 - Diagonal / : começa em (%d,%d) → (%d,%d) → (%d,%d)\n",
           lin_d1, col_d1, lin_d1+1, col_d1+1, lin_d1+2, col_d1+2);
    printf("Navio 4 - Diagonal \\ : começa em (%d,%d) → (%d,%d) → (%d,%d)\n",
           lin_d2, col_d2, lin_d2+1, col_d2-1, lin_d2+2, col_d2-2);

    return 0;
}