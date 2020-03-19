// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sound/SoundBase.h"
#include "UObject/SoftObjectPtr.h"
#include "FootstepSoundSettings.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FFootstepSoundSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> Default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> Carpet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> Dirt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> Grass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> Metal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> Rock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> Tile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> Wood;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> DefaultJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> CarpetJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> DirtJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> GrassJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> MetalJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> RockJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> TileJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep Sound Settings")
	TSoftObjectPtr<USoundBase> WoodJump;
};
