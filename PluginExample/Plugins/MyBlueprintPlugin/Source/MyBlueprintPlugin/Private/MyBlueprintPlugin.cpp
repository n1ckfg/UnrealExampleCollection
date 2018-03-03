// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Core.h" // can use Core.h or CoreMinimal.h
#include "Modules/ModuleManager.h"
#include "IMyBlueprintPlugin.h"


class FMyBlueprintPlugin : public IMyBlueprintPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FMyBlueprintPlugin, MyBlueprintPlugin )



void FMyBlueprintPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FMyBlueprintPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}



