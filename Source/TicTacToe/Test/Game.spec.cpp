// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

#if WITH_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "TicTacToe/Core/Game.h"

using namespace TTTGame;

DEFINE_SPEC(FTicTacToeGame, "TicTacToe",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority)

void FTicTacToeGame::Define()
{
    Describe("CoreGame", [this]() {  //
        It("GridShouldExists", 
            [this]() 
            {
                const auto CoreGame = Game();
                TestTrueExpr(CoreGame.grid().IsValid());
            }); 
    });
}

#endif
