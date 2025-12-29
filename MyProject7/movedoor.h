// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "movedoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT7_API Umovedoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Umovedoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
    
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    FVector StartLocation;
    FVector TargetLocation;
    bool ReachedTarget = false;
    
    UPROPERTY(EditAnywhere)
    FVector MoveOffset;
    
    UPROPERTY(EditAnywhere)
    float MoveTime = 4.0f;
 
    bool GetShouldMove();
    void SetShouldMove(bool NewShouldMove);
private:
    UPROPERTY(VisibleAnywhere)
    bool ShouldMove = false;

		
};
