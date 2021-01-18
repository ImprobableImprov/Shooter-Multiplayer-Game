// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "ShooterCharacter.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = "Update Player Location If Seen"; 
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	// UGameplayStatics::GetGameState(GetWorld())->PlayerArray;
	
	//if(PlayerPawn == nullptr) return;
	if(OwnerComp.GetAIOwner() == nullptr) return;

	bool isFound = false;

	for (APlayerState* Player : UGameplayStatics::GetGameState(GetWorld())->PlayerArray)
	{
		APawn* PlayerPawn = Player->GetPawn();
		if(PlayerPawn == nullptr) continue;
		
		if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
			isFound = true;
		}
	}

	if(!isFound)
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
	
	// if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
	// {
	// 	OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
	// }
	// else
	// {
	// 	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	// }


}
