// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreAssetManager.h"
#include "Engine/Engine.h"

void UCoreAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
}


UCoreAssetManager & UCoreAssetManager::Get()
{
	UCoreAssetManager* This = Cast<UCoreAssetManager>(GEngine->AssetManager);
	if (This)
	{
		return *This;
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, must be CoreAssetManager!"));
		return *NewObject<UCoreAssetManager>(); // never calls this
	}
}
