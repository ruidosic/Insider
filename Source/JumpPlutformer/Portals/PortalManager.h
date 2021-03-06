// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PortalManager.generated.h"

class AAdvancedPortal;
class UTexture;
class USceneCaptureComponent2D;
class UCanvasRenderTarget2D;
class ACorePlayerController;

UCLASS()
class INSIDER_API APortalManager : public AActor
{
	GENERATED_BODY()
	
public:	
	APortalManager();

	//Called by a Portal actor when wanting to teleport something
	UFUNCTION(BlueprintCallable)
	void RequestTeleportByPortal(AAdvancedPortal* Portal, AActor* TargetToTeleport);

	//Save a reference to the PlayerControler
	void SetControllerOwner(ACorePlayerController* NewOwner);

	//Various setup that happens during spawn
	void Init();

	//Manual Tick
	void Update(float DeltaTime);

	//Find all the portals in world and update them
	//returns the most valid/usable one for the Player
	AAdvancedPortal* UpdatePortalsInWorld();

	//Update SceneCapture
	void UpdateCapture(AAdvancedPortal* Portal);

	void ChangeSceneCaptureRotation(AAdvancedPortal * Portal, AActor * Target);

	void ChangeSceneCaptureLocation(AAdvancedPortal * Portal, AActor * Target);


protected:
	virtual void BeginPlay() override;


private:
	//Function to create the Portal render target
	void GeneratePortalTexture();

	UPROPERTY()
	USceneCaptureComponent2D* SceneCapture;

	UPROPERTY()
	UCanvasRenderTarget2D*	PortalTexture;

	UPROPERTY()
	ACorePlayerController* ControllerOwner;

	int32 PreviousScreenSizeX;
	int32 PreviousScreenSizeY;

	float UpdateDelay;
};
