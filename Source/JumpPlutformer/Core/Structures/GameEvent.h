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
