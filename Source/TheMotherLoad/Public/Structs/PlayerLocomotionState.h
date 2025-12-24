

#pragma once

#include "CoreMinimal.h"
#include "PlayerLocomotionState.generated.h"

USTRUCT(BlueprintType)
struct FPlayerLocomotionState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locomotion")
	float MaxWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locomotion")
	float MaxAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locomotion")
	float BrakingDeceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locomotion")
	float BrakingFrictionFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locomotion")
	float BreakingFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locomotion")
	bool UseSeperateBrakingFriction;
};