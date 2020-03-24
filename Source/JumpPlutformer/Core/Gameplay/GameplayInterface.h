// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Core/Gameplay/Structs/GameplaySettings.h"
#include "GameplayInterface.generated.h"


UINTERFACE(MinimalAPI)
class UGameplayInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INSIDER_API IGameplayInterface
{
	GENERATED_BODY()

	
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FGameplaySettings GetGameplaySettings();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsOnLadder();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsHelding();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsEquipTimelineInProgress();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetEquipTimelineInProgress(bool bValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetEquipmentSwitch(int Value);
};
