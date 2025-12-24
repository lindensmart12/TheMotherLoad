

#pragma once

#include "CoreMinimal.h"
#include "EPlayerStateLocomotion.generated.h"

UENUM(BlueprintType)
enum class EPlayerStateLocomotion : uint8
{
	Walking UMETA(DisplayName = "Walking"),
	Jogging UMETA(DisplayName = "Jogging")
};