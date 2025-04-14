


#include "JumpObstacle.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SkateCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AJumpObstacle::AJumpObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	// Trigger box
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);

	// Set size of the trigger
	TriggerBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));
	TriggerBox->SetCollisionProfileName(TEXT("Trigger")); // Important for overlap detection
	TriggerBox->SetGenerateOverlapEvents(true);
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	TriggerBox->SetGenerateOverlapEvents(true);
	SetActorTickEnabled(true);
	SetActorEnableCollision(true);
	TriggerBox->SetActive(true);
	TriggerBox->SetHiddenInGame(false);

	bHasTriggered = false;
}

// Called when the game starts or when spawned
void AJumpObstacle::BeginPlay()
{
	Super::BeginPlay();
	if (!TriggerBox->OnComponentBeginOverlap.IsAlreadyBound(this, &AJumpObstacle::OnBoxOverlap))
	{
		TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AJumpObstacle::OnBoxOverlap);
	}
	
}

// Called every frame
void AJumpObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AJumpObstacle::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
 {
	ASkateCharacter* SkateChar = Cast<ASkateCharacter>(OtherActor);
	if (SkateChar)
	{
		SkateChar->OnJumpObstacleOverlap(OverlappedComponent, this, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	}
}

