#include "../src/spinach.hpp"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE("spinach shows tilled soil symbol when first planted")
{
	Spinach spinach {};
	REQUIRE(spinach.getSymbol() == TILLED_SOIL_SYMBOL);
}

TEST_CASE("spinach sprouts into seedling after 2 day")
{
	Spinach spinach {};
	spinach.update();
	spinach.update();
	REQUIRE(spinach.getSymbol() == 'j');
}

TEST_CASE("spinach matures into adult plant after 5 days total")
{
	Spinach spinach {};
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	REQUIRE(spinach.getSymbol() == 'J');
}

TEST_CASE("spinach can't be harvested when it is tilled soil")
{
	Spinach spinach {};
	REQUIRE(!spinach.isHarvestable());
}

TEST_CASE("spinach can't be harvested when it is a seedling")
{
	Spinach spinach {};
	spinach.update();
	spinach.update();
	REQUIRE(!spinach.isHarvestable());
}

TEST_CASE("spinach can be harvested when it is mature")
{
	Spinach spinach {};
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	REQUIRE(spinach.isHarvestable());
}

TEST_CASE("spinach stays mature after many updates")
{
	Spinach spinach {};
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	spinach.update();
	REQUIRE(spinach.getSymbol() == 'J');
	REQUIRE(spinach.isHarvestable());
}
