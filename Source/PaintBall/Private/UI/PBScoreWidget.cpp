// // PaintBall. All Rights Reserved.

#include "UI/PBScoreWidget.h"
#include "PBGameMode.h"

FString UPBScoreWidget::GetCleanersCountText() const
{
    const auto GameMod = GetWorld() ? Cast<APBGameMode>(GetWorld()->GetAuthGameMode()) : nullptr;

    if (!GameMod) return FString::Printf(TEXT("CLEANERS LEFT : Error"));

    const auto CleanersLeft = GameMod->GetCleanersCount() - GameMod->GetPaintedCleanersCount();

    return FString::Printf(TEXT("CLEANERS LEFT : %i"), CleanersLeft);
}

FString UPBScoreWidget::GetPaintedPawnsCountText() const
{
    const auto GameMod = GetWorld() ? Cast<APBGameMode>(GetWorld()->GetAuthGameMode()) : nullptr;

    if (!GameMod) return FString::Printf(TEXT("PAINTED : Error"));

    const auto PaintedPawnsCount = GameMod->GetCurrentPaintedPawnsCount();

    return FString::Printf(TEXT("PAINTED : %i"), PaintedPawnsCount);
}