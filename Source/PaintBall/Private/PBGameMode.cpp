// // PaintBall. All Rights Reserved.


#include "PBGameMode.h"
#include "PBPlayer.h"
#include "PBPlayerController.h"

APBGameMode::APBGameMode()
{
    DefaultPawnClass = APBPlayer::StaticClass();
    PlayerControllerClass = APBPlayerController::StaticClass();
}