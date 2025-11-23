#include "../src/brussel_sprout.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE( "brussel sprout shows tilled soil symbol when first planted" )
{
    BrusselSprout brusselSprout {};
    REQUIRE( brusselSprout.getSymbol() == TILLED_SOIL_SYMBOL );
}

TEST_CASE( "brussel sprout sprouts into seedling after 1 day" )
{
    BrusselSprout brusselSprout {};
    brusselSprout.update();
    REQUIRE( brusselSprout.getSymbol() == 'v' );
}

TEST_CASE( "brussel sprout matures into adult plant after 2 days total" )
{
    BrusselSprout brusselSprout {};
    brusselSprout.update();
    brusselSprout.update();
    REQUIRE( brusselSprout.getSymbol() == 'V' );
}

TEST_CASE( "brussel sprout can't be harvested when it is tilled soil" )
{
    BrusselSprout brusselSprout {};
    REQUIRE( !brusselSprout.isHarvestable() );
}

TEST_CASE( "brussel sprout can't be harvested when it is a seedling" )
{
    BrusselSprout brusselSprout {};
    brusselSprout.update();
    REQUIRE( !brusselSprout.isHarvestable() );
}

TEST_CASE( "brussel sprout can be harvested when it is mature" )
{
    BrusselSprout brusselSprout {};
    brusselSprout.update();
    brusselSprout.update();
    REQUIRE( brusselSprout.isHarvestable() );
}

TEST_CASE( "brussel sprout stays mature after many updates" )
{
    BrusselSprout brusselSprout {};
    brusselSprout.update();
    brusselSprout.update();
    brusselSprout.update();
    brusselSprout.update();
    REQUIRE( brusselSprout.getSymbol() == 'V' );
    REQUIRE( brusselSprout.isHarvestable() );
}
