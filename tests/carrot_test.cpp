#include "../src/carrot.hpp"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE("carrot shows tilled soil symbol when first planted")
{
	Carrot carrot {};
	REQUIRE(carrot.getSymbol() == TILLED_SOIL_SYMBOL);
}

TEST_CASE("carrot sprouts into seedling after 1 day")
{
	Carrot carrot {};
	carrot.update();
	REQUIRE(carrot.getSymbol() == 'v');
}

TEST_CASE("carrot matures into adult plant after 2 days total")
{
	Carrot carrot {};
	carrot.update();
	carrot.update();
	REQUIRE(carrot.getSymbol() == 'V');
}

TEST_CASE("carrot can't be harvested when it is tilled soil")
{
	Carrot carrot {};
	REQUIRE(!carrot.isHarvestable());
}

TEST_CASE("carrot can't be harvested when it is a seedling")
{
	Carrot carrot {};
	carrot.update();
	REQUIRE(!carrot.isHarvestable());
}

TEST_CASE("carrot can be harvested when it is mature")
{
	Carrot carrot {};
	carrot.update();
	carrot.update();
	REQUIRE(carrot.isHarvestable());
}

TEST_CASE("carrot stays mature after many updates")
{
	Carrot carrot {};
	carrot.update();
	carrot.update();
	carrot.update();
	carrot.update();
	REQUIRE(carrot.getSymbol() == 'V');
	REQUIRE(carrot.isHarvestable());
}
