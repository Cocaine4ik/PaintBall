// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PBPaintComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangePaintedPawnsCount, int32, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangePaintedCleanersCount, int32, Value);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PAINTBALL_API UPBPaintComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UPBPaintComponent();
    
    FOnChangePaintedPawnsCount OnChangePaintedPawnsCount;
    FOnChangePaintedCleanersCount OnChangePaintedCleanersCount;
    
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
    UMaterial* BaseMaterial;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Color")
    FLinearColor DefaultColor;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Color")
    FLinearColor CurrentColor;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Color")
    bool bIsPainted = false;
    
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    void SetColor(FLinearColor Color);
    void SetDefaultColor();
    
    bool IsPainted() const { return bIsPainted;}
    FLinearColor GetDefaultColor() const { return DefaultColor; }
    FLinearColor GetCurrentColor() const { return CurrentColor; }

private:
    void ChangePaintedAIPawnsCount(int32 Value);
    void ChangePaintedCleanersCount(int32 Value);
};

