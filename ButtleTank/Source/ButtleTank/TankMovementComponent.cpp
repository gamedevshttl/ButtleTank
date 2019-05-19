// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
		return;

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForvard(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Throw %f"), Throw);
	if (LeftTrack)
		LeftTrack->SetThrottle(Throw);

	if (RightTrack)
		RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (LeftTrack)
		LeftTrack->SetThrottle(Throw);

	if (RightTrack)
		RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (LeftTrack)
		LeftTrack->SetThrottle(-Throw);

	if (RightTrack)
		RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardDirection = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardDirection);
	IntendMoveForvard(ForwardThrow);

	auto RigthThrow = FVector::CrossProduct(TankForward, AIForwardDirection).Z;
	IntendTurnRight(RigthThrow);
}
