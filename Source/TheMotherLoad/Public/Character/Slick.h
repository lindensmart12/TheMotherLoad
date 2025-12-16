

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Slick.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class THEMOTHERLOAD_API ASlick : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASlick();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Spring Arm Component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr < USpringArmComponent> SpringArmComp;

	// Camera Component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr < UCameraComponent> CameraComp;
};
