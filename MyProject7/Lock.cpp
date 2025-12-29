// Fill out your copyright notice in the Description page of Project Settings.


#include "Lock.h"

// Sets default values
ALock::ALock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root_Comp"));
	SetRootComponent(RootComp);
	TriggerComp = CreateDefaultSubobject<UTrigBoxComponent>(TEXT("Trigger_Comp"));
	TriggerComp->SetupAttachment(RootComp);
	KeyItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key_Item_Mesh"));
	KeyItemMesh->SetupAttachment(RootComp);
	Tags.Add("Lock");
}

// Called when the game starts or when spawned
void ALock::BeginPlay()
{
	Super::BeginPlay();
	SetIsKeyPlaced(false);
	
}

// Called every frame
void ALock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ALock::SetIsKeyPlaced(bool NewIsKeyPlaced)
{
	IsKeyPlaced = NewIsKeyPlaced;
	TriggerComp->Trigger(NewIsKeyPlaced);
	KeyItemMesh->SetVisibility(NewIsKeyPlaced);
}
bool ALock::GetIsKeyPlaced()
{
	return IsKeyPlaced;
}
