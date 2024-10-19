// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GamePlayStatics.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("IntreactBoundary"));
	RootComponent = sphereComponent;
	sphereComponent->SetSphereRadius(140.0f);
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(sphereComponent);
	CameraPos = CreateDefaultSubobject<USceneComponent>(TEXT("CameraPos"));
	CameraPos->SetupAttachment(sphereComponent);
	SeoriPos = CreateDefaultSubobject<USceneComponent>(TEXT("SeoriPos"));
	SeoriPos->SetupAttachment(sphereComponent);
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	type = InteractType::NPC;
	state = ConversationState::TALK;
	ResetRotate = GetActorRotation();
}
   
// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

InteractType ANPC::getType() {
	// 대화시작
	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (player == nullptr) return InteractType::NONE;
	
	FVector PlayerLoc = player->GetActorLocation();
	FVector NpcLoc = GetActorLocation();

	FVector Direction = (PlayerLoc - NpcLoc).GetSafeNormal();
	NewRotation = FRotationMatrix::MakeFromX(Direction).Rotator();

	NewRotation.Yaw -= 90.0f;
	NewRotation.Pitch = ResetRotate.Pitch;
	NewRotation.Roll = ResetRotate.Roll;

	SetActorRotation(NewRotation);
	return type;
}



void ANPC::Interact() {
	//UE_LOG(LogTemp, Log, TEXT("NPC Interact"));
	if (Talking) return;
	Talking = true;
	onTalking();
}

FVector ANPC::getCameraPos() {
	return CameraPos->GetComponentLocation();
}

FVector ANPC::getSeoriPos() {
	return SeoriPos->GetComponentLocation();
}

void ANPC::Talk() {
	state = ConversationState::TALK;
}

void ANPC::Listen() {
	state = ConversationState::LISTEN;
	
}
void ANPC::ResetRotation() {
	SetActorRotation(ResetRotate);
}