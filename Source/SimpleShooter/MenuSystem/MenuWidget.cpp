// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::Setup()
{
    this->bIsFocusable = true;
    this->AddToViewport();

    UWorld* World = GetWorld();
    if(!ensure(World != nullptr)) return;

    APlayerController* PlayerController = World->GetFirstPlayerController();
    if(!ensure(PlayerController != nullptr)) return;

    FInputModeUIOnly InputModeData;
    InputModeData.SetWidgetToFocus(this->TakeWidget());
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

    PlayerController->SetInputMode(InputModeData);
    PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::RemoveFromParent()
{
    Super::RemoveFromParent();

    UWorld* World = GetWorld();
    if (!World) return;
    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (!PlayerController) return;

    FInputModeGameOnly InputModeData;
    
    PlayerController->SetInputMode(InputModeData);
    PlayerController->bShowMouseCursor = false;
}


void UMenuWidget::SetMenuInterface(IMenuInterface* MI)
{
    this->MenuInterface = MI;
}
