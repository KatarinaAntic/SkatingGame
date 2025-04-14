

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SkateHUD.generated.h"

/**
 * 
 */
UCLASS()
class SKATINGGAME_API ASkateHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	int Score = 0;
	
	
};
