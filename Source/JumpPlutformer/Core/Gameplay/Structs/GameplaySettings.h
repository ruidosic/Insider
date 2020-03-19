// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/Gameplay/Structs/PlayerSettings.h"
#include "Core/Gameplay/Structs/EquipmentSettings.h"
#include "Core/Gameplay/Structs/FootstepSoundSettings.h"
#include "GameplaySettings.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FGameplaySettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Settings")
	FPlayerSettings PlayerSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Settings")
	FFootstepSoundSettings FootstepSoundSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Settings")
	FEquipmentSettings EquipmentSettings;
};
