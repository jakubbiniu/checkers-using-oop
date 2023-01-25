#include <iostream>
#include <string>

using namespace std;

class piece{
    private:
    bool is_alive;
    bool is_king;
    int x;
    int y;
    bool is_white;
    public:
    // piece(int a, int b);
    void set_x(int a);
    void set_y(int b);
    int get_x();
    int get_y();
    bool alive_check();
    bool king_check();
    bool color_check();
    virtual void move(int a, int b)=0;
    // virtual ~piece();
    void die();
    void make_alive();
    void make_king();
    void make_pawn();
};