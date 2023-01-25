#include "game.h"
#include <iostream>

using namespace std;

game::game(){
    white_count=12;
    black_count=12;
}

void game::decrease_number_white(){
    white_count--;
}

void game::decrease_number_black(){
    black_count--;
}

void game::show_board(){
    for (int i=7;i>=0;i--){
        cout<<"  ---------------------------------"<<endl;
        cout << i+1 <<" |";
        for (int j=0;j<8;j++){
            if (board[i][j]==-1){
                cout<<"   |";
            }
            else if (board[i][j]==0){
                cout<<" . |";
            }
            else if (board[i][j]==1){
                cout<<" w |";
            }
            else if (board[i][j]==2){
                cout<<" b |";
            }
            else if (board[i][j]==3){
                cout<<" W |";
            }
            else if (board[i][j]==4){
                cout<<" B |";
            }
        }
        cout<<endl;
    }
    cout<<"  ---------------------------------"<<endl;
    cout<<"    1   2   3   4   5   6   7   8"<<endl;
}

int game::get_black_count(){
    return black_count;
}

int game::get_white_count(){
    return white_count;
}