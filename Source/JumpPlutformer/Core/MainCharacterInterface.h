// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MainCharacterInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMainCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INSIDER_API IMainCharacterInterface
{
	GENERATED_BODY()

public:

	// overriden in BP_MainPawn
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RotationAfterTeleport(AActor* CurrentPortal, AActor* TargetPortal);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void JumpEvent(float JumpZ);
};
