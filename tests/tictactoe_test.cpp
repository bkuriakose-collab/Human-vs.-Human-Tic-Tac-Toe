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

TEST_CASE("game puts player back to X") {
    TicTacToe game;
    game.switch_player();
    game.reset_game();
    REQUIRE(game.get_current_player() == 'X');
}
TEST_CASE("game clears taken spots") {
    TicTacToe game;
    game.make_move(1);
    game.reset_game();
    REQUIRE(game.is_valid_move("1") == true);
}
TEST_CASE("trap is off by default") {
    TicTacToe game;
    game;

    for (int i = 1; i <= 9; i++) {
        REQUIRE(game.isTrap(i) == false);
    }
}

TEST_CASE("enableTrap creates exactly one trap") {
    TicTacToe game;
    game;
    game.enableTrap();

    int trapCount = 0;

    for (int i = 1; i <= 9; i++) {
        if (game.isTrap(i) == true) {
            trapCount++;
        }
    }

    REQUIRE(trapCount == 1);
}

TEST_CASE("disableTrap turns trap off") {
    TicTacToe game;
    game;
    game.enableTrap();
    game.disableTrap();

    for (int i = 1; i <= 9; i++) {
        REQUIRE(game.isTrap(i) == false);
    }
}

TEST_CASE("resetGame clears the trap") {
    TicTacToe game;
    game.enableTrap();
    game.reset_game();

    for (int i = 1; i <= 9; i++) {
        REQUIRE(game.isTrap(i) == false);
    }
}

TEST_CASE("draw works when trap cell is left unmarked") {
    TicTacToe game;
    game.enableTrap();

    for (int i = 1; i <= 9; i++) {
        if (game.isTrap(i) == false) {
            game.make_move(i);
        }
    }

    REQUIRE(game.check_draw() == true);
}


