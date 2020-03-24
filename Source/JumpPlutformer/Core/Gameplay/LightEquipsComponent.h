// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structs/GameplaySettings.h"
#include "LightEquipsComponent.generated.h"

class UTimelineComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogLightEquipsComponent, Display, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INSIDER_API ULightEquipsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	ULightEquipsComponent();

	/* For equipments with lights, we need setup Light Settings (Pointlight or Spotlight when we equip this equipment) */
	/*	For equipment's sounds we need setup their sounds when we equip this equipments */
	/*	Small Asset we loading synchronous, Large Asset we load Asynchronous;
	for sync load we can use native LoadSync function, but we need function for LoadAsync in CoreFunctionLibrary */

	/* Glowstick Settings that setup on BeginPlay */
	
	bool bHasGlowstick;
	bool bInfiniteGlowstick;
	float GlowstickDurationMinute;
	float GlowstickEmissiveIntensity;
	float GlowstickIntensity;
	FPointlightSettings GlowstickLight;
	TSoftObjectPtr<USoundBase> SoftGlowstickOnSound;
	UPROPERTY()
	USoundBase* GlowstickOnSound;
	TSoftObjectPtr<USoundBase> SoftGlowstickOffSound;
	UPROPERTY()
	USoundBase* GlowstickOffSound;

	/* Flashlight Settings that setup on BeginPlay */
	
	bool bHasFlashlight;
	bool bInfiniteFlashlight;
	float FlashlightDurationMinute;
	float FlashlightFlickerStartPercent;
	float FlashlightFlickeringSpeed;
	float FlashlightFocusAngle;
	float FlashlightIntensity;
	float FlashlightAngle;
	FSpotlightSettings FlashlightLight;
	TSoftObjectPtr<USoundBase> SoftFlashlightOnSound;
	UPROPERTY()
	USoundBase* FlashlightOnSound;
	TSoftObjectPtr<USoundBase> SoftFlashlightOffSound;
	UPROPERTY()
	USoundBase* FlashlightOffSound;
	TSoftObjectPtr<USoundBase> SoftFlashlightFocusSound;
	UPROPERTY()
	USoundBase* FlashlightFocusSound;

	/* Lighter Settings that setup on BeginPlay  */

	bool bHasLighter;
	bool bInfiniteLighter;
	float LighterDurationMinute;
	float LighterFlickeringSpeed;
	float LighterIntensity;
	FPointlightSettings LighterLight;
	TSoftObjectPtr<USoundBase> SoftLighterOnSound;
	UPROPERTY()
	USoundBase* LighterOnSound;
	TSoftObjectPtr<USoundBase> SoftLighterOffSound;
	UPROPERTY()
	USoundBase* LighterOffSound;

	/* Torch Settings that setup on BeginPlay  */

	bool bHasTorch;
	bool bInfiniteTorch;
	bool bTorchRequiresLighter;
	float TorchDurationMinute;
	float TorchFlickeringSpeed;
	float TorchIntensity;
	FPointlightSettings TorchLight;
	TSoftObjectPtr<USoundBase> SoftTorchOnSound;
	UPROPERTY()
	USoundBase* TorchOnSound;
	TSoftObjectPtr<USoundBase> SoftTorchOffSound;
	UPROPERTY()
	USoundBase* TorchOffSound;
	TSoftObjectPtr<USoundBase> SoftTorchFireSparksSound;
	UPROPERTY()
	USoundBase* TorchFireSparksSound;


	// Get GameplaySettings data from ACoreGameplay and setup all lighting equipments	
	void SetupDefaults();

	// Setup all Lighting Equipments settings 
	void SetupLightingEquips(const FEquipmentSettings& Equipment);
	
	// Partial Lighting Equips setups
	
	void SetupGlowstickSettings(const FGlowstickSettings& Glowstick);
	void SetupFlashlightSettings(const FFlashlightSettings& Flashlight);
	void SetupLighterSettings(const FLighterSettings& Lighter);
	void SetupTorchSettings(const FTorchSettings& Torch);

	// Partial Lighting Equips setups Async (this parameter setups when we equips our equipment)

	void SetupGlowstickAsyncSettings();
	void SetupFlashlightAsyncSettings();
	void SetupLighterAsyncSettings();
	void SetupTorchAsyncSettings();

	/* Glowstick functions for equipping */

	void TakeGlowstick();
	void EquipGlowstick(bool bSilent);
	UFUNCTION()
	void OnEquipGlowstick(float Value);
	UFUNCTION()
	void OnEquipGlowstickFinished();
	void UnequipGlowstick();
	void StartGlowstickDuration();
	void StopGlowstickDuration();
	void UseGlowstick();

protected:

	virtual void BeginPlay() override;

	UTimelineComponent* GlowstickEquipTimeline;

	UCurveFloat* DefaultSmoothFloatCurve;


private:

	// Mesc variables

	float GlowstickRemainingLifeProc = 100.0;
	bool bGlowstickOff = true;

	UPROPERTY()
	AActor* Owner;

};
