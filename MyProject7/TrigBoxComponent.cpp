// Fill out your copyright notice in the Description page of Project Settings.


#include "TrigBoxComponent.h"


UTrigBoxComponent::UTrigBoxComponent()
{
    PrimaryComponentTick.bCanEverTick = true; // Enable ticking if needed
}

// Called when the game starts
void UTrigBoxComponent::BeginPlay()
{
    Super::BeginPlay();
    if(MoverActor)
    {
        Mover = MoverActor->FindComponentByClass<Umovedoor>();
        if(Mover)
        {
         //   Mover->ShouldMove = true;
        }
    }
  if(IsPressurePlate)
  {
    OnComponentBeginOverlap.AddDynamic(this, &UTrigBoxComponent::OnOverlapBegin);
    OnComponentEndOverlap.AddDynamic(this, &UTrigBoxComponent::OnOverlapEnd);
    }
}


// Called every frame
void UTrigBoxComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}

void UTrigBoxComponent::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    
    bool HasTag = OtherActor->ActorHasTag("PressurePlateActivator");
    if(Mover && HasTag)
    {
        ActivatorCount++;
        if(!IsTriggered)
            Trigger(true);
    }
}
		
void UTrigBoxComponent::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    bool HasTag = OtherActor->ActorHasTag("PressurePlateActivator");
    if(Mover && HasTag)
    {
        ActivatorCount--;
        if(ActivatorCount == 0 && IsTriggered)
            Trigger(false);
    }
}

void UTrigBoxComponent::Trigger(bool NewTriggerValue)
{
    IsTriggered = NewTriggerValue;
    if(Mover)
    {
        Mover->SetShouldMove(IsTriggered);
    }else
    {
        UE_LOG(LogTemp, Display, TEXT("%s doesnt have a mover to trigger!"), *GetOwner()->GetActorNameOrLabel());
    }   
}