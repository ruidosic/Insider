// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sound/SoundBase.h"
#include "UObject/SoftObjectPtr.h"
#include "PlayerEvents.generated.h"

USTRUCT(BlueprintType)
struct FLookAtActorSequence
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Look At Actors Sequence")
	AActor* ActorToLook;

	UPROPERTY(BlueprintReadWrite, Category = "Look At Actors Sequence")
	bool bSmooth;

	UPROPERTY(BlueprintReadWrite, Category = "Look At Actors Sequence")
	float TurnSpeedSec;

	UPROPERTY(BlueprintReadWrite, Category = "Look At Actors Sequence")
	float KeepLookingDurationSec;

	UPROPERTY(BlueprintReadWrite, Category = "Look At Actors Sequence")
	float TargetFOV;
};


USTRUCT(BlueprintType)
struct FLookAtActors
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Look At Actors")
	TArray<FLookAtActorSequence> LookAtActorSeq;

	UPROPERTY(BlueprintReadWrite, Category = "Look At Actors")
	float DelayBeforeLookingSequenceSec;
};


USTRUCT(BlueprintType)
struct FOptionalDamageSound
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Optional Damage Sound")
	TAssetPtr<USoundBase> CustomDamageVoice;

	UPROPERTY(BlueprintReadWrite, Category = "Optional Damage Sound")
	TAssetPtr<USoundBase> CustomDieVoice;

	UPROPERTY(BlueprintReadWrite, Category = "Optional Damage Sound")
	TAssetPtr<USoundBase> CustomDieSFX;
};


USTRUCT(BlueprintType)
struct FDamagePlayer
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	float DamageValue;

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	bool bSurviveAfterThisDamage;

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	bool bDamageSound;

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	bool bDeathSoundVoice;

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	bool bDeathSoundSFX;

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	bool bHUDDamageAnimation;

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	bool bHealthAnimation;

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	FOptionalDamageSound CustomSounds;

	UPROPERTY(BlueprintReadWrite, Category = "Damage Player")
	float DelayBeforeDamageSec;
};


USTRUCT(BlueprintType)
struct FFearEffect
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite, Category = "Fear Effect")
	bool bFearAnimation;

	UPROPERTY(BlueprintReadWrite, Category = "Fear Effect")
	bool bFearSound;

	UPROPERTY(BlueprintReadWrite, Category = "Fear Effect")
	TAssetPtr<USoundBase> CustomFearSound;

	UPROPERTY(BlueprintReadWrite, Category = "Fear Effect")
	float DelayBeforeFear;
};


USTRUCT(BlueprintType)
struct FGlitchEffect 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Glitch Effect")
	float DelayBeforeGlitchSec;
};


USTRUCT(BlueprintType)
struct FPlayerEvents
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Player Events")
	TArray<FLookAtActors> LookAtActors;

	UPROPERTY(BlueprintReadWrite, Category = "Player Events")
	TArray<FDamagePlayer> DamagePlayer;

	UPROPERTY(BlueprintReadWrite, Category = "Player Events")
	TArray<FFearEffect> FearEffect;

	UPROPERTY(BlueprintReadWrite, Category = "Player Events")
	TArray<FGlitchEffect> GlitchEffect;
};
