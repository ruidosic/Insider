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
	void CreateGameEvent(FGameEvent& GameEvent);

private:


	
	// Cache all Spawned Game Events for cleaning
	TArray<ACoreGameEvent*> CoreGameEventsCache;


	// Clean memory when event done
	void DestroyCreatedEventsTimer(const FGameEvent& GameEvent);
	
	UFUNCTION()
	void DestroyCreatedEvents();


	// Actor Interactions Events
	int InteractionRepeatCounter = 0;
	void ActorInteractions(FGameEvent& GameEvent);
	void ActorInteraction(FActorInteraction& ActorInteraction);
	void ActorInteractionLoop(FActorInteraction & ActorInteraction);
};
