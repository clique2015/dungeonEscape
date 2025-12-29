// Fill out your copyright notice in the Description page of Project Settings.


#include "collectibleItem.h"

// Sets default values
AcollectibleItem::AcollectibleItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add("CollectibleItem");
}

// Called when the game starts or when spawned
void AcollectibleItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcollectibleItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

