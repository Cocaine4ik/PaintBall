// // PaintBall. All Rights Reserved.


#include "PBGameMode.h"
#include "PBCharacter.h"
#include "PBPlayerController.h"

APBGameMode::APBGameMode()
{
    DefaultPawnClass = APBCharacter::StaticClass();
    PlayerControllerClass = APBPlayerController::StaticClass();
}