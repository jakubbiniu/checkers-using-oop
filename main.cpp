#include<iostream>
#include "game.h"
// #include "white_piece.h"
// #include "black_piece.h"
#include "player.h"
#include<vector>

using namespace std;

int main(){
    game g;
    vector<piece*> pieces;
    black_piece *a = new black_piece();
    pieces.push_back(new black_piece());
    player white_player, black_player;
    for (int i=0;i<pieces.size();i++){
        pieces.at(i)->die();
    }
    for (int i=1; i<=8;i++){
        
    }
    g.show_board();
    return 0;
}