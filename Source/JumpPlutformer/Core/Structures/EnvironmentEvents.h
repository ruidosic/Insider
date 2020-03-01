// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/Enums/EventInteractions.h"
#include "UObject/SoftObjectPtr.h"
#include "EnvironmentEvents.generated.h"


// Additional struct for FActorTransforms
USTRUCT(BlueprintType)
struct FActorTransformSequence
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Actor Transforms Sequence")
	FTransform TransformTo;

	UPROPERTY(BlueprintReadWrite, Category = "Actor Transforms Sequence")
	bool bSmooth;

	UPROPERTY(BlueprintReadWrite, Category = "Actor Transforms Sequence")
	float TransformDurationSec;
};


// Additional struct for FSpawnActors
USTRUCT(BlueprintType)
struct FSpawnActorsAttachment
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors Attachment")
	AActor* AttachTo;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors Attachment")
	FName ParentComponentByTag;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors Attachment")
	EAttachmentRule LocationRule;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors Attachment")
	EAttachmentRule RotationRule;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors Attachment")
	EAttachmentRule ScaleRule;
};


	//
	// Additional structs for FEnvironmentEvents
	//


USTRUCT(BlueprintType)
struct FActorInteraction
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Actor Interaction")
	TArray<class ACoreUse*> ActorsToInteract;

	UPROPERTY(BlueprintReadWrite, Category = "Actor Interaction")
	TEnumAsByte<EEventInteractions> Interaction;

	UPROPERTY(BlueprintReadWrite, Category = "Actor Interaction")
	int RepeatTimes;

	UPROPERTY(BlueprintReadWrite, Category = "Actor Interaction")
	float DelayBeforeInteractionSec;

	UPROPERTY(BlueprintReadWrite, Category = "Actor Interaction")
	float DelayBeforeEachRepeatSec;
};


USTRUCT(BlueprintType)
struct FActorTransforms
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Actor Transforms")
	AActor* ActorToTransform;

	UPROPERTY(BlueprintReadWrite, Category = "Actor Transforms")
	TArray<FActorTransformSequence> TransformSequence;

	UPROPERTY(BlueprintReadWrite, Category = "Actor Transforms")
	float DelayBeforeTransformSequenceSec;
};


USTRUCT(BlueprintType)
struct FSpawnActors
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors")
	TAssetSubclassOf<AActor> SpawnedActorClass;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors")
	FTransform SpawnTransform;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors")
	ESpawnActorCollisionHandlingMethod CollisionHandling;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors")
	TArray<FName> SpawnedActorTags;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors")
	FSpawnActorsAttachment OptionalAttachTo;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn Actors")
	float DelayBeforeSpawnActorSec;
	
};


USTRUCT(BlueprintType)
struct FActorsAvailability
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Actors Availability Events")
	TArray<AActor*> ActorsToChange;

	UPROPERTY(BlueprintReadWrite, Category = "Actors Availability Events")
	TArray<FName> ActorsWithTagToChange;

	UPROPERTY(BlueprintReadWrite, Category = "Actors Availability Events")
	bool bHiddenInGame;

	UPROPERTY(BlueprintReadWrite, Category = "Actors Availability Events")
	bool bDisableCollision;

	UPROPERTY(BlueprintReadWrite, Category = "Actors Availability Events")
	bool bSkipAllSettingsAndDestroy;

	UPROPERTY(BlueprintReadWrite, Category = "Actors Availability Events")
	float DelayBeforeChange;

};


//Main struct
USTRUCT(BlueprintType)
struct FEnvironmentEvents
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Environment Events")
	TArray<FActorInteraction> ActorInteractions;

	UPROPERTY(BlueprintReadWrite, Category = "Environment Events")
	TArray<FActorTransforms> ActorTransforms;

	UPROPERTY(BlueprintReadWrite, Category = "Environment Events")
	TArray<FSpawnActors> SpawnActors;

	UPROPERTY(BlueprintReadWrite, Category = "Environment Events")
	TArray<FActorsAvailability> AvailabilityActors;
};
