// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreFunctionLibrary.h"
#include "Components/TimelineComponent.h"

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