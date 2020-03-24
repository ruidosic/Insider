// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/SoftObjectPtr.h"
#include "Sound/SoundBase.h"
#include "Sound/SoundAttenuation.h"
#include "SubtitlesEvents.generated.h"


USTRUCT(BlueprintType)
struct FSubtitleAttach
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle Sub")
	AActor* ActorToAttach;

	//Attach to tagged actor with skip selected
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle Sub")
	bool bAttachToTaggedActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle Sub")
	FName ActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle Sub")
	TSoftObjectPtr<USoundAttenuation> SoundAttenuation;
};


USTRUCT(BlueprintType)
struct FSubtitle
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle")
	FText SubtitleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle")
	TSoftObjectPtr<USoundBase> SubtitleSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle")
	bool bSound3D;

	//if sound is 3D
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle")
	FSubtitleAttach AttachSettings;

	// + or - (sec)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle")
	float ModifyDuration = 0.01;
};


USTRUCT(BlueprintType)
struct FSubtitleSequence
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle Sequence")
	TArray<FSubtitle> AddSubtitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle Sequence")
	float DelayBeforeStartSequenceSec = 0.01;
};


USTRUCT(BlueprintType)
struct FSubtitlesEvents
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Subtitle Event")
	TArray<FSubtitleSequence> AddSequence;
	
};
