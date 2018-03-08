
// Copyright Josh "Asheron" Deal 2018

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h" // Included to impiment OnDeath()
#include "TankAIController.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay() {

	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick( float DeltaTime ) {

	Super::Tick(DeltaTime);

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = (GetPawn());
	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked) {
		AimingComponent->Fire(); // Limit fire rate
	}
}

void ATankAIController::SetPawn(APawn * InPawn) {

	Super::SetPawn(InPawn);
	if (InPawn) {

		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossesdTankDeath);
	}
}

void ATankAIController::OnPossesdTankDeath() {

	if (!ensure(GetPawn())) { return; }

	GetPawn()->DetachFromControllerPendingDestroy();
}
