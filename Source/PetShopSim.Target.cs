// Copyright (c) 2026 zlatirl. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PetShopSimTarget : TargetRules
{
	public PetShopSimTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		ExtraModuleNames.Add("PetShopSim");
	}
}
