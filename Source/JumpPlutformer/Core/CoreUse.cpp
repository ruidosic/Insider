// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreUse.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Core/CoreGameEvent.h"

ACoreUse::ACoreUse()
{
	PrimaryActorTick.bCanEverTick = false;
}


void ACoreUse::ControllerInput(bool bEnabled)
{
	APlayerController* PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerController)
	{
		if (bEnabled)
		{
			EnableInput(PlayerController);
		}
		else
		{
			DisableInput(PlayerController);
		}
	}
}

void ACoreUse::GameEventCheck(TEnumAsByte<EEventCheck> CheckEvent)
{
	TArray<int> IndexCache;

	int Index = 0;
	
	// Loop for detect indexes for cache
	for (FGameEvents& GameEvent : GameEvents)
	{
		// we countered all matching, if this counter == AfterTimes, then we do event once or not. 
		if (GameEvent.TriggerInteraction == CheckEvent)
		{
			GameEvent.Counter++;
			if (GameEvent.AfterTimes == GameEvent.Counter)
			{
				IndexCache.Add(Index);
				if (!GameEvent.bDoOnce)
				{
					GameEvent.Counter = 0;
				}
			}
		}
		Index++;
	}

	//Loop for create game events by cached indexes
	for (const int& i : IndexCache)
	{
		ACoreGameEvent* GE;
		GE = GetWorld()->SpawnActor<ACoreGameEvent>(ACoreGameEvent::StaticClass(), 
													FVector::ZeroVector, FRotator::ZeroRotator);

		GE->CreateGameEvent(GameEvents[i].GameEvent);
	}
}



void ACoreUse::BeginPlay()
{
	Super::BeginPlay();
	
}


	///	Empty functions

void ACoreUse::Use(bool bGameEvent)
{
}

void ACoreUse::AlternativeUse(bool bGameEvent)
{
}

void ACoreUse::OpenOn(bool bGameEvent)
{
}

void ACoreUse::CloseOff(bool bGameEvent)
{
}

void ACoreUse::Lock(bool bGameEvent)
{
}

void ACoreUse::Unlock(bool bGameEvent)
{
}

void ACoreUse::SliderLock(bool bGameEvent)
{
}

void ACoreUse::SliderUnlock(bool bGameEvent)
{
}

void ACoreUse::Alarm(bool bGameEvent)
{
}

void ACoreUse::Disalarm(bool bGameEvent)
{
}

void ACoreUse::Flicker(bool bGameEvent)
{
}

void ACoreUse::Unflicker(bool bGameEvent)
{
}

void ACoreUse::TakeKey(bool bGameEvent)
{
}

void ACoreUse::TakePhoto(bool bGameEvent)
{
}

void ACoreUse::Explode(bool bGameEvent)
{
}


