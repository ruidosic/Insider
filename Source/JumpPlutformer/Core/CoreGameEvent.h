// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Structures/GameEvent.h"
#include "CoreGameEvent.generated.h"

class APlayerController;

UCLASS()
class INSIDER_API ACoreGameEvent : public AActor
{
	GENERATED_BODY()
	
public:	

	ACoreGameEvent();

	UFUNCTION()
	void CreateGameEvent(const FGameEvent& GameEvent);

private:



protected:

	virtual void BeginPlay() override;


};
