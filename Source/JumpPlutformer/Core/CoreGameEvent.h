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


	// Actor Interactions Events
	int InteractionRepeatCounter = 0;
	FActorInteraction AI;
	void ActorInteractions(FGameEvent& GameEvent);
	void ActorInteraction(FActorInteraction& ActorInteraction);
	void ActorInteractionLoop();


	//	Actor Transforms Events
	int TransformSequenceCounter = 0;
	FTransform ActorCurrentTransform;
	FActorTransforms AT;
	void ActorTransforms(FGameEvent& GameEvent);
	void ActorTransform(FActorTransforms& ActorTransform);
	void ActorTransformLoop();



protected:

	// Timelines properties
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
