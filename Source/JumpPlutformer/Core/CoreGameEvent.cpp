// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreGameEvent.h"

ACoreGameEvent::ACoreGameEvent()
{

	PrimaryActorTick.bCanEverTick = false;

}




void ACoreGameEvent::CreateGameEvent(const FGameEvent & GameEvent)
{
}

void ACoreGameEvent::BeginPlay()
{
	Super::BeginPlay();
	
}


