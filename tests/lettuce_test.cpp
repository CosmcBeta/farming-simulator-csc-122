#include "../src/lettuce.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE( "lettuce shows tilled soil symbol when first planted" )
{
    Lettuce lettuce {};
    REQUIRE( lettuce.getSymbol() == TILLED_SOIL_SYMBOL );
}

TEST_CASE( "lettuce sprouts into seedling after 1 day" )
{
    Lettuce lettuce {};
    lettuce.update();
    REQUIRE( lettuce.getSymbol() == 'l' );
}

TEST_CASE( "lettuce matures into adult plant after 2 days total" )
{
    Lettuce lettuce {};
    lettuce.update();
    lettuce.update();
    REQUIRE( lettuce.getSymbol() == 'L' );
}

TEST_CASE( "lettuce can't be harvested when it is tilled soil" )
{
    Lettuce lettuce {};
    REQUIRE( !lettuce.isHarvestable() );
}

TEST_CASE( "lettuce can't be harvested when it is a seedling" )
{
    Lettuce lettuce {};
    lettuce.update();
    REQUIRE( !lettuce.isHarvestable() );
}

TEST_CASE( "lettuce can be harvested when it is mature" )
{
    Lettuce lettuce {};
    lettuce.update();
    lettuce.update();
    REQUIRE( lettuce.isHarvestable() );
}

TEST_CASE( "lettuce stays mature after many updates" )
{
    Lettuce lettuce {};
    lettuce.update();
    lettuce.update();
    lettuce.update();
    lettuce.update();
    REQUIRE( lettuce.getSymbol() == 'V' );
    REQUIRE( lettuce.isHarvestable() );
}
