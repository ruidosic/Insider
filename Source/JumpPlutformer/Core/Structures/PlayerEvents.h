// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sound/SoundBase.h"
#include "UObject/SoftObjectPtr.h"
#include "PlayerEvents.generated.h"

// Additional struct for FLookAtActor
USTRUCT(BlueprintType)
struct FLookAtActorSequence
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look At Actors Sequence")
	AActor* ActorToLook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look At Actors Sequence")
	bool bSmooth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look At Actors Sequence")
	float TurnSpeedSec = 0.01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look At Actors Sequence")
	float KeepLookingDurationSec = 0.01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look At Actors Sequence")
	float TargetFOV;
};


// Additional struct for FDamagePlayer
USTRUCT(BlueprintType)
struct FOptionalDamageSound
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Optional Damage Sound")
		TAssetPtr<USoundBase> CustomDamageVoice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Optional Damage Sound")
		TAssetPtr<USoundBase> CustomDieVoice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Optional Damage Sound")
		TAssetPtr<USoundBase> CustomDieSFX;
};


	//
	// Additional structs for FPlayerEvents
	//


USTRUCT(BlueprintType)
struct FLookAtActors
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look At Actors")
	TArray<FLookAtActorSequence> LookAtActorSeq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Look At Actors")
	float DelayBeforeLookingSequenceSec = 0.01;
};


USTRUCT(BlueprintType)
struct FDamagePlayer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	float DamageValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	bool bSurviveAfterThisDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	bool bDamageSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	bool bDeathSoundVoice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	bool bDeathSoundSFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	bool bHUDDamageAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	bool bHealthAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	FOptionalDamageSound CustomSounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Player")
	float DelayBeforeDamageSec = 0.01;
};


USTRUCT(BlueprintType)
struct FFearEffect
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fear Effect")
	bool bFearAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fear Effect")
	bool bFearSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fear Effect")
	TAssetPtr<USoundBase> CustomFearSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fear Effect")
	float DelayBeforeFear = 0.01;
};


USTRUCT(BlueprintType)
struct FGlitchEffect 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Glitch Effect")
	float DelayBeforeGlitchSec = 0.01;
};


//Main struct
USTRUCT(BlueprintType)
struct FPlayerEvents
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Events")
	TArray<FLookAtActors> LookAtActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Events")
	TArray<FDamagePlayer> DamagePlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Events")
	TArray<FFearEffect> FearEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Events")
	TArray<FGlitchEffect> GlitchEffect;
};
