// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"

#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	class UButton* ReturnToGameButtonInGameMenu;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* GoToMainMenuButtonInGameMenu;

	UFUNCTION()
    void ReturnToGame();

	UFUNCTION()
    void GoToMainMenu();

protected:
	virtual bool Initialize() override;
	
};
