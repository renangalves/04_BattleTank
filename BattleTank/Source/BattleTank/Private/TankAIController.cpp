// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not possesing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possesing: %s "), *ControlledTank->GetName());
	}
	*/

	auto PlayerController = GetPlayerTank();
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller not found!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller has been found!"));
	}
	UE_LOG(LogTemp, Warning, TEXT("AI Begin Play"));
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
	
}



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}