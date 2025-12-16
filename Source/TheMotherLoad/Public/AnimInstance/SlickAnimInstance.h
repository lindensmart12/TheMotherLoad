

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TheMotherLoad/Public/Enums/SlickPlayerStateEnum.h"
#include "SlickAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class THEMOTHERLOAD_API USlickAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:


protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	
	// PlayerState
	ESlickCharacterState CurrentState;
};
