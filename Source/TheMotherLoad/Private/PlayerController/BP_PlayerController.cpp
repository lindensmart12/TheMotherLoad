


#include "PlayerController/BP_PlayerController.h"
#include "TheMotherLoad/Public/Character/Slick.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void ABP_PlayerController::BeginPlay()
{
	Super::BeginPlay();


	SlickPlayerCharacter = Cast < ASlick >(GetCharacter());

	if (SlickPlayerCharacter)
	{
		TObjectPtr < APlayerController > PlayerController = Cast < APlayerController >(SlickPlayerCharacter->GetController());
		if (PlayerController)
		{
			TObjectPtr < UEnhancedInputLocalPlayerSubsystem > Subsystem = ULocalPlayer::GetSubsystem < UEnhancedInputLocalPlayerSubsystem >(PlayerController->GetLocalPlayer());
			if (Subsystem)
			{
				Subsystem->AddMappingContext(PlayerMovementMappingContext, 0);
				Subsystem->AddMappingContext(WeaponMappingContext, 1);
			}
		}
	}
	
}

void ABP_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	TObjectPtr < UEnhancedInputComponent > PlayerEnhancedInputComponent = CastChecked < UEnhancedInputComponent >(InputComponent);

	// Player Movement Input Bindings
	PlayerEnhancedInputComponent->BindAction(PlayerMoveAction, ETriggerEvent::Triggered, this, &ABP_PlayerController::PlayerMove);
	PlayerEnhancedInputComponent->BindAction(PlayerLookAction, ETriggerEvent::Triggered, this, &ABP_PlayerController::PlayerLook);
	PlayerEnhancedInputComponent->BindAction(PlayerJumpAction, ETriggerEvent::Started, this, &ABP_PlayerController::PlayerJump);
	PlayerEnhancedInputComponent->BindAction(PlayerSprintAction, ETriggerEvent::Started, this, &ABP_PlayerController::PlayerSprintStart);
	PlayerEnhancedInputComponent->BindAction(PlayerSprintAction, ETriggerEvent::Completed, this, &ABP_PlayerController::PlayerSprintStop);

	// Weapon Input Bindings
	PlayerEnhancedInputComponent->BindAction(FireWeaponAction, ETriggerEvent::Started, this, &ABP_PlayerController::FireWeapon);
	PlayerEnhancedInputComponent->BindAction(AimWeaponAction, ETriggerEvent::Triggered, this, &ABP_PlayerController::AimWeapon);
	PlayerEnhancedInputComponent->BindAction(ReloadWeaponAction, ETriggerEvent::Started, this, &ABP_PlayerController::ReloadWeapon);
	PlayerEnhancedInputComponent->BindAction(MeleeAttackAction, ETriggerEvent::Started, this, &ABP_PlayerController::MeleeAttack);
	PlayerEnhancedInputComponent->BindAction(SelectPrimaryWeaponAction, ETriggerEvent::Started, this, &ABP_PlayerController::SelectPrimaryWeapon);
	PlayerEnhancedInputComponent->BindAction(SelectSecondaryWeaponAction, ETriggerEvent::Started, this, &ABP_PlayerController::SelectSecondaryWeapon);
	PlayerEnhancedInputComponent->BindAction(SelectMeleeWeaponAction, ETriggerEvent::Started, this, &ABP_PlayerController::SelectMeleeWeapon);
}








// Player Movement Input Functions

void ABP_PlayerController::PlayerMove(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	
	if (SlickPlayerCharacter->Controller)
	{
		const FRotator ControllerRotation = SlickPlayerCharacter->GetControlRotation();
		const FRotator YawRotation(0, ControllerRotation.Yaw, 0);
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		SlickPlayerCharacter->AddMovementInput(ForwardDirection, MovementVector.Y);
		SlickPlayerCharacter->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABP_PlayerController::PlayerLook(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (SlickPlayerCharacter->Controller)
	{
		SlickPlayerCharacter->AddControllerYawInput(LookAxisVector.X);
		SlickPlayerCharacter->AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABP_PlayerController::PlayerJump()
{
	SlickPlayerCharacter->Jump();
}

void ABP_PlayerController::PlayerSprintStart()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerSprintStart Input Received"));
}

void ABP_PlayerController::PlayerSprintStop()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerSprintStop Input Received"));
}









// Weapon Input Functions

void ABP_PlayerController::FireWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("FireWeapon Input Received"));
}

void ABP_PlayerController::AimWeapon(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("AimWeapon Input Received"));
}

void ABP_PlayerController::ReloadWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("ReloadWeapon Input Received"));
}

void ABP_PlayerController::MeleeAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("MeleeAttack Input Received"));
}

void ABP_PlayerController::SelectPrimaryWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("SelectPrimaryWeapon Input Received"));
}

void ABP_PlayerController::SelectSecondaryWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("SelectSecondaryWeapon Input Received"));
}

void ABP_PlayerController::SelectMeleeWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("SelectMeleeWeapon Input Received"));
}