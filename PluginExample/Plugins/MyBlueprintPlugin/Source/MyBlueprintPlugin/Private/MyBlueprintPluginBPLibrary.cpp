// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MyBlueprintPluginBPLibrary.h"
#include "MyBlueprintPlugin.h"

UMyBlueprintPluginBPLibrary::UMyBlueprintPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UMyBlueprintPluginBPLibrary::MyBlueprintPluginSampleFunction(float Param)
{
	return -1;
}

