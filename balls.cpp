#include "balls.h"
#include <random>
int Balls:: id = 0;

Balls:: Balls(int no, int * _balls): set_id(++id), no_of_balls(no)
{
   balls = new int[no]; 
   if (_balls == nullptr)
   {
       for (int i = 0; i < no_of_balls; i++)
       {
           balls[i] = i + 1;
       }
   }
   else
   {
       for (int i = 0; i < no_of_balls; i++)
       {
           balls[i] = _balls[i];
       }
   }
}



ostream& operator<<(ostream& out, const Balls& a)
{
   out << "Set ID =  " << a.set_id << " - " << "Balls: ";
   if(a.printing_format == Balls::format::full)
   {
     for(int i = 0; i < a.no_of_balls; i++)
     {
        out << a.balls[i] << (i == a.no_of_balls - 1 ? " " : ", ");
     }
     out << std::endl;
   }
   else{
     for(int i = 0; i < 6; i++)
     {
        out << a.balls[i] << ", ";
     }
       out << "... , " << a.no_of_balls << std::endl;
   }
   return out;
}

Balls:: ~Balls()
{
    delete [] balls;
}

Balls:: Balls(const Balls& b): set_id(++id), no_of_balls(b.no_of_balls), printing_format(b.printing_format)
{
   balls = new int[b.no_of_balls];
   for(int i =0; i < b.no_of_balls; i++)
   {
     balls[i] = b.balls[i];
   }
}

Balls& Balls:: operator=(const Balls& ab)
{
   if(this != &ab)
   {
      if(balls != nullptr)
      {
         delete [] balls;
      }

      no_of_balls = ab.no_of_balls;
      balls = new int[ab.no_of_balls];
      for(int i = 0; i < ab.no_of_balls; i++)
      {
        balls[i] = ab.balls[i];
      }
   }
   return *this;
}

void Balls::mix()
{
   for(int i = 0; i < no_of_balls; i++)
   {
      int idx = rand() % no_of_balls;
      std::swap(balls[i], balls[idx]);
   }
}

bool Balls:: draw(int pos, int& result)
{
   if(pos < 0 || pos >= no_of_balls)
   {
      return false;
   }

   result = balls[pos];

   for(int i = pos; i < no_of_balls - 1 ; i++)
   {
      balls[i] = balls[i+1];
   }
   
   int *arr = new int[no_of_balls - 1];
   for(int i = 0; i < no_of_balls - 1; i++)
   {
      arr[i] = balls[i];
   }
   delete [] balls;
   balls = arr;
   no_of_balls--;
   return true;
}

void Balls:: operator+=(int ball_number)
{
   int *arr = new int[no_of_balls + 1];
   for(int i = 0; i < no_of_balls; i++)
   {
      arr[i] = balls[i];
   }
   arr[no_of_balls] = ball_number;
   delete [] balls;
   balls = arr;
   no_of_balls++;
}