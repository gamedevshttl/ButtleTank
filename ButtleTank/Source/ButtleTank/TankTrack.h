// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BUTTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
	UTankTrack();	
public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	void DriveTrack(float CurentTrottle);
	
	TArray<class ASprungWheel*> GetWheels() const;

	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000.0f;
};
