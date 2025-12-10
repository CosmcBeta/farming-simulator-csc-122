#include "../src/soil.hpp"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE("it returns a dot as its symbol")
{
	Soil soil {};
	REQUIRE(soil.getSymbol() == '.');
}

TEST_CASE("it returns a dot as its symbol after updating")
{
	Soil soil {};
	soil.update();
	REQUIRE(soil.getSymbol() == '.');
}

TEST_CASE("can't be harvested")
{
	Soil soil {};
	REQUIRE(!soil.isHarvestable());
}

TEST_CASE("can't be harvested after updating")
{
	Soil soil {};
	soil.update();
	REQUIRE(!soil.isHarvestable());
}

TEST_CASE("works properly after many updates")
{
	Soil soil {};
	soil.update();
	soil.update();
	soil.update();
	soil.update();
	REQUIRE(soil.getSymbol() == '.');
	REQUIRE(!soil.isHarvestable());
}
