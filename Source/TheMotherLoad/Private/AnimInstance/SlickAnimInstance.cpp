


#include "AnimInstance/SlickAnimInstance.h"
#include "Character/Slick.h"

void USlickAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	APawn* OwnerPawn = TryGetPawnOwner();
	if (OwnerPawn)
	{
		SlickCharacter = Cast<ASlick>(OwnerPawn);
	}
}

void USlickAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!SlickCharacter)
	{
		APawn* OwnerPawn = TryGetPawnOwner();
		if (OwnerPawn)
		{
			SlickCharacter = Cast<ASlick>(OwnerPawn);
		}
	}
	else{
		GetPlayerState();
		GetCharacterSpeed();
		return;
		}
}

void USlickAnimInstance::GetCharacterSpeed()
{
	if (SlickCharacter)
	{
		SlickCharacterSpeed = SlickCharacter->GetVelocity().Size();
	}
}

void USlickAnimInstance::GetPlayerState()
{
	bInterfacesImplemented = SlickCharacter->GetClass()->ImplementsInterface(UPlayerAnimationInterface::StaticClass());
	if (bInterfacesImplemented)
	{
		CurrentState = IPlayerAnimationInterface::Execute_GetPlayerState(SlickCharacter);
	}
}
