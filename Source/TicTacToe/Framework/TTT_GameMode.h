// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TicTacToe/Core/Game.h"
#include "TTT_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATTT_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    virtual void StartPlay() override;

private:
    TUniquePtr<TTTGame::Game> Game;
};
