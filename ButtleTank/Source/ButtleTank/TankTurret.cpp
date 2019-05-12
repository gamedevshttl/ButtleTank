// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	float RotateChange = MaxDgreesPerSecond * RelativeSpeed * GetWorld()->DeltaTimeSeconds;
	auto YawRotate = RelativeRotation.Yaw + RotateChange;

	UE_LOG(LogTemp, Warning, TEXT(" GetWorld()->DeltaTimeSeconds %f,  YawRotate %f"), GetWorld()->DeltaTimeSeconds, YawRotate);	

	SetRelativeRotation(FRotator(0, YawRotate, 0));
}