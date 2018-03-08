// Copyright Josh "Asheron" Deal 2018

#include "BattleTank.h"
#include "Tank.h"


float ATank::GetHealthPercent() const {

	return (float)CurrentHealth / (float)StartingHealth;
}

// Sets default values
ATank::ATank() {

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay() {

	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) {

	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0) {
		// Tank died
		OnDeath.Broadcast();
	}

	return DamageToApply;
}

