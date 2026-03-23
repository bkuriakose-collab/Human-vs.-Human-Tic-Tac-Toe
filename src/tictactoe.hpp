#include <string>
#include <vector>
using namespace std;

class TicTacToe
{
public:
	TicTacToe();

	void print_board() const;
	bool is_valid_move(string input) const;
	void make_move(int position);
	bool check_win() const;
	bool check_draw() const;
	void switch_player();
	void reset_game();
	char get_current_player() const;

private:
	vector<string> board;
	char current_player;
};
