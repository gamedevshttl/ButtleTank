// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	auto ElevateChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevateChange;

	UE_LOG(LogTemp, Warning, TEXT(" GetWorld()->DeltaTimeSeconds %f,  RawNewElevation %f"), GetWorld()->DeltaTimeSeconds, RawNewElevation);

	RawNewElevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}
