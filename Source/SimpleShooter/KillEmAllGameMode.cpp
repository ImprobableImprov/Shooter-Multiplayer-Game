// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

#include "EngineUtils.h"
#include "ShooterAIController.h"
#include "ShooterCharacter.h"
#include "ShooterPlayerController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	bool PlayersDead = true;
	
	//APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	//if(PlayerController != nullptr)
	//	EndGame(false);

	for (AShooterCharacter *PlayerController : TActorRange<AShooterCharacter>(GetWorld()))
	{
		if(!PlayerController->IsDead()) PlayersDead = false;
	}

	if(PlayersDead)
		EndGame(false);
	
	for (AShooterAIController *AIController : TActorRange<AShooterAIController>(GetWorld()))
	{
		if(!AIController->IsDead())
			return;
	}

	EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for(AShooterPlayerController* Controller : TActorRange<AShooterPlayerController>(GetWorld()))
	{
		bool bIsWinner = (Controller->IsPlayerController() == bIsPlayerWinner);
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
