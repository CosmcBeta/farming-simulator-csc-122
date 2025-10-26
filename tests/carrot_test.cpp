#include "../src/carrot.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE( "it returns a v as its when it is a seedling" )
{
    Carrot carrot {};
    REQUIRE( carrot.getSymbol() == 'v' );
}

TEST_CASE( "it returns a V as its when it is mature" )
{
    Carrot carrot {};
    carrot.update();
    REQUIRE( carrot.getSymbol() == 'V' );
}

TEST_CASE( "can't be harvested when it is a seedling" )
{
    Carrot carrot {};
    REQUIRE( !carrot.isHarvestable() );
}

TEST_CASE( "can be harvested when it is mature" )
{
    Carrot carrot {};
    carrot.update();
    REQUIRE( carrot.isHarvestable() );
}

TEST_CASE( "works properly after many updates" )
{
    Carrot carrot {};
    carrot.update();
    carrot.update();
    carrot.update();
    carrot.update();
    REQUIRE( carrot.getSymbol() == 'V' );
    REQUIRE( carrot.isHarvestable() );
}
