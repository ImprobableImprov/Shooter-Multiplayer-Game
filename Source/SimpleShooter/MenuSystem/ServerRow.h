// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

#include "ServerRow.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UServerRow : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	class UButton* RowButton;

	UFUNCTION()
	void OnClicked();

	UPROPERTY()
	class UMainMenu* Parent;

	uint32 Index;
	
public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ServerName;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HostUser;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ConnectionFraction;

	UPROPERTY(BlueprintReadOnly)
	bool Selected = false;

	void Setup(class UMainMenu* InParent, uint32 InIndex);
};
