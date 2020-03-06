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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Transforms Sequence")
	FTransform TransformTo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Transforms Sequence")
	bool bSmooth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Transforms Sequence")
	float TransformDurationSec;
};


// Additional struct for FSpawnActors
USTRUCT(BlueprintType)
struct FSpawnActorsAttachment
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors Attachment")
	AActor* AttachTo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors Attachment")
	FName ParentComponentByTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors Attachment")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors Attachment")
	EAttachmentRule LocationRule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors Attachment")
	EAttachmentRule RotationRule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors Attachment")
	EAttachmentRule ScaleRule;
};


	//
	// Additional structs for FEnvironmentEvents
	//


USTRUCT(BlueprintType)
struct FActorInteraction
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Interaction")
	TArray<class ACoreUse*> ActorsToInteract;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Interaction")
	TEnumAsByte<EEventInteractions> Interaction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Interaction")
	int RepeatTimes = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Interaction")
	float DelayBeforeInteractionSec = 0.01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Interaction")
	float DelayBeforeEachRepeatSec = 0.01;
};


USTRUCT(BlueprintType)
struct FActorTransforms
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Transforms")
	AActor* ActorToTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Transforms")
	TArray<FActorTransformSequence> TransformSequence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Transforms")
	float DelayBeforeTransformSequenceSec = 0.01;
};


USTRUCT(BlueprintType)
struct FSpawnActors
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors")
	TSubclassOf<AActor> SpawnedActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors")
	FTransform SpawnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors")
	ESpawnActorCollisionHandlingMethod CollisionHandling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors")
	TArray<FName> SpawnedActorTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors")
	FSpawnActorsAttachment OptionalAttachTo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Actors")
	float DelayBeforeSpawnActorSec = 0.01;
	
};


USTRUCT(BlueprintType)
struct FActorsAvailability
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors Availability Events")
	TArray<AActor*> ActorsToChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors Availability Events")
	TArray<FName> ActorsWithTagToChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors Availability Events")
	bool bHiddenInGame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors Availability Events")
	bool bDisableCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors Availability Events")
	bool bSkipAllSettingsAndDestroy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors Availability Events")
	float DelayBeforeChange = 0.01;

};


//Main struct
USTRUCT(BlueprintType)
struct FEnvironmentEvents
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Environment Events")
	TArray<FActorInteraction> ActorInteractions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Environment Events")
	TArray<FActorTransforms> ActorTransforms;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Environment Events")
	TArray<FSpawnActors> SpawnActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Environment Events")
	TArray<FActorsAvailability> ActorAvailabilities;
};
