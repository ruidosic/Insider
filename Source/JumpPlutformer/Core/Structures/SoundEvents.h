// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/AssetPtr.h"
#include "Sound/SoundBase.h"
#include "Sound/SoundAttenuation.h"
#include "SoundEvents.generated.h"


 //
 // Additional structs for FSoundEvents
 //

USTRUCT(BlueprintType)
struct FSound2D
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2D Sound")
	TAssetPtr<USoundBase> Sound2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2D Sound")
	float DelayBeforePlaySec;
};


USTRUCT(BlueprintType)
struct FSound3D
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Sound")
	TAssetPtr<USoundBase> Sound3D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Sound")
	AActor* ActorToAttach;

	//Attach to taged actor with skip selected
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Sound")
	bool bAttachToTagedActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Sound")
	FName ActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Sound")
	TAssetPtr<USoundAttenuation> SoundAttenuation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Sound")
	float DelayBeforePlaySec;
};


USTRUCT(BlueprintType)
struct FSoundAmbient
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ambient Sound")
	TAssetPtr<USoundBase> AmbientSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmbientSound")
	TArray<FName> AmbientSoundTags;

	// 0 = instant 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmbientSound")
	float FadeInDurationSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AmbientSound")
	float DelayBeforePlaySec;
};


USTRUCT(BlueprintType)
struct FStopSoundAmbient
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stop Ambient Sound")
	TArray<FName> TagsAmbientSoundToStop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stop Ambient Sound")
	bool bSkipTagsAndStopAll;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stop Ambient Sound")
	float FadeOutDurationSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stop Ambient Sound")
	float DelayBeforeStopSec;
};


// Main struct
USTRUCT(BlueprintType)
struct FSoundEvents
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Events")
	TArray<FSound2D> PlaySound2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Events")
	TArray<FSound3D> PlaySound3D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Events")
	TArray<FSoundAmbient> PlayAmbientSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Events")
	TArray<FStopSoundAmbient> StopAmbientSound;
};
