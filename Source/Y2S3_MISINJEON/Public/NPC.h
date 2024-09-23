// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Conversation.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"
#include "NPC.generated.h"


class USkeletalMeshComponent;

UCLASS()
class Y2S3_MISINJEON_API ANPC : public AActor, public IInteractable, public IConversation
{
	GENERATED_BODY()
	
	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> sphereComponent;

	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh;
	UPROPERTY(Category = Guide, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> CameraPos;

public:	
	// Sets default values for this actor's properties
	ANPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool Talking = false;
	FRotator ResetRotate;
	FRotator NewRotation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual InteractType getType() override;
	virtual void Interact() override;
	virtual void Talk() override;
	virtual void Listen() override;
	void TalkStart();
	FVector getCameraPos();
	UFUNCTION(BlueprintCallable)
	ConversationState getState() { return state; };
	UFUNCTION(BlueprintCallable)
	bool isTalking() { return Talking; };

};
