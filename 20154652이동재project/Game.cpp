#include <iostream>
using namespace std;
#include <windows.h>
#include "Game.h"
#include "Probability.h"
#include "kicker.h"
#include "keeper.h"
#include "Player.h"

Game::Game(){
    game_count =  0;
    cout << "-------승부차기 게임을 시작합니다.-------\n\n\n";
    Sleep(1200);
    cout << "플레이 방법: \n";
    cout << "1. 승부차기 키커 또는 골키퍼가 되어 5번의 승부차기를 실행합니다.\n";
    cout << "2. 찰 방향과 강도를 입력합니다.\n\n";
    cout << "\t - ⓐ 방향 안내: 1, 2, 3, 4, 5중 하나 선택\n";
    cout << "\t - ⓑ 파워 안내: 1, 2, 3 중 하나 선택\n\n";
    cout << "\t 1. 파워가 1일 때, 키커는 25프로의 파워(약한 슛, 하지만 정확)으로 슛을 찬다.\n\t 이 때, 골대를 맞거나 골대 밖으로 나갈 확률은 25프로이다.\n\t 대신에 키커가 선택한 방향과 골키퍼가 선택받은 방향이 일치해도 75프로의 확률로 골키퍼가 막는다.\n\t(슛이 정확한데 약하니까 방향만 맞으면 막기 쉬우니까)\n\n";
    cout << "\t 2. 파워가 2일 때, 키커는 50프로의 게이지(중간 슛, 정확도 중간)으로 슛을 찬다.\n\t 이 때, 골대를 맞거나 골대 밖으로 나갈 확률은 50프로이다.\n\t 대신에 키커가 선택한 방향과 골키퍼가 선택받은 방향이 일치해도 50프로의 확률로 골키퍼가 막는다\n\n";
    cout << "\t 3. 파워가 3일 때, 키커는 75프로의 게이지(강한 슛, 하지만 부정확)으로 슛을 찬다.\n\t 이 때, 골대를 맞거나 골대 밖으로 나갈 확률은 75프로이다.\n\t 대신에 키커가 선택한 방향과 골키퍼가 선택받은 방향이 일치해도 25프로의 확률로만 골키퍼가 막는다\n\t(방향이 맞아도 슛이 강하니까 막기 어려움)\n\n";
    score = "";

}

void Game::playing(){
    goal = 0;
    while(game_count<5){
        Probability probability;
        keeper keeper;
        kicker kicker;

        cout << "\t\t -----------------------------------------\n";
        cout << "\t\t |                                       |\n";
        cout << "\t\t |                   0                   |\n";
        cout << "\t\t |                  -|-                  |\n";
        cout << "\t\t |                   =                   |\n";
        cout << "\t\t |                                       |\n";
        cout << "\t\t |                                       |\n";
        cout << "\t\t | 1        2        3        4        5 |\n";
        cout << "\t\t |                                       |\n";


        cout << "골키퍼의 차례입니다. 막을 방향을 선택하세요: ";
        int keep_way;
        cin >> keep_way;
        keeper.set_way(keep_way);


        cout << "키커의 차례입니다. 찰 방향과 세기를 선택하세요: ";
        int way;
        int power;
        cin >> way >> power;
        kicker.set_way(way);
        kicker.set_power(power);



        cout << kicker.get_way() << "번 방향으로 " << kicker.view_power(kicker.get_power()) << " ";
        cout << "슈~";
        Sleep(500);
        cout << "우~";
        Sleep(500);
        cout << "웃~~~!!!\n";
        Sleep(300);
        cout << "골키퍼도 " << keeper.get_way() << "번 방향으로 몸을 날립니다!!!\n\n";
        Sleep(700);

        if(kicker.get_way() == keeper.get_way()){
            cout << "아~~~ 골키퍼가 방향을 읽었는데요!?!?!?\n";
        }
        else{
            cout << "아~~~골키퍼가 방향을 못 읽었는데요!?!?!?\n";
        }

        Sleep(700);

        int goal = probability.determine_goal(kicker.get_way(), kicker.get_power(), keeper.get_way());
        if(goal){
            if(kicker.get_way() == keeper.get_way())
                cout << "와우~~~~~골키퍼의 손을 스치고 들어갑니다!\n아쉬워 하는 골키퍼!!!\n";
            else
                cout << "완벽한 골입니다~~~골키퍼를 완전히 속입니다!\n";
            set_score("O");
            goal++;
        }
        else{
            if(kicker.get_way() == keeper.get_way())
                cout << "와우!!! 막았습니다!!! 완벽한 선방을 보인 골키퍼!!!\n";

            else
                cout << "아~~골키퍼는 속였지만 골대를 빗나갑니다! 아쉬워 하는 키커!!\n";
            set_score("X");
        }
        Sleep(500);
        cout << "\n";
        show_score();
        game_count ++;
    }

    cout << "\n\n\n";
    cout << "최종스코어: " << score << "\n\n";

    if(goal<3)
        cout << "골키퍼의 승리!\n\n";
    else
        cout << "키커의 승리!\n\n";

    cout << "계속 게임 하려면 1, 종료하려면 0을 누르세요: ";
    int i;
    cin >> i;
    if(i){
        system("cls");
        init_score();
        game_count = 0;
        playing();
    }
    else
        exit(-1);


}

void Game::show_score(){
    cout << "승부 차기 점수판: " << score << "\n\n";
}
void Game::set_score(string score1){
    score.append(score1);
}
void Game::init_score(){
    score = "";
}
