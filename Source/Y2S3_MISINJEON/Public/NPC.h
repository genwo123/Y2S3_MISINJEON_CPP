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
	// 대화시 카메라 위치
	UPROPERTY(Category = Guide, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> CameraPos;
	// 대화시 서리 위치
	UPROPERTY(Category = Guide, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> SeoriPos;

public:	
	// Sets default values for this actor's properties
	ANPC();
	UPROPERTY(Category = State, EditAnywhere)
	int NPCid = 0;
	UPROPERTY(Category = State, EditAnywhere)
	FString name = "";

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
	FVector getCameraPos();
	FVector getSeoriPos();
	
	UFUNCTION(BlueprintCallable)
	virtual void Talk() override;
	UFUNCTION(BlueprintCallable)
	virtual void Listen() override;	
	UFUNCTION(BlueprintCallable)
	ConversationState getState() { return state; };
	
	UFUNCTION(BlueprintCallable)
	bool isTalking() { return Talking; };
	UFUNCTION(BlueprintCallable)
	void setTalking(bool tmp) { Talking = tmp; };
	UFUNCTION(BlueprintImplementableEvent)
	void onTalking();


	UFUNCTION(BlueprintCallable)
	void ResetRotation();

	UFUNCTION(BlueprintCallable)
	FString getName() { return name; };

};
