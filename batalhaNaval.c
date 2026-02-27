#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    //======================= CONFIGURAÇÕES INICIAIS ====================================
    // Tamanho fixo do tabuleiro (10x10)
    int TamanhoTabuleiro = 10;

    //tamanho fixo dos navios (ambos com 3 posições)
    int TamanhoNavio = 3;

    //matriz do tabuleiro: 0 = agua, 3 = parte do navio
    int tabuleiro[10][10] = {0}; //iniciar tudo com 0 automaticamente

    //======================= POSICIONAMENTO DO NAVIO HORIZONTAL ========================
    //Navio horizontal: ocupa 3 casas na mesma linha
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    //posiciona o navio horizontal (preenche com 3)
    for (int i = 0; i < TamanhoNavio; i++){
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    //======================== POSICIONAMENTO DO NAVIO VERTICAL ========================
    // Navio vertical: ocupa 3 casas na mesma coluna
    int ColunaVertical = 7;
    int LinhaVertical = 5;

    //Posiciona o navio vertical (Preeche com 3)
    for (int j = 0; j < TamanhoNavio; j++){
        tabuleiro[LinhaVertical + j][ColunaVertical] = 3;
    }

    //====================== EXIBIÇAO DO TABULEIRO ====================
    //Loops aninhados: externo = linhas, interno = coluna
    printf("\n=== Tabuleiro de Batalha Naval (10x10) ===\n");
    printf(" ");// Espaço para alinhar os numeros das colunas

    // Cabeçalho das colunas (0 a 9)
    for (int c = 0; c < TamanhoTabuleiro; c++) {
        printf("%2d", c);
    }
    printf("\n");

    //imprime cada linha
    for (int linha = 0; linha < TamanhoTabuleiro; linha++){
        //numero da linha no lado esquerdo
        printf("%2d ", linha);
        for (int coluna = 0; coluna < TamanhoTabuleiro; coluna++)
        {
            //numero 0 ou 3 com espaço para vizualização clara
            printf("%2d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Parte do navio\n");
    printf("Navio horizontal: linha %d, coluna %d a %d\n", linhaHorizontal, colunaHorizontal, colunaHorizontal + TamanhoNavio - 1);
    printf("Navio Vertical: coluna %d, linha %d a %d\n", ColunaVertical, LinhaVertical, LinhaVertical + TamanhoNavio - 1);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
