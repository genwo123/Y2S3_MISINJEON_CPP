// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MisinjeonPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class Y2S3_MISINJEON_API AMisinjeonPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	

protected:
	// 게임이 시작될 때 HUD를 화면에 표시
	virtual void BeginPlay() override;

private:
	// HUD로 사용할 위젯 블루프린트 클래스
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	// 생성된 HUD 위젯 인스턴스
	UPROPERTY()
	UUserWidget* HUD;
};
