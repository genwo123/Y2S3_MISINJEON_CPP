// Fill out your copyright notice in the Description page of Project Settings.


#include "Static.h"

// Sets default values
AStatic::AStatic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStatic::BeginPlay()
{
	Super::BeginPlay();
	type = InteractType::STATIC;
}

// Called every frame
void AStatic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

InteractType AStatic::getType() {
	return type;
}

void AStatic::Interact() {

}

