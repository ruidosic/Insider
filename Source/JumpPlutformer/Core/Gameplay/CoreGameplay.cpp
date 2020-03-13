// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameplay.h"
#include "Components/TimelineComponent.h"
#include "UObject/ConstructorHelpers.h"

ACoreGameplay::ACoreGameplay()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UCurveFloat> SmoothCurveFloatObject(TEXT("/Game/Insider/Curve_DefaultSmooth_Float"));

	// Setup Curves
	if (SmoothCurveFloatObject.Succeeded())
	{
		SmoothCurveFloat = SmoothCurveFloatObject.Object;
	}

	// Setup Timelines
	FocusTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Focus Timeline"));

}

	/**	SETUP Gameplay Settings Model **/

void ACoreGameplay::SetupPlayerSettings()
{
	Health = GameplaySettings.PlayerSettings.Health;
	WalkSpeed = GameplaySettings.PlayerSettings.WalkSpeed;
	RunSpeed = GameplaySettings.PlayerSettings.RunSpeed;
	CrouchSpeed = GameplaySettings.PlayerSettings.CrouchSpeed;
	CrouchHeight = GameplaySettings.PlayerSettings.CrouchHeight;
	DefaultFOV = GameplaySettings.PlayerSettings.DefaultFOV;
	FocusFOV = GameplaySettings.PlayerSettings.FocusFOV;
	DOFAperture = GameplaySettings.PlayerSettings.DOFAperture;
	DOFApertureInspecting = GameplaySettings.PlayerSettings.DOFApertureInspecting;
	bFilterInventory = GameplaySettings.PlayerSettings.bFilterInventoryWhileSearchItem;
	
	// Sounds Load Async
}

void ACoreGameplay::SetupEquipmentSettings()
{
	SetupGlowstickSettings();
	SetupFlashlightSettings();
	SetupLighterSettings();
	SetupTorchSettings();
	SetupNightVisionSettings();
	SetupCameroidSettings();
	SetupPistolSettings();
}

void ACoreGameplay::SetupGlowstickSettings()
{
	bHasGlowstick = GameplaySettings.EquipmentSettings.Glowstick.bHas;
	bInfiniteGlowstick = GameplaySettings.EquipmentSettings.Glowstick.bInfinite;
	GlowstickDurationMinute = GameplaySettings.EquipmentSettings.Glowstick.DurationMinute;
	GlowstickEmissiveIntensity = GameplaySettings.EquipmentSettings.Glowstick.EmissiveIntensity;
	GlowstickIntensity = GameplaySettings.EquipmentSettings.Glowstick.LightSettings.Intensity;
}

void ACoreGameplay::SetupFlashlightSettings()
{
}

void ACoreGameplay::SetupLighterSettings()
{
}

void ACoreGameplay::SetupTorchSettings()
{
}

void ACoreGameplay::SetupNightVisionSettings()
{
}

void ACoreGameplay::SetupCameroidSettings()
{
}

void ACoreGameplay::SetupPistolSettings()
{
}



void ACoreGameplay::BeginPlay()
{
	Super::BeginPlay();
	
}



void ACoreGameplay::StartFocus()
{
	if (!bHelding && bNightVisionOff)
	{
		float CurrentAperture = 3.0;

	}
}

void ACoreGameplay::EndFocus()
{
}

void ACoreGameplay::StopFocus()
{
}

void ACoreGameplay::FocusTimelineFloatReturn(float Value)
{
}




