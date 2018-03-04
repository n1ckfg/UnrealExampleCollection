// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class HLSL_UnrealTarget : TargetRules
{
	public HLSL_UnrealTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "HLSL_Unreal" } );
	}
}
