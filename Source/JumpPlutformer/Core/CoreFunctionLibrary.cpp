// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreFunctionLibrary.h"
#include "Components/TimelineComponent.h"
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


void UCoreFunctionLibrary::CloseWidgets()
{
}
