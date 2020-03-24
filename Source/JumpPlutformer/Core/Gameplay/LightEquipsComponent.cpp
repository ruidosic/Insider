// Fill out your copyright notice in the Description page of Project Settings.


#include "LightEquipsComponent.h"
#include "Core/Gameplay/GameplayInterface.h"
#include "UObject/ConstructorHelpers.h"
#include "Curves/CurveFloat.h"
#include "Components/TimelineComponent.h"
#include "Core/CoreFunctionLibrary.h"


DEFINE_LOG_CATEGORY(LogLightEquipsComponent)

ULightEquipsComponent::ULightEquipsComponent()
{
	Owner = GetOwner();

	GlowstickEquipTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));

	static ConstructorHelpers::FObjectFinder<UCurveFloat> DefaultSmoothFloatCurveObject(TEXT("/Game/Insider/Curve_DefaultSmooth_Float"));
	if (DefaultSmoothFloatCurveObject.Succeeded())
	{
		DefaultSmoothFloatCurve = DefaultSmoothFloatCurveObject.Object;
	}
	else
	{
		UE_LOG(LogLightEquipsComponent, Warning, TEXT("ULightEquipsComponent::ULightEquipsComponent -- not found Curve_DefaultSmooth_Float object at the specified path"));
	}


}

		/* Setup all Settings Variables from Owner's FGameplaySettings*/

void ULightEquipsComponent::SetupDefaults()
{
	if (Owner)
	{
		if(Owner->Implements<UGameplayInterface>())
		{
			FGameplaySettings GameplaySettings = IGameplayInterface::Execute_GetGameplaySettings(Owner);
			SetupLightingEquips(GameplaySettings.EquipmentSettings);
		}
		else
		{
			UE_LOG(LogLightEquipsComponent, Warning, TEXT("ULightEquipsComponent::SetupDefaults -- Missing IGameplayInterface implementation for: %s"), *GetOwner()->GetFullName());
		}
	}
	else
	{
		UE_LOG(LogLightEquipsComponent, Warning, TEXT("ULightEquipsComponent::SetupDefaults -- Cant Find Owner!"));
	}
}

void ULightEquipsComponent::SetupLightingEquips(const FEquipmentSettings & Equipment)
{
	SetupGlowstickSettings(Equipment.Glowstick);
	SetupFlashlightSettings(Equipment.Flashlight);
	SetupLighterSettings(Equipment.Lighter);
	SetupTorchSettings(Equipment.Torch);
}

void ULightEquipsComponent::SetupGlowstickSettings(const FGlowstickSettings& Glowstick)
{
	bHasGlowstick = Glowstick.bHas;
	bInfiniteGlowstick = Glowstick.bInfinite;
	GlowstickDurationMinute = Glowstick.DurationMinute;
	GlowstickEmissiveIntensity = Glowstick.EmissiveIntensity;
	GlowstickIntensity = Glowstick.LightSettings.Intensity;
}

void ULightEquipsComponent::SetupFlashlightSettings(const FFlashlightSettings & Flashlight)
{
}

void ULightEquipsComponent::SetupLighterSettings(const FLighterSettings & Lighter)
{
}

void ULightEquipsComponent::SetupTorchSettings(const FTorchSettings & Torch)
{
}

void ULightEquipsComponent::SetupGlowstickAsyncSettings()
{
	/*UCoreFunctionLibrary::SetPointlight(, GlowstickLight);*/
}

			/* Glowstick functions for equipping */

void ULightEquipsComponent::TakeGlowstick()
{
	bHasGlowstick = true;
}

void ULightEquipsComponent::EquipGlowstick(bool bSilent)
{
	
	if (Owner->Implements<UGameplayInterface>())
	{
		// Get needed variables from Gameplay (Owner) for check

		bool bEquipmentTimelineInProgress = IGameplayInterface::Execute_IsEquipTimelineInProgress(Owner);
		bool bOnLadder = IGameplayInterface::Execute_IsOnLadder(Owner);
		bool bHelding = IGameplayInterface::Execute_IsHelding(Owner);

		// Check that we can equip Glowstick
		if (!bEquipmentTimelineInProgress && !bHelding && !bOnLadder)
		{
			// Check that glowstick in inventory
			if (bHasGlowstick)
			{

				if(GlowstickRemainingLifeProc > 0)
				{
				
				}
			}
		}
	}
	return;

	FOnTimelineFloat OnTimelineCallback;
	FOnTimelineEventStatic OnTimelineFinishedCallback;
	
	OnTimelineCallback.BindUFunction(this, FName{ TEXT("OnEquipGlowstick") });
	OnTimelineFinishedCallback.BindUFunction(this, FName{ TEXT("OnEquipGlowstickFinished") });
	if (GlowstickEquipTimeline)
	{
		if (DefaultSmoothFloatCurve)
		{
			GlowstickEquipTimeline->AddInterpFloat(DefaultSmoothFloatCurve, OnTimelineCallback);
			GlowstickEquipTimeline->SetTimelineFinishedFunc(OnTimelineFinishedCallback);
			GlowstickEquipTimeline->SetTimelineLength(1.0);
			GlowstickEquipTimeline->SetLooping(false);
			GlowstickEquipTimeline->PlayFromStart();
		}
		else
		{
			UE_LOG(LogLightEquipsComponent, Warning, TEXT("ULightEquipsComponent::EquipGlowstick -- not found Curve_DefaultSmooth_Float object at the specified path"));
		}
	}
}

// Glowstick Equip Timeline Bindings

void ULightEquipsComponent::OnEquipGlowstick(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), Value);
}

void ULightEquipsComponent::OnEquipGlowstickFinished()
{

}



void ULightEquipsComponent::BeginPlay()
{
	Super::BeginPlay();
	SetupDefaults();
}



