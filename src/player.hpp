#pragma once

enum class Move
{
    Up,
    Down,
    Left,
    Right,
    None
};

class Player
{
public:
    Player(int row = 0, int column = 0, char symbol = '@');
    int getRow() const;
    int getColumn() const;
    void move(Move move);
    char getSymbol() const;
private:
    int row_;
    int column_;
    char symbol_;
};
