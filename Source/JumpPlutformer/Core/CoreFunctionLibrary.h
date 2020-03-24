// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Structures/PointlightSettings.h"
#include "Core/Structures/SpotlightSettings.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreFunctionLibrary.generated.h"

class UCoreGameplay;
class UTimelineComponent;
class UPointLightComponent;
class USpotLightComponent;
class UMaterialInstanceConstant;
class UUserWidget;

DECLARE_LOG_CATEGORY_EXTERN(LogCoreFunctionLibrary, Display, All);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FMyAsyncSpawnActorDelegate, bool, bResult, FStringAssetReference, LoadedReference, AActor*, SpawnedActor);

UCLASS()
class INSIDER_API UCoreFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION()
	static void SetPlayRate(UTimelineComponent* Timeline, float Sec);

	UFUNCTION(BlueprintCallable, Category = "CoreFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
	static ACoreGameplay* GetCoreGameplay(UObject* WorldContext);

	//sync and asycn load functions for different types of assets

	/** Asynchronously load asset and spawn actor then */
	UFUNCTION(BlueprintCallable, Category = "CoreFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Spawn Actor (Async)"))
	static void AsyncSpawnActor(UObject* WorldContextObject, TAssetSubclassOf<AActor> AssetPtr, FTransform SpawnTransform, const FMyAsyncSpawnActorDelegate& Callback);

	/** Synchronously load material instanse from asset */
	UFUNCTION(BlueprintCallable, Category = "CoreFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Load Material (Sync)"))
	static UMaterialInstanceConstant* SyncLoadMaterial(UObject* WorldContextObject, TSoftObjectPtr<UMaterialInstanceConstant> Asset);

	/** Synchronously create widget from asset */
	UFUNCTION(BlueprintCallable, Category = "CoreFunctionLibrary", meta = (WorldContext = "WorldContextObject", DisplayName = "Create Widget (Sync)"))
	static UUserWidget* SyncCreateWidget(UObject* WorldContextObject, TAssetSubclassOf<UUserWidget> Asset, APlayerController* OwningPlayer);

	/* Play and Stop Loading screen */
	
	UFUNCTION(BlueprintCallable, Category = Loading)
	static void PlayLoadingScreen(bool bPlayUntilStopped, float PlayTime);

	UFUNCTION(BlueprintCallable, Category = Loading)
	static void StopLoadingScreen();

	/* Set lights Settings*/

	UFUNCTION()
	static void SetPointlight(UPointLightComponent* Pointlight, FPointlightSettings PointlightSettings);

	UFUNCTION()
	static void SetSpotlight(USpotLightComponent* Spotlight, FSpotlightSettings SpotlightSettings);

	// Close All created widgets
	//	Need logic!!!
	UFUNCTION()
	static void CloseWidgets();

protected:

	/** Called when asset loading for actor spawn is finished */
	static void OnAsyncSpawnActorComplete(UObject* WorldContextObject, FStringAssetReference Reference, FTransform SpawnTransform, FMyAsyncSpawnActorDelegate Callback);


};
