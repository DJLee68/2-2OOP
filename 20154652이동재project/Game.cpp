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
    cout << "-------�º����� ������ �����մϴ�.-------\n\n\n";
    Sleep(1200);
    cout << "�÷��� ���: \n";
    cout << "1. �º����� ŰĿ �Ǵ� ��Ű�۰� �Ǿ� 5���� �º����⸦ �����մϴ�.\n";
    cout << "2. �� ����� ������ �Է��մϴ�.\n\n";
    cout << "\t - �� ���� �ȳ�: 1, 2, 3, 4, 5�� �ϳ� ����\n";
    cout << "\t - �� �Ŀ� �ȳ�: 1, 2, 3 �� �ϳ� ����\n\n";
    cout << "\t 1. �Ŀ��� 1�� ��, ŰĿ�� 25������ �Ŀ�(���� ��, ������ ��Ȯ)���� ���� ����.\n\t �� ��, ��븦 �°ų� ��� ������ ���� Ȯ���� 25�����̴�.\n\t ��ſ� ŰĿ�� ������ ����� ��Ű�۰� ���ù��� ������ ��ġ�ص� 75������ Ȯ���� ��Ű�۰� ���´�.\n\t(���� ��Ȯ�ѵ� ���ϴϱ� ���⸸ ������ ���� ����ϱ�)\n\n";
    cout << "\t 2. �Ŀ��� 2�� ��, ŰĿ�� 50������ ������(�߰� ��, ��Ȯ�� �߰�)���� ���� ����.\n\t �� ��, ��븦 �°ų� ��� ������ ���� Ȯ���� 50�����̴�.\n\t ��ſ� ŰĿ�� ������ ����� ��Ű�۰� ���ù��� ������ ��ġ�ص� 50������ Ȯ���� ��Ű�۰� ���´�\n\n";
    cout << "\t 3. �Ŀ��� 3�� ��, ŰĿ�� 75������ ������(���� ��, ������ ����Ȯ)���� ���� ����.\n\t �� ��, ��븦 �°ų� ��� ������ ���� Ȯ���� 75�����̴�.\n\t ��ſ� ŰĿ�� ������ ����� ��Ű�۰� ���ù��� ������ ��ġ�ص� 25������ Ȯ���θ� ��Ű�۰� ���´�\n\t(������ �¾Ƶ� ���� ���ϴϱ� ���� �����)\n\n";
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


        cout << "��Ű���� �����Դϴ�. ���� ������ �����ϼ���: ";
        int keep_way;
        cin >> keep_way;
        keeper.set_way(keep_way);


        cout << "ŰĿ�� �����Դϴ�. �� ����� ���⸦ �����ϼ���: ";
        int way;
        int power;
        cin >> way >> power;
        kicker.set_way(way);
        kicker.set_power(power);



        cout << kicker.get_way() << "�� �������� " << kicker.view_power(kicker.get_power()) << " ";
        cout << "��~";
        Sleep(500);
        cout << "��~";
        Sleep(500);
        cout << "��~~~!!!\n";
        Sleep(300);
        cout << "��Ű�۵� " << keeper.get_way() << "�� �������� ���� �����ϴ�!!!\n\n";
        Sleep(700);

        if(kicker.get_way() == keeper.get_way()){
            cout << "��~~~ ��Ű�۰� ������ �о��µ���!?!?!?\n";
        }
        else{
            cout << "��~~~��Ű�۰� ������ �� �о��µ���!?!?!?\n";
        }

        Sleep(700);

        int goal = probability.determine_goal(kicker.get_way(), kicker.get_power(), keeper.get_way());
        if(goal){
            if(kicker.get_way() == keeper.get_way())
                cout << "�Ϳ�~~~~~��Ű���� ���� ��ġ�� ���ϴ�!\n�ƽ��� �ϴ� ��Ű��!!!\n";
            else
                cout << "�Ϻ��� ���Դϴ�~~~��Ű�۸� ������ ���Դϴ�!\n";
            set_score("O");
            goal++;
        }
        else{
            if(kicker.get_way() == keeper.get_way())
                cout << "�Ϳ�!!! ���ҽ��ϴ�!!! �Ϻ��� ������ ���� ��Ű��!!!\n";

            else
                cout << "��~~��Ű�۴� �ӿ����� ��븦 �������ϴ�! �ƽ��� �ϴ� ŰĿ!!\n";
            set_score("X");
        }
        Sleep(500);
        cout << "\n";
        show_score();
        game_count ++;
    }

    cout << "\n\n\n";
    cout << "�������ھ�: " << score << "\n\n";

    if(goal<3)
        cout << "��Ű���� �¸�!\n\n";
    else
        cout << "ŰĿ�� �¸�!\n\n";

    cout << "��� ���� �Ϸ��� 1, �����Ϸ��� 0�� ��������: ";
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
    cout << "�º� ���� ������: " << score << "\n\n";
}
void Game::set_score(string score1){
    score.append(score1);
}
void Game::init_score(){
    score = "";
}
