// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreGameEvent.h"
#include "TimerManager.h"
#include "Core/CoreUse.h"

ACoreGameEvent::ACoreGameEvent()
{
	PrimaryActorTick.bCanEverTick = false;
}


//	Used by CoreUse for create game events 
void ACoreGameEvent::CreateGameEvent(FGameEvent & GameEvent)
{
	DestroyCreatedEventsTimer(GameEvent);
	ActorInteractions(GameEvent);
}

// Clean Memory

void ACoreGameEvent::DestroyCreatedEventsTimer(const FGameEvent & GameEvent)
{
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACoreGameEvent::DestroyCreatedEvents, GameEvent.EventsLifetimeSec, false);
}

void ACoreGameEvent::DestroyCreatedEvents()
{

	// Destroy All Spawned Actors
	for (ACoreGameEvent* CoreGameEvent : CoreGameEventsCache)
	{
		CoreGameEvent->Destroy();
	}
	//Destroy Self
	Destroy();
}


// Actor Interactions
void ACoreGameEvent::ActorInteractions(FGameEvent & GameEvent)
{
	if (GameEvent.Environment.ActorInteractions.IsValidIndex(0))
	{
		for (FActorInteraction& ActorInteraction : GameEvent.Environment.ActorInteractions)
		{
			ACoreGameEvent* GE;
			GE = GetWorld()->SpawnActor<ACoreGameEvent>(GetClass(), FVector::ZeroVector, FRotator::ZeroRotator);
			if (GE)
			{
				CoreGameEventsCache.Add(GE);
				GE->ActorInteraction(ActorInteraction);
			}
		}
	}
}

void ACoreGameEvent::ActorInteraction(FActorInteraction & ActorInteraction)
{
	if (ActorInteraction.ActorsToInteract.IsValidIndex(0))
	{
		// Delay Before Interaction
		FTimerDelegate TimerDel;
		FTimerHandle TimerHandle;
		TimerDel.BindUFunction(this, FName("ActorInteractionLoop"), ActorInteraction);
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, ActorInteraction.DelayBeforeInteractionSec, false);
	}

}

void ACoreGameEvent::ActorInteractionLoop(FActorInteraction & ActorInteraction)
{
	switch (ActorInteraction.Interaction)
	{
	case EI_Use:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->Use(true);
		break;
	}
	case EI_AlternativeUse:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->AlternativeUse(true);
		break;
	}
	case EI_OpenOn:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->OpenOn(true);
		break;
	}
	case EI_CloseOff:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->CloseOff(true);
		break;

	}
	case EI_Lock:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->Lock(true);
		break;
	}
	case EI_Unlock:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->Unlock(true);
		break;
	}
	case EI_SliderLock:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->SliderLock(true);
		break;
	}
	case EI_SliderUnlock:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->SliderUnlock(true);
		break;
	}
	case EI_Flicker:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->Flicker(true);
		break;
	}
	case EI_Unflicker:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->Unflicker(true);
		break;
	}
	case EI_Alarm:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->Alarm(true);
		break;
	}
	case EI_Disalarm:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->Disalarm(true);
		break;
	}
	case EI_Explode:
	{
		for (ACoreUse* ActorToInteract : ActorInteraction.ActorsToInteract)
			ActorToInteract->Explode(true);
		break;
	}
	default:
		break;
	}

	// if need repeat
	if (ActorInteraction.RepeatTimes > 0 && !(ActorInteraction.RepeatTimes == InteractionRepeatCounter))
	{
		InteractionRepeatCounter++;

		// Delay before Each Repeat
		FTimerDelegate TimerDel;
		FTimerHandle TimerHandle;
		TimerDel.BindUFunction(this, FName("ActorInteractionLoop"), ActorInteraction);
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, ActorInteraction.DelayBeforeEachRepeatSec, false);
	}
}


//	Actor Transforms
void ACoreGameEvent::ActorTransforms(FGameEvent & GameEvent)
{
	if (GameEvent.Environment.ActorTransforms.IsValidIndex(0))
	{
		for (FActorTransforms& ActorTransform : GameEvent.Environment.ActorTransforms)
		{
			ACoreGameEvent* GE;
			GE = GetWorld()->SpawnActor<ACoreGameEvent>(GetClass(), FVector::ZeroVector, FRotator::ZeroRotator);
			if (GE)
			{
				CoreGameEventsCache.Add(GE);
				GE->ActorTransform(ActorTransform);
			}
		}
	}
}

void ACoreGameEvent::ActorTransform(FActorTransforms & ActorTransform)
{
	if (ActorTransform.ActorToTransform && ActorTransform.TransformSequence.IsValidIndex(0))
	{

	}
}
