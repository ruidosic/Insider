// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Core/CorePlayerController.h"
#include "Core/Gameplay/CoreGameplay.h"
#include "Portals/PortalManager.h"
#include "Components/ChildActorComponent.h"
#include "Camera/CameraComponent.h"


ACoreMainCharacter::ACoreMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PC = nullptr;

	// Setup Camera
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	PlayerCamera->RelativeLocation = FVector(0.0, 0.0, 64.0);
	PlayerCamera->bUsePawnControlRotation = true;

	// Setup Gameplay
	CoreGameplay = CreateDefaultSubobject<UChildActorComponent>(TEXT("Core Gameplay"));
	CoreGameplay->SetChildActorClass(ACoreGameplay::StaticClass());
	CoreGameplay->SetupAttachment(PlayerCamera);
}


void ACoreMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Set Player Controller to get access to PortalManager
	PC = Cast<ACorePlayerController>(UGameplayStatics::GetPlayerController(this, 0));
}



void ACoreMainCharacter::RotationAfterTeleport_Implementation(AActor * CurrentPortal, AActor * TargetPortal)
{
}


void ACoreMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
	if (PC && PC->PortalManager)
	{
		PC->PortalManager->Update(DeltaTime); 
	}
}


// Setup Move and Look 

void ACoreMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Moving
	PlayerInputComponent->BindAxis("MoveForward", this, &ACoreMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACoreMainCharacter::MoveRight);

	// Looking
	PlayerInputComponent->BindAxis("Turn", this, &ACoreMainCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ACoreMainCharacter::LookUp);
}

void ACoreMainCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value, false);
}

void ACoreMainCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value, false);
}

void ACoreMainCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ACoreMainCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

