// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PBScoreWidget.generated.h"

class UTextBlock;

UCLASS()
class PAINTBALL_API UPBScoreWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    FString GetCleanersCountText() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    FString GetPaintedPawnsCountText() const;

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* CleanersCountTextBlock;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* PaintedPawnsCountTextBlock;
};