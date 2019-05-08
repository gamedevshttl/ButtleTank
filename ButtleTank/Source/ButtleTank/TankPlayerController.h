// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BUTTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	class ATank* GetControlledTank() const;

public:
	virtual void Tick(float DeltaSeconds) override;

	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D& ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(const FVector& LookDirection, FVector& HitLocation) const;

	UPROPERTY(VisibleAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(VisibleAnywhere)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(VisibleAnywhere)
	int LineTraceRange = 1000000;
};
