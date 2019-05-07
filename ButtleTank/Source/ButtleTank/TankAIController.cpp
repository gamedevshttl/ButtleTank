// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	ATank* Tank = Cast<ATank>(GetPawn());
	
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessed %s"), *Tank->GetName());
	}
}