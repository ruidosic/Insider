
#include "CameroidEquipsComponent.h"
#include "GameplayInterface.h"

DEFINE_LOG_CATEGORY(LogCameroidEquipsComponent)

UCameroidEquipsComponent::UCameroidEquipsComponent()
{
	Owner = GetOwner();

}

/* Setup all Settings Variables from Owner's FGameplaySettings*/

void UCameroidEquipsComponent::SetupDefaults()
{
	if (Owner)
	{
		if (Owner->Implements<UGameplayInterface>())
		{
			FGameplaySettings GameplaySettings = IGameplayInterface::Execute_GetGameplaySettings(Owner);
		}
		else
		{

		}
	}
	else
	{
		UE_LOG(LogCameroidEquipsComponent, Warning, TEXT("UCameroidEquipsComponents::SetupDefaults -- Cant Find Owner!"))
	}
}

void UCameroidEquipsComponent::SetupCameroidSettings(const FCameroidSettings & Cameroid)
{
	bHasCameroid = Cameroid.bHas;
	bInfiniteCameroid = Cameroid.bInfinite;
	CameroidPhotoShakeDifficulty = Cameroid.PhotoShakeDifficulty;
	CameroidFOV = Cameroid.CameroidFOV;
	SoftCameroidViewFinderTexture = Cameroid.ViewfinderTexture;
	SoftCameroidOnSound = Cameroid.OnSound;
	SoftCameroidOffSound = Cameroid.OffSound;
	SoftCameroidShotSound = Cameroid.CameroidShootSound;
}

void UCameroidEquipsComponent::BeginPlay()
{
	Super::BeginPlay();
	SetupDefaults();
}



