


#include "SkateCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "PlayerMappableInputConfig.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASkateCharacter::ASkateCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add Mapping Context
	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}

// Called when the game starts or when spawned
void ASkateCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkateCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Apply friction for slowing down when not speeding up
//	if (!bIsSpeedingUp && CurrentSpeed > 0)
//	{
//		CurrentSpeed -= 5.f;	//Friction rate
//		if (CurrentSpeed < 0)
//			CurrentSpeed = 0;
//	}
}

// Called to bind functionality to input
void ASkateCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASkateCharacter::Move);
		EnhancedInput->BindAction(SpeedUpAction, ETriggerEvent::Triggered, this, &ASkateCharacter::SpeedUp);
		EnhancedInput->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &ASkateCharacter::JumpAction);
	}
}

void ASkateCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);
}

void ASkateCharacter::SpeedUp(const FInputActionValue& Value)
{
	bool bPressed = Value.Get<bool>();
	bIsSpeedingUp = bPressed;

	if (bIsSpeedingUp)
	{
		GetCharacterMovement()->MaxWalkSpeed = MaxSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
	}
}


void ASkateCharacter::JumpAction(const FInputActionValue& Value)
{
	// Add the jump logic for tricks
	Jump();
}