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
