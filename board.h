#ifndef BOARD_H
#define BOARD_H

typedef struct {
        int size;
        char vetor[3][3];
} Board;

void Init_Board(Board *Board);
void mostrar_tabuleiro(Board *Board);
int c_para_numero(char c);
int marcar(Board *board, int posy, int posx, int player);
void pedra_papel_tesoura(Board *Board);
char Verificar_Vencedor(Board *Board);

#endif // !BOARD_H
