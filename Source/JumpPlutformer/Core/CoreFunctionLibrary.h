// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Structures/PointlightSettings.h"
#include "Core/Structures/SpotlightSettings.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreFunctionLibrary.generated.h"

class UCoreGameplay;
class UTimelineComponent;
class UPointLightComponent;
class USpotLightComponent;

UCLASS()
class INSIDER_API UCoreFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION()
	static void SetPlayRate(UTimelineComponent* Timeline, float Sec);

	UFUNCTION(meta = (WorldContext = "WorldContextObject"))
	static ACoreGameplay* GetCoreGameplay(UObject* WorldContext);

	UFUNCTION()
	static void SetPointlight(UPointLightComponent* Pointlight, FPointlightSettings PointlightSettings);

	UFUNCTION()
	static void SetSpotlight(USpotLightComponent* Spotlight, FSpotlightSettings SpotlightSettings);

	//	Need logic!!!
	UFUNCTION()
	static void CloseWidgets();




};
