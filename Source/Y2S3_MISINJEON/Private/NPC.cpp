// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("IntreactBoundary"));
	RootComponent = sphereComponent;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(sphereComponent);
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	type = InteractType::NPC;
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

InteractType ANPC::getType() {
	// 대화시작
	return type;
}

void ANPC::Interact() {
	UE_LOG(LogTemp, Log, TEXT("NPC Interact"));
}

