// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "QuestEvents.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FUpdateQuest
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Update Quest")
	FText NewQuest;

	UPROPERTY(BlueprintReadWrite, Category = "Update Quest")
	float DelayBeforeUpdateSec;

};



USTRUCT(BlueprintType)
struct FQuestEvents
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Quest Events")
	TArray<FUpdateQuest> UpdateQuests;
};
