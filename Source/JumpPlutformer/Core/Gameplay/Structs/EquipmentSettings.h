// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/SoftObjectPtr.h"
#include "Core/Structures/PointlightSettings.h"
#include "Sound/SoundBase.h"
#include "Core/Structures/SpotlightSettings.h"
#include "EquipmentSettings.generated.h"


//
// Setup All Light Equipment Structs
//
USTRUCT(BlueprintType)
struct FGlowstickSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Glowstick Settings")
	bool bHas = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Glowstick Settings")
	bool bInfinite = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Glowstick Settings")
	float DurationMinute = 5.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Glowstick Settings")
	float EmissiveIntensity = 5.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Glowstick Settings")
	FPointlightSettings LightSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	TSoftObjectPtr<USoundBase> OnSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	TSoftObjectPtr<USoundBase> OffSound;
};

USTRUCT(BlueprintType)
struct FFlashlightSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	bool bHas = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	bool bInfinite = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	float DurationMinute = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	float StartFlickerPercent = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	float FlickeringSpeed = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	float FocusAngle = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	FSpotlightSettings LightSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	TSoftObjectPtr<USoundBase> OnSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight Settings")
	TSoftObjectPtr<USoundBase> OffSound;
};

USTRUCT(BlueprintType)
struct FLighterSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	bool bHas = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	bool bInfinite = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	float DurationMinute = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	float FlickeringSpeed = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	FPointlightSettings LightSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	TSoftObjectPtr<USoundBase> OnSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	TSoftObjectPtr<USoundBase> OffSound;
};

USTRUCT(BlueprintType)
struct FTorchSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	bool bHas = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	bool bInfinite = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	bool bRequiresLighter = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	float DurationMinute = 7.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	float FlickeringSpeed = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	FPointlightSettings LightSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	TSoftObjectPtr<USoundBase> OnSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	TSoftObjectPtr<USoundBase> OffSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighter Settings")
	TSoftObjectPtr<USoundBase> FireSparksSound;
};

USTRUCT(BlueprintType)
struct FNightVisionSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	bool bHas = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	bool bInfinite = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	float DurationMinute = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	float LowBatteryWarningPercent = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	float MaxZoomFOV = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	FSpotlightSettings LightSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	float Saturation = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	float VignetteIntensity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	float GrainIntensity = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	float ExposureBias = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	UTexture* ColorGradingLUT;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	TSoftObjectPtr<USoundBase> OnSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	TSoftObjectPtr<USoundBase> OffSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	TSoftObjectPtr<USoundBase> ZoomInSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	TSoftObjectPtr<USoundBase> ZoomOutSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Night Vision Settings")
	TSoftObjectPtr<USoundBase> LowBatterySound;
};

USTRUCT(BlueprintType)
struct FCameroidSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	bool bHas = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	bool bInfinite = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float PhotoShakeDifficulty = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float CameroidFOV = 55;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	FPointlightSettings FlashSettings;

	// Viewfinder Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	UTexture* ViewfinderTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float ViewfinderSaturation = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float ViewfinderVignetteIntensity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float ViewfinderGrainIntensity = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float ViewfinderDirtMaskIntensity = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	UTexture* ViewfinderDirtMaskTexture;

	//	Captured Photo Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float CapturedPhotoSaturation = 0.75;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	FLinearColor CapturedPhotoSceneColorTint = FLinearColor(FVector4(1, 0.8, 0.41, 1));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float CapturedPhotoColorGradingLUTIntensity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	UTexture* CapturedPhotoColorGradingLUT;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float CapturedPhotoVignetteIntensity = 0.4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float CapturedPhotoGrainIntensity = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float CapturedPhotoDirtMaskIntensity = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	UTexture* CapturedPhotoDirtMask;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	float ExposureBias = 0;

	// Sound Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	TSoftObjectPtr<USoundBase> OnSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	TSoftObjectPtr<USoundBase> OffSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameroid Settings")
	TSoftObjectPtr<USoundBase> CameroidShootSound;

};

USTRUCT(BlueprintType)
struct FPistolSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	bool bHas = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	bool bContinuousShot = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	int TotalAmmo = 25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	int ClipCapasity = 7;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	int ClipAmmo = 7;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	float PistolShotDistance = 3000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	TSoftObjectPtr<UMaterialInterface> PistolShotDecal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	TSoftObjectPtr<UParticleSystem> MuzzleFlash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	TSoftObjectPtr<UParticleSystem> BulletTrail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	TSoftObjectPtr<USoundBase> EquipSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	TSoftObjectPtr<USoundBase> ShotSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	TSoftObjectPtr<USoundBase> ShotWhileEmptySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	TSoftObjectPtr<USoundBase> ReloadSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pistol Settings")
	TSoftObjectPtr<USoundBase> ReloadWhileEmptySound;
};

USTRUCT(BlueprintType)
struct FEquipmentSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipments Settings")
	FGlowstickSettings Glowstick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipments Settings")
	FFlashlightSettings Flashlight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipments Settings")
	FTorchSettings Torch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipments Settings")
	FNightVisionSettings NightVision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipments Settings")
	FPistolSettings Pistol;
};
