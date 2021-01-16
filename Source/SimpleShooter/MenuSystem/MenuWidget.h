// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"

#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Setup();
	
	virtual void RemoveFromParent() override;
	
	void SetMenuInterface(IMenuInterface* MI);

protected:
	IMenuInterface* MenuInterface;
};
