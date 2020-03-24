// Fill out your copyright notice in the Description page of Project Settings.


#include "NightVisionEquipsComponent.h"
#include "GameplayInterface.h"

DEFINE_LOG_CATEGORY(LogNightVisionEquipsComponent)

UNightVisionEquipsComponent::UNightVisionEquipsComponent()
{
	Owner = GetOwner();
}

/* Setup all Settings Variables from Owner's FGameplaySettings*/

void UNightVisionEquipsComponent::SetupDefaults()
{
	if (Owner)
	{
		if (Owner->Implements<UGameplayInterface>())
		{
			FGameplaySettings GameplaySettings = IGameplayInterface::Execute_GetGameplaySettings(Owner);
			SetupNightVisionSettings(GameplaySettings.EquipmentSettings.NightVision);
		}
		else
		{
			UE_LOG(LogNightVisionEquipsComponent, Warning, TEXT("UNightVisionEquipsComponent::SetupDefaults -- Missing IGameplayInterface implementation for: %s"), *GetOwner()->GetFullName());
		}
	}
	else
	{
		UE_LOG(LogNightVisionEquipsComponent, Warning, TEXT("UNightVisionEquipsComponent::SetupDefaults -- Cant Find Owner!"));
	}
}

void UNightVisionEquipsComponent::SetupNightVisionSettings(const FNightVisionSettings & NightVision)
{
	bHasNightVision = NightVision.bHas;
	bInfiniteNightVision = NightVision.bInfinite;
	NightVisionDurationMinute = NightVision.DurationMinute;
	NightVisionLowBatteryWarningPercent = NightVision.LowBatteryWarningPercent;
	NightVisionMaxZoomFOV = NightVision.MaxZoomFOV;
	SoftNightVisionOnSound = NightVision.OnSound;
	SoftNightVisionOffSound = NightVision.OffSound;
	SoftNightVisionZoomOutSound = NightVision.ZoomOutSound;
	SoftNightVisionZoomInSound = NightVision.ZoomInSound;
	SoftNightVisionLowBatterySound = NightVision.LowBatterySound;
}

void UNightVisionEquipsComponent::BeginPlay()
{
	Super::BeginPlay();
	SetupDefaults();
}


