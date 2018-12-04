#ifndef KICKER_H
#define KICKER_H

#include "Player.h"
#include "keeper.h"

class kicker : public Player{
    int kick_power;
public:
    void set_power(int power);
    string view_power(int power);
    int get_power();


};


#endif // KICKER_H
