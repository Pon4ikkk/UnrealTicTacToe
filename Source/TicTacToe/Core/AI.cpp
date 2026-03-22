// TicTacToe, Copyright ArtemZykov. All Rights Reserved.


#include "Core/AI.h"
#include "Grid.h"
#include <optional>

using namespace TTTGame;

AI::AI()
{}

optional<FGridCoord> AI::GetBestMove(const Grid* Board, ECellType AIPiece)
{
    return GetRandomMove(Board);
    
    //soon
    //return GetMinimaxMove(Board, AIPiece);
}

optional<FGridCoord> AI::GetRandomMove(const Grid* Board)
{
    for (int32 r = 0; r < Grid::BoardSize; r++)
    {
        for (int32 c = 0; c < Grid::BoardSize; c++)
        {
            if (Board->GetCell(r, c) == ECellType::Empty)
            {
                return FGridCoord{ r, c };
            }
        }
    }
    return nullopt;
}

// Minimax soon
optional<FGridCoord> AI::GetMinimaxMove(const Grid* Board, ECellType AIPiece)
{
    return GetRandomMove(Board);
}