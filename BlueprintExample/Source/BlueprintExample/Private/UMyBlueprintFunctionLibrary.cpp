// https://wiki.unrealengine.com/Blueprint_Function_Library,_Create_Your_Own_to_Share_With_Others
// https://www.unrealengine.com/en-US/blog/unreal-property-system-reflection
// https://answers.unrealengine.com/questions/200241/generate-visual-studio-project-files-did-not-auto.html
// https://wiki.unrealengine.com/File_Management,_Create_Folders,_Delete_Files,_and_More
// https://docs.unrealengine.com/latest/INT/API/Runtime/Core/Misc/FPaths/

#include "UMyBlueprintFunctionLibrary.h"

FString UMyBlueprintFunctionLibrary::GetHappyMessage() 
{
	return FString("Victory! BP Library works!");
}

bool UMyBlueprintFunctionLibrary::SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText, bool AllowOverWriting) 
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


