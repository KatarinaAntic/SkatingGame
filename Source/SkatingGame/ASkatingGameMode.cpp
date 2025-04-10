#include "ASkatingGameMode.h"
#include "SkateCharacter.h"

ASkatingGameMode::ASkatingGameMode()
{
    // Set default pawn class to your character class
    DefaultPawnClass = ASkateCharacter::StaticClass();
}