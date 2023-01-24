#include "black_piece.h"

void black_piece::move(int a, int b){
    set_x(a);
    set_y(b);
}

black_piece::black_piece(int a, int b){
    set_x(a);
    set_y(b);
    make_alive();
    make_pawn();
}

