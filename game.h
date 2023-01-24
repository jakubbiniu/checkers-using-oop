#include <iostream>
#include "black_piece.h"

using namespace std;

// class piece;

class game{
    private:
    int board[8][8] = {{1,-1,1,-1,1,-1,1,-1},{-1,1,-1,1,-1,1,-1,1},{1,-1,1,-1,1,-1,1,-1},{-1,0,-1,0,-1,0,-1,0},{0,-1,0,-1,0,-1,0,-1},{-1,2,-1,2,-1,2,-1,2},{2,-1,2,-1,2,-1,2,-1},{-1,2,-1,2,-1,2,-1,2}};
    int white_count;
    int black_count;
    public:
    game();
    void show_board();
    void decrease_number(int a);


};