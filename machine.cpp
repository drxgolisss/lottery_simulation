#include "machine.h"

GameMachine:: GameMachine(int _serial_number)
: serial_number(_serial_number), no_of_games(0)
{
   games = new Game*[max_games];
   for(int i = 0; i < max_games; i++)
   {
      games[i] = nullptr;
   }
}

GameMachine:: ~GameMachine()
{
    for(int i = 0; i < no_of_games; i++)
   {
      delete games[i];
   }
   delete [] games;
}

ostream& operator<<(ostream &out, const GameMachine& a)
{
   out << "GameMachine SN#" << a.serial_number
        << " (stored games: " << a.no_of_games << "/" << GameMachine::max_games << ")\n";
    for (int i = 0; i < a.no_of_games; i++)
     {
        out << "  " << (i+1) << ". " << *a.games[i] << "\n";
     }
   return out;
    
}

void GameMachine:: add_game(string game_name, int no_of_balls, int no_to_draw)
{
   if(no_of_games < max_games)
   {
      games[no_of_games] = new Game(game_name, no_of_balls, no_to_draw);
      no_of_games++; 
   }
   else{
      cout << "No space , deleting the last game..." << endl;
      delete games[0];
      for(int i = 1; i < no_of_games; i++)
      {
        games[i-1] = games[i];
      }
      games[max_games-1] = new Game(game_name, no_of_balls, no_to_draw);
   }
}

void GameMachine:: run()
{
   cout << "Running GameMachine SN#" << serial_number << ":\n";
   for (int i = 0; i < no_of_games; i++) {
       Balls result = games[i]->draw();
       result.set_format() = Balls::format::only_numbers;
       cout << "  " << games[i]->get_name() << " results: " << result;
   }
}