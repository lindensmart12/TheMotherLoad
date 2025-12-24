

#pragma once

#include "CoreMinimal.h"
#include "SlickPlayerStateEnum.generated.h"

UENUM(BlueprintType)
enum class ESlickCharacterState : uint8
{
	PrimaryWeapon UMETA(DisplayName = "Unarmed/Rifle"),
	SecondaryWeapon UMETA(DisplayName = "Pistol"),
	TertiaryWeapon UMETA(DisplayName = "Melee/Knife")
};

/**
 * 
 */
class THEMOTHERLOAD_API SlickPlayerStateEnum
{
public:
	
};
