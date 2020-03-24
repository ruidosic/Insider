// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "CoreAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class INSIDER_API UCoreAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	
	// Constructor and overrides
	UCoreAssetManager() {}
	virtual void StartInitialLoading() override;

	/* Static types for items */


	/* Returns the current AssetManager object */
	static UCoreAssetManager& Get();

	FStreamableManager StreamableManager;
	/**
 * Synchronously loads an RPGItem subclass, this can hitch but is useful when you cannot wait for an async load
 * This does not maintain a reference to the item so it will garbage collect if not loaded some other way
 *
 * @param PrimaryAssetId The asset identifier to load
 * @param bDisplayWarning If true, this will log a warning if the item failed to load
 */


	// Need logic!!!!!
};
