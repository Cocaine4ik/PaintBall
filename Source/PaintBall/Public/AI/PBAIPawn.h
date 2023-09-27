// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/PBBasePawn.h"
#include "PBAIPawn.generated.h"

class UBoxComponent;

UCLASS()
class PAINTBALL_API APBAIPawn : public APBBasePawn
{
    GENERATED_BODY()

public:
    APBAIPawn(const FObjectInitializer& ObjInit);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* BoxComponent;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    float SpeedStep = 50.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    float MovementDelay = 0.3f;
    
private:
    void MoveRandomDirection();
    float GetRandomValueWithStep(float Min, float Max, float Step);

public:
    virtual void BeginPlay() override;
    
    virtual void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit) override;
    
    
    FTimerHandle RandomMoveTimerHandle;
    
};