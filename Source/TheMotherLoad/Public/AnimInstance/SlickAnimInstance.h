

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TheMotherLoad/Public/Enums/SlickPlayerStateEnum.h"
#include "TheMotherLoad/Public/Interface/PlayerAnimationInterface.h"
#include "SlickAnimInstance.generated.h"

class ASlick;

/**
 * 
 */
UCLASS()
class THEMOTHERLOAD_API USlickAnimInstance : public UAnimInstance, public IPlayerAnimationInterface
{
	GENERATED_BODY()

public:


protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// Reference to Slick Character
	TObjectPtr<ASlick> SlickCharacter;

	
	// PlayerState
	ESlickCharacterState CurrentState;


	bool bInterfacesImplemented;


	// Get PlayerState from Character using Interface
	void GetPlayerState();
};
