// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreGameEvent.h"
#include "TimerManager.h"
#include "Core/CoreFunctionLibrary.h"
#include "Components/TimelineComponent.h"
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
	ActorTransforms(GameEvent);
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
		AI = ActorInteraction;
		// Delay Before Interaction
		FTimerDelegate TimerDel;
		FTimerHandle TimerHandle;
		TimerDel.BindUFunction(this, FName{ TEXT("ActorInteractionLoop") }, ActorInteraction);
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, ActorInteraction.DelayBeforeInteractionSec, false);
	}

}

void ACoreGameEvent::ActorInteractionLoop()
{
	switch (AI.Interaction)
	{
	case EI_Use:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->Use(true);
		break;
	}
	case EI_AlternativeUse:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->AlternativeUse(true);
		break;
	}
	case EI_OpenOn:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->OpenOn(true);
		break;
	}
	case EI_CloseOff:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->CloseOff(true);
		break;

	}
	case EI_Lock:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->Lock(true);
		break;
	}
	case EI_Unlock:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->Unlock(true);
		break;
	}
	case EI_SliderLock:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->SliderLock(true);
		break;
	}
	case EI_SliderUnlock:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->SliderUnlock(true);
		break;
	}
	case EI_Flicker:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->Flicker(true);
		break;
	}
	case EI_Unflicker:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->Unflicker(true);
		break;
	}
	case EI_Alarm:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->Alarm(true);
		break;
	}
	case EI_Disalarm:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->Disalarm(true);
		break;
	}
	case EI_Explode:
	{
		for (ACoreUse* ActorToInteract : AI.ActorsToInteract)
			ActorToInteract->Explode(true);
		break;
	}
	default:
		break;
	}

	// if need repeat
	if (AI.RepeatTimes > 0 && !(AI.RepeatTimes == InteractionRepeatCounter))
	{
		InteractionRepeatCounter++;

		// Delay before Each Repeat
		FTimerDelegate TimerDel;
		FTimerHandle TimerHandle;
		TimerDel.BindUFunction(this, FName{ TEXT("ActorInteractionLoop") });
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, AI.DelayBeforeEachRepeatSec, false);
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
		AT = ActorTransform;
		FTimerDelegate TimerDel;
		FTimerHandle TimerHandle;
		TimerDel.BindUFunction(this, FName{ TEXT("ActorTransformLoop") });
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, ActorTransform.DelayBeforeTransformSequenceSec, false);
	}
}

void ACoreGameEvent::ActorTransformLoop()
{
	ActorCurrentTransform = AT.ActorToTransform->GetActorTransform();
	
	FOnTimelineFloat OnTimelineCallback;
	FOnTimelineEventStatic OnTimelineFinishedCallback;

	// Setup Actor Transform Timeline
	if (DefaultLinearFloatCurve && DefaultSmoothFloatCurve)
	{

		// this two line is a Component Dynamic Creation, instead ActorTransformTimeline = DefaultSubobject<>() in constructor
		ActorTransformTimeline = NewObject<UTimelineComponent>(this, FName("Actor Transform Timeline"));
		ActorTransformTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript;

		// Bind Functions to Callback
		OnTimelineCallback.BindUFunction(this, FName{ TEXT("OnActorTransformFloatReturn") });
		OnTimelineFinishedCallback.BindUFunction(this, FName{ TEXT("OnActorTransformFinished") });

		//Setup Timeline Settings
		UCoreFunctionLibrary::SetPlayRate(ActorTransformTimeline, AT.TransformSequence[TransformSequenceCounter].TransformDurationSec);
		ActorTransformTimeline->SetTimelineLength(1.0);
		ActorTransformTimeline->SetLooping(false);
		ActorTransformTimeline->SetIgnoreTimeDilation(true);
		if (AT.TransformSequence[TransformSequenceCounter].bSmooth)
		{
			ActorTransformTimeline->AddInterpFloat(DefaultSmoothFloatCurve, OnTimelineCallback, FName("Smooth")); // Add Smooth float curve
		}
		else
		{
			ActorTransformTimeline->AddInterpFloat(DefaultLinearFloatCurve, OnTimelineCallback, FName("Direct")); // Add Direct float curve
		}
		ActorTransformTimeline->SetTimelineFinishedFunc(OnTimelineFinishedCallback);
		
		// Start Timeline
		ActorTransformTimeline->PlayFromStart();
	}
}

void ACoreGameEvent::OnActorTransformFloatReturn(float Value)
{
	const FTransform ActorTargetTransform = AT.TransformSequence[TransformSequenceCounter].TransformTo;
	
	FVector NewLocation = FMath::Lerp(ActorCurrentTransform.GetLocation(), ActorTargetTransform.GetLocation(), Value);
	FQuat NewRotation = FMath::Lerp(ActorCurrentTransform.GetRotation(), ActorTargetTransform.GetRotation(), Value);
	FVector NewScale = FMath::Lerp(ActorCurrentTransform.GetScale3D(), ActorTargetTransform.GetScale3D(), Value);
	FTransform NewTransform = FTransform(NewRotation, NewLocation, NewScale);
	AT.ActorToTransform->SetActorTransform(NewTransform, false);
}

void ACoreGameEvent::OnActorTransformFinished()
{
	if ((AT.TransformSequence.Num() - 1) == TransformSequenceCounter)
	{
		TransformSequenceCounter = 0;
	}
	else
	{
		TransformSequenceCounter++;
		ActorTransformLoop();
	}
}

