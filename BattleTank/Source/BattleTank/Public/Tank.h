// Copyright Josh "Asheron" Deal 2018

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Has to be lowest!

// Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	void BeginPlay();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint; // Alternative method: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/

	// TODO remove
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4100; // Sensible starting value of 1000 m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	// local barrel reference for spawning projectiles
	UTankBarrel* Barrel = nullptr; // TODO remove

	float LastFireTime = 0;
};
