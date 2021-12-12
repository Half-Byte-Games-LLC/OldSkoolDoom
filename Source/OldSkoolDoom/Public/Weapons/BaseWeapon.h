// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"


UCLASS()
class OLDSKOOLDOOM_API ABaseWeapon : public AActor
{
	GENERATED_BODY()


	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* WeaponSprite;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon|Flipbooks")
	class UPaperFlipbook* WeaponFire;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon|Flipbooks")
	class UPaperFlipbook* WeaponReload;
 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USceneComponent* WeaponTrace;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon|Damage Amount")
	float DamageOfGun;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon|Ammo Amounts")
	float PistolAmmo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon|Range")
	float TraceDistance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void WeaponLineTrace();

	UFUNCTION()
	void FireWeapon();
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
