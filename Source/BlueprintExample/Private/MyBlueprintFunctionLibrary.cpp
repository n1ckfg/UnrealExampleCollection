// https://wiki.unrealengine.com/Blueprint_Function_Library,_Create_Your_Own_to_Share_With_Others
// https://www.unrealengine.com/en-US/blog/unreal-property-system-reflection
// https://answers.unrealengine.com/questions/200241/generate-visual-studio-project-files-did-not-auto.html
// https://wiki.unrealengine.com/File_Management,_Create_Folders,_Delete_Files,_and_More

#include "MyBlueprintFunctionLibrary.h"

// Message
FString  UMyBlueprintFunctionLibrary::GetHappyMessage()
{
	return FString("Victory! BP Library works!");
}

bool  UMyBlueprintFunctionLibrary::SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText, bool AllowOverWriting)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// Directory exists?
	if (!PlatformFile.DirectoryExists(*SaveDirectory))
	{
		// Create directory if it doesn't exist.
		PlatformFile.CreateDirectory(*SaveDirectory);

		// Still couldn't make directory?
		if (!PlatformFile.DirectoryExists(*SaveDirectory))
		{
			// Could not make the specified directory.
			return false;
		}
	}

	// Get complete file path
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	// no overwriting?
	if (!AllowOverWriting)
	{
		// Check if file exists already
		if (PlatformFile.FileExists(*SaveDirectory))
		{
			// no overwriting
			return false;
		}
	}

	return FFileHelper::SaveStringToFile(SaveText, *SaveDirectory);
}


