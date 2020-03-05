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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Events")
	TEnumAsByte<EEventCheck> TriggerInteraction = EC_None;		

	// 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Events")
	int AfterTimes = 1;

	//it's variable need only for intermediate calculation

	UPROPERTY()
	int Counter = 0;

	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Events")
	bool bDoOnce = true;

	//Game Event, wich execute if TriggerInteraction match with some gameplay event
	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Game Events")
	FGameEvent GameEvent;
};
