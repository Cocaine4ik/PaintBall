// // PaintBall. All Rights Reserved.


#include "Components/PBPaintComponent.h"
#include "AI/PBAIPawn.h"
#include "AI/PBAICleaner.h"

UPBPaintComponent::UPBPaintComponent()
{
}

// Called when the game starts
void UPBPaintComponent::BeginPlay()
{
    Super::BeginPlay();

    SetColor(DefaultColor);
    bIsPainted = false;
}

void UPBPaintComponent::SetColor(FLinearColor Color)
{
    auto StaticMeshComponent = GetOwner()->GetComponentByClass<UStaticMeshComponent>();

    if(StaticMeshComponent && StaticMeshComponent->GetMaterial(0) && BaseMaterial && !bIsPainted)
    {
        const auto DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
        DynamicMaterial->SetVectorParameterValue(TEXT("Base Color"), Color);

        CurrentColor = Color;
        StaticMeshComponent->SetMaterial(0, DynamicMaterial);

        bIsPainted = true;

        if (Color == DefaultColor)
        {
            ChangePaintedAIPawnsCount(-1);
            ChangePaintedCleanersCount(-1);
        }
        else
        {
            ChangePaintedAIPawnsCount(1);
            ChangePaintedCleanersCount(1);
        }
    }
}

void UPBPaintComponent::SetDefaultColor()
{
    bIsPainted = false;

    SetColor(DefaultColor);
    
    bIsPainted = false;
}

void UPBPaintComponent::ChangePaintedAIPawnsCount(int32 Value)
{
    const auto AIPawn = Cast<APBAIPawn>(GetOwner());
    if (AIPawn)
    {
        OnChangePaintedPawnsCount.Broadcast(Value);
    }
}

void UPBPaintComponent::ChangePaintedCleanersCount(int32 Value)
{
    const auto AICleaner = Cast<APBAICleaner>(GetOwner());
    if (AICleaner)
    {
        OnChangePaintedCleanersCount.Broadcast(Value);
    }
}