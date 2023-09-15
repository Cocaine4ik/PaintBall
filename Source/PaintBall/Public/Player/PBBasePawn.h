// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PBBasePawn.generated.h"

class UStaticMeshComponent;
class UPBPaintComponent;

UCLASS()
class PAINTBALL_API APBBasePawn : public APawn
{
    GENERATED_BODY()

public:
    APBBasePawn(const FObjectInitializer& ObjInit);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UPBPaintComponent* PaintComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    float Speed = 500.0f;
};