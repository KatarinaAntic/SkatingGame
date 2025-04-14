

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SkateCharacter.generated.h"

class UInputAction;
class UInputMappingContext;
class USpringArmComponent;
class UCameraComponent;
class UAnimSequence;
class AJumpObstacle;


UCLASS()
class SKATINGGAME_API ASkateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASkateCharacter();

	UFUNCTION()
	void OnJumpObstacleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Input Functions
	void JumpAction(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void SlowDownStart();
	void SlowDownEnd();

	void PlayIdleAnimation();
	void StartSkatingAnimation();
	void StopSkatingAnimation();
	bool bIsSkating = false;
	bool bIsBraking = false;
	
	// Input mapping
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* SpeedUpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* SlowDownAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimSequence* IdleAnimation;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimSequence* SkateAnimation;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimSequence* JumpAnimation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skateboard")
	class UStaticMeshComponent* SkateboardMesh;  


	// Movement variables
	bool bIsSpeedingUp = false;
	float CurrentSpeed = 0.f;
	float MaxSpeed = 1200.f;
	float MinSpeed = 0.f;


private:
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* MeshComponent;
	
};
