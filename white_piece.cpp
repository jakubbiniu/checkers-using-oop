#include "white_piece.h"

void white_piece::move(int a, int b){
    set_x(a);
    set_y(b);
}

white_piece::white_piece(int a, int b){
    set_x(a);
    set_y(b);
    make_alive();
    make_pawn();
}

