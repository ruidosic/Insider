// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Math/Color.h"
#include "Engine/TextureLightProfile.h"
#include "UObject/SoftObjectPtr.h"
#include "SpotlightSettings.generated.h"



USTRUCT(BlueprintType)
struct FSpotlightSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	float Intensity = 5000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	FLinearColor LightColor = FLinearColor(FVector4(1, 0.92, 0.82, 1));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	float InnerConeAngle = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	float OuterConeAngle = 44;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	float AttenuationRadius = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	float SourceRadius = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	float SourceLength = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	bool bCastShadow = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spotlight Settings")
	TSoftObjectPtr<UTextureLightProfile> IESTexture;
};
