#include "game.h"

Game:: Game (string _name, int _no_of_balls, int _no_to_draw)
: name(_name), no_to_draw(_no_to_draw), drawing_balls(_no_of_balls)
{
}

ostream& operator<<(ostream& out, const Game& a)
{
   out << "Game: " << a.name << ", No. of balls :"  << a.drawing_balls.balls_no() << " , No. to draw: " << a.no_to_draw << endl;
   return out;
}

Balls Game:: draw()
{
   Balls newob;
   // int *arr = new int[no_to_draw];
   int a = 0;
   for(int i = 0; i < no_to_draw; i++)
   {
      drawing_balls.draw(0, a);
      newob += a;
   }
   return newob;
}

// Balls Game:: draw()
// {
//    drawing_balls.mix();
//    int *arr = new int[no_to_draw];
//    int res = 0;

//    for(int i = 0; i < no_to_draw; i++)
//    {
//       drawing_balls.draw(0, res);
//       arr[i] = res;
//    }

//    Balls a(no_to_draw, arr);
//    delete [] arr;
//    return a;
// }