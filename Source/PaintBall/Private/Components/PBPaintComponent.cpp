// // PaintBall. All Rights Reserved.


#include "Components/PBPaintComponent.h"

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
    }
}

void UPBPaintComponent::SetDefaultColor()
{
    bIsPainted = false;

    SetColor(DefaultColor);
    
    bIsPainted = false;
}