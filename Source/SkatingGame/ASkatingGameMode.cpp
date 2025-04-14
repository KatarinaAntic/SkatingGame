#include "ASkatingGameMode.h"
#include "SkateCharacter.h"
#include "SkateHUD.h"

ASkatingGameMode::ASkatingGameMode()
{
    // Set default pawn class to your character class
    DefaultPawnClass = ASkateCharacter::StaticClass();
    HUDClass = ASkateHUD::StaticClass();
}