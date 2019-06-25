// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
}

void UTankTrack::SetThrottle(float Throttle)
{		
	float CurentTrottle = FMath::Clamp<float>(Throttle, -2.0, 2.0);
	DriveTrack(CurentTrottle);
}

void UTankTrack::DriveTrack(float CurentTrottle)
{
	auto ForceApplied = CurentTrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	float ForceMagnitude = ForceApplied / Wheels.Num();

	for (auto Wheel : Wheels) {
		Wheel->AddDrivingForce(ForceMagnitude);
	}
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> Wheels;

	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);

	for (auto Child : Children) {
		auto SpawnPointItem = Cast<USpawnPoint>(Child);
		if (!SpawnPointItem)
			continue;

		auto Wheel = Cast<ASprungWheel>(SpawnPointItem->GetSpawnedActor());
		if (!Wheel)
			continue;

		Wheels.Add(Wheel);
	}

	return Wheels;
}
