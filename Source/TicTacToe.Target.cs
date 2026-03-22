// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TicTacToeTarget : TargetRules
{
	public TicTacToeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "TicTacToe" } );
	}
}
