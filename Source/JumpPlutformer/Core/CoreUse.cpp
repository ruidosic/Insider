// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreUse.h"

// Sets default values
ACoreUse::ACoreUse()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoreUse::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoreUse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

