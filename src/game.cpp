#include "player.hpp"
#include "game.hpp"
#include "farm.hpp"
#include "farm_printer.hpp"
#include "ansi_clear.hpp"
#include "carrot.hpp"

#include <iostream>

Game::Game()
:player_(0, 0, '@'), farm_(20, 20, &player_), printer_(&farm_)
{}

void Game::run()
{
    std::string playerInput {};
    bool gameInProgress {true};
    while (gameInProgress)
    {
        ansi_clear();
        std::cout << printer_.prettyPrint() << std::endl;
        std::cout << printer_.printLegend() << std::endl;
        std::getline(std::cin, playerInput);

        if (playerInput.length() != 1)
        {
            continue;
        }

        switch (std::tolower(playerInput[0]))
        {
            case 'q':
                gameInProgress = false;
                break;
            case 'w':
                if (player_.getRow() == 0)
                {
                    break;
                }
                player_.move(Move::Up);
                break;
            case 'a':
                if (player_.getColumn() == 0)
                {
                    break;
                }
                player_.move(Move::Left);
                break;
            case 's':
                if (player_.getRow() == farm_.getNumberOfRows() - 1)
                {
                    break;
                }
                player_.move(Move::Down);
                break;
            case 'd':
                if (player_.getColumn() == farm_.getNumberOfColumns() - 1)
                {
                    break;
                }
                player_.move(Move::Right);
                break;
            case 'c':
            {
                Carrot *carrot = new Carrot();
                farm_.plant(player_.getRow(), player_.getColumn(), carrot);
                break;
            }
            case 'e':
                farm_.updatePlants();
                break;
            case 'h':
                farm_.harvest(player_.getRow(), player_.getColumn());
                break;
            default:
                break;
        }
    }
}
