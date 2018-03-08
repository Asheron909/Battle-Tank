// Copyright Josh "Asheron" Deal 2018

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Has to be lowest!

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

// Forward declarations

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	// Returns current health as a percentage of starting health betweeen 0 and 1
	UFUNCTION(BlueprintPure, Category = "Gameplay")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	int32 CurrentHealth; // Initiallized in BeginPlay()
};
