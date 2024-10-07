// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MisinjeonPlayerController.generated.h"

UCLASS()
class Y2S3_MISINJEON_API AMisinjeonPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
<<<<<<< HEAD
	// HUD 위젯에 접근할 수 있는 함수 추가
	UFUNCTION(BlueprintCallable, Category = "HUD")
	UUserWidget* GetHUDWidget() const { return HUD; }
	
=======
    //UI 포커싱용
    UFUNCTION(BlueprintCallable, Category = "UI")
    void OpenUI(TSubclassOf<class UUserWidget> UIClass);
    UFUNCTION(BlueprintCallable, Category = "UI")
    void CloseTopUI();
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetFocusToTopUI();

    // HUD 위젯에 접근할 수 있는 함수
    UFUNCTION(BlueprintCallable, Category = "HUD")
    UUserWidget* GetHUDWidget() const { return HUD; }
>>>>>>> develop

protected:
    // 게임이 시작될 때 HUD를 화면에 표시
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

private:
    //UI스택 관리용 매니저먼트
    UPROPERTY()
    TArray<class UUserWidget*> UIStack;
    void HandleUIBack();
    void SetWidgetFocus(UUserWidget* Widget);

    // HUD로 사용할 위젯 블루프린트 클래스
    UPROPERTY(EditAnywhere, Category = "HUD")
    TSubclassOf<class UUserWidget> HUDClass;

    UPROPERTY(EditAnywhere, Category = "HUD")
    TSubclassOf<UUserWidget> GameOverWidgetClass;
    UPROPERTY(EditAnywhere, Category = "HUD")
    TSubclassOf<UUserWidget> MainMenuWidgetClass;

<<<<<<< HEAD
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
=======
    // 생성된 HUD 위젯 인스턴스
    UPROPERTY()
    UUserWidget* HUD;
    UPROPERTY()
    UUserWidget* GameOverWidget;
    // 생성된 MainMenu 위젯 인스턴스
    UPROPERTY()
    UUserWidget* MainMenuWidget;
};
>>>>>>> develop
