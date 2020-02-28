// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sound/SoundBase.h"
#include "UObject/AssetPtr.h"
#include "Sound/SoundAttenuation.h"
#include "SubtitlesEvents.generated.h"


USTRUCT(BlueprintType)
struct FSubtitleAttach
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle Sub")
	AActor* ActorToAttach;

	//Attach to tagged actor with skip selected
	UPROPERTY(BlueprintReadWrite, Category = "Subtitle Sub")
	bool bAttachToTaggedActor;

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle Sub")
	FName ActorTag;

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle Sub")
	TAssetPtr<USoundAttenuation> SoundAttenuation;
};


USTRUCT(BlueprintType)
struct FSubtitle
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle")
	FText SubtitleText;

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle")
	TAssetPtr<USoundBase> SubtitleSound;

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle")
	bool bSound3D;

	//if sound is 3D
	UPROPERTY(BlueprintReadWrite, Category = "Subtitle")
	FSubtitleAttach AttachSettings;

	// + or - (sec)
	UPROPERTY(BlueprintReadWrite, Category = "Subtitle")
	float ModifyDuration;
};


USTRUCT(BlueprintType)
struct FSubtitleSequence
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle Sequence")
	TArray<FSubtitle> AddSubtitle;

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle Sequence")
	float DelayBeforeStartSequenceSec;
};


USTRUCT(BlueprintType)
struct FSubtitlesEvents
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Subtitle Event")
	TArray<FSubtitleSequence> AddSequence;
	
};
