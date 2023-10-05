// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PBBasePawn.generated.h"

class USoundCue;
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

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UPBPaintComponent* OtherPaintComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    float Speed = 500.0f;
    
public:
    UFUNCTION()
    virtual void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);
};