#include "../src/farm.hpp"
#include "../src/farm_printer.hpp"
#include "../src/player.hpp"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE("it pretty prints a single plot of land")
{
	Player player {};
	Farm farm(1, 1, &player, false);
	FarmPrinter printer(&farm);
	REQUIRE(printer.prettyPrint() == "@ \n");
}

TEST_CASE("it pretty prints a 1x2 farm")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	FarmPrinter printer(&farm);
	REQUIRE(printer.prettyPrint() == "@ . \n");
}

TEST_CASE("it pretty prints a 2x1 farm")
{
	Player player {};
	Farm farm(2, 1, &player, false);
	FarmPrinter printer(&farm);
	REQUIRE(printer.prettyPrint() == "@ \n. \n");
}

TEST_CASE("it pretty prints a 2x2 farm")
{
	Player player {};
	Farm farm(2, 2, &player, false);
	FarmPrinter printer(&farm);
	REQUIRE(printer.prettyPrint() == "@ . \n. . \n");
}

TEST_CASE("prints the legend and information")
{
	Player player {};
	Farm farm(2, 2, &player, false);
	FarmPrinter printer(&farm);
	REQUIRE(
		printer.printLegend() ==
		"Controls\n[W/A/S/D] Move\n[C] Plant Carrot\n[L] Plant Lettuce\n[J] Plant Spinach\n[B] Plant Beet\n[N] Plant Brussel Sprout\n[R] Water Plant\n[H] Harvest\n[E] End Day\n[Q] Quit Game\n\nInformation\nDay: 1");
}

TEST_CASE("prints the legend and information with updated day")
{
	Player player {};
	Farm farm(2, 2, &player, false);
	FarmPrinter printer(&farm);
	REQUIRE(
		printer.printLegend() ==
		"Controls\n[W/A/S/D] Move\n[C] Plant Carrot\n[L] Plant Lettuce\n[J] Plant Spinach\n[B] Plant Beet\n[N] Plant Brussel Sprout\n[R] Water Plant\n[H] Harvest\n[E] End Day\n[Q] Quit Game\n\nInformation\nDay: 1");
	farm.updatePlants();
	REQUIRE(
		printer.printLegend() ==
		"Controls\n[W/A/S/D] Move\n[C] Plant Carrot\n[L] Plant Lettuce\n[J] Plant Spinach\n[B] Plant Beet\n[N] Plant Brussel Sprout\n[R] Water Plant\n[H] Harvest\n[E] End Day\n[Q] Quit Game\n\nInformation\nDay: 2");
}
