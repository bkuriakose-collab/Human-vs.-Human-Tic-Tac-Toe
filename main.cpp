#include <iostream>

#include "src/tictactoe.hpp"
using namespace std;

int main() {
	bool play_again = true;
	string answer;
	string mode;
	while (play_again) {
		
		while (true) {
			cout << "Choose a game mode:" << endl;
			cout << "1. Human vs Human" << endl;
			cout << "2. Human vs Computer" << endl;
			cout << "3. Computer vs Human" << endl;
			cout << "Enter your choice: ";
			getline(cin, mode);
			if (mode == "1" || mode == "2" || mode == "3") {
				break;
			}
			else {
				cout << "This is not a valid entry!" << endl;
			}
		}

	TicTacToe game;
	string input;
	cout << "Welcome to Tic-Tac-Toe!" << endl;
	game.print_board();
	
		while (true)
		{

			if ((mode == "2" && game.get_current_player() == 'O') || (mode == "3" && game.get_current_player() == 'X')) {
				for (int i = 1; i <= 9; i++) {
					string computerMove = to_string(i);
					if (game.is_valid_move(computerMove) == true) {
						cout << "Computer chooses " << i << endl;
						game.make_move(i);
						game.print_board();
						break;
					}
				}
				if (game.check_win() == true) {
					cout << "Player " << game.get_current_player() << " wins!" << endl;
					break;
				}
				if (game.check_draw() == true) {
					cout << "It's a draw!" << endl;
					break;
				}
				game.switch_player();
				continue;
			}




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

 

