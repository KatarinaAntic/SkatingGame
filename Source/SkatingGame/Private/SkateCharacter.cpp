


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
#include "JumpObstacle.h"
#include "Components/CapsuleComponent.h"
#include "SkateHUD.h"

class AJumpObstacle;
// Sets default values
ASkateCharacter::ASkateCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IdleAnimation = nullptr;
	SkateAnimation = nullptr;
	JumpAnimation = nullptr;


	// Load Input Mapping Context
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> MappingContextObj(TEXT("/Game/Input/IMCSkateCharacter.IMCSkateCharacter"));
	if (MappingContextObj.Succeeded())
	{
		InputMapping = MappingContextObj.Object;
	}

	// Load SpeedUp Input Action
	static ConstructorHelpers::FObjectFinder<UInputAction> SpeedUpActionObj(TEXT("/Game/Input/SpeedUp.SpeedUp"));
	if (SpeedUpActionObj.Succeeded())
	{
		SpeedUpAction = SpeedUpActionObj.Object;
	}

	// Load SlowDown Input Action
	static ConstructorHelpers::FObjectFinder<UInputAction> SlowDownActionObj(TEXT("/Game/Input/SlowDown.SlowDown"));
	if (SlowDownActionObj.Succeeded())
	{
		SlowDownAction = SlowDownActionObj.Object;
	}

	// Load Jump Input Action
	static ConstructorHelpers::FObjectFinder<UInputAction> JumpActionObj(TEXT("/Game/Input/Jump.Jump"));
	if (JumpActionObj.Succeeded())
	{
		JumpInputAction = JumpActionObj.Object;
	}

	// Load Look Input Action
	static ConstructorHelpers::FObjectFinder<UInputAction> LookActionObj(TEXT("/Game/Input/Look.Look"));
	if (LookActionObj.Succeeded())
	{
		LookAction = LookActionObj.Object;
	}

	GetCapsuleComponent()->SetGenerateOverlapEvents(true);

	GetMesh()->SetupAttachment(RootComponent);
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f)); // Rotate mesh to face +X

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMesh(TEXT("/Game/Character/character.character"));
	if (CharacterMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(CharacterMesh.Object);
	}

	SkateboardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SkateboardMesh"));
	SkateboardMesh->SetupAttachment(GetMesh(), FName("LeftFootSocket"));  // Attach it to the socket
	SkateboardMesh->SetRelativeLocation(FVector(0.f, 0.f, -15.f));  // Adjust position relative to foot
	SkateboardMesh->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));  // Adjust rotation if needed
	SkateboardMesh->SetVisibility(true);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SkateboardAsset(TEXT("/Game/Character/Skate.Skate"));
	if (SkateboardAsset.Succeeded())
	{
		SkateboardMesh->SetStaticMesh(SkateboardAsset.Object);  
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> IdleAnimObj(TEXT("/Game/Animation/IdleAnim_Anim.IdleAnim_Anim"));
	if (IdleAnimObj.Succeeded())
	{
		IdleAnimation = IdleAnimObj.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> SkateAnimObj(TEXT("/Game/Animation/PushingAnim_Anim.PushingAnim_Anim"));
	if (SkateAnimObj.Succeeded())
	{
		SkateAnimation = SkateAnimObj.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> JumpAnim(TEXT("/Game/Animation/Jumping__1__Beta_Surface_Anim.Jumping__1__Beta_Surface_Anim"));
	if (JumpAnim.Succeeded())
	{
		JumpAnimation = JumpAnim.Object;
	}


	// Create and initialize the Spring Arm component
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // Distance from the character to the camera
	CameraBoom->bUsePawnControlRotation = true; // Allow the camera to rotate with the character
	
	// Position and rotate the boom
	CameraBoom->SetRelativeLocation(FVector(0.f, 0.f, 60.f));

	// Create and initialize the Camera component
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Optional: reset camera’s own transform if needed
	FollowCamera->SetRelativeLocation(FVector::ZeroVector);
	FollowCamera->SetRelativeRotation(FRotator::ZeroRotator);

	// Set the response to "Pawn" to "Overlap"
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GetCapsuleComponent()->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);

}

void ASkateCharacter::PlayIdleAnimation()
{
	if (IdleAnimation)
	{
		GetMesh()->PlayAnimation(IdleAnimation, true); // loop idle
	}
}


// Called when the game starts or when spawned
void ASkateCharacter::BeginPlay()
{
	Super::BeginPlay();
	// Add Mapping Context
	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	if (IdleAnimation)
		GetMesh()->PlayAnimation(IdleAnimation, true);

}

// Called every frame
void ASkateCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If the character is skating, speed up
	if (bIsSkating && GetCharacterMovement() && !bIsBraking)
	{
		if (GetCharacterMovement()->MaxWalkSpeed < MaxSpeed)
		{
			// Gradually increase the speed up to the max speed
			GetCharacterMovement()->MaxWalkSpeed += 3.f;
			if (GetCharacterMovement()->MaxWalkSpeed > MaxSpeed)
			{
				GetCharacterMovement()->MaxWalkSpeed = MaxSpeed;
			}
		}
	}
	// If not skating, slow down to the minimum speed
	else if (!bIsSkating && GetCharacterMovement())
	{
		if (GetCharacterMovement()->MaxWalkSpeed > MinSpeed)
		{
			// Gradually decrease the speed down to the min speed
			GetCharacterMovement()->MaxWalkSpeed -= 1.5f;
			if (GetCharacterMovement()->MaxWalkSpeed < MinSpeed)
			{
				GetCharacterMovement()->MaxWalkSpeed = MinSpeed;
			}
		}
	}
	// If braking, slow down rapidly
	if (bIsBraking && GetCharacterMovement())
	{
		if (GetCharacterMovement()->MaxWalkSpeed > MinSpeed)
		{
			GetCharacterMovement()->MaxWalkSpeed -= 4.f;
			if (GetCharacterMovement()->MaxWalkSpeed < MinSpeed)
			{
				GetCharacterMovement()->MaxWalkSpeed = MinSpeed;
			}
		}
	}

	// Get the camera's forward vector for moving forward/backward in the camera's facing direction
	FVector CameraForward = FollowCamera->GetForwardVector(); // Camera's forward direction

	if (GetCharacterMovement()->MaxWalkSpeed >= 0.f)
	{
		// Add movement input using the camera's forward vector
		AddMovementInput(CameraForward, 1.f);  // Only move forward in the direction the camera is facing
	}
}

// Called to bind functionality to input
void ASkateCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(SpeedUpAction, ETriggerEvent::Started, this, &ASkateCharacter::StartSkatingAnimation);
		EnhancedInput->BindAction(SpeedUpAction, ETriggerEvent::Completed, this, &ASkateCharacter::StopSkatingAnimation);
		EnhancedInput->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &ASkateCharacter::JumpAction);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASkateCharacter::Look);
		EnhancedInput->BindAction(SlowDownAction, ETriggerEvent::Started, this, &ASkateCharacter::SlowDownStart);
		EnhancedInput->BindAction(SlowDownAction, ETriggerEvent::Completed, this, &ASkateCharacter::SlowDownEnd);
	}
}


void ASkateCharacter::StartSkatingAnimation()
{
	if (SkateAnimation && !bIsSkating && !bIsBraking)
	{
		bIsSkating = true;
		GetMesh()->PlayAnimation(SkateAnimation, true);
	}
}

void ASkateCharacter::StopSkatingAnimation()
{
	if (IdleAnimation && bIsSkating)
	{
		bIsSkating = false;
		GetMesh()->PlayAnimation(IdleAnimation, true);
	}
}

void ASkateCharacter::SlowDownStart()
{
	bIsBraking = true;
}

void ASkateCharacter::SlowDownEnd()
{
	bIsBraking = false;
}

void ASkateCharacter::JumpAction(const FInputActionValue& Value)
{
	if (JumpAnimation) {
		GetMesh()->PlayAnimation(JumpAnimation, false);
		FTimerHandle TimerHandle_ResetToIdle;
		float AnimDuration = JumpAnimation->GetPlayLength();
		 
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_ResetToIdle, this, &ASkateCharacter::PlayIdleAnimation, AnimDuration, false);
	}
		
	Jump();
}

void ASkateCharacter::Look(const FInputActionValue& Value)
{
	FVector2D Look = Value.Get<FVector2D>();
	AddControllerYawInput(Look.X);
	AddControllerPitchInput(Look.Y);
}

void ASkateCharacter::OnJumpObstacleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		AJumpObstacle* JumpObstacle = Cast<AJumpObstacle>(OtherActor);
		if (JumpObstacle)
		{
			if (!GetCharacterMovement()->IsMovingOnGround())
			{
				if (PC)
				{
					ASkateHUD* HUD = Cast<ASkateHUD>(PC->GetHUD());
					if (HUD)
						HUD->Score += 10;
				}
				
			}
		}
	}
}
