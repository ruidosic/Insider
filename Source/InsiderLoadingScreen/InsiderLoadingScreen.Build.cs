// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

// This module must be loaded "PreLoadingScreen" in the .uproject file, otherwise it will not hook in time!

public class InsiderLoadingScreen : ModuleRules
{
    public InsiderLoadingScreen(ReadOnlyTargetRules Target)
        : base(Target)
    {
        PrivatePCHHeaderFile = "Public/InsiderLoadingScreen.h";

        PCHUsage = PCHUsageMode.UseSharedPCHs;

        PrivateIncludePaths.Add("InsiderLoadingScreen/Private");

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "MoviePlayer",
                "Slate",
                "SlateCore",
                "InputCore"
            }
        );
    }
}
