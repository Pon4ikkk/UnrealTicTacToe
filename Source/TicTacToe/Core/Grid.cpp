// TicTacToe, Copyright ArtemZykov. All Rights Reserved.


#include "Grid.h"

using namespace TTTGame;

Grid::Grid()
{
    Reset();
    PrintDebug();
}

void Grid::Reset()
{
    for (auto& row : BoardGrid) {
        for (auto& cell : row) {
            cell = ECellType::Empty;
        }
    }
}

void Grid::PrintDebug() const
{
    UE_LOG(LogTemp, Log, TEXT("=== TIC TAC TOE ==="));
    for (int32 r = 0; r < BoardSize; ++r)
    {
        FString RowString = TEXT("");
        for (int32 c = 0; c < BoardSize; ++c)
        {
            TCHAR Symbol = TEXT('-');
            if (BoardGrid[r][c] == ECellType::X)
                Symbol = TEXT('X');
            else if (BoardGrid[r][c] == ECellType::O)
                Symbol = TEXT('O');

            RowString += FString::Printf(TEXT(" %c "), Symbol);
        }
        UE_LOG(LogTemp, Log, TEXT("%s"), *RowString);
    }
}

bool Grid::MakeMove(int32 Row, int32 Col, ECellType Player)
{
    FGridCoord Coord{Row, Col};
    if (!Coord.IsValid(BoardSize)) return false;
    if (BoardGrid[Row][Col] != ECellType::Empty) return false;

    BoardGrid[Row][Col] = Player;
    return true;
}

EGameplayEvent Grid::CheckWin(ECellType& OutWinner) const
{
    //Checking line and column
    for (int32 i = 0; i < BoardSize; i++) {
        if (CheckLine(BoardGrid[i][0], BoardGrid[i][1], BoardGrid[i][2], OutWinner)) return EGameplayEvent::Won;
        if (CheckLine(BoardGrid[0][i], BoardGrid[1][i], BoardGrid[2][i], OutWinner)) return EGameplayEvent::Won;
    }

    //Diagonals
    if (CheckLine(BoardGrid[0][0], BoardGrid[1][1], BoardGrid[2][2], OutWinner)) return EGameplayEvent::Won;
    if (CheckLine(BoardGrid[0][2], BoardGrid[1][1], BoardGrid[2][0], OutWinner)) return EGameplayEvent::Won;

    //Check for a draw (no empty cells)
    for (const auto& row : BoardGrid) {
        for (const auto& cell : row) {
            if (cell == ECellType::Empty) return EGameplayEvent::Playing;
        }
    }

    return EGameplayEvent::Draw;
}

bool Grid::CheckLine(ECellType A, ECellType B, ECellType C, ECellType& OutWinner) const
{
    if (A != ECellType::Empty && A == B && B == C)
    {
        OutWinner = A;
        return true;
    }

    return false;
}

ECellType Grid::GetCell(int32 Row, int32 Col) const
{
    if (Row < 0 || Row >= BoardSize || Col < 0 || Col >= BoardSize)
    {
        return ECellType::Empty;
    }

    return BoardGrid[Row][Col];
}
