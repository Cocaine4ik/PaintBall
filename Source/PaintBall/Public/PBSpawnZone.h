// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PBSpawnZone.generated.h"

class UBoxComponent;

UCLASS()
class PAINTBALL_API APBSpawnZone : public AActor
{
    GENERATED_BODY()

public:
    APBSpawnZone();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* SpawnArea;
    
    virtual void BeginPlay() override;

public:
    bool CalculateRandomSpawnLocation(FVector& SpawnLocation);
};