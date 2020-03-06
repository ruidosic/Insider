// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreGameEvent.h"
#include "TimerManager.h"
#include "Core/CoreFunctionLibrary.h"
#include "Components/TimelineComponent.h"
#include "Core/CoreUse.h"
#include "UObject/ConstructorHelpers.h"
#include "Core/Pickups/Interfaces/CorePhysicsObjectInterface.h"
#include "Kismet/GameplayStatics.h"

ACoreGameEvent::ACoreGameEvent()
{
	PrimaryActorTick.bCanEverTick = false;
	
	// Setup Curves
	static ConstructorHelpers::FObjectFinder<UCurveFloat> DefaultLinearFloatCurveObject(TEXT("/Game/Insider/Curve_DefaultLinear_Float"));
	static ConstructorHelpers::FObjectFinder<UCurveFloat> DefaultSmoothFloatCurveObject(TEXT("/Game/Insider/Curve_DefaultSmooth_Float"));

	if (DefaultLinearFloatCurveObject.Succeeded())
	{
		DefaultLinearFloatCurve = DefaultLinearFloatCurveObject.Object;
	}
	if (DefaultSmoothFloatCurveObject.Succeeded())
	{
		DefaultSmoothFloatCurve = DefaultSmoothFloatCurveObject.Object;
	}

	// Setup Timelines
	ActorTransformTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Actor Transform Timeline"));
}


//	Used by CoreUse for create game events 
void ACoreGameEvent::CreateGameEvent(FGameEvent & GameEvent)
{
	DestroyCreatedEventsTimer(GameEvent);
	ActorInteractions(GameEvent);
	ActorTransforms(GameEvent);
	SpawnActors(GameEvent);
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
void ACoreGameEvent::ActorInteractions(FGameEvent& GameEvent)
{
	if (GameEvent.Environment.ActorInteractions.IsValidIndex(0))
	{
		for (FActorInteraction& ActorInteraction : GameEvent.Environment.ActorInteractions)
		{
			ACoreGameEvent* GE;
			GE = GetWorld()->SpawnActor<ACoreGameEvent>(GetClass(), FVector::ZeroVector, FRotator::ZeroRotator);
			if (GE)
			{
				GE->ActorInteraction(ActorInteraction);
				CoreGameEventsCache.Add(GE);
			}
		}
	}
}

void ACoreGameEvent::ActorInteraction(FActorInteraction& ActorInteraction)
{
	AI = ActorInteraction;
	if (AI.ActorsToInteract.IsValidIndex(0) && AI.ActorsToInteract[0])
	{
		// Delay Before Interaction
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACoreGameEvent::ActorInteractionLoop, AI.DelayBeforeInteractionSec, false);
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
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACoreGameEvent::ActorInteractionLoop, AI.DelayBeforeEachRepeatSec, false);
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
	AT = ActorTransform;
	if (AT.ActorToTransform && AT.TransformSequence.IsValidIndex(0))
	{

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACoreGameEvent::ActorTransformLoop, AT.DelayBeforeTransformSequenceSec, false);
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

		// this two line is a Component Dynamic Creation, instead ActorTransformTimeline = CreateDefaultSubobject<>() in constructor (but it's not working)
		//ActorTransformTimeline = NewObject<UTimelineComponent>(this, FName("Actor Transform Timeline"));
		//ActorTransformTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript;

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


// Spawn Actors
void ACoreGameEvent::SpawnActors(FGameEvent & GameEvent)
{
	if (GameEvent.Environment.SpawnActors.IsValidIndex(0))
	{
		for (FSpawnActors& SpawnActor : GameEvent.Environment.SpawnActors)
		{
			ACoreGameEvent* GE;
			GE = GetWorld()->SpawnActor<ACoreGameEvent>(GetClass(), FVector::ZeroVector, FRotator::ZeroRotator);
			if (GE)
			{
				GE->SpawnActor(SpawnActor);
				CoreGameEventsCache.Add(GE);
			}
		}
	}
}

void ACoreGameEvent::SpawnActor(FSpawnActors & SpawnActor)
{
	SA = SpawnActor;
	if(SA.SpawnedActorClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Soft Subclass is Valid"));
		FTimerHandle Timer;
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &ACoreGameEvent::SpawnActorAfterDelay, SA.DelayBeforeSpawnActorSec, false);
	}
}

void ACoreGameEvent::SpawnActorAfterDelay()
{
	FActorSpawnParameters SpawnParam;
	SpawnParam.SpawnCollisionHandlingOverride = SA.CollisionHandling;
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(SA.SpawnedActorClass, SA.SpawnTransform, SpawnParam);
	
	// Add Tag to SpawnedActor
	if (SpawnedActor && SA.SpawnedActorTags.IsValidIndex(0))
	{
		SpawnedActor->Tags = SA.SpawnedActorTags;
	}

	// Attach Spawned Actor to another actor
	if (SA.OptionalAttachTo.AttachTo)
	{
		TArray<UActorComponent*> ActorComponents;
		ActorComponents = SA.OptionalAttachTo.AttachTo->GetComponentsByTag(UPrimitiveComponent::StaticClass(), SA.OptionalAttachTo.ParentComponentByTag);
		if (ActorComponents.IsValidIndex(0) && ActorComponents[0])
		{
			UPrimitiveComponent* CompToAttach;
			CompToAttach = Cast<UPrimitiveComponent>(ActorComponents[0]);
			if (CompToAttach)
			{
				SpawnedActor->AttachToComponent(CompToAttach,
					FAttachmentTransformRules(SA.OptionalAttachTo.LocationRule, SA.OptionalAttachTo.RotationRule, SA.OptionalAttachTo.ScaleRule, true),
					SA.OptionalAttachTo.SocketName);
			}
		}
	}
		
}


 // Availability Actors
void ACoreGameEvent::ActorAvailabilities(FGameEvent & GameEvent)
{
	if (GameEvent.Environment.ActorAvailabilities.IsValidIndex(0))
	{
		for (FActorsAvailability& ActorAvailability : GameEvent.Environment.ActorAvailabilities)
		{
			ACoreGameEvent* GE;
			GE = GetWorld()->SpawnActor<ACoreGameEvent>(GetClass(), FVector::ZeroVector, FRotator::ZeroRotator);
			if (GE)
			{
				GE->ActorAvailability(ActorAvailability);
			}
		}
	}
}

void ACoreGameEvent::ActorAvailability(FActorsAvailability & ActorAvailability)
{
	AA = ActorAvailability;
	if (AA.ActorsToChange.IsValidIndex(0))
	{
		FTimerHandle Timer;
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &ACoreGameEvent::ActorAvailabilityAfterDelay, AA.DelayBeforeChange, false);
	}
}

void ACoreGameEvent::ActorAvailabilityAfterDelay()
{
	// Visibility/Collision/Destroy/ReleaseIfPhysicsObject for ActorsToChange
	if (AA.ActorsToChange.IsValidIndex(0))
	{
		for (AActor* ActorToChange : AA.ActorsToChange)
		{
			if (AA.bSkipAllSettingsAndDestroy && ActorToChange)
			{
				ActorToChange->Destroy();
			}
			if (!AA.bSkipAllSettingsAndDestroy && ActorToChange)
			{
				ActorToChange->SetActorHiddenInGame(AA.bHiddenInGame);
				ActorToChange->SetActorEnableCollision(!AA.bDisableCollision);
				if (ActorToChange->Implements<UCorePhysicsObjectInterface>())
				{
					ICorePhysicsObjectInterface::Execute_Release(ActorToChange);
				}
			}
		}
	}


	// Visibility/Collision/Destroy/ReleaseIfPhysicsObject for TaggedActors
	if (AA.ActorsWithTagToChange.IsValidIndex(0))
	{
		for (const FName& Tag : AA.ActorsWithTagToChange)
		{
			TArray<AActor*> Actors;
			UGameplayStatics::GetAllActorsWithTag(this, Tag, Actors);
			if (Actors.IsValidIndex(0))
			{
				for (AActor* Actor : Actors)
				{
					if (AA.bSkipAllSettingsAndDestroy && Actor)
					{
						Actor->Destroy();
					}
					if (!AA.bSkipAllSettingsAndDestroy && Actor)
					{
						Actor->SetActorHiddenInGame(AA.bHiddenInGame);
						Actor->SetActorEnableCollision(!AA.bDisableCollision);
						if (Actor->Implements<UCorePhysicsObjectInterface>())
						{
							ICorePhysicsObjectInterface::Execute_Release(Actor);
						}
					}
				}
			}
		}
	}
}
	
