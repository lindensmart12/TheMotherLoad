

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TheMotherLoad/Public/Enums/SlickPlayerStateEnum.h"
#include "TheMotherLoad/Public/Interface/PlayerAnimationInterface.h"
#include "TheMotherLoad/Public/Enums/EPlayerStateLocomotion.h"
#include "Slick.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class THEMOTHERLOAD_API ASlick : public ACharacter, public IPlayerAnimationInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASlick();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Get PlayerState from PlayerController
	void RecieveCharacterState(ESlickCharacterState NewState);


	//Interfaces
	
	// Send PlayerState to Animation Blueprint using Interfaces
	ESlickCharacterState GetPlayerState_Implementation() override;

	// Set Locomotion State
	void SetLocomotionState(EPlayerStateLocomotion NewLocomotionState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Spring Arm Component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr < USpringArmComponent> SpringArmComp;

	// Camera Component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr < UCameraComponent> CameraComp;


	// Default CharacterState
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacterState")
	ESlickCharacterState CurrentPlayerState = ESlickCharacterState::PrimaryWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacterState")
	EPlayerStateLocomotion CurrentLocomotionState;
};
