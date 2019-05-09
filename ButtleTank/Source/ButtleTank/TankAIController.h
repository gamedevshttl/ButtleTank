// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BUTTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	class ATank* GetControlledTank() const;
	class ATank* GetPlayerTank() const;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
