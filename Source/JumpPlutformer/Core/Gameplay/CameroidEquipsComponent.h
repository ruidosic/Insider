// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structs/GameplaySettings.h"
#include "CameroidEquipsComponent.generated.h"

class UTexture;

DECLARE_LOG_CATEGORY_EXTERN(LogCameroidEquipsComponent, Display, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INSIDER_API UCameroidEquipsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UCameroidEquipsComponent();

	/* Cameroid Settings that setup on BeginPlay*/

	bool bHasCameroid;
	bool bInfiniteCameroid;
	float CameroidPhotoShakeDifficulty; // from 0 to 6
	float CameroidFOV;
	TSoftObjectPtr<UTexture> SoftCameroidViewFinderTexture;
	UPROPERTY()
	UTexture* CameroidViewFinderTexture;
	TSoftObjectPtr<USoundBase> SoftCameroidOnSound;
	UPROPERTY()
	USoundBase* CameroidOnSound;
	TSoftObjectPtr<USoundBase> SoftCameroidOffSound;
	UPROPERTY()
	USoundBase* CameroidOffSound;
	TSoftObjectPtr<USoundBase> SoftCameroidShotSound;
	UPROPERTY()
	USoundBase* CameroidShotSound;


	// Get GameplaySettings data from ACoreGameplay and setup it into Cameroid Settings vars
	void SetupDefaults();

	//
	void SetupCameroidSettings(const FCameroidSettings& Cameroid);
	
protected:

	virtual void BeginPlay() override;
	
private:

	UPROPERTY()
	AActor* Owner;
};
