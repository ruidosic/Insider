// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreFunctionLibrary.h"
#include "Components/TimelineComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "Core/Gameplay/CoreGameplay.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetArrayLibrary.h"
#include "GameFramework/Pawn.h"
#include "InsiderLoadingScreen.h"
#include "Materials/MaterialInstanceConstant.h"
#include "UObject/SoftObjectPtr.h"
#include "CoreAssetManager.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogCoreFunctionLibrary)

// Set timelines PlayRate in sec
void UCoreFunctionLibrary::SetPlayRate(UTimelineComponent* Timeline, float Sec)
{
	if (!Timeline)
		return;

	if (Sec <= 0)
	{
		Timeline->SetPlayRate(1 / 0.001);
	}
	else
	{
		Timeline->SetPlayRate(1 / Sec);
	}
}


// Get MainPlayer's ChildActor class (it is ACoreGameplay) 
ACoreGameplay * UCoreFunctionLibrary::GetCoreGameplay(UObject* WorldContext)
{
	if (!WorldContext)
	{
		return nullptr;
	}
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(WorldContext, 0);
	if (PlayerPawn)
	{
		TArray<AActor*> ChildActors;
		PlayerPawn->GetAllChildActors(ChildActors);
		if (ChildActors.IsValidIndex(0) && ChildActors.Num() > 0)
		{
			TArray<AActor*> CoreGameplay;
			UKismetArrayLibrary::FilterArray(ChildActors, ACoreGameplay::StaticClass(), CoreGameplay);
			if (CoreGameplay.IsValidIndex(0))
			{
				return Cast<ACoreGameplay>(CoreGameplay[0]);
			}
			UE_LOG(LogCoreFunctionLibrary, Warning, TEXT("UCoreFunctionLibrary::GetCoreGameplay -- CoreGameplay doesnt exist as ChildActor in MainPawn"))
		}
	}
	return nullptr;
}


// Asset Load functions

void UCoreFunctionLibrary::AsyncSpawnActor(UObject * WorldContextObject, TAssetSubclassOf<AActor> AssetPtr, FTransform SpawnTransform, const FMyAsyncSpawnActorDelegate & Callback)
{
	/* Async load Asset into memory */ 
	FStreamableManager& StreamableManager = UCoreAssetManager::Get().StreamableManager;
	FSoftObjectPath Reference = AssetPtr.ToSoftObjectPath();
	StreamableManager.RequestAsyncLoad(Reference, FStreamableDelegate::CreateStatic(&UCoreFunctionLibrary::OnAsyncSpawnActorComplete, WorldContextObject, Reference, SpawnTransform, Callback));
}

void UCoreFunctionLibrary::OnAsyncSpawnActorComplete(UObject * WorldContextObject, FStringAssetReference Reference, FTransform SpawnTransform, FMyAsyncSpawnActorDelegate Callback)
{
	AActor* SpawnedActor;
	
	//now asset must be in memory, so we try load it
	UClass* ActorClass = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), nullptr, *(Reference.ToString())));
	if (ActorClass)
	{
		// Spawn actor in World
		SpawnedActor = WorldContextObject->GetWorld()->SpawnActor<AActor>(ActorClass, SpawnTransform);
	}
	else
	{
		UE_LOG(LogCoreFunctionLibrary, Warning, TEXT("UCoreFunctionLibrary::OnAsyncSpawnActorComplete -- Failed to load object: $"), *Reference.ToString());
	}

	// call spawn event in blueprints
	Callback.ExecuteIfBound(SpawnedActor != nullptr, Reference, SpawnedActor);
}

UMaterialInstanceConstant * UCoreFunctionLibrary::SyncLoadMaterial(UObject * WorldContextObject, TSoftObjectPtr<UMaterialInstanceConstant> Asset)
{
	// Check we're trying to load not null asset
	if (Asset.IsNull())
	{
		FString InstigatorName = (WorldContextObject != nullptr) ? WorldContextObject->GetFullName() : TEXT("Unknown");
		UE_LOG(LogCoreFunctionLibrary, Warning, TEXT("UCoreFunctionLibrary::SyncLoadMaterial -- Asset ptr is null for: %s"), *InstigatorName);
		return nullptr;
	}

	// Load Asset into memory
	FStreamableManager& StreamableManager = UCoreAssetManager::Get().StreamableManager;
	FSoftObjectPath Reference = Asset.ToSoftObjectPath();
	StreamableManager.LoadSynchronous(Reference);

	// Now load object and check it has desired class
	UMaterialInstanceConstant* LoadedFrame = (UMaterialInstanceConstant*)(StaticLoadObject(UMaterialInstanceConstant::StaticClass(), WorldContextObject, *(Reference.ToString())));
	if (LoadedFrame)
	{
		// Be sure that it won't be killed by GC on this frame, so we protect LoadedFrame during current Frame
		LoadedFrame->SetFlags(RF_StrongRefOnFrame);
	}
	else
	{
		UE_LOG(LogCoreFunctionLibrary, Warning, TEXT("UCoreFunctionLibrary::SyncLoadMaterial -- Failed to load object: %s"), *Asset.ToString());
	}
	return LoadedFrame;
}

UUserWidget * UCoreFunctionLibrary::SyncCreateWidget(UObject * WorldContextObject, TAssetSubclassOf<UUserWidget> Asset, APlayerController * OwningPlayer)
{
	// Check we're trying to load not null asset
	if (Asset.IsNull())
	{
		FString InstigatorName = WorldContextObject != nullptr ? WorldContextObject->GetFullName() : TEXT("Unknown");
		UE_LOG(LogCoreFunctionLibrary, Warning, TEXT("UCoreFunctionLibrary::SyncCreateWidget -- Asset ptr is null for: %s"), *InstigatorName);
		return nullptr;
	}

	//Load Asset into memory
	FStreamableManager& StreamableManager = UCoreAssetManager::Get().StreamableManager;
	FSoftObjectPath Reference = Asset.ToSoftObjectPath();
	StreamableManager.LoadSynchronous(Reference);

	// Now load object and check it has desired class
	UClass* WidgetType = Cast<UClass>(StaticLoadObject(UUserWidget::StaticClass(), nullptr, *Reference.ToString()));
	if (!WidgetType)
	{
		return nullptr;
	}

	// Create widget from loaded object
	UUserWidget* UserWidget;
	if(!OwningPlayer)
	{
		UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
		UserWidget = CreateWidget<UUserWidget>(World, WidgetType);
	}
	else
	{
		UserWidget = CreateWidget<UUserWidget>(OwningPlayer, WidgetType);
	}

	// Be sure that it won't be killed by GC on this frame, so we protect UserWidget during current Frame
	if(UserWidget)
	{
		UserWidget->SetFlags(RF_StrongRefOnFrame);
	}
	return UserWidget;
}


// Loading Screen functions

void UCoreFunctionLibrary::PlayLoadingScreen(bool bPlayUntilStopped, float PlayTime)
{
	IInsiderLoadingScreenModule& LoadingScreenModule = IInsiderLoadingScreenModule::Get();
	LoadingScreenModule.StartInGameLoadingScreen(bPlayUntilStopped, PlayTime);
}

void UCoreFunctionLibrary::StopLoadingScreen()
{
	IInsiderLoadingScreenModule& LoadingScreenModule = IInsiderLoadingScreenModule::Get();
	LoadingScreenModule.StopInGameLoadingScreen();
}

// Set Lights functions

void UCoreFunctionLibrary::SetPointlight(UPointLightComponent * Pointlight, FPointlightSettings PointlightSettings)
{
	if (!Pointlight)
	{
		UE_LOG(LogCoreFunctionLibrary, Warning, TEXT("UCoreFunctionLibrary::SetPointlight -- PointlightComponent is null"));
		return;
	}
	Pointlight->SetIntensity(PointlightSettings.Intensity);
	Pointlight->SetLightColor(PointlightSettings.LightColor);
	Pointlight->SetAttenuationRadius(PointlightSettings.AttenuationRadius);
	Pointlight->SetSourceRadius(PointlightSettings.SourceRadius);
	Pointlight->SetSourceLength(PointlightSettings.SourceLength);
	Pointlight->SetCastShadows(PointlightSettings.bCastShadow);
	if (PointlightSettings.IESTexture.IsValid())
	{
		Pointlight->SetIESTexture(PointlightSettings.IESTexture.LoadSynchronous());
	}
}

void UCoreFunctionLibrary::SetSpotlight(USpotLightComponent * Spotlight, FSpotlightSettings SpotlightSettings)
{
	if (!Spotlight)
	{
		UE_LOG(LogCoreFunctionLibrary, Warning, TEXT("UCoreFunctionLibrary::SetSpotlight -- SpotlightComponent is null"));
		return;
	}
	Spotlight->SetIntensity(SpotlightSettings.Intensity);
	Spotlight->SetLightColor(SpotlightSettings.LightColor);
	Spotlight->SetInnerConeAngle(SpotlightSettings.InnerConeAngle);
	Spotlight->SetOuterConeAngle(SpotlightSettings.OuterConeAngle);
	Spotlight->SetAttenuationRadius(SpotlightSettings.AttenuationRadius);
	Spotlight->SetSourceRadius(SpotlightSettings.SourceRadius);
	Spotlight->SetSourceLength(SpotlightSettings.SourceLength);
	Spotlight->SetCastShadows(SpotlightSettings.bCastShadow);
	if (SpotlightSettings.IESTexture.IsValid())
	{
		Spotlight->SetIESTexture(SpotlightSettings.IESTexture.LoadSynchronous());
	}
}

// Close All created widgets
void UCoreFunctionLibrary::CloseWidgets()
{
}

