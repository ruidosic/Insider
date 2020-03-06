// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/CoreUse.h"
#include "Core/Pickups/Interfaces/CorePhysicsObjectInterface.h"
#include "CorePhysicsObject.generated.h"

/**
 * 
 */
UCLASS()
class INSIDER_API ACorePhysicsObject : public ACoreUse, public ICorePhysicsObjectInterface
{
	GENERATED_BODY()
	
public:

	virtual void Release_Implementation() override;
};
