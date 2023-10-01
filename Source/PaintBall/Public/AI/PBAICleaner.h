// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/PBAIPawn.h"
#include "PBAICleaner.generated.h"

UCLASS

()
class PAINTBALL_API APBAICleaner : public APBAIPawn
{
    GENERATED_BODY()

public:
    APBAICleaner(const FObjectInitializer& ObjInit);
    
    virtual void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit) override;

};