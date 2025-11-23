#include "../src/beet.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE( "beet shows tilled soil symbol when first planted" )
{
    Beet beet {};
    REQUIRE( beet.getSymbol() == TILLED_SOIL_SYMBOL );
}

TEST_CASE( "beet sprouts into seedling after 2 day" )
{
    Beet beet {};
    beet.update();
    beet.update();
    REQUIRE( beet.getSymbol() == 'b' );
}

TEST_CASE( "beet matures into adult plant after 7 days total" )
{
    Beet beet {};
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    REQUIRE( beet.getSymbol() == 'B' );
}

TEST_CASE( "beet can't be harvested when it is tilled soil" )
{
    Beet beet {};
    REQUIRE( !beet.isHarvestable() );
}

TEST_CASE( "beet can't be harvested when it is a seedling" )
{
    Beet beet {};
    beet.update();
    beet.update();
    REQUIRE( !beet.isHarvestable() );
}

TEST_CASE( "beet can be harvested when it is mature" )
{
    Beet beet {};
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    REQUIRE( beet.isHarvestable() );
}

TEST_CASE( "beet stays mature after many updates" )
{
    Beet beet {};
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    beet.update();
    REQUIRE( beet.getSymbol() == 'B' );
    REQUIRE( beet.isHarvestable() );
}
