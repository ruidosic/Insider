// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Structures/GameEvent.h"
#include "CoreGameEvent.generated.h"

class APlayerController;
class UTimelineComponent;
class UCurveFloat;

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

				/*  Environment Events   */

	// Actor Interactions Events
	int InteractionRepeatCounter = 0;
	FActorInteraction AI;
	void ActorInteractions(FGameEvent& GameEvent);
	void ActorInteraction(FActorInteraction& ActorInteraction);
	UFUNCTION()
	void ActorInteractionLoop();


	//	Actor Transforms Events
	int TransformSequenceCounter = 0;
	FTransform ActorCurrentTransform;
	FActorTransforms AT;
	void ActorTransforms(FGameEvent& GameEvent);
	void ActorTransform(FActorTransforms& ActorTransform);
	UFUNCTION()
	void ActorTransformLoop();


	// Spawn Actors Events
	FSpawnActors SA;
	void SpawnActors(FGameEvent& GameEvent);
	void SpawnActor(FSpawnActors& SpawnActor);
	UFUNCTION()
	void AsyncSpawnActorCompleted(bool bResult, FStringAssetReference LoadedReference, AActor* SpawnedActor);
	UFUNCTION()
	void SpawnActorAfterDelay();


	// Availability Actors Events
	FActorsAvailability AA;
	void ActorAvailabilities(FGameEvent& GameEvent);
	void ActorAvailability(FActorsAvailability& ActorAvailability);
	UFUNCTION()
	void ActorAvailabilityAfterDelay();

				/*  Player Events   */

	// Look At Actors Events
	FLookAtActors LAA;
	void LookAtActors(FGameEvent& GameEvent);
	void LookAtActor(FLookAtActors& LookAtActor);
	UFUNCTION()
	void LookAtActorSequence();

protected:

	//
	// Timelines properties
	//

	UPROPERTY()
	UTimelineComponent* ActorTransformTimeline;

	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* DefaultLinearFloatCurve;

	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* DefaultSmoothFloatCurve;

	// Timelines Callbacks
	UFUNCTION()
	void OnActorTransformFloatReturn(float Value);

	UFUNCTION()
	void OnActorTransformFinished();
};
