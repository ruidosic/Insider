// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Gameplay/Structs/GameplaySettings.h"
#include "CoreGameplay.generated.h"


class UTimelineComponent;
class UCurveFloat;
class USoundBase;


UCLASS()
class INSIDER_API ACoreGameplay : public AActor
{
	GENERATED_BODY()
	
public:	

	ACoreGameplay();

protected:
	
	virtual void BeginPlay() override;

	// Main Configuration Model
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SimpleDisplay)
	FGameplaySettings GameplaySettings;

public:
	//
	// Player Settings Properties from GameplaySettings model
	//
	float Health;
	float WalkSpeed;
	float RunSpeed;
	float CrouchSpeed;
	float CrouchHeight;
	float DefaultFOV;
	float FocusFOV;
	float DOFAperture;
	float DOFApertureInspecting;
	bool bFilterInventory;
	TSoftObjectPtr<USoundBase> SoftDamageSound;
	USoundBase* DamageSound;
	TSoftObjectPtr<USoundBase> SoftDeathSound;
	USoundBase* DeathSound;
	TSoftObjectPtr<USoundBase> SoftFearSound;
	USoundBase* FearSound;
	TSoftObjectPtr<USoundBase> SoftYouDiedSFX;
	USoundBase* YouDiedSFX;

	//
	// Equipment Settings from GameplaySettings model
	//

	// Glowstick
	bool bHasGlowstick;
	bool bInfiniteGlowstick;
	float GlowstickDurationMinute;
	float GlowstickEmissiveIntensity;
	float GlowstickIntensity;
	TSoftObjectPtr<USoundBase> SoftGlowstickOnSound;
	USoundBase* GlowstickOnSound;
	TSoftObjectPtr<USoundBase> SoftGlowstickOffSound;
	USoundBase* GlowstickOffSound;
	
	// Flashlight
	bool bHasFlashlight;
	bool bInfiniteFlashlight;
	float FlashlightDurationMinute;
	float FlashlightFlickerStartPercent;
	float FlashlightFlickeringSpeed;
	float FlashlightFocusAngle;
	float FlashlightIntensity;
	float FlashlightAngle;
	TSoftObjectPtr<USoundBase> SoftFlashlightOnSound;
	USoundBase* FlashlightOnSound;
	TSoftObjectPtr<USoundBase> SoftFlashlightOffSound;
	USoundBase* FlashlightOffSound;
	TSoftObjectPtr<USoundBase> SoftFlashlightFocusSound;
	USoundBase* FlashlightFocusSound;

	// Lighter
	bool bHasLighter;
	bool bInfiniteLighter;
	float LighterDurationMinute;
	float LighterFlickeringSpeed;
	float LighterIntensity;
	TSoftObjectPtr<USoundBase> SoftLighterOnSound;
	USoundBase* LighterOnSound;
	TSoftObjectPtr<USoundBase> SoftLighterOffSound;
	USoundBase* LighterOffSound;

	// Torch
	bool bHasTorch;
	bool bInfiniteTorch;
	bool bTorchRequiresLighter;
	float TorchDurationMinute;
	float TorchFlickeringSpeed;
	float TorchIntensity;
	TSoftObjectPtr<USoundBase> SoftTorchOnSound;
	USoundBase* TorchOnSound;
	TSoftObjectPtr<USoundBase> SoftTorchOffSound;
	USoundBase* TorchOffSound;
	TSoftObjectPtr<USoundBase> SoftTorchFireSparksSound;
	USoundBase* TorchFireSparksSound;

	// NightVision
	bool bHasNightVision;
	bool bInfiniteNightVision;
	float NightVisionDurationMinute;
	float NightVisionLowBatteryWarningPercent;
	float NightVisionMaxZoomFOV;
	TSoftObjectPtr<USoundBase> SoftNightVisionOnSound;
	USoundBase* NightVisionOnSound;
	TSoftObjectPtr<USoundBase> SoftNightVisionOffSound;
	USoundBase* NightVisionOffSound;
	TSoftObjectPtr<USoundBase> SoftNightVisionZoomOutSound;
	USoundBase* NightVisionZoomOutSound;
	TSoftObjectPtr<USoundBase> SoftNightVisionZoomInSound;
	USoundBase* NightVisionZoomInSound;
	TSoftObjectPtr<USoundBase> SoftNightVisionLowBatterySound;
	USoundBase* NightVisionLowBatterySound;

	// Cameroid
	bool bHasCameroid;
	bool bInfiniteCameroid;
	float CameroidPhotoShakeDifficulty; // from 0 to 6
	float CameroidFOV;
	TSoftObjectPtr<UTexture> SoftCameroidViewFinderTexture;
	UTexture* CameroidViewFinderTexture;
	TSoftObjectPtr<USoundBase> SoftCameroidOnSound;
	USoundBase* CameroidOnSound;
	TSoftObjectPtr<USoundBase> SoftCameroidOffSound;
	USoundBase* CameroidOffSound;
	TSoftObjectPtr<USoundBase> SoftCameroidShotSound;
	USoundBase* CameroidShotSound;

	// Pistol
	bool bHasPistol;
	bool bPistolContinuousShot;
	int TotalAmmo;
	int PistolClipCapasity;
	int PistolClipAmmo;
	float PistolShotDistance;
	TSoftObjectPtr<UMaterialInterface> SoftPistolShotDecal;
	UMaterialInterface* PistolShotDecal;
	TSoftObjectPtr<USoundBase> SoftSoftPistolEquipSound;
	USoundBase* PistolEquipSound;
	TSoftObjectPtr<USoundBase> SoftPistolShotSound;
	USoundBase* PistolShotSound;
	TSoftObjectPtr<USoundBase> SoftPistolShotWhileEmptySound;
	USoundBase* PistolShotWhileEmptySound;
	TSoftObjectPtr<USoundBase> SoftPistolReloadSound;
	USoundBase* PistolReloadSound;
	TSoftObjectPtr<USoundBase> SoftPistolReloadWhileEmptySound;
	USoundBase* PistolReloadWhileEmptySound;

private:

	void SetupPlayerSettings();
	void SetupEquipmentSettings();
	void SetupGlowstickSettings();
	void SetupFlashlightSettings();
	void SetupLighterSettings();
	void SetupTorchSettings();
	void SetupNightVisionSettings();
	void SetupCameroidSettings();
	void SetupPistolSettings();

public:
	void StartFocus();
	void EndFocus();
	void StopFocus();

	UPROPERTY(BlueprintReadOnly, Category = "Physics")
	bool bHelding = false;

	UPROPERTY(BlueprintReadOnly, Category = "Night Vision")
	bool bNightVisionOff = true;

private:

	//
	// Timeline properties
	//
	UPROPERTY()
	UTimelineComponent* FocusTimeline;
	
	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* SmoothCurveFloat;

	UFUNCTION()
	void FocusTimelineFloatReturn(float Value);

};
