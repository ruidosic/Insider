// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Core/MainCharacterInterface.h"
#include "CoreMainCharacter.generated.h"


class ACorePlayerController;
class UInputComponent;
class UChildActorComponent;
class UCameraComponent;

UCLASS()
class INSIDER_API ACoreMainCharacter : public ACharacter, public IMainCharacterInterface
{
	GENERATED_BODY()

public:

	ACoreMainCharacter();

protected:

	virtual void BeginPlay() override;

public:	
	
	UPROPERTY()
	ACorePlayerController* PC;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UChildActorComponent* CoreGameplay;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* PlayerCamera;


	virtual void RotationAfterTeleport_Implementation(AActor* CurrentPortal, AActor* TargetPortal) override;
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;

private:

	// Input Axes 

	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void LookUp(float Value);

	UFUNCTION()
	void Turn(float Value);
};
