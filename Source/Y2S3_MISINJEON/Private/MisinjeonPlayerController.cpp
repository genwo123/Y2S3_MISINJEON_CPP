// Fill out your copyright notice in the Description page of Project Settings.


#include "MisinjeonPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"

void AMisinjeonPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // HUDClass에 할당된 블루프린트 위젯이 있는지 확인
    if (HUDClass != nullptr)
    {
        HUD = CreateWidget<UUserWidget>(this, HUDClass);
        if (HUD != nullptr)
        {
            // HUD를 화면에 추가
            HUD->AddToViewport();
        }
    }
}

void AMisinjeonPlayerController::OpenUI(TSubclassOf<UUserWidget> UIClass)
{
    if (UIClass)
    {
        UUserWidget* NewUI = CreateWidget<UUserWidget>(this, UIClass);
        UIStack.Add(NewUI);
        NewUI->AddToViewport();
        SetFocusToTopUI();
    }
}

void AMisinjeonPlayerController::CloseTopUI()
{
    if (UIStack.Num() > 0)
    {
        UUserWidget* TopUI = UIStack.Last();
        UIStack.Pop();
        TopUI->RemoveFromParent();
        SetFocusToTopUI();
    }
}

void AMisinjeonPlayerController::SetFocusToTopUI()
{
    if (UIStack.Num() > 0)
    {
        UUserWidget* TopUI = UIStack.Last();
        SetWidgetFocus(TopUI);
    }
}

void AMisinjeonPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAction("UIBack", IE_Pressed, this, &AMisinjeonPlayerController::HandleUIBack);
}

void AMisinjeonPlayerController::HandleUIBack()
{
    if (UIStack.Num() > 1)
    {
        CloseTopUI();
    }
    else if (UIStack.Num() == 1)
    {
        // 게임 일시정지 해제 또는 다른 로직
    }
}

void AMisinjeonPlayerController::SetWidgetFocus(UUserWidget* Widget)
{
    if (Widget && Widget->IsValidLowLevel())
    {
        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(Widget->TakeWidget());
        SetInputMode(InputMode);
        bShowMouseCursor = true;
    }
}