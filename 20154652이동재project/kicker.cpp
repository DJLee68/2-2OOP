#include <iostream>

using namespace std;

#include "kicker.h"
#include "Player.h"


void kicker::set_power(int power){
    kick_power = power;
}
string kicker::view_power(int power){
    switch(power){
    case 1:
        return "약하게";
    case 2:
        return "중간 세기로";
    case 3:
        return "강하게";

    }

}
int kicker::get_power(){
    return kick_power;
}


