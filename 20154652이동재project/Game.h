#ifndef GAME_H
#define GAME_H

class Game{
    string score;
public:
    int game_count;
    int goal;
    Game();
    void playing();
    void show_score();
    void set_score(string score1);
    void init_score();
};





#endif // GAME_H
