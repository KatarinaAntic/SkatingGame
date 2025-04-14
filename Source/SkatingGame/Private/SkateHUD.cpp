


#include "SkateHUD.h"
#include "Engine/Canvas.h"
#include "UObject/ConstructorHelpers.h"

void ASkateHUD::DrawHUD()
{
	Super::DrawHUD();

	// Controls text - top left
	FString ControlsText = TEXT("Left Shift to Skate\nSpace to Jump\nLeft Control to Brake");
	DrawText(ControlsText, FColor::White, 50.0f, 50.0f, nullptr, 1.5f);

	// Score text - top right
	FString ScoreText = FString::Printf(TEXT("Score: %d"), Score);
	float X = Canvas->SizeX - 200.0f;
	DrawText(ScoreText, FColor::Yellow, X, 50.0f, nullptr, 1.8f);
}


