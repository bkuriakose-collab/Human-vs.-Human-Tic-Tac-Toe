#include <iostream>

#include "src/tictactoe.hpp"
using namespace std;

int main() {
	bool play_again = true;
	string answer;
	while (play_again) {
	TicTacToe game;
	string input;
	cout << "Welcome to Tic-Tac-Toe!" << endl;
	game.print_board();
	
		while (true)
		{
			cout << "What is your move? ";
			getline(cin, input);
			if (game.is_valid_move(input) == false)
			{
				cout << endl;
				cout << "That is not a valid move! Try agian" << endl << endl;
				game.print_board();
				continue;
			}


			int position = input[0] - '0';
			game.make_move(position);
			game.print_board();

			if (game.check_win() == true)
			{
				cout << "Player " << game.get_current_player() << " wins!" << endl;
				break;
			}
			if (game.check_draw() == true)
			{
				cout << "It's a draw!" << endl;
				break;
			}
			game.switch_player();
			
		}
		while (true) {


			cout << "Play agian? ";
			getline(cin, answer);
			if (answer == "Yes" || answer == "Y" || answer == "yes" || answer == "YES")
			{
				break;
			}
			else if (answer == "No" || answer == "N" || answer == "no" || answer == "NO")
			{

				play_again = false;
				break;
			}
			else {
				cout << "That is not a valid entry!" << endl;
				
			}
		}

	}
	cout << "Goodbye!" << endl;
	return 0;
}

 

