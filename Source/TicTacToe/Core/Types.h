// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <array>
#include <cstdint>


enum class ECellType
{
    Empty,
    X,
    O
};

enum class EPlayerType : uint8_t
{
    Human,
    AI
};

enum class EGameplayEvent
{
    Playing,
    Won,
    Draw
};

// For storage coordinates
struct FGridCoord
{
    int32 Row;
    int32 Col;

    bool IsValid(int32 BoardSize = 3) const { return Row >= 0 && Row < BoardSize && Col >= 0 && Col < BoardSize; }
};

