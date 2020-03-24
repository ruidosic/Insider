// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structs/GameplaySettings.h"
#include "WeaponEquipsComponent.generated.h"

class UMaterialInterface;

DECLARE_LOG_CATEGORY_EXTERN(LogWeaponEquipsComponent, Display, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INSIDER_API UWeaponEquipsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UWeaponEquipsComponent();

	/* Pistol Settings setup in BeginPlay */

	bool bHasPistol;
	bool bPistolContinuousShot;
	int PistolTotalAmmo;
	int PistolClipCapasity;
	int PistolClipAmmo;
	float PistolShotDistance;
	TSoftObjectPtr<UMaterialInterface> SoftPistolShotDecal;
	UPROPERTY()
	UMaterialInterface* PistolShotDecal;
	TSoftObjectPtr<USoundBase> SoftPistolEquipSound;
	UPROPERTY()
	USoundBase* PistolEquipSound;
	TSoftObjectPtr<USoundBase> SoftPistolShotSound;
	UPROPERTY()
	USoundBase* PistolShotSound;
	TSoftObjectPtr<USoundBase> SoftPistolShotWhileEmptySound;
	UPROPERTY()
	USoundBase* PistolShotWhileEmptySound;
	TSoftObjectPtr<USoundBase> SoftPistolReloadSound;
	UPROPERTY()
	USoundBase* PistolReloadSound;
	TSoftObjectPtr<USoundBase> SoftPistolReloadWhileEmptySound;
	UPROPERTY()
	USoundBase* PistolReloadWhileEmptySound;

	// Get GameplaySettings data from ACoreGameplay and setup it into add Weapon settings vars
	void SetupDefaults();
	
	//Setup all Weapon Equipments settings 
	void SetupWeaponEquips(const FEquipmentSettings& Equipments);

	//Partial Weapon Equips setups

	void SetupPistolSettings(const FPistolSettings& Pistol);
	// TODO: other weapon

	// TODO: need SetupAsyncPistolSettings() and other to setup hard-pointers vars
	// TODO: need ClearAsyncLoadedPistolSettings() and other to clean hard-pointers vars

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	AActor* Owner;
};
