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

FString UMyBlueprintPluginBPLibrary::GetHappyMessage()
{
	return FString("Victory! BP Library works!");
}

bool UMyBlueprintPluginBPLibrary::SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText, bool AllowOverWriting)
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


