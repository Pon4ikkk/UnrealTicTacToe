// TicTacToe, Copyright ArtemZykov. All Rights Reserved.


#include "Framework/TTT_GameMode.h"

void ATTT_GameMode::StartPlay()
{
    Super::StartPlay();

    Game = MakeUnique<TTTGame::Game>();
}
