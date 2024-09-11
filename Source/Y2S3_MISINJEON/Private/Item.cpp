// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("IntreactBoundary"));
	RootComponent = sphereComponent;
	
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	type = InteractType::ITEM;
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

InteractType AItem::getType() {
	UE_LOG(LogTemp, Log, TEXT("Item Interact"));
	return type;
}

void AItem::Interact() {

}

