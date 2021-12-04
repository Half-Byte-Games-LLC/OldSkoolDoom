// Copyright Epic Games, Inc. All Rights Reserved.

#include "OldSkoolDoomGameMode.h"
#include "OldSkoolDoomHUD.h"
#include "OldSkoolDoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOldSkoolDoomGameMode::AOldSkoolDoomGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AOldSkoolDoomHUD::StaticClass();
}
