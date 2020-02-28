// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "EventCheck.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EEventCheck
{
	EC_None						UMETA(DisplayName = "Nothing"),
	EC_OpenOn					UMETA(DisplayName = "Open / On"),
	EC_CloseOff					UMETA(DisplayName = "Close / Off"),
	EC_Explode					UMETA(DisplayName = "Explode"),
	EC_Jump						UMETA(DisplayName = "Jump"),
	EC_OverlapWithTrigger		UMETA(DisplayName = "Overlap with Trigger"),
	EC_Lock						UMETA(DisplayName = "Lock"),
	EC_Unlock					UMETA(DisplayName = "Unlock"),
	EC_KnockKnock				UMETA(DisplayName = "Knock Knock"),
	EC_ForceToOpen				UMETA(DisplayName = "Force to Open"),
	EC_HoldLadder				UMETA(DisplayName = "Hold Ladder"),
	EC_LeaveLadder				UMETA(DisplayName = "Leave Ladder"),
	EC_LeaveLadderTop			UMETA(DisplayName = "Leave Ladder at Top"),
	EC_Take						UMETA(DisplayName = "Take"),
	EC_TakeKey					UMETA(DisplayName = "Take Key"),
	EC_PutItemBack				UMETA(DisplayName = "Put Item Back"),
	EC_DeniedWrongPassword		UMETA(DisplayName = "Denied / Wrong Password"),
	EC_HeldPhysicsObject		UMETA(DisplayName = "Held Physics Object"),
	EC_ReleasePhysicsObject		UMETA(DisplayName = "Release Physics Object"),
	EC_ThrowPhysicsObject		UMETA(DisplayName = "Throw Physics Object"),
	EC_TeleportPlayer			UMETA(DisplayName = "Teleport Player"),
	EC_TeleportPhysicsObject	UMETA(DisplayName = "Teleport Physics Object"),
	EC_DesiredWeightComplete	UMETA(DisplayName = "Desired Weight Complete"),
	EC_DesiredWeightUncomplete	UMETA(DisplayName = "Desired Weight Uncomplete"),
	EC_EquipFlashlight			UMETA(DisplayName = "Equip Flashlight"),
	// in this place we can add EquipTorch, EquipGun, etc. When we implement them.
	EC_DetectedByCamera			UMETA(DisplayName = "Deetected By Camera"),
	EC_SwitchChannel			UMETA(DisplayName = "Switch Channel"),
	EC_Alarm					UMETA(DisplayName = "Alarm"),
	EC_Disalarm					UMETA(DisplayName = "Disalarm")
};
