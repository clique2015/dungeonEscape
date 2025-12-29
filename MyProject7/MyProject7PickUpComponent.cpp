// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProject7PickUpComponent.h"

UMyProject7PickUpComponent::UMyProject7PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UMyProject7PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UMyProject7PickUpComponent::OnSphereBeginOverlap);
}

void UMyProject7PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AMyProject7Character* Character = Cast<AMyProject7Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
