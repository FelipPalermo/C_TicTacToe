#include "board.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3
#define EMPTY '0'

void Init_Board(Board *Board) {
    Board->size = 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Board->vetor[i][j] = '0';
        }
    }
}

void mostrar_tabuleiro(Board *Board) {
    char coluna = 'A';
    int linha = 1;

    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("  %c", coluna + i);
    }
    printf("\n---------");

    for (int i = 0; i < 3; i++) {
        printf("\n");
        printf("%d|", linha + i);
        for (int j = 0; j < 3; j++) {
            printf(" %c", Board->vetor[i][j]);
        }
    }
}

int c_para_numero(char c) {
    if (c >= 'a' && c <= 'c') {
        return c - 'a' + 1;

    } else if (c >= 'A' && c <= 'c') {
        return c - 'A' + 1;

    } else {
        return -1;
    }
}

int marcar(Board *board, int posy, int posx, int player) {
    if (board->vetor[posx - 1][posy - 1] == '0') {
        if (player == 0) {
            board->vetor[posx - 1][posy - 1] = 'G';
        } else {
            board->vetor[posx - 1][posy - 1] = 'X';
        }
        return 0;

    } else {
        return 1;
    }
}

char Verificar_Vencedor(Board *board) {

    char(*vetor)[3] = board->vetor;

    // Linhas
    for (int i = 0; i < SIZE; i++) {
        if (vetor[i][0] != EMPTY && vetor[i][0] == vetor[i][1] &&
            vetor[i][0] == vetor[i][2]) {
            return vetor[i][0];
        }
    }

    // colunas
    for (int i = 0; i < SIZE; i++) {
        if (vetor[0][i] != EMPTY && vetor[0][i] == vetor[1][i] &&
            vetor[0][i] == vetor[2][i]) {
            return vetor[0][i];
        }
    }

    // diagonal  0, 4, 8
    if (vetor[0][0] != EMPTY && vetor[0][0] == vetor[1][1] &&
        vetor[0][0] == vetor[2][2]) {
        return vetor[0][0];
    }

    // diagonal 2, 4, 6
    if (vetor[0][2] != EMPTY && vetor[0][2] == vetor[1][1] &&
        vetor[0][2] == vetor[2][0]) {
        return vetor[0][0];
    }

    return 'O';
}

char entrada_caracter() {
    char entrada_usuario[2];
    while (true) {

        printf("\nLetra da coluna ( a - c ): ");
        scanf(" %c", entrada_usuario);
        printf("\n");

        if (entrada_usuario[0] != 'a' && entrada_usuario[0] != 'b' &&
            entrada_usuario[0] != 'c') {
            printf("Por favor digite colunas entre (a) e (c)");
        } else {
            return *entrada_usuario;
            break;
        }
    }
}

int entrada_int() {
    int entrada_int;
    while (true) {
        printf("Numero da linha : ");
        scanf(" %d", &entrada_int);
        if (entrada_int >= 4) {
            printf("Por favor digite linhas enter (1) e (3)");
        } else {
            return entrada_int;
            break;
        }
    }
}

void pedra_papel_tesoura(Board *Board) {
    char c_entrada_usuario[2];
    int d_entrada_usuario;

    int vencedor = 1;
    char player_vencedor;
    while (vencedor) {
        for (int player = 0; player < 2; player++) {

            system("clear");
            mostrar_tabuleiro(Board);

            *c_entrada_usuario = entrada_caracter();
            d_entrada_usuario = entrada_int();

            marcar(Board, c_para_numero(c_entrada_usuario[0]),
                   d_entrada_usuario, player);

            player_vencedor = Verificar_Vencedor(Board);

            if (player_vencedor != 'O') {
                system("clear");
                printf("Vencedor : %c", player_vencedor);
                vencedor = 0;
                exit(0);
            }
        }
    }
}
