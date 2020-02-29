// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structures/GameEvents.h"
#include "Enums/EventCheck.h"
#include "CoreGameEvent.generated.h"

class APlayerController;

UCLASS()
class INSIDER_API ACoreGameEvent : public AActor
{
	GENERATED_BODY()
	
public:	

	ACoreGameEvent();

	// Enable or Disable Player's Input
	void ControllerInput(bool bEnabled);

	void GameEventCheck(TEnumAsByte<EEventCheck> CheckEvent);

private:



protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	bool bInteractionEnabled;

	UPROPERTY(VisibleAnywhere)
	TArray<FGameEvents> GameEvents;

	UPROPERTY(VisibleAnywhere)
	TArray<int> IndexCache;
};
