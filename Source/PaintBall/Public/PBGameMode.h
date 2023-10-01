// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PBGameMode.generated.h"

class UBoxComponent;
class APBSpawnZone;

UCLASS()
class PAINTBALL_API APBGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    APBGameMode();

    virtual void BeginPlay() override;
    virtual void StartPlay() override;
    
    int32 GetPaintedCleanersCount() const{ return PaintedCleanersCount; }
    int32 GetCleanersCount() const {return AICleanersCount; }
    
    UFUNCTION()
    void AddPaintedCleaners(int32 Value) { PaintedCleanersCount += Value; }

    int32 GetCurrentPaintedPawnsCount() const { return PaintedPawnsCount; }
    
    UFUNCTION()
    void AddPaintedPawns(int32 Value);
    
protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AIPawn;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AICleaner;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    int32 AIPawnsCount = 10;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    int32 AICleanersCount  = 10;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    float SpawnDelay = 0.1f;
    
private:
    APBSpawnZone* SpawnZone;
    FTimerHandle SpawnTimerHandle;

    int32 PaintedPawnsCount = 0;
    int32 PaintedCleanersCount = 0;
    
    int32 GetNumOfSpawnedActorsOfClass(TSubclassOf<AActor> ActorClass);
    void SpawnActorsOfClass(TSubclassOf<AActor> ActorClass, int32 ActorsCount);
    void SubscribePawnsToDelegates();
    void SpawnBots();

    void GameOver();
};