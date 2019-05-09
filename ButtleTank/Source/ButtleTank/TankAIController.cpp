// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include <Engine/World.h>

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControlledTank();
	if (Tank)
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessed %s"), *Tank->GetName());

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank)
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank name is %s"), *PlayerTank->GetName());
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());	
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PalyerTank = GetWorld()->GetFirstPlayerController()->GetPawn();	
	if (PalyerTank) 
		return Cast<ATank>(PalyerTank);
	
	return nullptr;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetPlayerTank()) {
		ATank* Tank = Cast<ATank>(GetPawn());
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

