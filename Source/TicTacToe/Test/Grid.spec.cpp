// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

#if WITH_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "TicTacToe/Core/Grid.h"

using namespace TTTGame;

DEFINE_SPEC(FTicTacToeGrid, "TicTacToe", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority)

void FTicTacToeGrid::Define()
{
Describe("CoreGrid", [this]() { It("GridShouldExists", [this]() { }); });
}

#endif
