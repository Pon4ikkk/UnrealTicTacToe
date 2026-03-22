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

class Grid;
class AI;

using FOnGameStatusChanged = function<void(EGameplayEvent, ECellType)>;
using FOnCellUpdated = function<void(int32, int32, ECellType)>;

class TICTACTOE_API Game
{
public:
    Game();

    void FOnGameStatusChangedSubscribe(FOnGameStatusChanged Callback);
    void FOnCellUpdatedSubscribe(FOnCellUpdated Callback);
    void RestartGame();
    void OnPlayerMove(int32 Row, int32 Col);
    void TriggerAIMove();

    TSharedPtr<Grid> grid() const { return m_grid; }

private:
    TSharedPtr<Grid> m_grid;

    void ProcessMove(int32 Row, int32 Col);

    ECellType CurrentPlayer;
    EGameplayEvent GameStatus;
    EPlayerType GetPlayerType(ECellType Piece) const;

    FOnGameStatusChanged OnGameStatusChangedCallback;
    FOnCellUpdated OnCellUpdatedCallback;
};

}  // namespace TTTGame
