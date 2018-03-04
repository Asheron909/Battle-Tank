// Copyright Josh "Asheron" Deal 2018

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Has to be lowest!

// Forward declarations

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

private:
	// Sets default values for this pawn's properties
	ATank();
};
