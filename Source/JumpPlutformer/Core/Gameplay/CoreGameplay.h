// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoreGameplay.generated.h"

UCLASS()
class INSIDER_API ACoreGameplay : public AActor
{
	GENERATED_BODY()
	
public:	

	ACoreGameplay();

protected:
	
	virtual void BeginPlay() override;

public:
	void StartFocus();
	void EndFocus();
	void StopFocus();
};
