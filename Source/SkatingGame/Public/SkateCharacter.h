

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SkateCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class SKATINGGAME_API ASkateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASkateCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Input Functions
	void Move(const FInputActionValue& Value);
	void SpeedUp(const FInputActionValue& Value);
	void JumpAction(const FInputActionValue& Value);

	// Input mapping
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SpeedUpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpInputAction;

	// Movement variables
	bool bIsSpeedingUp = false;
	float CurrentSpeed = 600.f;
	float MaxSpeed = 1200.f;
	float BaseSpeed = 600.f;


private:

	
};
