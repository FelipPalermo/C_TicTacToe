#include "board.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    Board *board = (Board *)malloc(sizeof(Board));
    Init_Board(board);

    pedra_papel_tesoura(board);

    return 0;
}
