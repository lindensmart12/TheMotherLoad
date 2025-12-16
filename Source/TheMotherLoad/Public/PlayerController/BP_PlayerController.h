

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "TheMotherLoad/Public/Enums/SlickPlayerStateEnum.h"
#include "BP_PlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

class ASlick;

/**
 * 
 */
UCLASS()
class THEMOTHERLOAD_API ABP_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;



	// Player Character
	TObjectPtr < ASlick > SlickPlayerCharacter;





	// PlayerMovement Input MappingContext, Actions and Functions
	
	// Input Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputMappingContext> PlayerMovementMappingContext;


	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > PlayerMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > PlayerLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > PlayerJumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > PlayerSprintAction;

	// Input Functions
	void PlayerMove(const FInputActionValue& Value);
	void PlayerLook(const FInputActionValue& Value);
	void PlayerJump();
	void PlayerSprintStart();
	void PlayerSprintStop();


	// Weapon Input MappingContext, Actions and Functions

	// Input Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputMappingContext> WeaponMappingContext;

	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > FireWeaponAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > AimWeaponAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > ReloadWeaponAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > MeleeAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > SelectPrimaryWeaponAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > SelectSecondaryWeaponAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr < UInputAction > SelectMeleeWeaponAction;


	// Input Functions
	void FireWeapon();
	void AimWeapon(const FInputActionValue& Value);
	void ReloadWeapon();
	void MeleeAttack();
	void SelectPrimaryWeapon();
	void SelectSecondaryWeapon();
	void SelectMeleeWeapon();
};
