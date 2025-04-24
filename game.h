#pragma once
#include <iostream>
using namespace std;
#include "balls.h"
#include <string>

class Game
{
    string name;
    int no_to_draw;
    Balls drawing_balls;
public:
    // Part 4: Конструктор
    Game(string _name= "", int _no_of_balls= 0, int _no_to_draw = 0);
    friend ostream& operator<<(ostream& out, const Game& a);

    // Part 5: Прототип функции для проведения розыгрыша
    Balls draw();

    string get_name() const { return name; }
};
