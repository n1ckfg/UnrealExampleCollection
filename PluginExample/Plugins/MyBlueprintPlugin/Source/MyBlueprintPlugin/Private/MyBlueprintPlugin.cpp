// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Core.h" // can use Core.h or CoreMinimal.h
#include "Modules/ModuleManager.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IMyBlueprintPlugin.h"


class FMyBlueprintPlugin : public IMyBlueprintPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	FString GetHappyMessage();
	bool SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText, bool AllowOverWriting);
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

UFUNCTION(BlueprintCallable, Category = "MyBlueprintPlugin")
FString FMyBlueprintPlugin::GetHappyMessage()
{
	return FString("Victory! BP Library works!");
}

UFUNCTION(BlueprintCallable, Category = "MyBlueprintPlugin")
bool  FMyBlueprintPlugin::SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText, bool AllowOverWriting)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (SaveDirectory.Len() > 0)
	{
		FPaths::NormalizeDirectoryName(SaveDirectory);
		FPaths::NormalizeFilename(FileName);

		if (!PlatformFile.DirectoryExists(*SaveDirectory))
		{
			PlatformFile.CreateDirectory(*SaveDirectory);
			if (!PlatformFile.DirectoryExists(*SaveDirectory))
			{
				return false; // Failed to create the directory.
			}
		}

		SaveDirectory += "/" + FileName;
	}
	else
	{
		SaveDirectory = FPaths::GameDir() + "/" + FileName;
	}


	if (!AllowOverWriting)
	{
		if (PlatformFile.FileExists(*SaveDirectory))
		{
			return false; // Won't overwrite the file.
		}
	}

	return FFileHelper::SaveStringToFile(SaveText, *SaveDirectory);
}



