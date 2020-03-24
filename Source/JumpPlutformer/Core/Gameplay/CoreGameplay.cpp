// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameplay.h"
#include "Components/TimelineComponent.h"
#include "Components/PostProcessComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "LightEquipsComponent.h"
#include "NightVisionEquipsComponent.h"
#include "WeaponEquipsComponent.h"
#include "CameroidEquipsComponent.h"
#include "LightEquipsComponent.h"
#include "UObject/ConstructorHelpers.h"


ACoreGameplay::ACoreGameplay()
{
	PrimaryActorTick.bCanEverTick = false;

	SetupComponents();

	static ConstructorHelpers::FObjectFinder<UCurveFloat> SmoothCurveFloatObject(TEXT("/Game/Insider/Curve_DefaultSmooth_Float"));

	// Setup Curves
	if (SmoothCurveFloatObject.Succeeded())
	{
		SmoothCurveFloat = SmoothCurveFloatObject.Object;
	}
}

void ACoreGameplay::SetupComponents()
{
	FocusTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("FocusTimeline"));

	// Setup Roots PostProcess- and Scene- Components

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = RootComp;

	LightsRootComp = CreateDefaultSubobject<USceneComponent>(TEXT("LightsRootComponent"));
	LightsRootComp->SetRelativeRotation(FRotator(0.0, -20.0, 0.0));

	NightVisionRootComp = CreateDefaultSubobject<UPostProcessComponent>(TEXT("NightVisionRootComponent"));
	
	WeaponRootComp = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponRootComponent"));
	WeaponRootComp->SetRelativeRotation(FRotator(0.0, -25.0, 0.0));

	CameroidRootComp = CreateDefaultSubobject<UPostProcessComponent>(TEXT("CameroidRootComponent"));

	HeldSlotComp = CreateDefaultSubobject<USceneComponent>(TEXT("HeldSlotComponent"));
	HeldSlotComp->SetRelativeLocation(FVector(60.0, 0.0, 0.0));

	// Setup Arm Components

	GlowstickArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("GlowstickArm"));
	GlowstickArm->SetRelativeLocation(FVector(17.0, 22.0, -22.0));
	GlowstickArm->TargetArmLength = 0.0;
	GlowstickArm->bEnableCameraRotationLag = true;
	GlowstickArm->SetupAttachment(LightsRootComp);

	FlashlightArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("FlashlightArm"));
	FlashlightArm->SetRelativeLocation(FVector(7.0, 22.0, -17.0));
	FlashlightArm->TargetArmLength = 0.0;
	FlashlightArm->bEnableCameraRotationLag = true;
	FlashlightArm->SetupAttachment(LightsRootComp);

	LighterArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("LighterArm"));
	LighterArm->SetRelativeLocation(FVector(22.0, 22.0, -17.0));
	LighterArm->TargetArmLength = 0.0;
	LighterArm->bEnableCameraRotationLag = true;
	LighterArm->SetupAttachment(LightsRootComp);

	TorchArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("TorchArm"));
	TorchArm->SetRelativeLocation(FVector(15.0, 22.0, -20.0));
	TorchArm->TargetArmLength = 0.0;
	TorchArm->bEnableCameraRotationLag = true;
	TorchArm->SetupAttachment(LightsRootComp);

	PistolArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("PistolArm"));
	PistolArm->SetRelativeLocation(FVector(10.0, 18.0, -6.0));
	PistolArm->TargetArmLength = 0.0;
	PistolArm->bEnableCameraRotationLag = true;
	PistolArm->SetupAttachment(WeaponRootComp);

	// Setup Custom ActorComponents 

	LightEquipsComponent = CreateDefaultSubobject<ULightEquipsComponent>(TEXT("LightingsEquipmentsComponent"));
	NightVisionEquipsComponent = CreateDefaultSubobject<UNightVisionEquipsComponent>(TEXT("NightVisionEquipmentsComponent"));
	WeaponEquipsComponent = CreateDefaultSubobject<UWeaponEquipsComponent>(TEXT("WeaponsEquipmentsComponent"));
	CameroidEquipsComponent = CreateDefaultSubobject<UCameroidEquipsComponent>(TEXT("CameroidEquipmentsComponent"));
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



void ACoreGameplay::BeginPlay()
{
	Super::BeginPlay();
	
}

FGameplaySettings ACoreGameplay::GetGameplaySettings_Implementation()
{
	return GameplaySettings;
}

bool ACoreGameplay::IsOnLadder_Implementation()
{
	return bOnLadder;
}

bool ACoreGameplay::IsHelding_Implementation()
{
	return bHelding;
}

bool ACoreGameplay::IsEquipTimelineInProgress_Implementation()
{
	return bEquipTimelineInProgress;
}

void ACoreGameplay::SetEquipTimelineInProgress_Implementation(bool bValue)
{
	bEquipTimelineInProgress = bValue;
}

void ACoreGameplay::SetEquipmentSwitch_Implementation(int Value)
{
	EquipmentSwitch = Value;
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




