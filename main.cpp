#include<iostream>
#include "game.h"
// #include "white_piece.h"
// #include "black_piece.h"
#include "player.h"
#include<vector>

using namespace std;

void move_pawn(vector<piece*> pieces,game &g,int x1, int y1, int x2, int y2){
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

void jump(vector<piece*> pieces, game &g,int x1, int y1, int x2, int y2){
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
                if (pieces.at(i)->color_check()){
                    g.decrease_number_white();
                }
                else{
                    g.decrease_number_black();
                }
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

bool can_move_white(game &g, int x1, int y1, int x2, int y2){
    x1=x1-1;
    x2=x2-1;
    y1=y1-1;
    y2=y2-1;
    if (x1<0 || x1>7 || x2<0 || x2>7 || y1<0 || y1>7 || y2<0 || y2>7){
        return false;
    }
    if (g.board[x2][y2]!=0){
        return false;
    }
    if (abs(x2-x1)!=abs(y2-y1)){
            return false;
        }
    if (g.board[x1][y1]==1 && abs(y2-y1)==1 && x2-x1==1){
        return true;
    }
    if (g.board[x1][y1]==3){
        if (x2>x1 && y2>y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1+abs(i-x1);
                if (g.board[i][j]!=0){
                    return 0;
                }
            }
            return true;
        }
        if (x2>x1 && y2<y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1-abs(i-x1);
                if (g.board[i][j]!=0){
                    return false;
                }
            }
            return true;
        }
        if (x2<x1 && y2>y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1+abs(x1-i);
                if (g.board[i][j]!=0){
                    return false;
                }
            }
            return true;
        }
        if (x2<x1 && y2<y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1-abs(x1-i);
                if (g.board[i][j]!=0){
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool can_move_black(game &g, int x1, int y1, int x2, int y2){
    x1=x1-1;
    x2=x2-1;
    y1=y1-1;
    y2=y2-1;
    if (x1<0 || x1>7 || x2<0 || x2>7 || y1<0 || y1>7 || y2<0 || y2>7){
        return false;
    }
    if (g.board[x2][y2]!=0){
        return false;
    }
    if (abs(x2-x1)!=abs(y2-y1)){
            return false;
        }
    if (g.board[x1][y1]==2 && abs(y1-y2)==1 && x1-x2==1){
        return true;
    }
    if (g.board[x1][y1]==4){
        if (x2>x1 && y2>y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1+abs(i-x1);
                if (g.board[i][j]!=0){
                    return false;
                }
            }
            return true;
        }
        if (x2>x1 && y2<y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1-abs(i-x1);
                if (g.board[i][j]!=0){
                    return false;
                }
            }
            return true;
        }
        if (x2<x1 && y2>y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1+abs(x1-i);
                if (g.board[i][j]!=0){
                    return false;
                }
            }
            return true;
        }
        if (x2<x1 && y2<y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1-abs(x1-i);
                if (g.board[i][j]!=0){
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool can_jump_white(game &g, int x1, int y1, int x2, int y2){
    x1--;
    x2--;
    y1--;
    y2--;
    int x3 = (x1+x2)/2;
    int y3 = (y1+y2)/2;
    if (x1<0 || x1>7 || x2<0 || x2>7 || y1<0 || y1>7 || y2<0 || y2>7){
        return false;
    }
    if (g.board[x2][y2]!=0){
        return false;
    }
    if (abs(x2-x1)!=abs(y2-y1)){
            return false;
        }
    if (g.board[x1][y1]==1 && (g.board[x3][y3]==2 || g.board[x3][y3]==4) && abs(x1-x2)==2 && abs(y2-y1)==2){
        return true;
    }
    if (g.board[x1][y1]==3){
        int c=0;
        if (x2>x1 && y2>y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1+abs(i-x1);
                if (g.board[i][j]==2 || g.board[i][j]==4){
                    c++;
                }
                else if (g.board[i][j]==1 || g.board[i][j]==3){
                    return false;
                }
            }
            if (c==1){
                return true;
            }
            return false;
        }
        else if (x2>x1 && y2<y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1-abs(i-x1);
                if (g.board[i][j]==2 || g.board[i][j]==4){
                    c++;
                }
                 else if (g.board[i][j]==1 || g.board[i][j]==3){
                    return false;
                }
            }
            if (c==1){
                return true;
            }
            return false;
        }
        else if (x2<x1 && y2>y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1+abs(x1-i);
                if (g.board[i][j]==2 || g.board[i][j]==4){
                    c++;
                }
                 else if (g.board[i][j]==1 || g.board[i][j]==3){
                    return false;
                }
            }
            if (c==1){
                return true;
            }
            return false;
        }
        else if (x2<x1 && y2<y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1-abs(x1-i);
                if (g.board[i][j]==2 || g.board[i][j]==4){
                    c++;
                }
                 else if (g.board[i][j]==1 || g.board[i][j]==3){
                    return false;
                }
            }
            if (c==1){
                return true;
            }
            return false;
        }
    }
    return false;
}
// sprawdzanie czy czarny pion moze bic
bool can_jump_black(game &g, int x1, int y1, int x2, int y2){
    x1--;
    x2--;
    y1--;
    y2--;
    int x3 = (x1+x2)/2;
    int y3 = (y1+y2)/2;
    if (x1<0 || x1>7 || x2<0 || x2>7 || y1<0 || y1>7 || y2<0 || y2>7){
        return false;
    }
    if (g.board[x2][y2]!=0){
        return false;
    }
    if (abs(x2-x1)!=abs(y2-y1)){
            return false;
        }
    if (g.board[x1][y1]==2 && (g.board[x3][y3]==1 || g.board[x3][y3]==3) && abs(x1-x2)==2 && abs(y2-y1)==2){
        return true;
    }
    if (g.board[x1][y1]==4){
        int c=0;
        if (x2>x1 && y2>y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1+abs(i-x1);
                if (g.board[i][j]==1 || g.board[i][j]==3){
                    c++;
                }
                else if (g.board[i][j]==2 || g.board[i][j]==4){
                    return false;
                }
            }
            if (c==1){
                return true;
            }
            return false;
        }
        if (x2>x1 && y2<y1){
            for (int i=x1+1;i<x2;i++){
                int j=y1-abs(i-x1);
                if (g.board[i][j]==1 || g.board[i][j]==3){
                    c++;
                }
                 else if (g.board[i][j]==2 || g.board[i][j]==4){
                    return false;
                }
            }
            if (c==1){
                return true;
            }
            return false;
        }
        if (x2<x1 && y2>y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1+abs(x1-i);
                if (g.board[i][j]==1 || g.board[i][j]==3){
                    c++;
                }
                 else if (g.board[i][j]==2 || g.board[i][j]==4){
                    return false;
                }
            }
            if (c==1){
                return true;
            }
            return false;
        }
        if (x2<x1 && y2<y1){
            for (int i=x1-1;i>x2;i--){
                int j=y1-abs(x1-i);
                if (g.board[i][j]==1 || g.board[i][j]==3){
                    c++;
                }
                 else if (g.board[i][j]==2 || g.board[i][j]==4){
                    return false;
                }
            }
            if (c==1){
                return true;
            }
            return false;
        }
    }
    return false;
}

bool can_jump_white_all(game &g){
    for (int i=1;i<9;i++){
        for (int j=1;j<9;j++){
            if (g.board[i-1][j-1]==1){
                if (can_jump_white(g,i,j,i+2,j+2)==true || can_jump_white(g,i,j,i+2,j-2)==true || can_jump_white(g,i,j,i-2,j+2)==true || can_jump_white(g,i,j,i-2,j-2)==true){
                    return true;
                }
            }
            else if (g.board[i-1][j-1]==3){
                for (int a=1;a<9;a++){
                    for (int b=1;b<9;b++){
                        if (can_jump_white(g,i,j,a,b)==true){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

bool can_jump_black_all(game &g){
    for (int i=1;i<9;i++){
        for (int j=1;j<9;j++){
            if (g.board[i-1][j-1]==2){
                if (can_jump_black(g,i,j,i+2,j+2)==true || can_jump_black(g,i,j,i+2,j-2)==true || can_jump_black(g,i,j,i-2,j+2)==true || can_jump_black(g,i,j,i-2,j-2)==true){
                    return true;
                }
            }
            else if (g.board[i-1][j-1]==4){
                for (int a=1;a<9;a++){
                    for (int b=1;b<9;b++){
                        if (can_jump_black(g,i,j,a,b)==true){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void white_move(vector<piece*> pieces, game &g){
    int x_1, y_1, x_2, y_2;
    cout<<"white move"<<endl;
        if (can_jump_white_all(g)==true){
            cout<<"Input coordinates of pawn you want to move ";
            cin>>x_1;
            cin>>y_1;
            cout<<"Input coordinates of place you want to move your pawn "; 
            cin>>x_2;
            cin>>y_2;
            while (can_jump_white(g,x_1,y_1,x_2,y_2)==false){
                cout<<"Input coordinates of pawn you want to move ";
                cin>>x_1;
                cin>>y_1;
                cout<<"Input coordinates of place you want to move your pawn "; 
                cin>>x_2;
                cin>>y_2;
            }
            jump(pieces,g,x_1,y_1,x_2,y_2);
            for (int i=0;i<8;i++){
                if (g.board[7][i]==1){
                    g.board[7][i]=3;
                    for (int i=0;i<pieces.size();i++){
                        int x = pieces.at(i)->get_x();
                        int y = pieces.at(i)->get_y();
                        if (x==7 && y==i){
                        pieces.at(i)->make_king();
                        }
                    }
                }
            }
            g.show_board();
            x_1=x_2;
            y_1=y_2;
            while (can_jump_white(g,x_1,y_1,x_1+2,y_1+2)==true || can_jump_white(g,x_1,y_1,x_1+2,y_1-2)==true || can_jump_white(g,x_1,y_1,x_1-2,y_1-2)==true || can_jump_white(g,x_1,y_1,x_1-2,y_1+2)==true){
                cout<<"give me next coordinates of place you want to go: ";
                cin>>x_2;
                cin>>y_2;
                if (can_jump_white(g,x_1,y_1,x_2,y_2)==1){
                    jump(pieces,g,x_1,y_1,x_2,y_2);
                    for (int i=0;i<8;i++){
                        if (g.board[7][i]==1){
                            g.board[7][i]=3;
                            for (int i=0;i<pieces.size();i++){
                                int x = pieces.at(i)->get_x();
                                int y = pieces.at(i)->get_y();
                                if (x==7 && y==i){
                                pieces.at(i)->make_king();
                                }
                            }
                        }
                    }
                    g.show_board();
                    x_1=x_2;
                    y_1=y_2;
                }
                }
        }
        else{
            while (1){
                cout<<"Input coordinates of pawn you want to move ";
                cin>>x_1;
                cin>>y_1;
                cout<<"Input coordinates of place you want to move your pawn "; 
                cin>>x_2;
                cin>>y_2;
                if (can_move_white(g,x_1,y_1,x_2,y_2)==true){
                    move_pawn(pieces,g,x_1,y_1,x_2,y_2);
                    for (int i=0;i<8;i++){
                        if (g.board[7][i]==1){
                            g.board[7][i]=3;
                            for (int i=0;i<8;i++){
                        if (g.board[7][i]==1){
                            g.board[7][i]=3;
                            for (int i=0;i<pieces.size();i++){
                                int x = pieces.at(i)->get_x();
                                int y = pieces.at(i)->get_y();
                                if (x==7 && y==i){
                                pieces.at(i)->make_king();
                                }
                            }
                        }
                    }
                        }
                    }
                    g.show_board();
                    break;
                }
            }
        }
}

void black_move(vector<piece*> pieces, game &g){
    int x_1, y_1, x_2, y_2;
    cout<<"black move"<<endl;
        if (can_jump_black_all(g)==true){
            cout<<"Input coordinates of pawn you want to move";
            cin>>x_1;
            cin>>y_1;
            cout<<"Input coordinates of place you want to move your pawn"; 
            cin>>x_2;
            cin>>y_2;
            while (can_jump_black(g,x_1,y_1,x_2,y_2)==false){
                cout<<"Input coordinates of pawn you want to move";
                cin>>x_1;
                cin>>y_1;
                cout<<"Input coordinates of place you want to move your pawn"; 
                cin>>x_2;
                cin>>y_2;
            }
            jump(pieces,g,x_1,y_1,x_2,y_2);
            for (int i=0;i<8;i++){
                if (g.board[7][i]==1){
                    g.board[7][i]=3;
                    for (int i=0;i<pieces.size();i++){
                        int x = pieces.at(i)->get_x();
                        int y = pieces.at(i)->get_y();
                        if (x==7 && y==i){
                        pieces.at(i)->make_king();
                        }
                    }
                }
            }
            g.show_board();
            x_1=x_2;
            y_1=y_2;
            while (can_jump_black(g,x_1,y_1,x_1+2,y_1+2)==true || can_jump_black(g,x_1,y_1,x_1+2,y_1-2)==true || can_jump_black(g,x_1,y_1,x_1-2,y_1-2)==true || can_jump_black(g,x_1,y_1,x_1-2,y_1+2)==true){
                cout<<"give me next coordinates of place you want to go";
                cin>>x_2;
                cin>>y_2;
                if (can_jump_black(g,x_1,y_1,x_2,y_2)==true){
                    jump(pieces,g,x_1,y_1,x_2,y_2);
                    for (int i=0;i<8;i++){
                        if (g.board[0][i]==2){
                            g.board[0][i]=4;
                            for (int i=0;i<pieces.size();i++){
                                int x = pieces.at(i)->get_x();
                                int y = pieces.at(i)->get_y();
                                if (x==7 && y==i){
                                pieces.at(i)->make_king();
                                }
                            }
                        }
                    }
                    g.show_board();
                    x_1=x_2;
                    y_1=y_2;
                }
                }
        }
        else{
            while (1){
                cout<<"Input coordinates of pawn you want to move";
                cin>>x_1;
                cin>>y_1;
                cout<<"Input coordinates of place you want to move your pawn"; 
                cin>>x_2;
                cin>>y_2;
                if (can_move_black(g,x_1,y_1,x_2,y_2)==true){
                    move_pawn(pieces,g,x_1,y_1,x_2,y_2);
                    for (int i=0;i<8;i++){
                        if (g.board[0][i]==2){
                            g.board[0][i]=4;
                            for (int i=0;i<pieces.size();i++){
                                int x = pieces.at(i)->get_x();
                                int y = pieces.at(i)->get_y();
                                if (x==7 && y==i){
                                pieces.at(i)->make_king();
                                }
                            }
                        }
                    }
                    g.show_board();
                    break;
                }
            }
        }
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
    player white_player, black_player;
    cout<<"Symbols: w-white pawn, b-black pawn, W-white king, B-black king, . -empty place:"<<endl;
    g.show_board();
    while ((g.get_white_count()+g.get_black_count())>0){
        white_move(pieces,g);
        // show_board(board);
        if ((g.get_white_count()==0) || (g.get_black_count()==0)){
            break;
        }
        black_move(pieces,g);
        if ((g.get_white_count()==0) || (g.get_black_count()==0)){
            break;
        }
        // show_board(board);
    }
    if (g.get_white_count()==0){
        black_player.make_winner();
        cout<<"black won!"<<endl;
    }
    else{
        white_player.make_winner();
        cout<<"white won!"<<endl;
    }
    cout<<"Game over!"<<endl;        
    return 0;
}