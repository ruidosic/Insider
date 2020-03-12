// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Gameplay/Structs/GameplaySettings.h"
#include "CoreGameplay.generated.h"


class UTimelineComponent;
class UCurveFloat;

UCLASS()
class INSIDER_API ACoreGameplay : public AActor
{
	GENERATED_BODY()
	
public:	

	ACoreGameplay();

protected:
	
	virtual void BeginPlay() override;

	// Main Configuration Model
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplaySettings GameplaySettings;

public:
	void StartFocus();
	void EndFocus();
	void StopFocus();

	UPROPERTY(BlueprintReadOnly, Category = "Physics")
	bool bHelding = false;

	UPROPERTY(BlueprintReadOnly, Category = "Night Vision")
	bool bNightVisionOff = true;

private:

	//
	// Timeline properties
	//
	UPROPERTY()
	UTimelineComponent* FocusTimeline;
	
	UPROPERTY(EditDefaultsOnly)
	UCurveFloat* SmoothCurveFloat;

	UFUNCTION()
	void FocusTimelineFloatReturn(float Value);

};
