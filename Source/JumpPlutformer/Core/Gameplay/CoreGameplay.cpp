// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameplay.h"
#include "Components/TimelineComponent.h"
#include "UObject/ConstructorHelpers.h"

ACoreGameplay::ACoreGameplay()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UCurveFloat> SmoothCurveFloatObject(TEXT("/Game/Insider/Curve_DefaultSmooth_Float"));

	// Setup Curves
	if (SmoothCurveFloatObject.Succeeded())
	{
		SmoothCurveFloat = SmoothCurveFloatObject.Object;
	}

	// Setup Timelines
	FocusTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Focus Timeline"));

}


void ACoreGameplay::BeginPlay()
{
	Super::BeginPlay();
	
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




