// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structs/GameplaySettings.h"
#include "NightVisionEquipsComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNightVisionEquipsComponent, Display, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INSIDER_API UNightVisionEquipsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UNightVisionEquipsComponent();

	/* NightVision Settings that setup on BeginPlay */

	bool bHasNightVision;
	bool bInfiniteNightVision;
	float NightVisionDurationMinute;
	float NightVisionLowBatteryWarningPercent;
	float NightVisionMaxZoomFOV;
	TSoftObjectPtr<USoundBase> SoftNightVisionOnSound;
	UPROPERTY()
	USoundBase* NightVisionOnSound;
	TSoftObjectPtr<USoundBase> SoftNightVisionOffSound;
	UPROPERTY()
	USoundBase* NightVisionOffSound;
	TSoftObjectPtr<USoundBase> SoftNightVisionZoomOutSound;
	UPROPERTY()
	USoundBase* NightVisionZoomOutSound;
	TSoftObjectPtr<USoundBase> SoftNightVisionZoomInSound;
	UPROPERTY()
	USoundBase* NightVisionZoomInSound;
	TSoftObjectPtr<USoundBase> SoftNightVisionLowBatterySound;
	UPROPERTY()
	USoundBase* NightVisionLowBatterySound;

	// Get GameplaySettings data from ACoreGameplay and setup it into NightVision Settings vars
	void SetupDefaults();

	void SetupNightVisionSettings(const FNightVisionSettings& NightVision);

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	AActor* Owner;
};
