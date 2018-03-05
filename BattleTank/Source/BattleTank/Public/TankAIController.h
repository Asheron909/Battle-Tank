// Copyright Josh "Asheron" Deal 2018

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	// void ATank::AimAt(FVector HitLocation);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000; // How close the AI tank gets to the Player in cm

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
