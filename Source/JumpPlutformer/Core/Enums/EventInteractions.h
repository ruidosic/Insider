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
	EI_OpenON			UMETA(DisplayName = "Open / On"),
	EI_CloseOff			UMETA(DisplayName = "Close / Off"),
	EI_Lock				UMETA(DisplayName = "Lock"),
	EI_Unlock			UMETA(DisplayName = "Unlock")
};
