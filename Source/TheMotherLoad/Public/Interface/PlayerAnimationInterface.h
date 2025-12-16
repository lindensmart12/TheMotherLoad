

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TheMotherLoad/Public/Enums/SlickPlayerStateEnum.h"
#include "PlayerAnimationInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlayerAnimationInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEMOTHERLOAD_API IPlayerAnimationInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PlayerState")
	ESlickCharacterState GetPlayerState();
	
};
