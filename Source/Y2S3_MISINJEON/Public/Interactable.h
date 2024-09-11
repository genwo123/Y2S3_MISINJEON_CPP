// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UENUM(BlueprintType)
enum class InteractType : uint8 {
	NONE UMETA(DisplayName = "None"),
	STATIC UMETA(DisplayNmae = "Static"),
	ITEM UMETA(DisplayNmae = "Item"),
	NPC UMETA(DisplayName = "NPC")
};


UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};


class Y2S3_MISINJEON_API IInteractable
{
	GENERATED_BODY()
protected:
	InteractType type = InteractType::NONE;
public :
	InteractType  virtual getType() { return type; };
	void virtual Interact() {};
};