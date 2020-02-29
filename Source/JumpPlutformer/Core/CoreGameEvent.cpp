// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "CoreGameEvent.h"


ACoreGameEvent::ACoreGameEvent()
{

	PrimaryActorTick.bCanEverTick = false;

}


void ACoreGameEvent::ControllerInput(bool bEnabled)
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

void ACoreGameEvent::GameEventCheck(TEnumAsByte<EEventCheck> CheckEvent)
{
	int Index = 0;
	for (FGameEvents& GameEvent : GameEvents)
	{
		if (GameEvent.TriggerInteraction == CheckEvent)
		{
			GameEvent.Counter++;
			if(GameEvent.AfterTimes == GameEvent.Counter)
			{
				IndexCache.Add(Index);


			}
		}
		Index++;
	}
}

void ACoreGameEvent::BeginPlay()
{
	Super::BeginPlay();
	
}


