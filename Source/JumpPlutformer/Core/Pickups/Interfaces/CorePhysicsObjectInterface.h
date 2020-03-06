// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CorePhysicsObjectInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCorePhysicsObjectInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INSIDER_API ICorePhysicsObjectInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Release();
};
