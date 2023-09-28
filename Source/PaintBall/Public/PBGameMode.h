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
    
protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AIPawn;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AICleaner;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    int32 AIPawnCount = 10;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    int32 AICleanerCount = 10;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    float SpawnDelay = 0.1f;

private:
    APBSpawnZone* SpawnZone;
    FTimerHandle SpawnTimerHandle;
    
    void SpawnBots();
};