// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/Enums/EventCheck.h"
#include "Core/Structures/GameEvent.h"
#include "GameEvents.generated.h"


USTRUCT(BlueprintType)
struct FGameEvents
{
	GENERATED_BODY()

	//Interaction Event for matching with some gameplay event, if it's true, then execute GameEvent
	UPROPERTY(BlueprintReadWrite, Category = "Game Events")
	TEnumAsByte<EEventCheck> TriggerInteraction;		

	// 
	UPROPERTY(BlueprintReadWrite, Category = "Game Events")
	int AfterTimes;

	//
	UPROPERTY(BlueprintReadWrite, Category = "Game Events")
	int Counter;

	//
	UPROPERTY(BlueprintReadWrite, Category = "Game Events")
	bool bDoOnce;

	//Game Event, wich execute if TriggerInteraction match with some gameplay event
	UPROPERTY(BLueprintReadWrite, Category = "Game Events")
	FGameEvent GameEvent;
};
