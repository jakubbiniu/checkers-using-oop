#include "player.h"

player::player(){
    is_winner = false;
}

bool player::check_winner(){
    return is_winner;
}

void player::make_winner(){
    is_winner=true;
}