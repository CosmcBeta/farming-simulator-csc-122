#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"

#include <iostream>

int main()
{
    char playerSymbol {'@'};
    Player player(0, 0, playerSymbol);
    Farm farm(7, 8, &player);
    FarmPrinter printer(&farm);

    std::string playerInput {};
    bool gameInProgress {true};
    while(gameInProgress)
    {
        ansi_clear();
        std::cout << printer.prettyPrint() << std::endl;
        std::getline(std::cin, playerInput);

        if (playerInput == "q")
        {
            gameInProgress = false;
        }
        else if (playerInput == "w")
        {
            player.move(Move::Up);
        }
        else if (playerInput == "a")
        {
            player.move(Move::Left);
        }
        else if (playerInput == "s")
        {
            player.move(Move::Down);
        }
        else if (playerInput == "d")
        {
            player.move(Move::Right);
        }
        else if (playerInput == "c")
        {
            Carrot *carrot = new Carrot();
            farm.plant(player.getRow(), player.getColumn(), carrot);
        }
    }
}
