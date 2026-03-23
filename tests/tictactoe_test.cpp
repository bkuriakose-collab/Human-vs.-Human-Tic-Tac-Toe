#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"

TEST_CASE( "Game Starting wilt player X" ) {
    TicTacToe game;
    REQUIRE( game.get_current_player() == 'X');
}
TEST_CASE("is a vaild move accepted") {
    TicTacToe game;
    REQUIRE(game.is_valid_move("1") == true);
}
TEST_CASE("taken spot would be invaild") {
    TicTacToe game;
    game.make_move(1);
    REQUIRE(game.is_valid_move("1") == false);
}
TEST_CASE("swithing players work") {
    TicTacToe game;
    game.switch_player();
    REQUIRE(game.get_current_player() == 'O');
}


