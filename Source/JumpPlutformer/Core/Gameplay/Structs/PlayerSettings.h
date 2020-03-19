// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sound/SoundBase.h"
#include "UObject/SoftObjectPtr.h"
#include "PlayerSettings.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float Health = 100; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float WalkSpeed = 150;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float RunSpeed = 300;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float CrouchSpeed = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float CrouchHeight = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float DefaultFOV = 90;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float FocusFOV = 60;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float DOFAperture = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	float DOFApertureInspecting = 1.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	bool bFilterInventoryWhileSearchItem = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	TSoftObjectPtr<USoundBase> DamageSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	TSoftObjectPtr<USoundBase> DeathSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	TSoftObjectPtr<USoundBase> FearSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	TSoftObjectPtr<USoundBase> PlayerDiedSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
	TSoftObjectPtr<UTexture> PlayerDiedTexture;

	
};
