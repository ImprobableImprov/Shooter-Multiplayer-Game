// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"


#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
    const bool Success = Super::Initialize();
    if(!Success) return false;

    if(!ensure(ReturnToGameButtonInGameMenu != nullptr)) return false;
    ReturnToGameButtonInGameMenu->OnClicked.AddDynamic(this, &UInGameMenu::ReturnToGame);

    if(!ensure(GoToMainMenuButtonInGameMenu != nullptr)) return false;
    GoToMainMenuButtonInGameMenu->OnClicked.AddDynamic(this, &UInGameMenu::GoToMainMenu);

    return true;
}

void UInGameMenu::ReturnToGame()
{
    RemoveFromParent();
}

void UInGameMenu::GoToMainMenu()
{
    if(MenuInterface != nullptr)
    {
        RemoveFromParent();
        MenuInterface->LoadMainMenu();
    }
}
