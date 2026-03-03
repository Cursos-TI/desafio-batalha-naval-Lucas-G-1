#include <stdio.h>

int main() {
    const int TAM = 10;
    const int TAM_NAVIO = 3;

    // ====================== TABULEIRO PRINCIPAL ======================
    int tabuleiro[10][10] = {0};   // 0 = Água, 3 = Navio, 5 = Área afetada

    // ====================== POSICIONAMENTO DOS 4 NAVIOS ======================
    // Navio Horizontal
    int lin_h = 1, col_h = 2;
    for (int i = 0; i < TAM_NAVIO; i++) tabuleiro[lin_h][col_h + i] = 3;

    // Navio Vertical
    int col_v = 8, lin_v = 6;
    for (int i = 0; i < TAM_NAVIO; i++) tabuleiro[lin_v + i][col_v] = 3;

    // Navio Diagonal /
    int lin_d1 = 3, col_d1 = 1;
    for (int i = 0; i < TAM_NAVIO; i++) tabuleiro[lin_d1 + i][col_d1 + i] = 3;

    // Navio Diagonal \;
    int lin_d2 = 2, col_d2 = 9;
    for (int i = 0; i < TAM_NAVIO; i++) tabuleiro[lin_d2 + i][col_d2 - i] = 3;

    // ====================== HABILIDADES ESPECIAIS (MATRIZES SEPARADAS) ======================

    // Matrizes 5x5 para cada habilidade (0 = não afeta, 1 = afeta)
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // ------------------- 1. Construção do CONE (com loops aninhados + condicionais) -------------------
    for (int i = 0; i < 5; i++) {           // linha
        for (int j = 0; j < 5; j++) {       // coluna
            if (j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 1;
            }
        }
    }

    // ------------------- 2. Construção da CRUZ -------------------
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {         // linha do meio ou coluna do meio
                cruz[i][j] = 1;
            }
        }
    }

    // ------------------- 3. Construção do OCTAEDRO (diamante) -------------------
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {   // distância de Manhattan
                octaedro[i][j] = 1;
            }
        }
    }

    // ====================== SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO ======================
    // Ponto de origem de cada habilidade no tabuleiro 10x10 (centro da habilidade)
    int origem_cone_linha = 4,   origem_cone_coluna = 4;
    int origem_cruz_linha = 7,   origem_cruz_coluna = 2;
    int origem_octa_linha = 2,   origem_octa_coluna = 6;

    // Função para aplicar habilidade (reutilizável)
    void aplicar_habilidade(int hab[5][5], int orig_l, int orig_c) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (hab[i][j] == 1) {
                    int linha_tab = orig_l + (i - 2);   // centraliza a matriz 5x5
                    int coluna_tab = orig_c + (j - 2);

                    // Verifica limites do tabuleiro
                    if (linha_tab >= 0 && linha_tab < TAM &&
                        coluna_tab >= 0 && coluna_tab < TAM) {
                        tabuleiro[linha_tab][coluna_tab] = 5;   // 5 = área afetada
                    }
                }
            }
        }
    }

    // Aplica as 3 habilidades
    aplicar_habilidade(cone, origem_cone_linha, origem_cone_coluna);
    aplicar_habilidade(cruz, origem_cruz_linha, origem_cruz_coluna);
    aplicar_habilidade(octaedro, origem_octa_linha, origem_octa_coluna);

    // ====================== EXIBIÇÃO FINAL ======================
    printf("\n=== TABULEIRO FINAL ===\n");
    printf("   ");
    for (int c = 0; c < TAM; c++) printf("%2d ", c);
    printf("\n");

    for (int l = 0; l < TAM; l++) {
        printf("%2d ", l);
        for (int c = 0; c < TAM; c++) {
            printf("%2d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Parte de Navio\n");
    printf("5 = Área afetada por habilidade\n\n");

    printf("Habilidades aplicadas:\n");
    printf("• Cone     → origem em (%d, %d)\n", origem_cone_linha, origem_cone_coluna);
    printf("• Cruz     → origem em (%d, %d)\n", origem_cruz_linha, origem_cruz_coluna);
    printf("• Octaedro → origem em (%d, %d)\n", origem_octa_linha, origem_octa_coluna);

    return 0;
}