// PaintBall. All Rights Reserved.

using UnrealBuildTool;

public class PaintBall : ModuleRules
{
	public PaintBall(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
		PublicIncludePaths.AddRange(new[]
		{
			"PaintBall/Public/Player",
			"PaintBall/Public/Components"
		});
	}
}