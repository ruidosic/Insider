// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/Structures/EnvironmentEvents.h"
#include "Core/Structures/PlayerEvents.h"
#include "Core/Structures/SoundEvents.h"
#include "Core/Structures/QuestEvents.h"
#include "Core/Structures/LevelEvents.h"
#include "Core/Structures/SubtitlesEvents.h"
#include "GameEvent.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FGameEvent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Event")
	FEnvironmentEvents Environment;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Event")
	FPlayerEvents Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Event")
	FSoundEvents Sounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Event")
	FQuestEvents Quests;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Event")
	FLevelEvents Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Event")
	FSubtitlesEvents Subtitles;

	// Time when Game Event was destroyed with all child actors
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Game Events")
	float EventsLifetimeSec = 10;
};
