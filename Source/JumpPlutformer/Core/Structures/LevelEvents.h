// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "LevelEvents.generated.h"

	//
	// Additional structs for FLevelEvents
	//

USTRUCT(BlueprintType)
struct FLevelOpen
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Open Level")
	bool bOpenLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Open Level")
	bool bCarryInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Open Level")
	FName LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Open Level")
	float DelayBeforeOpenLevelSec;
};


USTRUCT(BlueprintType)
struct FLoadStream
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Load Stream")
	FName LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Load Stream")
	bool bVisibleAfterLoad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Load Stream")
	bool bShouldBlockAfterLoad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Load Stream")
	float DelayBeforeLoadSec;
};

USTRUCT(BlueprintType)
struct FUnloadStream
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unload Stream")
	FName LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unload Stream")
	float DelayBeforeUnloadSec;
};


// Main struct
USTRUCT(BlueprintType)
struct FLevelEvents
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Events")
	FLevelOpen OpenLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Events")
	TArray<FLoadStream> LoadStreamLevels;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Events")
	TArray<FUnloadStream> UnloadStreamLevels;
};
