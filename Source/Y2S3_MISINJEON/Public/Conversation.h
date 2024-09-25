// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Conversation.generated.h"

UENUM(BlueprintType)
enum class ConversationState : uint8
{
	LISTEN UMETA(DisplayName = "Listen"),
	TALK UMETA(DisplayName = "Talk")
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConversation : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class Y2S3_MISINJEON_API IConversation
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	ConversationState state;

	virtual void Talk(){};
	virtual void Listen() {};
	
};
