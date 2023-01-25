#include "piece.h"
#include <string>

using namespace std;

void piece::die(){
    is_alive = false;
}

void piece::make_alive(){
    is_alive = true;
}

void piece::make_king(){
    is_king = true;
}

void piece::make_pawn(){
    is_king=false;
}

// piece::piece(int a, int b){
//     x = a;
//     y = b;
// }

void piece::set_x(int a){
    x=a;
}

void piece::set_y(int a){
    y=a;
}

int piece::get_x(){
    return x;
}

int piece::get_y(){
    return y;
}

bool piece::alive_check(){
    return is_alive;
}

bool piece::king_check(){
    return is_king;
}

bool piece::color_check(){
    return is_white;
}
