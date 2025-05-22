// batalha_naval.c
// Programa para posicionar dois navios (um horizontal e um vertical) em um tabuleiro 10x10
// Utiliza arrays unidimensionais para os navios e matriz para o tabuleiro
// Autor: GitHub Copilot

#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // Matriz do tabuleiro: 0 = água, 3 = parte do navio
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Vetores para os navios (valores não são usados, só o tamanho)
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios (definidas no código)
    int linha_h = 2, coluna_h = 4; // Navio horizontal começa na linha 2, coluna 4
    int linha_v = 5, coluna_v = 7; // Navio vertical começa na linha 5, coluna 7

    // Posiciona navio horizontal (valida se cabe no tabuleiro)
    if (coluna_h + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
        }
    }

    // Posiciona navio vertical (valida se cabe no tabuleiro e não sobrepõe)
    if (linha_v + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] == 0) { // Garante que não sobrepõe
                tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
            }
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval (0 = agua, 3 = navio):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
