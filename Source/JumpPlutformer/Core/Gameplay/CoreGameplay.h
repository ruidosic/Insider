// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Gameplay/Structs/GameplaySettings.h"
#include "Core/Gameplay/GameplayInterface.h"
#include "CoreGameplay.generated.h"

class ULightEquipsComponent;
class UNightVisionEquipsComponent;
class UCameroidEquipsComponent;
class UWeaponEquipsComponent;
class UTimelineComponent;
class UPostProcessComponent;
class USpringArmComponent;

UCLASS()
class INSIDER_API ACoreGameplay : public AActor, public IGameplayInterface
{
	GENERATED_BODY()
	
public:	

	ACoreGameplay();

protected:
	
	virtual void BeginPlay() override;

	// Main Configuration Model
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SimpleDisplay)
	FGameplaySettings GameplaySettings;

	bool bEquipTimelineInProgress;
	
public:

	/* overriden from IGameplayInterface */

	FGameplaySettings GetGameplaySettings_Implementation() override;
	bool IsOnLadder_Implementation() override;
	bool IsHelding_Implementation() override;
	bool IsEquipTimelineInProgress_Implementation() override;
	void SetEquipTimelineInProgress_Implementation(bool bValue) override;
	void SetEquipmentSwitch_Implementation(int Value) override;
	
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
	UPROPERTY()
	USoundBase* DamageSound;
	TSoftObjectPtr<USoundBase> SoftDeathSound;
	UPROPERTY()
	USoundBase* DeathSound;
	TSoftObjectPtr<USoundBase> SoftFearSound;
	UPROPERTY()
	USoundBase* FearSound;
	TSoftObjectPtr<USoundBase> SoftYouDiedSFX;
	UPROPERTY()
	USoundBase* YouDiedSFX;

	//
	// Equipment Settings from GameplaySettings model
	// Was setting and using into LightEquipsComponent,  
	//
	

private:

	void SetupPlayerSettings();

	/* Setup Equipments, Timelines and others components (create components and attach them to component's hierarchy)*/
	void SetupComponents();

public:
	void StartFocus();
	void EndFocus();
	void StopFocus();

	UPROPERTY(BlueprintReadOnly, Category = "Physics")
	bool bHelding = false;

	bool bOnLadder;

	int EquipmentSwitch;

	UPROPERTY(BlueprintReadOnly, Category = "Night Vision")
	bool bNightVisionOff = true;

protected:
	
	// Root Components for Equipments Objects attach
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* LightsRootComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UPostProcessComponent* NightVisionRootComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* WeaponRootComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UPostProcessComponent* CameroidRootComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* HeldSlotComp;

	// Arm Components for Lights and Weapons Equipments

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USpringArmComponent* FlashlightArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USpringArmComponent* LighterArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USpringArmComponent* GlowstickArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USpringArmComponent* TorchArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USpringArmComponent* PistolArm;

	/* Contain all logic for Glowstick, Flashlight, Torch, Lighter*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	ULightEquipsComponent* LightEquipsComponent;

	/* Contain logic for equip, unequip, etc.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UNightVisionEquipsComponent* NightVisionEquipsComponent;

	/* Contain all logic for Pistol and other weapon (like equip, unequip and other)*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UWeaponEquipsComponent* WeaponEquipsComponent;

	/* Contain logic for equip, unequip, etc.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UCameroidEquipsComponent* CameroidEquipsComponent;

	UPROPERTY()
	UTimelineComponent* FocusTimeline;
	
	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* SmoothCurveFloat;

	UFUNCTION()
	void FocusTimelineFloatReturn(float Value);

};
