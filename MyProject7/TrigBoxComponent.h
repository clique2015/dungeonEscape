// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"

#include "movedoor.h"
#include "TrigBoxComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT7_API UTrigBoxComponent : public UBoxComponent
{
    GENERATED_BODY()

public:
    UTrigBoxComponent();
protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
    void Trigger(bool NewTriggerValue);

    UPROPERTY(EditAnywhere)
    bool IsPressurePlate = false;

    UPROPERTY(EditAnywhere)
    AActor* MoverActor;

    UPROPERTY(VisibleAnywhere)
    bool IsTriggered = false;

    UPROPERTY(VisibleAnywhere)
    int32 ActivatorCount = 0;

    Umovedoor* Mover;

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		
    UFUNCTION()
    void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
