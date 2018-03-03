// https://answers.unrealengine.com/questions/70019/how-to-include-the-header-file-from-a-plugin.html

namespace UnrealBuildTool.Rules
{
	public class MyBlueprintPlugin : ModuleRules
	{
		public MyBlueprintPlugin(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					"MyBlueprintPlugin/Public", 
					"MyBlueprintPlugin/Classes"
					// ... add public include paths required here ...
				}
                );

			PrivateIncludePaths.AddRange(
				new string[] {
					"MyBlueprintPlugin/Private"
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core", 
					"CoreUObject", 
					"Engine", 
					"InputCore"
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
		}
	}
}
