#include "../src/beet.hpp"
#include "../src/brussel_sprout.hpp"
#include "../src/carrot.hpp"
#include "../src/farm.hpp"
#include "../src/lettuce.hpp"
#include "../src/player.hpp"
#include "../src/spinach.hpp"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE("it starts with day counter at 1")
{
	Player player {};
	Farm farm(1, 1, &player, false);
	REQUIRE(farm.getDayCount() == 1);
}

TEST_CASE("it can be initialized with a single plot")
{
	Player player {};
	Farm farm(1, 1, &player, false);
	REQUIRE(farm.getNumberOfRows() == 1);
	REQUIRE(farm.getNumberOfColumns() == 1);
}

TEST_CASE("it returns the symbol for a single soil plot")
{
	Player player {};
	Farm farm(1, 1, &player, false);
	REQUIRE(farm.getSymbol(0, 0) == '@');
}

TEST_CASE("it allows us to plant a carrot")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot carrot {};
	farm.plant(0, 1, &carrot);
	REQUIRE(farm.getSymbol(0, 1) == '~');
}

TEST_CASE("it allows us to plant lettuce")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Lettuce lettuce {};
	farm.plant(0, 1, &lettuce);
	REQUIRE(farm.getSymbol(0, 1) == '~');
}

TEST_CASE("it allows us to plant spinach")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Spinach spinach {};
	farm.plant(0, 1, &spinach);
	REQUIRE(farm.getSymbol(0, 1) == '~');
}

TEST_CASE("it allows us to plant beet")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Beet beet {};
	farm.plant(0, 1, &beet);
	REQUIRE(farm.getSymbol(0, 1) == '~');
}

TEST_CASE("it allows us to plant brussel sprout")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	BrusselSprout brusselsprout {};
	farm.plant(0, 1, &brusselsprout);
	REQUIRE(farm.getSymbol(0, 1) == '~');
}

TEST_CASE("it can harvest a single harvestable plant")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot* carrot = new Carrot();
	farm.plant(0, 1, carrot);

	farm.updatePlants();
	farm.updatePlants();

	farm.harvest(0, 1);
	REQUIRE(farm.getSymbol(0, 1) == '.');
}

TEST_CASE("it increments day counter when updating plants")
{
	Player player {};
	Farm farm(1, 1, &player, false);
	farm.updatePlants();
	REQUIRE(farm.getDayCount() == 2);
}

TEST_CASE("it can be initialized as a 1x2 farm")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	REQUIRE(farm.getNumberOfRows() == 1);
	REQUIRE(farm.getNumberOfColumns() == 2);
}

TEST_CASE("it can be initialized as a 2x1 farm")
{
	Player player {};
	Farm farm(2, 1, &player, false);
	REQUIRE(farm.getNumberOfRows() == 2);
	REQUIRE(farm.getNumberOfColumns() == 1);
}

TEST_CASE("it returns the symbols for a 1x2 farm")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	REQUIRE(farm.getSymbol(0, 0) == '@');
	REQUIRE(farm.getSymbol(0, 1) == '.');
}

TEST_CASE("it returns the symbols for a 2x1 farm")
{
	Player player {};
	Farm farm(2, 1, &player, false);
	REQUIRE(farm.getSymbol(0, 0) == '@');
	REQUIRE(farm.getSymbol(1, 0) == '.');
}

TEST_CASE("it can plant multiple carrots on different plots")
{
	Player player {};
	Farm farm(2, 2, &player, false);
	Carrot* carrot1 = new Carrot();
	Carrot* carrot2 = new Carrot();

	farm.plant(0, 1, carrot1);
	farm.plant(1, 0, carrot2);

	REQUIRE(farm.getSymbol(0, 1) == '~');
	REQUIRE(farm.getSymbol(1, 0) == '~');
}

TEST_CASE("it can plant different vegetables on different plots")
{
	Player player {};
	Farm farm(2, 3, &player, false);
	Carrot* carrot = new Carrot();
	Lettuce* lettuce = new Lettuce();
	Spinach* spinach = new Spinach();

	farm.plant(0, 1, carrot);
	farm.plant(0, 2, lettuce);
	farm.plant(1, 0, spinach);

	REQUIRE(farm.getSymbol(0, 1) == '~');
	REQUIRE(farm.getSymbol(0, 2) == '~');
	REQUIRE(farm.getSymbol(1, 0) == '~');
}

TEST_CASE("it updates all plants when day advances")
{
	Player player {};
	Farm farm(2, 2, &player, false);
	Carrot* carrot1 = new Carrot();
	Carrot* carrot2 = new Carrot();

	farm.plant(0, 1, carrot1);
	farm.plant(1, 0, carrot2);
	farm.updatePlants();
	farm.updatePlants();

	REQUIRE(farm.getSymbol(0, 1) == 'V');
	REQUIRE(farm.getSymbol(1, 0) == 'V');
	REQUIRE(farm.getDayCount() == 3);
}

TEST_CASE("it increments day counter multiple times")
{
	Player player {};
	Farm farm(1, 1, &player, false);

	farm.updatePlants();
	farm.updatePlants();
	farm.updatePlants();

	REQUIRE(farm.getDayCount() == 4);
}

TEST_CASE("it returns player symbol at player position")
{
	Player player {};
	Farm farm(3, 3, &player, false);
	REQUIRE(farm.getSymbol(0, 0) == '@');
}

TEST_CASE("shows player at players position after planting")
{
	Player player {};
	Farm farm(1, 1, &player, false);
	Carrot* carrot = new Carrot();
	farm.plant(0, 0, carrot);
	REQUIRE(farm.getSymbol(0, 0) == '@');
}

TEST_CASE("it cannot plant over an existing plant")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot* carrot1 = new Carrot();
	Carrot* carrot2 = new Carrot();

	farm.plant(0, 1, carrot1);
	farm.plant(0, 1, carrot2);

	REQUIRE(farm.getSymbol(0, 1) == '~');
}

TEST_CASE("it does not harvest non-harvestable plants")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot* carrot = new Carrot();
	farm.plant(0, 1, carrot);

	farm.harvest(0, 1);

	REQUIRE(farm.getSymbol(0, 1) == '~');
}

TEST_CASE("it does not harvest seedlings")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot* carrot = new Carrot();
	farm.plant(0, 1, carrot);

	farm.updatePlants();
	farm.harvest(0, 1);

	REQUIRE(farm.getSymbol(0, 1) == 'v');
}

TEST_CASE("it does not harvest empty soil")
{
	Player player {};
	Farm farm(1, 2, &player, false);

	farm.harvest(0, 1);

	REQUIRE(farm.getSymbol(0, 1) == '.');
}

TEST_CASE("it handles different plot types correctly")
{
	Player player {};
	Farm farm(1, 3, &player, false);
	Carrot* carrot = new Carrot();

	farm.plant(0, 1, carrot);

	REQUIRE(farm.getSymbol(0, 0) == '@');
	REQUIRE(farm.getSymbol(0, 1) == '~');
	REQUIRE(farm.getSymbol(0, 2) == '.');
}

TEST_CASE("it supports complete plant lifecycle")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot* carrot = new Carrot();

	farm.plant(0, 1, carrot);
	REQUIRE(farm.getSymbol(0, 1) == '~');

	farm.updatePlants();
	farm.updatePlants();
	farm.updatePlants();

	farm.harvest(0, 1);
	REQUIRE(farm.getSymbol(0, 1) == '.');
}

TEST_CASE("it tracks days accurately through multiple cycles")
{
	Player player {};
	Farm farm(2, 2, &player, false);

	REQUIRE(farm.getDayCount() == 1);

	farm.updatePlants();
	REQUIRE(farm.getDayCount() == 2);

	farm.updatePlants();
	REQUIRE(farm.getDayCount() == 3);

	farm.updatePlants();
	REQUIRE(farm.getDayCount() == 4);
}

TEST_CASE("it maintains farm state after multiple operations")
{
	Player player {};
	Farm farm(2, 2, &player, false);
	Carrot* carrot1 = new Carrot();
	Carrot* carrot2 = new Carrot();

	farm.plant(0, 1, carrot1);
	farm.plant(1, 1, carrot2);
	farm.updatePlants();
	farm.updatePlants();

	REQUIRE(farm.getNumberOfRows() == 2);
	REQUIRE(farm.getNumberOfColumns() == 2);
	REQUIRE(farm.getDayCount() == 3);
	REQUIRE(farm.getSymbol(0, 1) == 'V');
	REQUIRE(farm.getSymbol(1, 1) == 'V');
}

TEST_CASE("watering empty soil does nothing")
{
	Player player {};
	Farm farm(1, 2, &player, false);

	farm.waterPlant(0, 1);
	farm.updatePlants();

	REQUIRE(farm.getSymbol(0, 1) == '.');
}

TEST_CASE("watered carrot matures faster")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot* carrot = new Carrot();

	farm.plant(0, 1, carrot);
	farm.waterPlant(0, 1);
	farm.updatePlants();

	REQUIRE(farm.getSymbol(0, 1) == 'V');
}

TEST_CASE("watered lettuce matures faster")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Lettuce* lettuce = new Lettuce();

	farm.plant(0, 1, lettuce);
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();

	REQUIRE(lettuce->isHarvestable());
}

TEST_CASE("watered spinach matures faster")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Spinach* spinach = new Spinach();

	farm.plant(0, 1, spinach);
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.updatePlants();

	REQUIRE(spinach->isHarvestable());
}

TEST_CASE("watered beet matures faster")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Beet* beet = new Beet();

	farm.plant(0, 1, beet);
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.updatePlants();

	REQUIRE(beet->isHarvestable());
}

TEST_CASE("watered brussel sprout matures faster")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	BrusselSprout* brusselsprout = new BrusselSprout();

	farm.plant(0, 1, brusselsprout);
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.waterPlant(0, 1);
	farm.updatePlants();
	farm.updatePlants();

	REQUIRE(brusselsprout->isHarvestable());
}

TEST_CASE("watering does not immediately mature plant")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot* carrot = new Carrot();

	farm.plant(0, 1, carrot);
	farm.waterPlant(0, 1);

	REQUIRE(farm.getSymbol(0, 1) == '~');
	REQUIRE(!carrot->isHarvestable());
}

TEST_CASE("repeatedly watering on same day has no extra effect")
{
	Player player {};
	Farm farm(1, 2, &player, false);
	Carrot* carrot = new Carrot();

	farm.plant(0, 1, carrot);
	farm.waterPlant(0, 1);
	farm.waterPlant(0, 1);
	farm.waterPlant(0, 1);
	farm.updatePlants();

	REQUIRE(farm.getSymbol(0, 1) == 'V');
}

TEST_CASE("different vegetables have different mature symbols")
{
	Player player {};
	Farm farm(2, 3, &player, false);
	Carrot* carrot = new Carrot();
	Lettuce* lettuce = new Lettuce();
	Spinach* spinach = new Spinach();
	Beet* beet = new Beet();
	BrusselSprout* brusselsprout = new BrusselSprout();

	farm.plant(0, 0, carrot);
	farm.plant(0, 1, lettuce);
	farm.plant(0, 2, spinach);
	farm.plant(1, 0, beet);
	farm.plant(1, 1, brusselsprout);

	for (int i = 0; i < 15; i++)
	{
		farm.updatePlants();
	}

	char carrotSymbol = farm.getSymbol(0, 0);
	char lettuceSymbol = farm.getSymbol(0, 1);
	char spinachSymbol = farm.getSymbol(0, 2);
	char beetSymbol = farm.getSymbol(1, 0);
	char brusselsproutSymbol = farm.getSymbol(1, 1);

	REQUIRE(carrotSymbol != lettuceSymbol);
	REQUIRE(carrotSymbol != spinachSymbol);
	REQUIRE(carrotSymbol != beetSymbol);
	REQUIRE(carrotSymbol != brusselsproutSymbol);
	REQUIRE(lettuceSymbol != spinachSymbol);
	REQUIRE(lettuceSymbol != beetSymbol);
	REQUIRE(lettuceSymbol != brusselsproutSymbol);
	REQUIRE(spinachSymbol != beetSymbol);
	REQUIRE(spinachSymbol != brusselsproutSymbol);
	REQUIRE(beetSymbol != brusselsproutSymbol);
}
