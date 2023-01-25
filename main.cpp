#include<iostream>
#include "game.h"
// #include "white_piece.h"
// #include "black_piece.h"
#include "player.h"
#include<vector>

using namespace std;


void move_pawn(vector<piece*> pieces,game g,int x1, int y1, int x2, int y2){
    x1--;x2--;y1--;y2--;
    int p=g.board[x1][y1];
    g.board[x1][y1]=0;
    g.board[x2][y2]=p;
    for (int i=0;i<pieces.size();i++){
        int x = pieces.at(i)->get_x();
        int y = pieces.at(i)->get_y();
        if (x==x1 && y==y1){
            pieces.at(i)->move(x,y);
        }
    }
}

void jump(vector<piece*> pieces, game g,int x1, int y1, int x2, int y2){
    x1--;x2--;y1--;y2--;
    int p = g.board[x1][y1];
    if (g.board[x1][y1]==1 || g.board[x1][y1]==2){
        int x3=(x1+x2)/2;
        int y3=(y1+y2)/2;
        if (g.board[x3][y3]==1 || g.board[x3][y3]==3){
            g.decrease_number_white();
        }
        else if(g.board[x3][y3]==2 || g.board[x3][y3]==4){
            g.decrease_number_black();
        }
        g.board[x3][y3]=0;
        g.board[x2][y2]=p;
        g.board[x1][y1]=0;
        for (int i=0;i<pieces.size();i++){
            int x = pieces.at(i)->get_x();
            int y = pieces.at(i)->get_y();
            if (x==x1 && y==y1){
                pieces.at(i)->move(x2,y2);
            }
            if (x==x3 && y==y3){
                pieces.at(i)->die();
            }
        }

    }
    else if (g.board[x1][y1]==3 || g.board[x1][y1]==4){
        if (x2>x1 && y2>y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1+abs(i-x1);
                if (g.board[i][j]!=0){
                    if (g.board[i][j]>0){
                        for (int i=0;i<pieces.size();i++){
                            int x = pieces.at(i)->get_x();
                            int y = pieces.at(i)->get_y();
                            if (x==i && y==j){
                                pieces.at(i)->die();
                                if (pieces.at(i)->color_check()){
                                    g.decrease_number_white();
                                }
                                else{
                                    g.decrease_number_black();
                                }
                            }
                        }
                    }
                    g.board[i][j]=0;
                    g.board[x2][y2]=p;
                    g.board[x1][y1]=0;
                    for (int i=0;i<pieces.size();i++){
                            int x = pieces.at(i)->get_x();
                            int y = pieces.at(i)->get_y();
                            if (x==x1 && y==y1){
                                pieces.at(i)->move(x2,y2);
                            }
                            if (x==i && y==j){
                                pieces.at(i)->die();
                            }
                        }
                    return;
                }
            }
        }
        if (x2>x1 && y2<y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1-abs(i-x1);
                if (g.board[i][j]!=0){
                    if (g.board[i][j]>0){
                        for (int i=0;i<pieces.size();i++){
                            int x = pieces.at(i)->get_x();
                            int y = pieces.at(i)->get_y();
                            if (x==i && y==j){
                                pieces.at(i)->die();
                                if (pieces.at(i)->color_check()){
                                    g.decrease_number_white();
                                }
                                else{
                                    g.decrease_number_black();
                                }
                            }
                        }
                    }
                    g.board[i][j]=0;
                    g.board[x2][y2]=p;
                    g.board[x1][y1]=0;
                    for (int i=0;i<pieces.size();i++){
                            int x = pieces.at(i)->get_x();
                            int y = pieces.at(i)->get_y();
                            if (x==x1 && y==y1){
                                pieces.at(i)->move(x2,y2);
                            }
                            if (x==i && y==j){
                                pieces.at(i)->die();
                            }
                        }
                    return;
                }
            }
        }
        if (x2<x1 && y2>y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1+abs(x1-i);
                if (g.board[i][j]!=0){
                    if (g.board[i][j]>0){
                        for (int i=0;i<pieces.size();i++){
                            int x = pieces.at(i)->get_x();
                            int y = pieces.at(i)->get_y();
                            if (x==i && y==j){
                                pieces.at(i)->die();
                                if (pieces.at(i)->color_check()){
                                    g.decrease_number_white();
                                }
                                else{
                                    g.decrease_number_black();
                                }
                            }
                        return;
                        }
                    }
                    g.board[i][j]=0;
                    g.board[x2][y2]=p;
                    g.board[x1][y1]=0;
                    for (int i=0;i<pieces.size();i++){
                            int x = pieces.at(i)->get_x();
                            int y = pieces.at(i)->get_y();
                            if (x==x1 && y==y1){
                                pieces.at(i)->move(x2,y2);
                            }
                            if (x==i && y==j){
                                pieces.at(i)->die();
                            }
                        }
                    return;
                }
            }
        }
        if (x2<x1 && y2<y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1-abs(x1-i);
                if (g.board[i][j]!=0){
                    if (g.board[i][j]>0){
                        for (int i=0;i<pieces.size();i++){
                            int x = pieces.at(i)->get_x();
                            int y = pieces.at(i)->get_y();
                            if (x==i && y==j){
                                pieces.at(i)->die();
                                if (pieces.at(i)->color_check()){
                                    g.decrease_number_white();
                                }
                                else{
                                    g.decrease_number_black();
                                }
                            }
                        return;
                        }
                    }
                    g.board[i][j]=0;
                    g.board[x2][y2]=p;
                    g.board[x1][y1]=0;
                    for (int i=0;i<pieces.size();i++){
                            int x = pieces.at(i)->get_x();
                            int y = pieces.at(i)->get_y();
                            if (x==x1 && y==y1){
                                pieces.at(i)->move(x2,y2);
                            }
                            if (x==i && y==j){
                                pieces.at(i)->die();
                            }
                        }
                    return;
                }
            }
        }
    }
    return;
}

int main(){
    game g;
    vector<piece*> pieces;
    for (int i=0;i<=2;i+=2){
        for (int j=0;j<=6;j+=2){
        pieces.push_back(new white_piece(i,j));
        }
    }
    for (int j=1;j<=7;j+=2){
        pieces.push_back(new white_piece(1,j));
    }
    for (int i=5;i<=7;i+=2){
        for (int j=1;j<=7;j+=2){
            pieces.push_back(new black_piece(i,j));
        }
    }
    for (int j=0;j<=6;j+=2){
        pieces.push_back(new black_piece(6,j));
    }
    pieces.push_back(new black_piece());
    player white_player, black_player;
    // for (int i=0;i<pieces.size();i++){
    //     pieces.at(i)->die();
    // }
    g.show_board();
    return 0;
}