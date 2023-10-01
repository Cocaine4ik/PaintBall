// // PaintBall. All Rights Reserved.


#include "UI/PBGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/PBScoreWidget.h"
void APBGameHUD::BeginPlay()
{
    Super::BeginPlay();

    if (!ScoreWidgetClass || !YouWinWidgetClass) return;

    const auto ScoreWidget = CreateWidget<UPBScoreWidget>(GetWorld(), ScoreWidgetClass);
    ScoreWidget->AddToViewport();
    ScoreWidget->SetVisibility(ESlateVisibility::Visible);

    YouWinWidget = CreateWidget<UUserWidget>(GetWorld(), YouWinWidgetClass);
    YouWinWidget->AddToViewport();
    YouWinWidget->SetVisibility(ESlateVisibility::Hidden);
}

void APBGameHUD::ShowYouWinWidget()
{
    YouWinWidget->SetVisibility(ESlateVisibility::Visible);
}
