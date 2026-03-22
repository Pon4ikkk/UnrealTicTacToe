// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

using UnrealBuildTool;

public class TicTacToe : ModuleRules
{
	public TicTacToe(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });

		PublicIncludePaths.AddRange(new string[] { "TicTacToe" });

        if (Target.Configuration != UnrealTargetConfiguration.Shipping)
        {
            PublicDependencyModuleNames.Add("FunctionalTesting");
        }
    }
}
