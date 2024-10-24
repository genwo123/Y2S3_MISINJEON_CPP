// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Components/SphereComponent.h"
#include "Static.generated.h"

UCLASS()
class Y2S3_MISINJEON_API AStatic : public AActor, public IInteractable
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	AStatic();
	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> sphereComponent;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool interacted = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual InteractType getType() override;
	virtual void Interact() override;
	UFUNCTION(BlueprintImplementableEvent)
	void OnInteract();

	UFUNCTION(BlueprintCallable)
	bool isInteracted() { return interacted; }
	UFUNCTION(BlueprintCallable)
	void setInteracted(bool tmp) { interacted = tmp; }

};
