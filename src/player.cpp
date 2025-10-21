#include "player.hpp"

Player::Player(int row, int column, char symbol)
:row_(row), column_(column), symbol_(symbol)
{}

int Player::getRow() const
{
    return row_;
}

int Player::getColumn() const
{
    return column_;
}

void Player::move(Move move)
{
    switch (move)
    {
    case Move::Up:
        row_ -= 1;
        break;
    case Move::Down:
        row_ += 1;
        break;
    case Move::Left:
        column_ -= 1;
        break;
    case Move::Right:
        column_ += 1;
        break;
    default:
        break;
    }
}

char Player::getSymbol() const
{
    return symbol_;
}
