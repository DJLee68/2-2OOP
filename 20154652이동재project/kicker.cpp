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
        return "���ϰ�";
    case 2:
        return "�߰� �����";
    case 3:
        return "���ϰ�";

    }

}
int kicker::get_power(){
    return kick_power;
}


