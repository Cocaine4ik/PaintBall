// // PaintBall. All Rights Reserved.


#include "PBGameMode.h"
#include "PBPlayer.h"
#include "PBPlayerController.h"
#include "PBSpawnZone.h"
#include "Kismet/GameplayStatics.h"

APBGameMode::APBGameMode()
{
    DefaultPawnClass = APBPlayer::StaticClass();
    PlayerControllerClass = APBPlayerController::StaticClass();

}

void APBGameMode::BeginPlay()
{
    Super::BeginPlay();

    SpawnZone = Cast<APBSpawnZone>(UGameplayStatics::GetActorOfClass(GetWorld(), APBSpawnZone::StaticClass()));
}

void APBGameMode::StartPlay()
{
    Super::StartPlay();

    SpawnBots();
}

void APBGameMode::SpawnBots()
{
    if (!SpawnZone || !GetWorld() || !AIPawn || !AICleaner) return;
    
    FVector SpawnLocation = FVector::Zero();
    
    for (int32 i = 0; i < AIPawnCount; i++)
    {
        if(SpawnZone->CalculateRandomSpawnLocation(SpawnLocation))
        {
            GetWorld()->SpawnActor(AIPawn, &SpawnLocation);
        }
    }

    for (int32 i = 0; i < AICleanerCount; i++)
    {
        if(SpawnZone->CalculateRandomSpawnLocation(SpawnLocation))
        {
            GetWorld()->SpawnActor(AICleaner, &SpawnLocation);
        }
    }
}