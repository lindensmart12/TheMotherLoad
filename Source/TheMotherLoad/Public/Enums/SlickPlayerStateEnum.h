

#pragma once

#include "CoreMinimal.h"
#include "SlickPlayerStateEnum.generated.h"

UENUM()
enum class ESlickCharacterState : uint8
{
	PrimaryWeapon = 0 UMETA(DisplayName = "Unarmed/Rifle"),
	SecondaryWeapon = 1 UMETA(DisplayName = "Pistol"),
	TertiaryWeapon = 2 UMETA(DisplayName = "Melee/Knife")
};

/**
 * 
 */
class THEMOTHERLOAD_API SlickPlayerStateEnum
{
public:
	
};
