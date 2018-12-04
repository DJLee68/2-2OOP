#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "Probability.h"


Probability::Probability(){
    srand((unsigned int)time(0));
    rand_num1 = rand()% 4;
    rand_num2 = rand()% 4;
}

int Probability::determine_goal(int kick_way, int kick_power, int keep_way){

    if(kick_way != keep_way){
        switch(kick_power){
        case 1:

            if(rand_num1<=0){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 2:
            if(rand_num1<=1){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 3:
            if(rand_num1<=2){
                return 0;
            }
            else{
                return 1;
            }
            break;

        }
    }
    else{
        switch(kick_power){
        case 1:
            if(rand_num1<=2){
                if(rand_num2<=0){
                    return 1;
                }
                else
                    return 0;
            }
            else{
                return 0;
            }
            break;
        case 2:
            if(rand_num1<=1){
                if(rand_num2<=1){
                    return 1;
                }
                else
                    return 0;
            }
            else{
                return 0;
            }
            break;
        case 3:
            if(rand_num1<=0){
                if(rand_num2<=2){
                    return 1;
                }
                else
                    return 0;
            }
            else{
                return 0;
            }
            break;
        }
    }
}
