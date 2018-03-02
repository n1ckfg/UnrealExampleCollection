// https://wiki.unrealengine.com/Blueprint_Function_Library,_Create_Your_Own_to_Share_With_Others
// https://www.unrealengine.com/en-US/blog/unreal-property-system-reflection
// https://answers.unrealengine.com/questions/200241/generate-visual-studio-project-files-did-not-auto.html
// https://wiki.unrealengine.com/File_Management,_Create_Folders,_Delete_Files,_and_More

#include "UMyBlueprintFunctionLibrary.h"

FString  UMyBlueprintFunctionLibrary::GetHappyMessage()
{
	return FString("Victory! BP Library works!");
}

bool  UMyBlueprintFunctionLibrary::SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText, bool AllowOverWriting)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// Check if directory exists.
	if (!PlatformFile.DirectoryExists(*SaveDirectory))
	{
		// Create the directory if it doesn't exist.
		PlatformFile.CreateDirectory(*SaveDirectory);

		// Could not make the directory.
		if (!PlatformFile.DirectoryExists(*SaveDirectory))
		{
			return false;
		}
	}

	// Get complete file path
	SaveDirectory += "\\" + FileName;

	// Check if overwriting is allowed.
	if (!AllowOverWriting)
	{
		// Check if the file exists already.
		if (PlatformFile.FileExists(*SaveDirectory))
		{
			return false;
		}
	}

	return FFileHelper::SaveStringToFile(SaveText, *SaveDirectory);
}


