// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types.h"
#include <cstdint>
#include <functional>
#include <memory>

using namespace std;

namespace TTTGame
{

class TICTACTOE_API Grid
{
public:
    static constexpr int32 BoardSize = 3;

    Grid();

    void Reset();

    void PrintDebug() const;

    EGameplayEvent CheckWin(ECellType& OutWinner) const;

    bool MakeMove(int32 Row, int32 Col, ECellType Player);

    ECellType GetCell(int32 Row, int32 Col) const;

private:
    array<array<ECellType, BoardSize>, BoardSize> BoardGrid;

    bool CheckLine(ECellType A, ECellType B, ECellType C, ECellType& OutWinner) const;
};

}  // namespace TTTGame
