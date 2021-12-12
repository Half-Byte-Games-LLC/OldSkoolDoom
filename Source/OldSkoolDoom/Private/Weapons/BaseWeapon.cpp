// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/BaseWeapon.h"

#include "CollisionDebugDrawingPublic.h"
#include "DrawDebugHelpers.h"
#include "PaperFlipbookComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Comp"));
	SetRootComponent(Collision);

	WeaponSprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PaperFlipbook"));
	WeaponSprite->SetupAttachment(Collision);

	WeaponTrace = CreateDefaultSubobject<USceneComponent>("Weapon Trace");
	WeaponTrace->SetupAttachment(Collision);
}


// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseWeapon::WeaponLineTrace()
{
	FVector Loc = WeaponTrace->GetComponentLocation();
	FRotator Rot = WeaponTrace->GetComponentRotation();
	FCollisionQueryParams WeaponTraceParams = FCollisionQueryParams(FName(TEXT("WeaponTrace")), true, this);
	WeaponTraceParams.bTraceComplex = true;
	WeaponTraceParams.bReturnPhysicalMaterial = false;

	FHitResult HitResult(ForceInit);
	

	const FVector Start = Loc;
	FVector End = Start + (UKismetMathLibrary::GetForwardVector(Rot) * TraceDistance);

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, true, 0.f, false, 2.f);
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Pawn, WeaponTraceParams);

	
	UKismetSystemLibrary::PrintString(GetWorld(),HitResult.GetActor()->GetName(),true,true,FLinearColor::Blue,0.f );	
}

void ABaseWeapon::FireWeapon()
{
	WeaponSprite->SetFlipbook(WeaponFire);
	WeaponLineTrace();
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
}

