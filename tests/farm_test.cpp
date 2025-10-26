#include "../src/farm.hpp"
#include "../src/carrot.hpp"
#include "../src/player.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE( "it starts with day counter at 1" )
{
    Player player {};
    Farm farm(1, 1, &player);
    REQUIRE( farm.getDayCount() == 1 );
}

TEST_CASE( "it can be initialized with a single plot" )
{
    Player player {};
    Farm farm(1, 1, &player);
    REQUIRE( farm.getNumberOfRows() == 1 );
    REQUIRE( farm.getNumberOfColumns() == 1 );
}

TEST_CASE( "it returns the symbol for a single soil plot" )
{
    Player player {};
    Farm farm(1, 1, &player);
    REQUIRE( farm.getSymbol(0, 0) == '@' );
}

TEST_CASE( "it allows us to plant a carrot" )
{
    Player player {};
    Farm farm(1, 2, &player);
    Carrot carrot {};
    farm.plant(0, 1, &carrot);
    REQUIRE( farm.getSymbol(0, 1) == 'v' );
}

TEST_CASE( "it can harvest a single harvestable plant" )
{
    Player player {};
    Farm farm(1, 2, &player);
    Carrot* carrot = new Carrot();
    farm.plant(0, 1, carrot);

    farm.updatePlants();

    farm.harvest(0, 1);
    REQUIRE( farm.getSymbol(0, 1) == '.' );
}

TEST_CASE( "it increments day counter when updating plants" )
{
    Player player {};
    Farm farm(1, 1, &player);
    farm.updatePlants();
    REQUIRE( farm.getDayCount() == 2 );
}

TEST_CASE( "it can be initialized as a 1x2 farm" )
{
    Player player {};
    Farm farm(1, 2, &player);
    REQUIRE( farm.getNumberOfRows() == 1 );
    REQUIRE( farm.getNumberOfColumns() == 2 );
}

TEST_CASE( "it can be initialized as a 2x1 farm" )
{
    Player player {};
    Farm farm(2, 1, &player);
    REQUIRE( farm.getNumberOfRows() == 2 );
    REQUIRE( farm.getNumberOfColumns() == 1 );
}

TEST_CASE( "it returns the symbols for a 1x2 farm" )
{
    Player player {};
    Farm farm(1, 2, &player);
    REQUIRE( farm.getSymbol(0, 0) == '@' );
    REQUIRE( farm.getSymbol(0, 1) == '.' );
}

TEST_CASE( "it returns the symbols for a 2x1 farm" )
{
    Player player {};
    Farm farm(2, 1, &player);
    REQUIRE( farm.getSymbol(0, 0) == '@' );
    REQUIRE( farm.getSymbol(1, 0) == '.' );
}

TEST_CASE( "it can plant multiple carrots on different plots" )
{
    Player player {};
    Farm farm(2, 2, &player);
    Carrot* carrot1 = new Carrot();
    Carrot* carrot2 = new Carrot();

    farm.plant(0, 1, carrot1);
    farm.plant(1, 0, carrot2);

    REQUIRE( farm.getSymbol(0, 1) == 'v' );
    REQUIRE( farm.getSymbol(1, 0) == 'v' );
}

TEST_CASE( "it updates all plants when day advances" )
{
    Player player {};
    Farm farm(2, 2, &player);
    Carrot* carrot1 = new Carrot();
    Carrot* carrot2 = new Carrot();

    farm.plant(0, 1, carrot1);
    farm.plant(1, 0, carrot2);
    farm.updatePlants();

    REQUIRE( farm.getSymbol(0, 1) == 'V' );
    REQUIRE( farm.getSymbol(1, 0) == 'V' );
    REQUIRE( farm.getDayCount() == 2 );
}

TEST_CASE( "it increments day counter multiple times" )
{
    Player player {};
    Farm farm(1, 1, &player);

    farm.updatePlants();
    farm.updatePlants();
    farm.updatePlants();

    REQUIRE( farm.getDayCount() == 4 );
}

TEST_CASE( "it returns player symbol at player position" )
{
    Player player {};
    Farm farm(3, 3, &player);
    REQUIRE( farm.getSymbol(0, 0) == '@' );
}

TEST_CASE( "shows player at players position after planting" )
{
    Player player {};
    Farm farm(1, 1, &player);
    Carrot* carrot = new Carrot();
    farm.plant(0, 0, carrot);
    REQUIRE( farm.getSymbol(0, 0) == '@' );
}

TEST_CASE( "it cannot plant over an existing plant" )
{
    Player player {};
    Farm farm(1, 2, &player);
    Carrot* carrot1 = new Carrot();
    Carrot* carrot2 = new Carrot();

    farm.plant(0, 1, carrot1);
    farm.plant(0, 1, carrot2);

    REQUIRE( farm.getSymbol(0, 1) == 'v' );
}

TEST_CASE( "it does not harvest non-harvestable plants" )
{
    Player player {};
    Farm farm(1, 2, &player);
    Carrot* carrot = new Carrot();
    farm.plant(0, 1, carrot);

    farm.harvest(0, 1);

    REQUIRE( farm.getSymbol(0, 1) == 'v' );
}

TEST_CASE( "it does not harvest empty soil" )
{
    Player player {};
    Farm farm(1, 2, &player);

    farm.harvest(0, 1);

    REQUIRE( farm.getSymbol(0, 1) == '.' );
}

TEST_CASE( "it handles different plot types correctly" )
{
    Player player {};
    Farm farm(1, 3, &player);
    Carrot* carrot = new Carrot();

    farm.plant(0, 1, carrot);

    REQUIRE( farm.getSymbol(0, 0) == '@' );
    REQUIRE( farm.getSymbol(0, 1) == 'v' );
    REQUIRE( farm.getSymbol(0, 2) == '.' );
}

TEST_CASE( "it supports complete plant lifecycle" )
{
    Player player {};
    Farm farm(1, 2, &player);
    Carrot* carrot = new Carrot();

    farm.plant(0, 1, carrot);
    REQUIRE( farm.getSymbol(0, 1) == 'v' );

    farm.updatePlants();
    farm.updatePlants();
    farm.updatePlants();

    farm.harvest(0, 1);
    REQUIRE( farm.getSymbol(0, 1) == '.' );
}

TEST_CASE( "it tracks days accurately through multiple cycles" )
{
    Player player {};
    Farm farm(2, 2, &player);

    REQUIRE( farm.getDayCount() == 1 );

    farm.updatePlants();
    REQUIRE( farm.getDayCount() == 2 );

    farm.updatePlants();
    REQUIRE( farm.getDayCount() == 3 );

    farm.updatePlants();
    REQUIRE( farm.getDayCount() == 4 );
}

TEST_CASE( "it maintains farm state after multiple operations" )
{
    Player player {};
    Farm farm(2, 2, &player);
    Carrot* carrot1 = new Carrot();
    Carrot* carrot2 = new Carrot();

    farm.plant(0, 1, carrot1);
    farm.plant(1, 1, carrot2);
    farm.updatePlants();

    REQUIRE( farm.getNumberOfRows() == 2 );
    REQUIRE( farm.getNumberOfColumns() == 2 );
    REQUIRE( farm.getDayCount() == 2 );
    REQUIRE( farm.getSymbol(0, 1) == 'V' );
    REQUIRE( farm.getSymbol(1, 1) == 'V' );
}
