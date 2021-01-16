// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"

#include "MainMenu.generated.h"

USTRUCT()
struct FServerData
{
	GENERATED_BODY()
	
	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;
};


/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

	TSubclassOf<class UUserWidget> ServerRowClass;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButtonJoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButtonJoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButtonMainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* HostMenu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* ServerHostName;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelHostMenuButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* ConfirmHostMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* ServerList;

	UFUNCTION()
	void QuitPressed();
	
	UFUNCTION()
	void HostServer();

	UFUNCTION()
    void JoinServer();
	
	UFUNCTION()
    void OpenJoinMenu();

	UFUNCTION()
    void OpenHostMenu();

	UFUNCTION()
	void OpenMainMenu();
	
	TOptional<uint32> SelectedIndex;

protected:
	virtual bool Initialize() override;

public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FServerData> ServerNames);

	void SelectIndex(uint32 Index);

	void UpdateChildren();
};
