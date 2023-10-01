// // PaintBall. All Rights Reserved.

#include "PBGameMode.h"
#include "PBPlayer.h"
#include "PBPlayerController.h"
#include "PBSpawnZone.h"
#include "Kismet/GameplayStatics.h"
#include "UI/PBGameHUD.h"
#include "EngineUtils.h"
#include "PBPaintComponent.h"
#include "AI/PBAICleaner.h"
#include "AI/PBAIPawn.h"

APBGameMode::APBGameMode()
{
    DefaultPawnClass = APBPlayer::StaticClass();
    PlayerControllerClass = APBPlayerController::StaticClass();
    HUDClass = APBGameHUD::StaticClass();
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

    SubscribePawnsToDelegates();
}

void APBGameMode::AddPaintedPawns(int32 Value)
{
    PaintedPawnsCount += Value;
    if (PaintedPawnsCount == AIPawnsCount + AICleanersCount)
    {
        GameOver();
    }
}


int32 APBGameMode::GetNumOfSpawnedActorsOfClass(TSubclassOf<AActor> ActorClass)
{
    if (!GetWorld())
    {
        return 0;
    }

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ActorClass, FoundActors);

    return FoundActors.Num();
}

void APBGameMode::SpawnActorsOfClass(TSubclassOf<AActor> ActorClass, int32 ActorsCount)
{
    if (!SpawnZone || !GetWorld() || !ActorClass)
    {
        return;
    }

    FVector SpawnLocation = FVector::Zero();

    int32 ActorsSpawned = 0;

    while (ActorsSpawned != ActorsCount)
    {

        if (SpawnZone->CalculateRandomSpawnLocation(SpawnLocation))
        {
            GetWorld()->SpawnActor(ActorClass, &SpawnLocation);
            ActorsSpawned = GetNumOfSpawnedActorsOfClass(ActorClass);
        }
    }
}

void APBGameMode::SubscribePawnsToDelegates()
{/**/
    for (TActorIterator<APBAIPawn> It(GetWorld()); It; ++It)
    {
        APBAIPawn* Pawn = *It;
        if (Pawn)
        {
            const auto PainComponent = Pawn->GetComponentByClass<UPBPaintComponent>();
            PainComponent->OnChangePaintedPawnsCount.AddDynamic(this, &APBGameMode::APBGameMode::AddPaintedPawns);
        }
    }

    for (TActorIterator<APBAICleaner> It(GetWorld()); It; ++It)
    {
        APBAICleaner* Cleaner = *It;
        if (Cleaner)
        {
            const auto PainComponent = Cleaner->GetComponentByClass<UPBPaintComponent>();
            PainComponent->OnChangePaintedCleanersCount.AddDynamic(this, &APBGameMode::AddPaintedCleaners);
        }
    }
}

void APBGameMode::SpawnBots()
{
    SpawnActorsOfClass(AIPawn, AIPawnsCount);
    SpawnActorsOfClass(AICleaner, AICleanersCount);
}

void APBGameMode::GameOver()
{
    for (auto Pawn : TActorRange<APawn>(GetWorld()))
    {
        if (Pawn)
        {
            Pawn->TurnOff();
            Pawn->DisableInput(nullptr);
        }
    }
    const auto HUD = Cast<APBGameHUD>(UGameplayStatics::GetPlayerController(this,0)->GetHUD());
    HUD->ShowYouWinWidget();
}