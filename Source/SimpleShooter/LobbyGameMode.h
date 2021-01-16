// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzlePlatformsGameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API ALobbyGameMode : public APuzzlePlatformsGameMode
{
	GENERATED_BODY()

	void StartGame();

	uint32 NumberOfPlayers = 0;
	FTimerHandle GameStartTimer;
	
public:
	void PostLogin(APlayerController* NewPlayer) override;
	void Logout(AController* Exiting) override;
};
