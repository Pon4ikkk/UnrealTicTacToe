// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types.h"
#include <optional>

using namespace std;

namespace TTTGame
{

class Grid;

class TICTACTOE_API AI
{
public:
    AI();

    static optional<FGridCoord> GetBestMove(const Grid* Board, ECellType AIPeace);

private:
    static optional<FGridCoord> GetRandomMove(const Grid* Board);
    static optional<FGridCoord> GetMinimaxMove(const Grid* Board, ECellType AIPiece);
};

}  // namespace TTTGame