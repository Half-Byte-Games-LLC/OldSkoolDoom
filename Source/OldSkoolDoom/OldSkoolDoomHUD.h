// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "OldSkoolDoomHUD.generated.h"

UCLASS()
class AOldSkoolDoomHUD : public AHUD
{
	GENERATED_BODY()

public:
	AOldSkoolDoomHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

