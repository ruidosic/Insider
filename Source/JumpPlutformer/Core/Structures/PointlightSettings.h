// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Math/Color.h"
#include "Engine/TextureLightProfile.h"
#include "PointlightSettings.generated.h"


USTRUCT(BlueprintType)
struct FPointlightSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	float Intensity = 5000.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	FLinearColor LightColor = FLinearColor(FVector4(1.0, 0.92, 0.82, 1.0));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	float AttenuationRadius = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	float SourceRadius = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	float SourceLength = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	bool bCastShadow = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointlight Settings")
	UTextureLightProfile* IESTexture;
	
};
