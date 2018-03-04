// Copyright Josh "Asheron" Deal 2018

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories =("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 in max downward movement, and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10; // sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 45; // sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0; // sensible default
};
