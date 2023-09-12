// PaintBall. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PaintBallEditorTarget : TargetRules
{
	public PaintBallEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("PaintBall");
	}
}
