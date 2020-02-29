// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Structures/EnvironmentEvents.h"
#include "Structures/PlayerEvents.h"
#include "Structures/SoundEvents.h"
#include "Structures/QuestEvents.h"
#include "Structures/LevelEvents.h"
#include "Structures/SubtitlesEvents.h"
#include "GameEvent.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FGameEvent
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Game Event")
	FEnvironmentEvents Environment;
	
	UPROPERTY(BlueprintReadWrite, Category = "Game Event")
	FPlayerEvents Player;

	UPROPERTY(BlueprintReadWrite, Category = "Game Event")
	FSoundEvents Sounds;

	UPROPERTY(BlueprintReadWrite, Category = "Game Event")
	FQuestEvents Quests;

	UPROPERTY(BlueprintReadWrite, Category = "Game Event")
	FLevelEvents Level;

	UPROPERTY(BlueprintReadWrite, Category = "Game Event")
	FSubtitlesEvents Subtitles;
};
