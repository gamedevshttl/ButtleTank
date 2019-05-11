// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) 
		return;

	FVector OutLauchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	
		
	if(UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLauchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		)
	)
	{
		auto AimDirection = OutLauchVelocity.GetSafeNormal();
		MoveAim(AimDirection);

		UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no aim"));
	}
}

void UTankAimingComponent::MoveAim(FVector AimDirection)
{
	auto AimAsRotator = AimDirection.Rotation();
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	UE_LOG(LogTemp, Warning, TEXT("%s"), *DeltaRotator.ToString());

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}


