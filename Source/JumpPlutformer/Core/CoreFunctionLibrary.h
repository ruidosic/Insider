// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreFunctionLibrary.generated.h"

class UCoreGameplay;
class UTimelineComponent;

UCLASS()
class INSIDER_API UCoreFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION()
	static void SetPlayRate(UTimelineComponent* Timeline, float Sec);

	UFUNCTION(meta = (WorldContext = "WorldContextObject"))
	static ACoreGameplay* GetCoreGameplay(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, Category = Loading)
	static void PlayLoadingScreen(bool bPlayUntilStopped, float PlayTime);

	UFUNCTION(BlueprintCallable, Category = Loading)
	static void StopLoadingScreen();

	//	Need logic!!!
	UFUNCTION()
	static void CloseWidgets();
};
