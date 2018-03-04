// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class HLSL_UnrealEditorTarget : TargetRules
{
	public HLSL_UnrealEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "HLSL_Unreal" } );
	}
}
