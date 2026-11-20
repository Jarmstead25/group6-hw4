#include <iostream>
#include "bowling_frame.h"
#include <random>
#include <cstdlib>

using namespace std;

std::random_device dev_main;
std::mt19937 rng_main(dev_main());

int current_game_total(Bowling_Frame * first_frame)
{
	Bowling_Frame * temp = first_frame;
	int game_total = 0;
	int temp_total = 0;
	while(temp)
	{
		game_total += temp->frame_score();
		temp = temp->next_frame();
	}
	return game_total;	
}

int main(int argc, char* argv[])
{
      if (argc != 2)
{
  cout << "Usage: " << argv[0] << "<num_players>" << endl;
  return 1;
}
  int num_players = atoi(argv[1]);
  
     if (num_players <= 0)
{
   cout << "Error: Number of players must be greater than 0." << endl;
   return 1;
}

  cout << "Player count is: " <<num_players << endl;

  Bowling_Frame** players = new Bowling_Frame*[num_players];

for (int i = 0; i < num_players; i++)
{
    players[i] = new Bowling_Frame(1);
    Bowling_Frame* previous = players[i];

    for (int j = 2; j <= 10; j++)
    {
        Bowling_Frame* current = new Bowling_Frame(j);

        previous->next_frame(current);
        current->prev_frame(previous);

        previous = current;
   }
}	

	//set frame scores	
	//set frame scores for each player
     for (int i = 0; i < num_players; i++)
{
        for (int j = 0; j < 20; j++)
     {
           players[i]->update_scores();
     }
}

	//iterate through linked list and print values
         
         for (int i = 0; i < num_players; i++)
{
           Bowling_Frame * traverse = players[i];

	while(traverse)
	{
		cout << "Frame " << traverse->frame_num() << ": " << endl
		 	 << " Score 1: " << traverse->score1() << endl
		 	 << " Score 2: " << traverse->score2() << endl;

		traverse = traverse->next_frame();
	}
                cout << "Total Game Score for player " << i + 1
                         << ": " << current_game_total(players[i]) << endl;
}

}

