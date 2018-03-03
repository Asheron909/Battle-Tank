// Copyright Josh "Asheron" Deal 2018

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	// void ATank::AimAt(FVector HitLocation);

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	float AcceptanceRadius = 3000; // How close the AI tank gets to the Player in cm?
};
