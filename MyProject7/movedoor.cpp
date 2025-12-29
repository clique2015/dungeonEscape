// Fill out your copyright notice in the Description page of Project Settings.


#include "movedoor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
Umovedoor::Umovedoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Umovedoor::BeginPlay()
{
	Super::BeginPlay();
    AActor* MyOwner = GetOwner();
    MyOwner->GetActorNameOrLabel();
    StartLocation = MyOwner->GetActorLocation();
    SetShouldMove(false);
    UE_LOG(LogTemp, Display, TEXT("My owner is %s"), *MyOwner->GetActorNameOrLabel());
    
    
    UE_LOG(LogTemp, Display, TEXT("My owner is at location %s"), *StartLocation.ToCompactString());
	// ...
	
}


// Called every frame
void Umovedoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    FVector CurrentLocation = GetOwner()->GetActorLocation();
    ReachedTarget = CurrentLocation.Equals(TargetLocation);
    if(!ReachedTarget)
    {
        float Speed  = MoveOffset.Length() / MoveTime;
        FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
        GetOwner()->SetActorLocation(NewLocation);
    }
	// ...
}

    bool Umovedoor::GetShouldMove()
    {
        return ShouldMove;
    }
    void Umovedoor::SetShouldMove(bool NewShouldMove)
    {
        ShouldMove = NewShouldMove;
        if(ShouldMove)
        {
            TargetLocation = StartLocation + MoveOffset;
            
        }else
        {
            TargetLocation = StartLocation;
        }
    }