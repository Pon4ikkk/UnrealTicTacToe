// TicTacToe, Copyright ArtemZykov. All Rights Reserved.


#include "Core/Game.h"
#include "Grid.h"
#include "AI.h"

using namespace TTTGame;

Game::Game() : CurrentPlayer(ECellType::X), GameStatus(EGameplayEvent::Playing)
{
    m_grid = MakeShared<Grid>();
}

void Game::OnPlayerMove(int32 Row, int32 Col)
{
    if (GetPlayerType(CurrentPlayer) != EPlayerType::Human) return;

    ProcessMove(Row, Col);
}

void Game::TriggerAIMove()
{
    if (GetPlayerType(CurrentPlayer) != EPlayerType::AI) return;
    if (GameStatus != EGameplayEvent::Playing) return;

    optional<FGridCoord> Move = AI::GetBestMove(m_grid.Get(), CurrentPlayer);

    if (Move.has_value()) {

    }
}

void Game::ProcessMove(int32 Row, int32 Col)
{
    if (m_grid->MakeMove(Row, Col, CurrentPlayer)){

        //Notify
        if (OnCellUpdatedCallback) OnCellUpdatedCallback(Row, Col, CurrentPlayer);

        ECellType Winner = ECellType::Empty;
        GameStatus = m_grid->CheckWin(Winner);
        if (OnGameStatusChangedCallback) OnGameStatusChangedCallback(GameStatus, Winner);

        if (GameStatus == EGameplayEvent::Playing) {
            CurrentPlayer = (CurrentPlayer == ECellType::X) ? ECellType::O : ECellType::X;

            if (GetPlayerType(CurrentPlayer) == EPlayerType::AI) {
                TriggerAIMove();
            }
        }
    }
}

EPlayerType Game::GetPlayerType(ECellType Piece) const
{
    if (Piece == ECellType::X) return EPlayerType::Human;
    if (Piece == ECellType::O) return EPlayerType::AI;
    return EPlayerType::Human;
}

void Game::FOnGameStatusChangedSubscribe(FOnGameStatusChanged Callback)
{
    OnGameStatusChangedCallback = Callback;
}

void Game::FOnCellUpdatedSubscribe(FOnCellUpdated Callback)
{
    OnCellUpdatedCallback = Callback;
}

void Game::RestartGame()
{
    m_grid.Reset();
    CurrentPlayer = ECellType::X;
    GameStatus = EGameplayEvent::Playing;

    if (OnGameStatusChangedCallback) {
        OnGameStatusChangedCallback(GameStatus, ECellType::Empty);
    }
}
