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
	// HUD 위젯에 접근할 수 있는 함수 추가
	UFUNCTION(BlueprintCallable, Category = "HUD")
	UUserWidget* GetHUDWidget() const { return HUD; }
	

protected:
	// 게임이 시작될 때 HUD를 화면에 표시
	virtual void BeginPlay() override;

private:
	// HUD로 사용할 위젯 블루프린트 클래스
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;


	

	UPROPERTY(EditAnywhere, Category = "HUD")
	TSubclassOf<UUserWidget> GameOverWidgetClass;

	UPROPERTY(EditAnywhere, Category = "HUD")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	// 생성된 HUD 위젯 인스턴스
	UPROPERTY()
	UUserWidget* HUD;

	UPROPERTY()
	UUserWidget* GameOverWidget;

	// 생성된 MainMenu 위젯 인스턴스
	UPROPERTY()
	UUserWidget* MainMenuWidget;

};
