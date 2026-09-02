#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

enum class Symbol
{
    X,
    O,
    EMPTY
};

enum class GameStatus
{
    NOT_STARTED,
    IN_PROGRESS,
    X_WON,
    O_WON,
    DRAW
};

class Player
{
private:
    int id;
    string name;
    Symbol symbol;

public:
    Player(int id, string name, Symbol symbol) : id(id), name(name), symbol(symbol) {}

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    Symbol getSymbol() const
    {
        return symbol;
    }
};