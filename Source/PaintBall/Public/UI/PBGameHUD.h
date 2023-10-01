// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PBGameHUD.generated.h"

class UUserWidget;

UCLASS()
class PAINTBALL_API APBGameHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> ScoreWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> YouWinWidgetClass;

public:
    virtual void BeginPlay() override;
    void ShowYouWinWidget();

private:
    UUserWidget* YouWinWidget;
};