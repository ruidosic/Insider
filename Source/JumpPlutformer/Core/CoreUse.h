// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Enums/EventCheck.h"
#include "Core/Structures/GameEvents.h"
#include "CoreUse.generated.h"

UCLASS()
class INSIDER_API ACoreUse : public AActor
{
	GENERATED_BODY()
	
public:	

	ACoreUse();

	// Enable or Disable Player's Input
	void ControllerInput(bool bEnabled);

	UFUNCTION(BlueprintCallable)
	void GameEventCheck(TEnumAsByte<EEventCheck> CheckEvent);

protected:

	UPROPERTY(BlueprintReadOnly)
	bool bInteractionEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGameEvents> GameEvents;

public:

	// Interactions that will be overriden by child

	UFUNCTION()
	virtual void Use(bool bGameEvent);
	UFUNCTION()
	virtual void AlternativeUse(bool bGameEvent);

	UFUNCTION()
	virtual void OpenOn(bool bGameEvent);
	UFUNCTION()
	virtual void CloseOff(bool bGameEvent);
	
	UFUNCTION()
	virtual void Lock(bool bGameEvent);
	UFUNCTION()
	virtual void Unlock(bool bGameEvent);
	
	UFUNCTION()
	virtual void SliderLock(bool bGameEvent);
	UFUNCTION()
	virtual void SliderUnlock(bool bGameEvent);
	
	UFUNCTION()
	virtual void Alarm(bool bGameEvent);
	UFUNCTION()
	virtual void Disalarm(bool bGameEvent);
	
	UFUNCTION()
	virtual void Flicker(bool bGameEvent);
	UFUNCTION()
	virtual void Unflicker(bool bGameEvent);

	UFUNCTION()
	virtual void TakeKey(bool bGameEvent);
	UFUNCTION()
	virtual void TakePhoto(bool bGameEvent);

	UFUNCTION()
	virtual void Explode(bool bGameEvent);
};
