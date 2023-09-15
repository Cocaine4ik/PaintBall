// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/PBBasePawn.h"
#include "PBAIPawn.generated.h"

/**
 * 
 */
UCLASS()
class PAINTBALL_API APBAIPawn : public APBBasePawn
{
    GENERATED_BODY()

public:
    APBAIPawn(const FObjectInitializer& ObjInit);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    float SpeedStep = 50.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    float MovementDelay = 0.3f;
    
private:
    void MoveRandomDirection();
    float GetRandomValueWithStep(float Min, float Max, float Step);

public:
    FTimerHandle RandomMoveTimerHandle;
    
    virtual void BeginPlay() override;
    
};