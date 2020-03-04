// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EventInteractions.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EEventInteractions 
{
	EI_None				UMETA(DisplayName = "Nothing"),
	EI_Use				UMETA(DisplayName = "Use"),
	EI_AlternativeUse	UMETA(DisplayName = "AlternativeUse"),
	EI_OpenOn			UMETA(DisplayName = "Open / On"),
	EI_CloseOff			UMETA(DisplayName = "Close / Off"),
	EI_Lock				UMETA(DisplayName = "Lock"),
	EI_Unlock			UMETA(DisplayName = "Unlock"),
	EI_SliderLock		UMETA(DisplayName = "Slider Lock"),
	EI_SliderUnlock		UMETA(DisplayName = "Slider Unlock"),
	EI_Flicker			UMETA(DisplayName = "Flicker"),
	EI_Unflicker		UMETA(DisplayName = "Unflicker"),
	EI_Alarm			UMETA(DisplayName = "Alarm"),
	EI_Disalarm			UMETA(DisplayName = "Disalarm"),
	EI_Explode			UMETA(DisplayName = "Explode")
};
