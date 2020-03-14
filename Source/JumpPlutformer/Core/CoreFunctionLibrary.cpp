// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreFunctionLibrary.h"
#include "Components/TimelineComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "Core/Gameplay/CoreGameplay.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetArrayLibrary.h"
#include "GameFramework/Pawn.h"


void UCoreFunctionLibrary::SetPlayRate(UTimelineComponent* Timeline, float Sec)
{
	if (!Timeline)
		return;

	if (Sec <= 0)
	{
		Timeline->SetPlayRate(1 / 0.001);
	}
	else
	{
		Timeline->SetPlayRate(1 / Sec);
	}
}


ACoreGameplay * UCoreFunctionLibrary::GetCoreGameplay(UObject* WorldContext)
{
	if (!WorldContext)
		return nullptr;
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(WorldContext, 0);
	if (PlayerPawn)
	{
		TArray<AActor*> ChildActors;
		PlayerPawn->GetAllChildActors(ChildActors);
		if (ChildActors.IsValidIndex(0) && ChildActors.Num() > 0)
		{
			TArray<AActor*> CoreGameplay;
			UKismetArrayLibrary::FilterArray(ChildActors, ACoreGameplay::StaticClass(), CoreGameplay);
			if (CoreGameplay.IsValidIndex(0))
			{
				return Cast<ACoreGameplay>(CoreGameplay[0]);
			}
			UE_LOG(LogTemp, Warning, TEXT("Error: CoreGameplay doesnt exist in MainPawn"))
		}
	}
	return nullptr;
}


void UCoreFunctionLibrary::SetPointlight(UPointLightComponent * Pointlight, FPointlightSettings PointlightSettings)
{
	Pointlight->SetIntensity(PointlightSettings.Intensity);
	Pointlight->SetLightColor(PointlightSettings.LightColor);
	Pointlight->SetAttenuationRadius(PointlightSettings.AttenuationRadius);
	Pointlight->SetSourceRadius(PointlightSettings.SourceRadius);
	Pointlight->SetSourceLength(PointlightSettings.SourceLength);
	Pointlight->SetCastShadows(PointlightSettings.bCastShadow);
	if (PointlightSettings.IESTexture.IsValid())
	{
		Pointlight->SetIESTexture(PointlightSettings.IESTexture.LoadSynchronous());
	}
}

void UCoreFunctionLibrary::SetSpotlight(USpotLightComponent * Spotlight, FSpotlightSettings SpotlightSettings)
{
	Spotlight->SetIntensity(SpotlightSettings.Intensity);
	Spotlight->SetLightColor(SpotlightSettings.LightColor);
	Spotlight->SetInnerConeAngle(SpotlightSettings.InnerConeAngle);
	Spotlight->SetOuterConeAngle(SpotlightSettings.OuterConeAngle);
	Spotlight->SetAttenuationRadius(SpotlightSettings.AttenuationRadius);
	Spotlight->SetSourceRadius(SpotlightSettings.SourceRadius);
	Spotlight->SetSourceLength(SpotlightSettings.SourceLength);
	Spotlight->SetCastShadows(SpotlightSettings.bCastShadow);
	if (SpotlightSettings.IESTexture.IsValid())
	{
		Spotlight->SetIESTexture(SpotlightSettings.IESTexture.LoadSynchronous());
	}
}


void UCoreFunctionLibrary::CloseWidgets()
{
}
