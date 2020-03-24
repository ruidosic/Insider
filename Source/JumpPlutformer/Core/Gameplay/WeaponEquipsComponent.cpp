
#include "WeaponEquipsComponent.h"
#include "GameplayInterface.h"


DEFINE_LOG_CATEGORY(LogWeaponEquipsComponent)

UWeaponEquipsComponent::UWeaponEquipsComponent()
{
	Owner = GetOwner();
}

		/* Setup all Settings Variables from Owner's FGameplaySettings */

void UWeaponEquipsComponent::SetupDefaults()
{
	if (Owner)
	{
		if (Owner->Implements<UGameplayInterface>())
		{
			FGameplaySettings GameplaySettings = IGameplayInterface::Execute_GetGameplaySettings(Owner);
			SetupWeaponEquips(GameplaySettings.EquipmentSettings);
		}
		else
		{
			UE_LOG(LogWeaponEquipsComponent, Warning, TEXT("UWeaponEquipsComponent::SetupDefaults -- Missing IGameplayInterface implementation for: %s"), *GetOwner()->GetFullName());
		}
	}
	else
	{
		UE_LOG(LogWeaponEquipsComponent, Warning, TEXT("UWeaponEquipsComponent::SetupDefaults -- Cant Find Owner!"));
	}
}

void UWeaponEquipsComponent::SetupWeaponEquips(const FEquipmentSettings & Equipments)
{
	SetupPistolSettings(Equipments.Pistol);
	// TODO: need other weapon's setups
}

void UWeaponEquipsComponent::SetupPistolSettings(const FPistolSettings & Pistol)
{
	bHasPistol = Pistol.bHas;
	bPistolContinuousShot = Pistol.bContinuousShot;
	PistolTotalAmmo = Pistol.TotalAmmo;
	PistolClipCapasity = Pistol.ClipCapasity;
	PistolClipAmmo = Pistol.ClipAmmo;
	PistolShotDistance = Pistol.PistolShotDistance;
	SoftPistolShotDecal = Pistol.PistolShotDecal;
	SoftPistolEquipSound = Pistol.EquipSound;
	SoftPistolShotSound = Pistol.ShotSound;
	SoftPistolShotWhileEmptySound = Pistol.ShotWhileEmptySound;
	SoftPistolReloadSound = Pistol.ReloadSound;
	SoftPistolReloadWhileEmptySound = Pistol.ReloadWhileEmptySound;
}

void UWeaponEquipsComponent::BeginPlay()
{
	Super::BeginPlay();
	SetupDefaults();
	
}
