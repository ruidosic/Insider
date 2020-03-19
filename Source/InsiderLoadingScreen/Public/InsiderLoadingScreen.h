// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleInterface.h"
#include "Modules/ModuleManager.h"

/** Module interface for this game's loading screens */
class IInsiderLoadingScreenModule : public IModuleInterface
{
public:
	/** Loads the module so it can be turned on*/
	static inline IInsiderLoadingScreenModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IInsiderLoadingScreenModule>("InsiderLoadingScreen");
	}

	/** Kicks off the loading screen for in game loading (not startup) */
	virtual void StartInGameLoadingScreen(bool bPlayUntilStopped, float PlayTime) = 0;

	/** Stops the loading screen */
	virtual void StopInGameLoadingScreen() = 0;
};