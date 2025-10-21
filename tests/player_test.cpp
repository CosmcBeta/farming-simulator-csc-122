#include "../src/player.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE( "it starts the player in row zero, column zero, with @ as its symbol" )
{
    Player player {};
    REQUIRE( player.getRow() == 0 );
    REQUIRE( player.getColumn() == 0 );
    REQUIRE( player.getSymbol() == '@' );
}

TEST_CASE( "it starts the player in row 1, column 1, with @ as its symbol" )
{
    Player player(1, 1);
    REQUIRE( player.getRow() == 1 );
    REQUIRE( player.getColumn() == 1 );
    REQUIRE( player.getSymbol() == '@' );
}

TEST_CASE( "it starts the player in row zero, column zero, with # as its symbol" )
{
    char symbol {'#'};
    Player player(0, 0, symbol);
    REQUIRE( player.getRow() == 0 );
    REQUIRE( player.getColumn() == 0 );
    REQUIRE( player.getSymbol() == symbol );
}

TEST_CASE( "it moves the player to the right" )
{
    Player player {};
    player.move(Move::Right);
    REQUIRE( player.getRow() == 0 );
    REQUIRE( player.getColumn() == 1 );
}

TEST_CASE( "it moves the player down" )
{
    Player player {};
    player.move(Move::Down);
    REQUIRE( player.getRow() == 1 );
    REQUIRE( player.getColumn() == 0 );
}

TEST_CASE( "it moves the player up" )
{
    Player player(1, 1);
    player.move(Move::Up);
    REQUIRE( player.getRow() == 0 );
    REQUIRE( player.getColumn() == 1 );
}

TEST_CASE( "it moves the player left" )
{
    Player player(1, 1);
    player.move(Move::Left);
    REQUIRE( player.getRow() == 1 );
    REQUIRE( player.getColumn() == 0 );
}
