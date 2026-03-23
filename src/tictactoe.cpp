#include <string>
#include "tictactoe.hpp"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe()
{
	board.push_back("1");
	board.push_back("2");
	board.push_back("3");
	board.push_back("4");
	board.push_back("5");
	board.push_back("6");
	board.push_back("7");
	board.push_back("8");
	board.push_back("9");
	current_player = 'X';
}
void TicTacToe::print_board() const
{
	cout << endl;
	cout << "    " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << " -----+-----+-----" << endl;
	cout << "    " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << " -----+-----+-----" << endl;
	cout << "    " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << endl;
}
bool TicTacToe::is_valid_move(string input) const
{
	if (input.length() != 1)
	{
	
	return false;
    }
	if (input[0] < '1' || input[0] > '9') {
		return false;
	}
	int position = input[0] - '0';
	if (board[position - 1] == "X" || board[position - 1] == "O") {
		return false;
	}
	return true;
}
void TicTacToe::make_move(int position)
{
	if (current_player == 'X')
	{
		board[position - 1] = "X";

	}
	else {
		board[position - 1] = "O";
	}
}
bool TicTacToe::check_win() const
{
	if (board[0] == board[1] && board[1] == board[2])
	{
		return true;
	}
	if (board[3] == board[4] && board[4] == board[5])
	{
		return true;
	}
	if (board[6] == board[7] && board[7] == board[8])
	{
		return true;
	}
	if (board[0] == board[3] && board[3] == board[6])
	{
		return true;
	}
	if (board[1] == board[4] && board[4] == board[7])
	{
		return true;
	}
	if (board[2] == board[5] && board[5] == board[8])
	{
		return true;
	}
	if (board[0] == board[4] && board[4] == board[8])
	{
		return true;
	}
	if (board[2] == board[4] && board[4] == board[6])
	{
		return true;
	}

	return false;


}
bool TicTacToe::check_draw() const
{
	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] != "X" && board[i] != "O")
		{
			return false;
		}
	}
	return true;
}
void TicTacToe::switch_player()
{
	if (current_player == 'X') {
		current_player = 'O';

	}
	else

	{
		current_player = 'X';
	}
}
void TicTacToe::reset_game() {
	board.clear();
	board.push_back("1");
	board.push_back("2");
	board.push_back("3");
	board.push_back("4");
	board.push_back("5");
	board.push_back("6");
	board.push_back("7");
	board.push_back("8");
	board.push_back("9");

	current_player = 'X';


}
char TicTacToe::get_current_player() const
{
	return current_player;
}